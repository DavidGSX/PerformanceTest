/**
*
* @file     RobotHeartbeatReq.h
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

#ifndef __ROBOTHEARTBEATREQ_H__
#define __ROBOTHEARTBEATREQ_H__

#include "protocal/cmd/BaseMsgCmdBizReq.h"
#include "protocal/SprProtocal.h"
using namespace std;



class RobotHeartbeatReq : public BaseMsgCmdBizReq
{
public:
	int parseCmdid()
	{
		return SprProtocal_master_robotHeartBeatReq;
	}

	string getName()
	{
		return "RobotHeartbeatReq";
	}

	RobotHeartbeatReq()
	{
	}

	virtual ~RobotHeartbeatReq()
	{
	}
};

#endif