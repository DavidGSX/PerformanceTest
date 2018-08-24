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
* Copyright (c)  2016-2017, ��Ѷ�Ƽ����޹�˾���������з���
* All rights reserved.
*
*/

#pragma once
#include "dataUpload/Messages/BaseMsgReq.h"
#include <string>
using namespace std;
/**
*  ����ʼ���Ե���Ϣ��
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

