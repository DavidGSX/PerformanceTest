/**
*
* @file     HttpMessage.h
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

#ifndef __HTTPMESSAGE_H__
#define __HTTPMESSAGE_H__

#include "core/CommonFunction.h"

#define MAX_HTTPMSG_LEN 10000

using namespace std;

/**
*   Http��Ϣ�࣬������Ϣ���齨�����͡����պͽ�������
*/
class HttpMessage
{
private:
	char m_httpMsgBuf[MAX_HTTPMSG_LEN];
	char m_httpRecvHeadBuf[MAX_HTTPMSG_LEN];
	char m_httpRecvBodyBuf[MAX_HTTPMSG_LEN];
	int m_crtHeadDataLen;
	int m_crtBodyDataLen;
	int m_sendMsgLen;
	void constructPostHead(string &url, int bodyLen,string httpVersion="HTTP/1.1");
	void constructHttpBodyMsg(string bodyInfo);
	void constructHttpMsg(string &url, string &body, string method="POST");
	int isHeadRecieved(int infoLen);
	int getBodyLen();

public:
	HttpMessage();
	~HttpMessage(void);
	string doPost(string &ip, string &port, string &url, string &body);
};

#endif

