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
* Copyright (c)  2016-2017, ��Ѷ�Ƽ����޹�˾���������з���
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
	int  m_robotNum;//������������
	int  m_robotPerSec;//ÿ�뿪�������˵�������������1000��
	vector<AbstractRobot*> *m_pRobotVec;
	Stat * m_pStat;//ͳ���߳�
public:
	void setStat(Stat * stat);
	void runAllRobots();//�������л�����
	void stopRobot();


	RobotsService(vector<AbstractRobot*> *robotVec, int robotNum, int robotPerSec,int testRunModel);
	RobotsService();

	~RobotsService();
	

};

