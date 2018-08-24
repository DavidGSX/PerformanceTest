/**
*
* @file     EndTestRes.h
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
#include "dataUpload/Messages/BaseMsgRes.h"
/**
*  服务器对结束测试请求的响应类
*/
class EndTestRes :
	public BaseMsgRes
{
public:
	EndTestRes(void);
	~EndTestRes(void);
	void decode(string &jsonStr);
	string encode();
};

