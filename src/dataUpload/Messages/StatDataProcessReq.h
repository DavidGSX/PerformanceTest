/**
*
* @file     StatDataProcessReq.h
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
#include <vector>
#include <sstream>
using namespace std;

/**
*  �����������ͳ����Ϣ����Ϣ��
*/
class StatDataProcessReq :
	public BaseMsgReq
{
private:
	vector<string> m_statlogVec;
public:
	StatDataProcessReq(void);
	~StatDataProcessReq(void);
	virtual string encode();
	virtual void decode(string &jsonStr);
	void setStatLog(vector<string> *statLogVec);
	vector<string> getStatLog();
};

