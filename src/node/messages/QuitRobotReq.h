/**
*
* @file     QuitRobotReq.h
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

#ifndef __QUITROBOTREQ_H__
#define __QUITROBOTREQ_H__

#include "protocal/cmd/BaseMsgCmdBizReq.h"
#include "protocal/SprProtocal.h"
using namespace std;



class QuitRobotReq : public BaseMsgCmdBizReq
{
public:
	int parseCmdid()
	{
		return SprProtocal_robot_quitReq;
	}

	string getName()
	{
		return "QuitRobotReq";
	}

	QuitRobotReq()
	{
	}

	virtual ~QuitRobotReq()
	{
	}
};

#endif