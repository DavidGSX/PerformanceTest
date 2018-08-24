#include <iostream>
#include <string>
#include <stdio.h>
#include <stdlib.h>

#include "robot/RobotBattle.h"
#include "core/Stat.h"
#include "core/Sampler.h"
#include "core/CommonFunction.h"
#include "core/Logger.h"

using namespace std;
extern Logger g_logger;

/**
	* 机器人构造方法
	* 在初始化的时候调用一次
	* 一般用于传递机器人参数或者初始化逻辑
	* @param index  机器人编号
	* @param tranTotal   事务执行的次数
*/
RobotBattle::RobotBattle(int index,long tranTotal):AbstractRobot(index, tranTotal) 
{
	
}

/**
	* 初始化函数
	* 只调用一次，如果返回false，后面runAction动作不会执行
	* 一般用于实现机器人初始化逻辑
	* 
*/
bool RobotBattle::init()
{
	m_pGameAPI = new GameAPI();

	Sampler sampler("Battle",this);
	sampler.sampleStart();

	int iResult = m_pGameAPI->Login(this->getRobotIndex());	

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
	 * 机器人执行的动作
	 * 1、主要功能
	 *   执行机器人行为，参考GameSceneDemo.battleScene()实现
	 *   给每个动作加上事务机制，这样平台就能统计tps/响应时间等性能参数	   
	 * 2、每个事务需自定义
	 *    设置开启/结束事务代码
	 *    Sampler sampler("事务名",...);
	 *    sampler.sampleStart();
	 *          //todo 执行具体事务的代码	   
	 *    sampler.sampleEnd(true);//表示事务成功，如果失败设置false
	 * 3、runAction方法根据配置执行tranTotal次 
	 * 4、返回值，如果为非0会马上退出机器人
*/
inline int RobotBattle::runAction()
{	
	int iResult;
	Sampler sampler("Start_Game",this);
	sampler.sampleStart();
	iResult = m_pGameAPI->StartGame();

	SleepMsec(500);

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
	 
	Sampler sampler1("End_Game",this);
	sampler1.sampleStart();
	
	iResult = m_pGameAPI->EndGame();

	SleepMsec(500);

	if(iResult == ROBOT_MISSION_SUCCESS){  //执行任务成功
		sampler1.sampleEnd(ROBOT_MISSION_SUCCESS);//spr的结束统计
	}
	else if(iResult == ROBOT_MISSION_FAIL){  //执行任务失败
		sampler1.sampleEnd(ROBOT_MISSION_FAIL);
	}
	else if(iResult == ROBOT_DUMP){  //机器人出现问题，准备退出
		sampler1.sampleEnd(ROBOT_DUMP);
		return -1;
	}
	else if(iResult == ROBOT_MISSION_EXCEPTION){
		sampler1.sampleEnd(ROBOT_MISSION_EXCEPTION);
	}
	else if(iResult == ROBOT_CONNECT_TIMEOUT){
		sampler1.sampleEnd(ROBOT_CONNECT_TIMEOUT);
	}

	return 0;
 }
 
 /**
 * 
 * Description ：析构函数，如果添加的代码中有动态申请资源的动作，必须在这里释放掉，否则会出现内存泄露
 */
 RobotBattle::~RobotBattle()
 { 
	delete m_pGameAPI;
 }


 
 
