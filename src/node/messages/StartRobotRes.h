/**
*
* @file     StartRobotRes.h
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

#ifndef __STARTROBOTRES_H__
#define __STARTROBOTRES_H__

#include "protocal/cmd/BaseMsgCmdBizRes.h"
#include "protocal/SprProtocal.h"

using namespace std;



class StartRobotRes:public BaseMsgCmdBizRes
{
public:
	StartRobotRes();
	virtual ~StartRobotRes();
	int parseCmdid();
	string getName();
};

#endif // !__STARTROBOTRES_H__


