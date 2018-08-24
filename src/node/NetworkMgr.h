/**
*
* @file     NetworkMgr.h
* @brief
*
* @author honyliu jennachen
* @version 1.0
* @date 2017-11-08
*
*
* Copyright (c)  2016-2017, 腾讯科技有限公司互动娱乐研发部
* All rights reserved.
*
*/

#ifndef __NETWORKMGR_H__
#define __NETWORKMGR_H__

#include <string>
#include "node/NodeMgr.h"
#include "protocal/cmd/MsgCmd.h"
#include "core/CommonFunction.h"



class NetworkMgr :public AbstractThread
{
private:
	string ip;
	int port;
	NodeMgr * m_pNodeMgr;
	MessageMgr * m_pMsgMgr;
	bool quit;

	int  m_max_tcpbuf;//缓冲区最大
	char * m_tcpSendBuf;//发送缓冲区
	char * m_tcpRecvBuf;//接收缓冲区	
	CommonSocket * m_pCommonSocket;
private :
	NetworkMgr(string ip,int port,MessageMgr *msgMgr, NodeMgr *nodeMgr);
	static NetworkMgr* p_network;
public:
	static NetworkMgr* getInstance(MessageMgr *msgMgr, NodeMgr *nodeMgr);
	static NetworkMgr* getInstance();
	void init(){}
	int getint(char* msgBuffer);
	//将buf中的数据写入到输出流m_tcpSendBuf
	bool sendMsg(char* m_tcpSendBuf,int &len);
	//将输入流m_tcpRecvBuf 的数据写入到body[]中, RecvSize为输入流中有效数据总长度
	bool receive();
	void recvMust(char * buff,int len,string  packageInfo);
	void doWork(); 
    virtual  void runThread();//线程启动后运行的函数
	void stopNetwork();
	void closeSocket(CommonSocket * socket);
	void startNetWork();
	~NetworkMgr();


	//---------------定义析构类，可以程序结束的时候自动析构该单例----------- 
	class CGarbo
	{
	public:
		~CGarbo()
		{ 
			if (NetworkMgr::p_network)
			{
				delete NetworkMgr::p_network;
			}
			g_logger.info("destory NetworkMgr::p_network");
		}
	};
	static CGarbo garbo; // 声明一个静态成员，在程序结束时，系统会调用它的析构函数




};

#endif