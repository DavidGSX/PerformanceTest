/**
*
* @file     LinuxFunction.h
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

#ifndef __LINUXFUNCTION_H__
#define __LINUXFUNCTION_H__

#ifndef _WIN32
#include <sys/time.h>
//#include <unistd.h>
#include <pthread.h>

#include <stdio.h> /* printf, sprintf */
#include <stdlib.h> /* exit */
#include <unistd.h> /* read, write, close */
#include <string.h> /* memcpy, memset */
#include <sys/socket.h> /* socket, connect */
#include <netinet/in.h> /* struct sockaddr_in, struct sockaddr */
#include <netdb.h> /* struct hostent, gethostbyname */

#include <iostream>
#include <string>
#include "tools/StringTools.h"
#include "core/SPR_ERROR.h"
#include  "core/DataTypeDefine.h"

using namespace std;

void SleepMsec(long);
int SleepUsec(long long sleepTime);
UInt64 GetTimeSec();
UInt64 GetTimeMsec();
UInt64 GetTimeUsec();
void  GetTimeval(unsigned int &tv_sec,unsigned int &tv_usec);
/*
void *mShowStat(void *arg);
void *runRobot(void * arg);
void *dataUploadLoop(void * arg);
void *startNetWork(void * arg);
*/
void * commThreadFunction(void * arg);

//ԭ��mooseд�Ľ�������
/*
void InitThread(int threadNum, void * &p1, void * &p2 );
int CommonCreateThread(int num,void *mpThread_t, void * mpThread_attr_t, void* pFunction, void* param);
void CommonClearThread(void *pt, void *pattr );
*/
//��������߳̾��
void InitThread(void * & pThread, void * &pThreadAtt);
//int CommonCreateThread(void *mpThread_t, void * mpThread_attr_t, void* pFunction, void* param);
int CommonCreateThread(void * &mpThread_t, void * &mpThread_attr_t, void* pFunction, void* param);
void CommonClearThread(void *pt, void *pattr );
//-----------------�����-------------------
void Lock(pthread_mutex_t &lock);
void UnLock(pthread_mutex_t &lock);
/**
* Socket �ӿ��࣬Ϊͳһwin��linux socket��ʹ�ö���
*/
class CommonSocket
{
private:
	struct sockaddr_in m_serverAddr;
	struct hostent *server;
	int m_sockfd;
	int m_port;
	string m_IP;

public:
	/**
	*  ��ʼ������������tpc����
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
	*  �����������tpc����
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
	int getSocket();

	/**
	*  �����������Ͽ���������е�����
	*/
	~CommonSocket();
	
};



#endif

#endif








