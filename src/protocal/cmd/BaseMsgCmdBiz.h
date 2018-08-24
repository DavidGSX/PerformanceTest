/**
*
* @file     BaseMsgCmdBiz.h
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

#ifndef __BASEMSGCMDBIZ_H__
#define __BASEMSGCMDBIZ_H__

#include "protocal/base/BaseMsg.h"

using namespace std;

class BaseMsgCmdBiz:public BaseMsg{
private:
	string nodeId;
	string projectCode;

public:
	BaseMsgCmdBiz(void){}
	virtual ~BaseMsgCmdBiz(void){}

	string getProjectCode()
	{
		return projectCode;
	}

	void setProjectCode(string projectCode)
	{
		this->projectCode = projectCode;
	}

	string getNodeId()
	{
		return nodeId;
	}

	void setNodeId(string nodeId)
	{
		this->nodeId = nodeId;
	}
	//virtual void   encodeJson() = 0;
	
	
	virtual int parseCmdid() = 0;
	virtual string getName() = 0;
};

#endif