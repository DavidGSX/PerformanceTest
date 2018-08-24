/**
*
* @file     RobotUploadReq.h
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

#ifndef __ROBOTUPLOADREQ_H__
#define __ROBOTUPLOADREQ_H__

#include "protocal/cmd/BaseMsgCmdBizReq.h"
#include "protocal/SprProtocal.h"
#include "node/StatDataAlltrans.h"
#include "node/StatDataTrans.h"
#include <list>
using namespace std;



class RobotUploadReq : public BaseMsgCmdBizReq{
private:
	StatDataAlltrans  allTrans;
	list<StatDataTrans*> statDataTransList;//事务统计列表	
public:
	RobotUploadReq();
	virtual ~RobotUploadReq();
	StatDataAlltrans * getAllTrans() ;
	void setAllTrans(StatDataAlltrans  allTrans) ;
	list<StatDataTrans*>  * getStatDataTransLst();
	void setStatDataTransLst(list<StatDataTrans*> * p_statDataTransLst) ;
	virtual string encode();
	int parseCmdid();
	string getName();
	

};

#endif