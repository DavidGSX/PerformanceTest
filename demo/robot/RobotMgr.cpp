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
 * ���������������������л�����
 * 1��robotScene�������ھ����������������
	  ���ݲ���ֵ���ö�Ӧ������������ӳ���ϵ�ڹ��캯���н���
 */
void  RobotMgr::initAllRobot(string robotScene)
{
	int robot_Num = this->getRobotNum();//��ȡ����������
	long tran_Total = this->getTranTotal();//��ȡ������ִ������Ĵ���
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
		//�����robotScene��ֵ���������Ķ���֮��
		string info="The scene call function  with param \"robotScene\"= "+robotScene+" is NOT defined in the RobotMgr! Please cheack the RobotMgr::RobotMgr() ";
		g_logger.error(info,__FILE__,__FUNCTION__,__LINE__);
		exit(0);
	}
}

/*
*  �Ը�����������tps
*/
void RobotMgr::setTpsInfo()
{
	//����1������������Robot��runAction()�д����������һ��
	//����2��tpsֵ���������0
	//setTps("Start_Game",3.5);
	//setTps("DoLogin",150);
}


RobotMgr::RobotMgr()
{
	//���û�ʵ��,ֻ��Ҫ�޸ĳ����ַ����Ͷ�Ӧ������
	//�û��������ͳ�����������һһӳ���ϵ
	sceneCall["defaultScene"]   = &RobotMgr::initCTestSceneRobots;
	//sceneCall["defaultScene"] = &RobotMgr::initLoginSceneRobots;
	//sceneCall["battleScene"]  = &RobotMgr::initBattleSceneRobots;
	//sceneCall["multiScene"]   = &RobotMgr::initMultiSceneRobots;
}



/**
 * 
 * Description ������������ʼ��LoginScene����Ҫ�Ļ�����
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
 * Description ������������ʼ��LoginScene����Ҫ�Ļ�����
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
 * Description ������������ʼ��BattlScene����Ҫ�Ļ�����
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
 * Description ���ۺϳ�������ʼ��MultiScene����Ҫ�Ļ�����
 *               ��Ϊʾ��������һ��Ļ�������login��������һ���������Battle�Ķ���
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




 
