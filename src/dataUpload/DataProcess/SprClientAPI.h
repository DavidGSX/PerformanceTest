/**
*
* @file     SprClientAPI.h
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
#include <string>
#include <iostream>
#include "tools/StringTools.h"
#include "dataUpload/Messages/StatDataProcessReq.h"
#include "dataUpload/Messages/StatDataProcessRes.h"
#include "dataUpload/Messages/StartTestReq.h"
#include "dataUpload/Messages/StartTestRes.h"
#include "dataUpload/Messages/EndTestReq.h"
#include "dataUpload/Messages/EndTestRes.h"

#include "dataUpload/DataProcess/HttpMessage.h"
#include "protocal/SprProtocal.h"

using namespace std;

/**
*  ����ͳ�Ƶ��������ĸ����࣬��Ҫ�����ǣ�����һ��HTTP��Ϣ������󣬷���һ����Ӧ����Ϣ��Ӧ����
*/
class SprClientAPI
{
private:
    HttpMessage *pHttpMessage;
	string m_dataProcessURL;
	string m_serverIP;
	string m_serverPort;
	string m_projectCode;
	string m_uid;
	//static SprClientAPI *m_pSprClientAPI;
	
public:
	//static SprClientAPI * getInstance();
	SprClientAPI();
	void setBaseMsg(BaseMsgReq* pBaseMsgReq);
	StatDataProcessRes statDataProcess(StatDataProcessReq *req);
	StartTestRes startTest(StartTestReq *req);
	EndTestRes endTest(EndTestReq *req);
	~SprClientAPI(void);
};

