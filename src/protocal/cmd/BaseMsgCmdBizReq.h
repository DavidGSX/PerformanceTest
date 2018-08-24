/**
*
* @file     BaseMsgCmdBizReq.h
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

#ifndef __BASEMSGCMDBIZREQ_H__
#define __BASEMSGCMDBIZREQ_H__

#include "protocal/cmd/BaseMsgCmdBiz.h"
#include "protocal/SprProtocal.h"
using namespace std;



class BaseMsgCmdBizReq : public BaseMsgCmdBiz
{
public:
	BaseMsgCmdBizReq(void){}
	virtual ~BaseMsgCmdBizReq(void){}
	
	virtual int parseCmdid()
	{
		return 0;
	}

	virtual void decode(string &jsonStr)
	{
		Json::Value value;
		Json::Reader reader;
		reader.parse(jsonStr,value);
		string tempStr = value["projectCode"].asString();
		this->setProjectCode(tempStr);
		tempStr = value["nodeId"].asString();
		this->setNodeId(tempStr);
	}

	virtual string encode()
	{
		
		m_jsonRootValue["projectCode"] = this->getProjectCode();
		m_jsonRootValue["nodeId"] = this->getNodeId();
		return BaseMsg::encode();
	}
};

#endif // !__BASEMSGCMDBIZREQ_H__
