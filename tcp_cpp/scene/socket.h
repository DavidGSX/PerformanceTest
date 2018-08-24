/******************************************************************************
文件名: Socket.h
功能描述: 套接字功能封装类的定义。
******************************************************************************/
#ifndef _SOCKET_INCLUDE_
#define _SOCKET_INCLUDE_
#if defined(ANDROID)
#include <arpa/inet.h>
 #include <stdio.h>
 #include <stdlib.h>
 #include <errno.h>
 #include <unistd.h>
 #include <string.h>
 #include <sys/socket.h>
 #include <netinet/in.h>
#include <netinet/tcp.h>   //for TCP_NODELAY
 #include <netdb.h>
 #include <iostream>
 #include <sstream>
#include <fcntl.h>
#include <sys/types.h>
#elif defined(WIN32)
#include <WinSock2.h>
#include <windows.h>
#pragma comment(lib, "WS2_32")
#endif

#define SOCKET_ERROR -1

class CSocket
{
public:
	CSocket();
	virtual ~CSocket();

private:
	int m_Socket;

public:
	bool Create();
	bool Connect(const char* pIp, unsigned short uPort);
	bool Connect(unsigned int uIp, unsigned short uPort);
	bool Bind(const char* pIp, unsigned short uPort);
	bool Bind(unsigned int uIp, unsigned short uPort);
	bool Listen();
	int Read(const char* pBuffer, int nLen);
	int Write(const char* pBuffer, int nLen);
	void Disconnect();
	void Close();

public:
	bool IsReadable();
	bool IsWritable();
	bool IsConnected();
	bool IsAcceptable();
};

#endif // _SOCKET_INCLUDE_