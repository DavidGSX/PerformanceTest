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
* Copyright (c)  2016-2017, 腾讯科技有限公司互动娱乐研发部
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
*  发送统计到服务器的辅助类，主要功能是：输入一个HTTP消息请求对象，返回一个对应的消息响应对象
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

