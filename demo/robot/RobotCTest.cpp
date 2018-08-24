#include <iostream>
#include <string>
#include <stdio.h>
#include <stdlib.h>

#include "robot/RobotCTest.h"
#include "core/Stat.h"
#include "core/Sampler.h"
#include "core/CommonFunction.h"
#include "core/Logger.h"

using namespace std;

extern Logger g_logger;

/**
 * 
 * Description ：init robot
 */
RobotCTest::RobotCTest(int index,long tranTotal):AbstractRobot(index, tranTotal) 
{

}

/**
 * 
 * Description ：connect to server first
 */
bool RobotCTest::init()
{
	m_pGameAPI = new GameAPI();

	Sampler sampler("ConnectSvr",this);
	sampler.sampleStart();

	if(m_pGameAPI->connectToServer()){
		sampler.sampleEnd(true);
		return true;
	}else{
		sampler.sampleEnd(false);
		return false;
	}
}

/**
 * 
 * Description ：repeat doing something 
 */
inline int RobotCTest::runAction()
{	
	//int iResult;

	Sampler sampler("CTest",this);
	//开始采样
	sampler.sampleStart();
	
	//iResult = ROBOT_MISSION_SUCCESS;
	int iResult = m_pGameAPI->tLoginGame(this->getRobotIndex(),"123","456");	

	//ROBOT_MISSION_SUCCESS 0;	ROBOT_MISSION_FAIL 1;	ROBOT_DUMP -1
	if(iResult == ROBOT_MISSION_SUCCESS) //执行任务成功
	{
		sampler.sampleEnd(true);
		return 0;
	}
	else if(iResult == ROBOT_MISSION_FAIL)//执行任务失败
	{
		sampler.sampleEnd(false);
		return 0;
	}
	else if(iResult == ROBOT_DUMP)//机器人出现问题，准备退出
	{
		sampler.sampleEnd(false);
		return -1;
	}
	
	return 0;
 }
 

 /**
 * 
 * Description ：析构函数，如果添加的代码中有动态申请资源的动作，必须在这里释放掉，否则会出现内存泄露
 */
 RobotCTest::~RobotCTest()
 { 
	delete m_pGameAPI;
 }

 
 
