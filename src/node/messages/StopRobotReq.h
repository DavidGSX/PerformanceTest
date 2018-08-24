/**
*
* @file     StopRobotReq.h
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

#ifndef __STOPROBOTREQ_H__
#define __STOPROBOTREQ_H__

#include "protocal/cmd/BaseMsgCmdBizReq.h"
#include "protocal/SprProtocal.h"

using namespace std;



class StopRobotReq:public BaseMsgCmdBizReq
{
public:
	StopRobotReq(){};
	virtual ~StopRobotReq(){};

	int parseCmdid()
	{
		return SprProtocal_robot_stopReq;
	}

	string getName()
	{
		return "StopRobotReq";
	}

};

#endif // !__STOPROBOTREQ_H__
