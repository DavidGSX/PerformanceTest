/**
*
* @file     BaseMsg.h
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
#include <iostream>
#include <string>
#include "jsonCPP/dist/json/json.h"

using namespace std;

/**
*  消息基类
*/
class BaseMsg
{
protected :
	Json::Value m_jsonRootValue; //编码为json 后的根节点，其他要编码的都需要加入到该根节点里面
public:
	BaseMsg(void);
	virtual ~BaseMsg(void);
	virtual void decode(string &jsonStr) = 0;
	//virtual void encodeJson() = 0;
	virtual string encode()
	{
		Json::FastWriter fw;
		return fw.write(m_jsonRootValue);
	}
	
};


