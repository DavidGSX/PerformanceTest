#include "GameAPI.h"
#include <iostream>


GameAPI::GameAPI()
{
	this->pCClient = CClient::getCClient();
	this->m_recvBodyBuffer = new char[BODYBUFFSIZE];
	this->adr_send.Reset(m_aSendBuffer,SENDBUFFSIZE);
	this->adr_recv.Reset(m_recvBodyBuffer,BODYBUFFSIZE);
}

GameAPI::~GameAPI()
{
	if(this->pCClient){
		delete this->pCClient;
	} 
}


bool GameAPI::connectToServer(){
	return pCClient->Start(SERVER_IP,SERVER_PORT_LOGIN);
}

void GameAPI::disconnect(){
	pCClient->Close();
}

/*
	return:	-1	send error
			>=0 send bytes size
*/
//校验数据包 包头填写的包体长度与实际包体长度是否一致
int GameAPI::sendGameMessage(char data[], int data_len )
{
	int len;
	memcpy(&len, data, sizeof(int));
	if(len + 4 != data_len){
		cout<< "send Message Error!!! pack size = "<<len<<" data_len = "<< data_len<<endl;
		return false;
	}
	return pCClient->Send(data,data_len);
}

//reset the tcp recv buff status
void GameAPI::resetRecvBufStatus(){
	buffer_len = 0;	//读取到的长度
	read_pos = 0;
	memset(m_aRecvBuffer,0,RECVBUFFSIZE);
}



/******************************************************************************
函数名称: recvMessage

功能描述: 根据包头的长度字段读取一个包，
          如果buf没有数据则会从tcp接收缓存中读数据，每次读取包先读包头，直到包头拼接完成，
		  然后解析包头，计算后续还需要读取多少字节的数据（命令字长度 shrot + 包体数据），
		  将读取完的数据写到body_buffer，data_size。
输入: body_buffer - 存储包体的buf
	  body_buffer_len - buf长度
	  data_size - 读取到的包体长度
返回值: 成功返回PKG_ERRPR_NONE，若返回PKG_ERRPR_NONE_CONTINUE表示recv buf还有数据，其他见头文件定义
完整包格式：
    包头 
	  unsigned int 4 字节，表示后续还有多少字节数据即包体的长度
	包体 
	  usinged short 2 字节  协议命令字
	  自定义结构体
******************************************************************************/
int GameAPI::recvMessage(char* body_buffer,int body_buffer_len,int& data_size){
	unsigned int pkgBodySize = 0;
	unsigned int head_buf_pos_ = 0;
	unsigned int body_buf_pos_ = 0;

	//全局变量在头文件里面定义
	//buffer_len 表示接收处理缓存m_aRecvBuffer里数据的长度
	//read_pos	表示读取的游标，即已经读取到哪里，如果下次再调用此函数则从此游标位置开始读取，
	//游标read_pos等于buffer_len则表示数据已经读取完，需要重新从tcp接收缓存读取数据
	do{
		unsigned int buffer_data_left = buffer_len - read_pos;
        //目前一次收包会把所有数据拷贝到m_aRecvBuffer，一次收的可能包含一个包，或者多个包，最后一个包也未必是完整的包 
		//如果m_aRecvBuffer没有数据了，则从tcp缓冲区读取数据进来
		//如果m_aRecvBuffer还有数据，不进行收包，直接解析包
		if( !buffer_data_left ){//表示m_aRecvBuffer已经没数据了
			//重置m_aRecvBuffer
			resetRecvBufStatus();
			//tick
			int waitTime = 10000;
			int waitCounts = 0;
			int tcp_read_result = 0;

			do{
				//从tcp缓冲区读取数据
				tcp_read_result = pCClient->Read(m_aRecvBuffer,RECVBUFFSIZE);
				
				//超时检测
				if( waitTime*waitCounts > TIME_OUT )
				{
					return PKG_ERROR_TIME_OUT;
				}

				//没有读取到数据则线程休眠一段时间
				if( tcp_read_result == -2 ){
					usleep(waitTime);
					waitCounts++;
					continue;
				}
				if( tcp_read_result == 0 ){
					cout<<"rec msg fail! soceket has been closed..."<<endl;
					return PKG_ERROR_TCP_READ;
				}

				if( tcp_read_result == -1 ){
					cout<<"rec msg fail! ret code = "<< tcp_read_result <<endl;
					return PKG_ERROR_TCP_READ;
				}
				//读取到数据则跳出此循环
				if( tcp_read_result > 0 ){
					//cout<<"rec msg success!"<<endl;
					buffer_len = tcp_read_result;
					break;
				}

			}while(true);
			continue;
		}
		
         /***********************包头处理********************/
		unsigned int head_len_leave = HEADLEN - head_buf_pos_;	//表示还包头剩多少数据需要读取
		//从m_aRecvBuffer里面读取包头
		if( head_len_leave ){
			//剩下数据不够完整包头，则拷贝剩下数据，跳出此循环重新从tcp缓存读取数据
			if( buffer_data_left < head_len_leave ){
				memcpy(&pkgBodySize + head_buf_pos_,m_aRecvBuffer + read_pos, buffer_data_left);
				head_buf_pos_ += buffer_data_left;
				read_pos += buffer_data_left;
				continue;
			}
			//数据够完整包头
			if(true){
				//pkg head recv finish
				memcpy(&pkgBodySize + head_buf_pos_,m_aRecvBuffer + read_pos, head_len_leave);
				read_pos += head_len_leave;
				head_buf_pos_+= head_len_leave;
				data_size = pkgBodySize;//设置返回值 包体长度
			}
		}

         /***********************包体处理********************/
		//包体大小，如果计算出来包体大小异常则返回
		if(! (pkgBodySize > 0)){
			cout<<"recv error: pkgBodySize = "<< pkgBodySize << endl;
			return PKG_ERRPR_UNPACKMSG;
		}
        //表示溢出，需要修改RECVBUFFSIZE缓冲区大小
		if( pkgBodySize > body_buffer_len ){
			cout<<"recv error: body_buffer len < pkgLen, pkgBodySize = "<<pkgBodySize<<endl;
			return PKG_ERROR_NO_COMPLETE;
		}

		//从m_aRecvBuffer里面读取包体
		unsigned int body_len_leave = pkgBodySize - body_buf_pos_;
		//计算m_aRecvBuffer接收缓冲区还剩下多少数据需要读取
		buffer_data_left = buffer_len - read_pos;
		//pgk body
		if(body_len_leave){
			//如果数据不够完整包体，表示没收到完整的包，则拷贝剩下的数据跳出此循环从tcp缓存再拷贝数据
			if( read_pos + pkgBodySize > buffer_len){
				memcpy(body_buffer + body_buf_pos_, m_aRecvBuffer + read_pos, buffer_data_left);
				body_buf_pos_ += buffer_data_left;
				read_pos += buffer_data_left;
				continue;
			}

			//数据够用了则包体读取完成返回
			//pkg body recv finish
			if(true){
				memcpy(body_buffer + body_buf_pos_,m_aRecvBuffer + read_pos, body_len_leave);
				read_pos += body_len_leave;
				body_buf_pos_ += body_len_leave;
			}

			if( read_pos < buffer_len)
				return PKG_ERRPR_NONE_CONTINUE;
			else
				return PKG_ERRPR_NONE;
		}		
		
	}while(true);

}


