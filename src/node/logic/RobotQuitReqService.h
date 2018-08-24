/**
*
* @file     RobotQuitReqService.h
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

#ifndef __ROBOTQUITREQSERVICE_H__
#define __ROBOTQUITREQSERVICE_H__

#include "node/logic/AbstractService.h"
#include "protocal/cmd//BaseMsgCmdBiz.h"


class RobotQuitReqService:public AbstractService
{
public:
	void doCmd(BaseMsgCmdBiz* msgBiz) ;
};
#endif // !__ROBOTQUITREQSERVICE_H__
