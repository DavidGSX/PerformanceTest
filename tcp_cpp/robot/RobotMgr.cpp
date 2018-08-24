#include "robot/RobotMgr.h"
#include "robot/RobotLogin.h"
#include "robot/RobotCTest.h"

#include "core/Logger.h"
#include "core/TpsControler.h"
#include "core/CommonFunction.h"

extern Logger g_logger;

RobotMgr::RobotMgr()
{
}

/**
 * 
 * 机器人生成器，生成所有机器人
 * 1、robotScene参数用于决定产生哪类机器人
      参数是由main函数从命令行获取的
	  具体参数值对应调用哪个初始化机器人函数，用户自己定义
 */
void  RobotMgr::initAllRobot(string robotScene)
{
	int robot_Num = this->getRobotNum();//获取机器人数量
	long tran_Total = this->getTranTotal();//获取机器人执行任务的次数
	
	//根据传入的robotScene参数来开启哪种类型的机器人
	if(robotScene=="defaultScene")//load connect test scene
	{
		initCTestSceneRobots(robot_Num,0,tran_Total);
	}
	else if (robotScene=="multiScene")//执行多场景  //初始化多场景机器人
	{  
        initMultiSceneRobots(robot_Num, 0,tran_Total);
	}
	else
	{
		//传入的robotScene的值不在上述的定义之列
		stringstream ss4Input;
		ss4Input<<"param \"robotScene\"= "<<robotScene<<" is NOT defined, see details in RobotMgr::initAllRobot()";
		g_logger.error(&ss4Input);
	}
}

/*
*  对各类事务设置tps
*/
void RobotMgr::setTpsInfo()
{
	//参数1：事务名，与Robot的runAction()中传入的事务名一致
	//参数2：tps值，必须大于0
	//setTps("Start_Game",3.5);
	//setTps("DoLogin",300);
}

/**
 * 
 * Description ：单场景，初始化LoginScene所需要的机器人
 */
void RobotMgr::initLoginSceneRobots(int totalNum, int indexStart, int tranTotal)
{
	int i = 0;
	for(i=0;i<totalNum;i++)
	{
		RobotLogin *robot= new RobotLogin(indexStart+i,tranTotal);
		addRobot(robot);
	}
}



/**
 * 
 * Description ：单场景，初始化LoginScene所需要的机器人
 */
void RobotMgr::initCTestSceneRobots(int totalNum, int indexStart, int tranTotal)
{
	int i = 0;
	for(i=0;i<totalNum;i++)
	{
		RobotCTest *robot= new RobotCTest(indexStart+i,tranTotal);
		addRobot(robot);
	}
}


/**
 * 
 * Description ：综合场景，初始化MultiScene所需要的机器人
 *               作为示例，这里一半的机器人做login动作，另一半机器人做Battle的动作
 */
void RobotMgr::initMultiSceneRobots(int totalNum, int indexStart, int tranTotal)
{
	int i = 0;
	for(i=0;i<totalNum/2;i++)
	{
		RobotLogin *robot= new RobotLogin(indexStart+i,tranTotal);
		addRobot(robot);
	}
	
	for(i=totalNum/2;i<totalNum;i++)
	{
		//other robot
	}
}




 