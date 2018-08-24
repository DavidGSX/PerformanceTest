/**
*
* @file     MsgCmd.h
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

#ifndef __MSGCMD_H__
#define __MSGCMD_H__

#include <string>
#include <iostream>
#include "protocal/cmd/BaseMsgCmdBiz.h"
#include  "core/CommonFunction.h"

//#include "core/WindowsFunction.h"
//#include <WINSOCK2.H>

using namespace std;

#define   MSGCMD_HEAD_LEN        8
#define   MSGCMD_MAX_BODY_LEN    50000

class MsgCmd
{
public:
	int lengthBody;
	int cmdid;
	BaseMsgCmdBiz* msgbiz;
public:
	//把业务包打包都缓冲区
	//char* packMsgCmd(int &len);
	int packMsgCmd(int &bufLen,char *buff,string & packInfo);
	//把缓冲区解包到业务包
	void unpackMsgCmd(char *body,int bodylen);

	static  char * getByteArray(int i);
	static int getInt( char buf[]);

	MsgCmd();
	~MsgCmd();

};

#endif