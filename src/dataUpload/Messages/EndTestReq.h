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
* Copyright (c)  2016-2017, ��Ѷ�Ƽ����޹�˾���������з���
* All rights reserved.
*
*/

#pragma once
#include "dataUpload/Messages/BaseMsgReq.h"
/**
*   �������Ե���Ϣ������
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

