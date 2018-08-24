/**
*
* @file     BaseMsgRes.h
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
#include "protocal/base/BaseMsg.h"

/**
*  收到的回复的消息基类
*/
class BaseMsgRes :
	public BaseMsg
{
private:
	string m_info;
	string m_detail;
public:
	BaseMsgRes(void);
	~BaseMsgRes(void);
	string getInfo();
	void setInfo(string &info);
	string getDetail();
	void setDetail(string &detail);
};

