/**
*
* @file     WindowsFunction.h
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

#pragma once


#ifdef _WIN32

#include <time.h>
#include <iostream>
#include <WINSOCK2.H>
#pragma  comment(lib,"ws2_32.lib")

#include "core/SPR_ERROR.h"
#include "tools/StringTools.h"
#include  "core/DataTypeDefine.h"


void SleepMsec(long);
void SleepUsec(unsigned int sleepTime);
UInt64 GetTimeSec();
UInt64 GetTimeMsec();
UInt64 GetTimeUsec();
void  GetTimeval(unsigned int &tv_sec,unsigned int &tv_usec);

//���߳�ָ��ִ�к��������
DWORD WINAPI commThreadFunction(LPVOID Para);
//�����Լ������߳̾��
void InitThread(void * &pHandle, void * &pNotUse );
int  CommonCreateThread( void * & pHandle, void * pNothing,void* pFunction, void* param);
void CommonClearThread(void *pHandle, void *pNotUse);

/*�����*/
void Lock(CRITICAL_SECTION &lock);
void UnLock(CRITICAL_SECTION &lock);


/**
* Socket �ӿ��࣬Ϊͳһwin��linux socket��ʹ�ö���
*/
class CommonSocket
{
private:
	WORD m_sockVersion;
	WSADATA m_wsaData;
	SOCKET m_socket;
	sockaddr_in m_serverAddr;

	int m_port;
	string m_IP;
public:
	/**
	*  ��ʼ������������tcp����
	*/
	CommonSocket(string ip, int port);

	/**
	*  ��ʼ������������tpc����
	*/
	CommonSocket(string ip, string port);
	
	/**
	*  tpc����׼������
	*/
	int initSocket();
	int setNoBlock();
	/**
	*  �����������tcp����
	*/
	int connectServer();

	/**
	*  ��������Ͽ�����
	*/
	int disconnectServer();
	/**
	*  ���������������
	*/
	int sendMsg(char* msgBuffer,int msgLen);

	/**
	*  �ӷ������������ݣ����ؽ��յ����ݵĳ���
	*/
	int recieveMsg(char* msgBuffer, int bufferLen);


	/**
	* ��ȡsocket
	*/
	SOCKET getSocket();
		

	/**
	*  �����������Ͽ���������е�����
	*/
	~CommonSocket();
};

#endif




