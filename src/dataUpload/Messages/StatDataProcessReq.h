/**
*
* @file     StatDataProcessReq.h
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
#include "dataUpload/Messages/BaseMsgReq.h"
#include <vector>
#include <sstream>
using namespace std;

/**
*  向服务器发送统计信息的消息类
*/
class StatDataProcessReq :
	public BaseMsgReq
{
private:
	vector<string> m_statlogVec;
public:
	StatDataProcessReq(void);
	~StatDataProcessReq(void);
	virtual string encode();
	virtual void decode(string &jsonStr);
	void setStatLog(vector<string> *statLogVec);
	vector<string> getStatLog();
};

