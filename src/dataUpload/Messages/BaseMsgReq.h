/**
*
* @file     BaseMsgReq.h
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
#include "protocal/base/BaseMsg.h"
/**
*  ������Ϣ�Ļ���
*/
class BaseMsgReq :
	public BaseMsg
{
private:
	string m_projectCode;
	string m_uid;
public:
	BaseMsgReq(void);
	~BaseMsgReq(void);
	void setProjectCode(string &projectCode);
	string getProjectCode();
	void setUid(string &uid);
	string getUid();
};

