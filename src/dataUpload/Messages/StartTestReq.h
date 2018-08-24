/**
*
* @file     StartTestReq.h
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
#include <string>
using namespace std;
/**
*  请求开始测试的消息类
*/
class StartTestReq :
	public BaseMsgReq
{
public:
	StartTestReq(void);
	~StartTestReq(void);
	void decode(string &jsonStr);
	string encode();
};

