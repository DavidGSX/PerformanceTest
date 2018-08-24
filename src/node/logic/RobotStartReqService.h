/**
*
* @file     RobotStartReqService.h
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

#ifndef __ROBOTSTARTREQSERVICE_H__
#define __ROBOTSTARTREQSERVICE_H__

#include "core/Logger.h"
#include "node/logic/AbstractService.h"
#include "protocal/cmd/BaseMsgCmdBiz.h"


class RobotStartReqService:public AbstractService
{
public:
	RobotStartReqService();
	virtual ~RobotStartReqService();
	void doCmd(BaseMsgCmdBiz* msgBiz);
	
};

#endif