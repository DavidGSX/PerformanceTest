/**
*
* @file     RobotStopReqService.h
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

#ifndef __ROBOTSTOPREQSERVICE_H__
#define __ROBOTSTOPREQSERVICE_H__

#include "node/logic/AbstractService.h"
#include "protocal/cmd/BaseMsgCmdBiz.h"


class RobotStopReqService : public AbstractService
{
public:
	RobotStopReqService();
	virtual ~RobotStopReqService();
	void doCmd(BaseMsgCmdBiz *msgBiz);	
};

#endif
