/**
*
* @file     RobotConnectRes.h
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

#ifndef  __ROBOTCONNECTRES_H__
#define  __ROBOTCONNECTRES_H__

#include "protocal/cmd/BaseMsgCmdBizRes.h"
#include "protocal/SprProtocal.h"
using namespace std;



class RobotConnectRes:public BaseMsgCmdBizRes
{
private:
	int stat_interval;
public:
	RobotConnectRes();
	virtual ~RobotConnectRes();

	int getStat_interval();
	void setStat_interval(int stat_interval) ;
	int parseCmdid();
	string getName();
	virtual void decode(string &jsonStr);

};

#endif // ! __ROBOTCONNECTRES_H__
