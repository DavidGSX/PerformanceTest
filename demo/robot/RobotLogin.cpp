#include <iostream>
#include <string>
#include <stdio.h>
#include <stdlib.h>

#include "robot/RobotLogin.h"
#include "core/Stat.h"
#include "core/Sampler.h"
#include "core/CommonFunction.h"
#include "core/Logger.h"

using namespace std;

extern Logger g_logger;

/**
 * 
 * Description ：初始化机器人
 */
RobotLogin::RobotLogin(int index,long tranTotal):AbstractRobot(index, tranTotal) 
{
	// g_logger.info("robot  , index="+StringTools::int2string(this->getRobotIndex()));   
	// SleepMsec(1000);
}




/**
 * 
 * Description ：机器人在这里执行登陆的操作，一般情况下仅仅登陆一次
 */
bool RobotLogin::init()
{
	m_pGameAPI = new GameAPI();

	Sampler sampler("Login",this);
	sampler.sampleStart();

	int iResult = m_pGameAPI->tLoginGame(this->getRobotIndex(),"123","456"); //m_pGameAPI->Login(this->getRobotIndex());	
	if(iResult == ROBOT_MISSION_SUCCESS)
	{
		sampler.sampleEnd(true);
		return true;
	}
	else
	{
		sampler.sampleEnd(false);
		return false;
	}

}

/**
 * 
 * Description ：机器人执行具体事务
 */
inline int RobotLogin::runAction()
{	
	int iResult;

	Sampler sampler("DoLogin",this);
	//开始采样
	sampler.sampleStart();
	iResult = m_pGameAPI->Login(this->getRobotIndex());
	
	//SleepMsec(500);
	//SleepMsec(rand()%100);


	if(iResult == ROBOT_MISSION_SUCCESS)  {  //执行任务成功
		sampler.sampleEnd(ROBOT_MISSION_SUCCESS);//spr的结束统计
	}
	else if(iResult == ROBOT_MISSION_FAIL){  //执行任务失败
		sampler.sampleEnd(ROBOT_MISSION_FAIL);
	}
	else if(iResult == ROBOT_DUMP)  {  //机器人出现问题，准备退出
		sampler.sampleEnd(ROBOT_DUMP);
		return -1;
	}
	else if(iResult == ROBOT_MISSION_EXCEPTION){
		sampler.sampleEnd(ROBOT_MISSION_EXCEPTION);
	}
	else if(iResult == ROBOT_CONNECT_TIMEOUT){
		sampler.sampleEnd(ROBOT_CONNECT_TIMEOUT);
	}
	return 0;
 }
 
 /**
 * 
 * Description ：机器人执行完runAction()循环后做的动作，仅执行一次
 */
bool RobotLogin::close()
{
	return true;
}
 /**
 * 
 * Description ：析构函数，如果添加的代码中有动态申请资源的动作，必须在这里释放掉，否则会出现内存泄露
 */
 RobotLogin::~RobotLogin()
 { 
	delete m_pGameAPI;
	//destory robot, you can get info where debug
	//g_logger.info("robot have destory , index="+StringTools::int2string(this->getRobotIndex()));
 }

 
 