bool GameAPI::packMsgHead(short cmd){
    //4字节 表示包体长度
	memset(m_aSendBuffer,0,SENDBUFFSIZE);
	adr_send.Reset(m_aSendBuffer,SENDBUFFSIZE);
	adr_send.WritePos(0);
	char toNet1_ = 0;
	uint32_t body_length = 0;
	if(!adr_send.Write(body_length,toNet1_))
		return false;
    //设置命令字		
	if(!adr_send.Write((uint16_t)cmd,toNet1_))
		return false;
	return true;
}

bool GameAPI::packMsgBody(const char* msgBody, int msgBody_len){
	char toNet1_ = 0;
	uint32_t pkg_len = msgBody_len + sizeof(short);
	if(!adr_send.Write(msgBody,msgBody_len))
		return false;
	adr_send.WritePos(0);
	adr_send.Write( pkg_len, toNet1_);
	return true;
}

short GameAPI::getMsgCmdId(const char* msgBody, int msgBody_len){
	char toNet1_ = 0;
	int16_t cmdId = 0;
	adr_recv.Reset(m_recvBodyBuffer,BODYBUFFSIZE);
	adr_recv.Read(cmdId, toNet1_);
	return cmdId;
}
/*
登录功能：包括收发包
登录完整包格式：
    包头 
	  unsigned int 4 字节，表示后续还有多少字节数据即包体的长度
	包体 
	  usinged short 2 字节  协议命令字
	  登录结构体
*/	  
int GameAPI::tLoginGame(int userId,const string& account,const string& pwd){
	/****************组包 登录*****************************/
	TLoginDataReq tLoginDataReq;
	//tLoginDataReq.userId = userId;
	char strUser[20];
	memset(strUser, 0, sizeof(strUser));
	snprintf(strUser, 19, "%d", userId);
	memcpy( tLoginDataReq.userId, strUser, strlen(strUser) );
	memcpy( tLoginDataReq.account, account.c_str(), account.length() );
	memcpy( tLoginDataReq.pwd, pwd.c_str(), pwd.length() );

	int tLoginData_len = sizeof(TLoginDataReq);
	packMsgHead(PCS_TLoginGame);//设置头，同时设置命令字
	packMsgBody( (char *)&tLoginDataReq, tLoginData_len);//设置登录结构体
	int pkg_len = tLoginData_len + sizeof(short) + 4;
	//发送数据
	int ret = sendGameMessage(m_aSendBuffer, pkg_len);

	if( ret <= 0 ){
		cout<<"sendGameMessage fail..."<<ret<<endl;
		return ret;
	}

	//cout<<"sendGameMessage success..."<<endl;

	//收包
	int body_data_len = 0;
	ret = recvMessage(m_recvBodyBuffer, BODYBUFFSIZE, body_data_len);

	if(ret == PKG_ERRPR_NONE_CONTINUE){
		//get pkg body success, more than one pkg
		//cout<<"recv more than one pkg..."<<endl;
	}

	if(PKG_ERROR_TCP_READ == ret){
		//connect has been closed
		return -1;
	}

	if( ret == PKG_ERRPR_NONE || ret == PKG_ERRPR_NONE_CONTINUE){
		//get a pkg body success
		if(!body_data_len){
			cout<<"recv pkg error: body_data_len = 0"<<endl;
			return -1;
		}
        //解包
		//命令字
		short cmdId = getMsgCmdId(m_recvBodyBuffer,body_data_len);
		//cout<<"cmdId = "<< cmdId<< endl; 
		//cout<<"userId = "<< userId << " dataLen = " << body_data_len << endl; 
		//登录包
		if( cmdId == PCS_TLoginGame){
			//TLoginDataResp tLoginDataResp;
			//memcpy( &tLoginDataResp, m_recvBodyBuffer + sizeof(short), body_data_len );
			TLoginDataReq tLoginDataResq;
			memcpy(&tLoginDataResq, m_recvBodyBuffer + sizeof(short), body_data_len - sizeof(short));
			//memcpy( &tLoginDataResq, m_recvBodyBuffer + sizeof(short), body_data_len );
			//if(tLoginDataResp.ret_code == 0){
			//if(tLoginDataResq.userId == userId) {
			if(strncmp(tLoginDataResq.userId, strUser, strlen(strUser)) == 0) {
				//check ret code
				//cout<<"check ret code success! userId = "<< tLoginDataResq.userId << " account = " << tLoginDataResq.account << " pwd = " << tLoginDataResq.pwd << endl;
				return 1;
			}else{
				cout<<"msg error: check ret userId = "<< tLoginDataResq.userId << " origin =" << strUser << " account = " << tLoginDataResq.account << " pwd = " << tLoginDataResq.pwd << endl;
				return 0;
			}
		}
	}

	cout<<"recv msg error: error code = "<< ret <<endl;
	return -1;
	
}

