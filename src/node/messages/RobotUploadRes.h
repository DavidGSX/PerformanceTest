/**
*
* @file     RobotUploadRes.h
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

#ifndef __ROBOTUPLOADRES_H__
#define __ROBOTUPLOADRES_H__

#include "protocal/cmd/BaseMsgCmdBizRes.h"
#include "protocal/SprProtocal.h"



class RobotUploadRes:public BaseMsgCmdBizRes
{
public:
	RobotUploadRes();
	virtual ~RobotUploadRes();

	int parseCmdid();
	string getName();

};

#endif // !__ROBOTUPLOADRES_H__