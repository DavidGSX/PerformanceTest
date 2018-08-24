/**
*
* @file     RobotConnectReq.h
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

#ifndef __ROBOTCONNECTREQ_H__
#define __ROBOTCONNECTREQ_H__


#include "protocal/SprProtocal.h"
#include "protocal/cmd/BaseMsgCmdBizReq.h"

using namespace std;


class RobotConnectReq:public BaseMsgCmdBizReq
{
private :
   double  m_curTime;//当前机器的时间，用于跟master对时
public:
	RobotConnectReq(void);
	virtual ~RobotConnectReq(void);
	virtual string encode();
	double getCurTime();
	void setCurTime(double curTime);
	int parseCmdid();
	string getName();
	

};

#endif // !__ROBOTCONNECTREQ_H__
