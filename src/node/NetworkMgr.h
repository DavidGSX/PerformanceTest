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
* Copyright (c)  2016-2017, ��Ѷ�Ƽ����޹�˾���������з���
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

	int  m_max_tcpbuf;//���������
	char * m_tcpSendBuf;//���ͻ�����
	char * m_tcpRecvBuf;//���ջ�����	
	CommonSocket * m_pCommonSocket;
private :
	NetworkMgr(string ip,int port,MessageMgr *msgMgr, NodeMgr *nodeMgr);
	static NetworkMgr* p_network;
public:
	static NetworkMgr* getInstance(MessageMgr *msgMgr, NodeMgr *nodeMgr);
	static NetworkMgr* getInstance();
	void init(){}
	int getint(char* msgBuffer);
	//��buf�е�����д�뵽�����m_tcpSendBuf
	bool sendMsg(char* m_tcpSendBuf,int &len);
	//��������m_tcpRecvBuf ������д�뵽body[]��, RecvSizeΪ����������Ч�����ܳ���
	bool receive();
	void recvMust(char * buff,int len,string  packageInfo);
	void doWork(); 
    virtual  void runThread();//�߳����������еĺ���
	void stopNetwork();
	void closeSocket(CommonSocket * socket);
	void startNetWork();
	~NetworkMgr();


	//---------------���������࣬���Գ��������ʱ���Զ������õ���----------- 
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
	static CGarbo garbo; // ����һ����̬��Ա���ڳ������ʱ��ϵͳ�����������������




};

#endif