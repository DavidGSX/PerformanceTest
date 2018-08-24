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
* Copyright (c)  2016-2017, ��Ѷ�Ƽ����޹�˾���������з���
* All rights reserved.
*
*/

#pragma once
#include <iostream>
#include <string>
#include "jsonCPP/dist/json/json.h"

using namespace std;

/**
*  ��Ϣ����
*/
class BaseMsg
{
protected :
	Json::Value m_jsonRootValue; //����Ϊjson ��ĸ��ڵ㣬����Ҫ����Ķ���Ҫ���뵽�ø��ڵ�����
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


