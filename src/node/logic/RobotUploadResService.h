/**
*
* @file     RobotUploadResService.h
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

#ifndef __ROBOTUPLOADRESSERVICE_H__
#define __ROBOTUPLOADRESSERVICE_H__

#include "node/logic/AbstractService.h"
#include "protocal/cmd/BaseMsgCmdBiz.h"

class RobotUploadResService:public AbstractService
{
public:
	RobotUploadResService();
	virtual ~RobotUploadResService();
	void doCmd(BaseMsgCmdBiz* msgBiz); 
};

#endif // !__ROBOTUPLOADRESSERVICE_H__



