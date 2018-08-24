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
* Copyright (c)  2016-2017, 腾讯科技有限公司互动娱乐研发部
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

//原来moose写的将来废弃
/*
void InitThread(int threadNum, void * &p1, void * &p2 );
int CommonCreateThread(int num,void *mpThread_t, void * mpThread_attr_t, void* pFunction, void* param);
void CommonClearThread(void *pt, void *pattr );
*/
//外面管理线程句柄
void InitThread(void * & pThread, void * &pThreadAtt);
//int CommonCreateThread(void *mpThread_t, void * mpThread_attr_t, void* pFunction, void* param);
int CommonCreateThread(void * &mpThread_t, void * &mpThread_attr_t, void* pFunction, void* param);
void CommonClearThread(void *pt, void *pattr );
//-----------------锁相关-------------------
void Lock(pthread_mutex_t &lock);
void UnLock(pthread_mutex_t &lock);
/**
* Socket 接口类，为统一win和linux socket的使用而设
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
	*  初始化到服务器的tpc连接
	*/
	CommonSocket(string ip, int port);

	/**
	*  初始化到服务器的tpc连接
	*/
	CommonSocket(string ip, string port);

	/**
	*  tpc连接准备工作
	*/	
	int initSocket();
	int setNoBlock();
	/**
	*  与服务器建立tpc连接
	*/
	int connectServer();
	
	/**
	*  与服务器断开连接
	*/
	int disconnectServer();
	/**
	*  向服务器发送数据
	*/
	int sendMsg(char* msgBuffer,int msgLen);

	/**
	*  从服务器接收数据，返回接收到数据的长度
	*/
	int recieveMsg(char* msgBuffer, int bufferLen);
	
	/**
	* 获取socket
	*/
	int getSocket();

	/**
	*  析构函数，断开与服务器中的连接
	*/
	~CommonSocket();
	
};



#endif

#endif








