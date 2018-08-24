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
* Copyright (c)  2016-2017, 腾讯科技有限公司互动娱乐研发部
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

//给线程指定执行函数的入口
DWORD WINAPI commThreadFunction(LPVOID Para);
//外面自己管理线程句柄
void InitThread(void * &pHandle, void * &pNotUse );
int  CommonCreateThread( void * & pHandle, void * pNothing,void* pFunction, void* param);
void CommonClearThread(void *pHandle, void *pNotUse);

/*锁相关*/
void Lock(CRITICAL_SECTION &lock);
void UnLock(CRITICAL_SECTION &lock);


/**
* Socket 接口类，为统一win和linux socket的使用而设
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
	*  初始化到服务器的tcp连接
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
	*  与服务器建立tcp连接
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
	SOCKET getSocket();
		

	/**
	*  析构函数，断开与服务器中的连接
	*/
	~CommonSocket();
};

#endif