/**
 * --------NOTICE--------*
 * 这里的返回值为int型，建议统一如下：
 * return  0 ===》表示任务执行成功
 * return  1 ===》表示任务执行失败，由于常规因素引起的任务失败，例如超时，机器人可以继续执行后面的动作
 * return -1 ===》表示任务执行失败，由于不可逆因素引起的任务失败，例如机器人被服务器踢掉了，又没有设置重连的策略，
 *				后面的任务确定会执行失败的情况，此时机器人会退出，不再执行后续任务
 *	其它类似的执行任务的函数使用相同的思路来构造
 * @author honyliu & moosedong
 *
 */
int GameAPI::Login(int uid)
{
	/*
	//----发送登录包
	//-----接收登录包
	 //----根据执行业务结果返回1 或者其他参数
	 */
	int iResult=1;
	return iResult;
}

int GameAPI::Logout()
{
	/*
	//----发送登出包
	//-----接收登出包
	 //----根据执行业务结果返回0 或者其他参数
	 */
	int iResult = 1;
	return iResult;
}

int GameAPI::StartGame()
{
	/*
	//-----发送开始游戏包
	//------接收游戏开始包
	//----根据执行业务结果返回1  或者其他参数
	*/
	int iResult = 1;
	return iResult;
}

int GameAPI::EndGame()
{
	/*
	 //-----发送结束游戏包
	   //-----接收结束开始包
	   //----根据执行业务结果返回0 或者其他参数
	*/
	int iResult = 1;
	return iResult;
}
