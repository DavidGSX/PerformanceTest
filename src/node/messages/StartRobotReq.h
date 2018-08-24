/**
*
* @file     StartRobotReq.h
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


#ifndef __STARTROBOTREQ_H__
#define __STARTROBOTREQ_H__

#include "protocal/cmd/BaseMsgCmdBizReq.h"
#include "protocal/SprProtocal.h"

using namespace std;



class StartRobotReq:public BaseMsgCmdBizReq
{
private:
	int robotnum ;
	int startIndex ; 
	int robotPerSec; 
	long tranTotal; 
	string robotScene;

public:
	StartRobotReq();
	virtual ~StartRobotReq();

	int getRobotnum();
	void setRobotnum(int robotnum) ;
	int getStartIndex() ;	
	void setStartIndex(int startIndex) ;
	int getRobotPerSec() ;
	void setRobotPerSec(int robotPerSec) ;
	long getTranTotal() ;
	void setTranTotal(long tranTotal) ;
	string getRobotScene();	
	void setRobotScene(string robotScene); 
	int parseCmdid();
	string getName();
	virtual void decode(string &jsonStr);
	

};

#endif // !__STARTROBOTREQ_H__
