/**
*
* @file     StopRobotRes.h
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

#ifndef __STOPROBOTRES_H__
#define __STOPROBOTRES_H__

#include "protocal/cmd/BaseMsgCmdBizRes.h"
#include "protocal/SprProtocal.h"

using namespace std;



class StopRobotRes:public BaseMsgCmdBizRes
{
public:
	StopRobotRes(){}
	virtual ~StopRobotRes(){}
	int parseCmdid()
	{
		return SprProtocal_robot_stopRes;
	}

	string getName()
	{
		return "StopRobotRes";
	}

};
#endif