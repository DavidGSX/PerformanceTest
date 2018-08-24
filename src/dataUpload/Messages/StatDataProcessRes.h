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
* Copyright (c)  2016-2017, ��Ѷ�Ƽ����޹�˾���������з���
* All rights reserved.
*
*/

#pragma once
#include "dataUpload/Messages/BaseMsgRes.h"
#include "jsonCPP/dist/json/json.h"

/**
*  ���������ϴ���ͳ����Ϣ����Ӧ��
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

