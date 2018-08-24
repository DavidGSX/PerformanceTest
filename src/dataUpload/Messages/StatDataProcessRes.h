/**
*
* @file     StatDataProcessRes.h
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
#include "jsonCPP/dist/json/json.h"

/**
*  服务器对上传的统计信息的响应类
*/
class StatDataProcessRes :
	public BaseMsgRes
{
public:
	static string m_infoError;
	static string m_infoOk;
	StatDataProcessRes(void);
	~StatDataProcessRes(void);
	void decode(string &jsonStr);
	string encode();
};

