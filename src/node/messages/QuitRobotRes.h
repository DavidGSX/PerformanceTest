/**
*
* @file     QuitRobotRes.h
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

#ifndef __QUITROBOTRES_H__
#define __QUITROBOTRES_H__

#include "protocal/cmd/BaseMsgCmdBizRes.h"
#include "protocal/SprProtocal.h"
using namespace std;


class QuitRobotRes : public BaseMsgCmdBizRes
{
public:
	int parseCmdid()
	{
		return SprProtocal_robot_quitRes;
	}

	string getName()
	{
		return "QuitRobotRes";
	}

	QuitRobotRes()
	{
	}

	virtual ~QuitRobotRes()
	{
	}
};

#endif