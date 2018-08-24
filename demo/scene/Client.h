/*
 * Client.h
 *
 *  Created on: 2016-03-25
 *      Author: hazelnutlin
 */

#ifndef _CLIENT_INCLUDE_
#define _CLIENT_INCLUDE_

#include "socket.h"

#include <iostream>
#include <string.h>
#include <time.h> 

using namespace std;

class CClient
{
private:
	CClient(void);
public:
	~CClient(void);

public:
	CSocket	m_Socket;

//	struct cc_timeval	m_ConnectTime;

protected:

private:
	

public:
	bool Start(const char* ip, unsigned short port);
	void Close();

	string DomainToIP(const char* pDomain);

public:
	int Send(char* pBuffer, int nLenght);
	int Read(char* pBuffer, int nLenght);

public:
	static CClient* getCClient();	
};

#endif //_CLIENT_INCLUDE_