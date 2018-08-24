/**
*
* @file     RobotService.h
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

#pragma once
#include <iostream>
#include <vector>
#include "core/Stat.h"
#include "core/Logger.h"
#include "core/AbstractRobotMgr.h"
#include "core/CommonFunction.h"
#include "core/SPR_ERROR.h"

using namespace std;
extern Logger g_logger;

class RobotsService
{
private:
	int  m_robotNum;//机器人总数量
	int  m_robotPerSec;//每秒开启机器人的数量（不超过1000）
	vector<AbstractRobot*> *m_pRobotVec;
	Stat * m_pStat;//统计线程
public:
	void setStat(Stat * stat);
	void runAllRobots();//启动所有机器人
	void stopRobot();


	RobotsService(vector<AbstractRobot*> *robotVec, int robotNum, int robotPerSec,int testRunModel);
	RobotsService();

	~RobotsService();
	

};

