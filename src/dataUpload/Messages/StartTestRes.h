/**
*
* @file     StartTestRes.h
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

/**
*  ������������ʼ���Ե���Ϣ����Ӧ��
*/
class StartTestRes :
	public BaseMsgRes
{
public:
	StartTestRes(void);
	~StartTestRes(void);
	void decode(string &jsonStr);
	string encode();
};

