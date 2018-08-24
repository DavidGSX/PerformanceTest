/**
*
* @file     EndTestReq.h
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
/**
*   结束测试的消息请求类
*/
class EndTestReq :
	public BaseMsgReq
{
public:
	EndTestReq(void);
	~EndTestReq(void);
	void decode(string &jsonStr);
	string encode();
};

