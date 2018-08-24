#include "robot/RobotMgr.h"
#include "robot/RobotBattle.h"
#include "robot/RobotLogin.h"
#include "robot/RobotCTest.h"
#include "core/Logger.h"
#include "core/TpsControler.h"
#include "core/CommonFunction.h"
//#include "api/api.h"

extern Logger g_logger;

void RobotMgr::getSceneList()
{
	string fileName = "SceneList.txt";
	m_pScenefile = fileName.c_str();
	m_osfLogFile.open(m_pScenefile,ios::app);
	if(!this->m_osfLogFile.is_open())
	{
		string info = "Open the SceneList.txt Fail! ";
		g_logger.error(info,__FILE__,__FUNCTION__,__LINE__);
	}
	for(Scene2Fun::iterator iter = sceneCall.begin(); iter != sceneCall.end(); iter++)
	{
		m_osfLogFile<<iter->first<<endl;
		m_osfLogFile.flush();
	}
}

/**
 * 
 * 机器人生成器，生成所有机器人
 * 1、robotScene参数用于决定产生哪类机器人
	  根据参数值调用对应场景函数；该映射关系在构造函数中建立
 */
void  RobotMgr::initAllRobot(string robotScene)
{
	int robot_Num = this->getRobotNum();//获取机器人数量
	long tran_Total = this->getTranTotal();//获取机器人执行任务的次数
	Scene2Fun::iterator iter = sceneCall.begin();
	for(iter = sceneCall.begin(); iter != sceneCall.end(); iter++)
	{
		if(iter->first == robotScene)
		{
			sceneFun fun = iter->second;
			(this->*fun)(robot_Num, getIndexStart(),tran_Total);
			break;
		}
	}
	if(iter == sceneCall.end())
	{
		//传入的robotScene的值不在上述的定义之列
		string info="The scene call function  with param \"robotScene\"= "+robotScene+" is NOT defined in the RobotMgr! Please cheack the RobotMgr::RobotMgr() ";
		g_logger.error(info,__FILE__,__FUNCTION__,__LINE__);
		exit(0);
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
	//setTps("DoLogin",150);
}


RobotMgr::RobotMgr()
{
	//由用户实现,只需要修改场景字符串和对应函数名
	//用户场景名和场景函数建立一一映射关系
	sceneCall["defaultScene"]   = &RobotMgr::initCTestSceneRobots;
	//sceneCall["defaultScene"] = &RobotMgr::initLoginSceneRobots;
	//sceneCall["battleScene"]  = &RobotMgr::initBattleSceneRobots;
	//sceneCall["multiScene"]   = &RobotMgr::initMultiSceneRobots;
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
 * Description ：单场景，初始化BattlScene所需要的机器人
 */
void RobotMgr::initBattleSceneRobots(int totalNum, int indexStart, int tranTotal)
{
    //string value = GetArgv("param1");
	//g_logger.info("param1: "+value);
	int i = 0;
	for(i=0;i<totalNum;i++)
	{
		RobotBattle *robot= new RobotBattle(indexStart+i,tranTotal);
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
		RobotBattle *robot= new RobotBattle(indexStart+i,tranTotal);
		addRobot(robot);
	}
}




 
