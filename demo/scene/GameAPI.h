/*
 * GameAPI.h
 *
 *  Created on: 2016-03-25
 *      Author: hazelnutlin
 */

#ifndef __GAMEAPI_H__
#define __GAMEAPI_H__

#include <iostream>

#include "Common/Protocol.h"
#include "Common/adr.h"

#include "Client.h"

//send缓冲区大小 
#define	SENDBUFFSIZE	40960
//接收缓冲区大小
#define	RECVBUFFSIZE	40960
//body
#define BODYBUFFSIZE 	40960

#define HEADLEN 4
#define PROTOCOL_CMD_LEN 2

#define SERVER_IP "10.7.2.12"
#define SERVER_PORT_LOGIN 8888

#define TIME_OUT 2000000

#define PKG_ERRPR_UNPACKMSG			1	//解包异常
#define PKG_ERROR_NO_DATA			2	//无数据
#define PKG_ERROR_NO_COMPLETE  		3	//接收数据包异常
#define PKG_ERRPR_NONE  			4	//读取完毕
#define PKG_ERRPR_NONE_CONTINUE	 	5	//读取完毕且缓冲区还有数据未读
#define PKG_ERROR_TCP_READ			6	//tcp 收数据异常
#define PKG_ERROR_TIME_OUT			7	//tcp 收数据超时


using namespace std;

class GameAPI
{
	public:
		GameAPI();
		~GameAPI();

		int Login(int uid);
		int StartGame();
		int EndGame();
		int Logout();

		int sendGameMessage(char data[], int data_len );
		int recvMessage(char* body_buffer,int body_buffer_len,int& data_size);
		bool connectToServer();
		void disconnect();
		bool packMsgHead(short cmd);
		bool packMsgBody(const char* msgBody, int msgBody_len);
		short getMsgCmdId(const char* msgBody, int msgBody_len);
		void resetRecvBufStatus();
		int tLoginGame(int userId,const string& account,const string& pwd);

	private:
		ADR adr_send;
		ADR adr_recv;
		//发送队列及接受缓冲区
		char m_aSendBuffer[SENDBUFFSIZE];
		char m_aRecvBuffer[RECVBUFFSIZE];
		//body buffer
		char* m_recvBodyBuffer;
		unsigned int buffer_len ;	//读取到的长度
		unsigned int read_pos ;		//读取游标
		CClient* pCClient;
};

#endif


