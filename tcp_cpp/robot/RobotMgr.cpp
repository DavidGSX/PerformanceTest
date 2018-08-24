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
 * ���������������������л�����
 * 1��robotScene�������ھ����������������
      ��������main�����������л�ȡ��
	  �������ֵ��Ӧ�����ĸ���ʼ�������˺������û��Լ�����
 */
void  RobotMgr::initAllRobot(string robotScene)
{
	int robot_Num = this->getRobotNum();//��ȡ����������
	long tran_Total = this->getTranTotal();//��ȡ������ִ������Ĵ���
	
	//���ݴ����robotScene�����������������͵Ļ�����
	if(robotScene=="defaultScene")//load connect test scene
	{
		initCTestSceneRobots(robot_Num,0,tran_Total);
	}
	else if (robotScene=="multiScene")//ִ�жೡ��  //��ʼ���ೡ��������
	{  
        initMultiSceneRobots(robot_Num, 0,tran_Total);
	}
	else
	{
		//�����robotScene��ֵ���������Ķ���֮��
		stringstream ss4Input;
		ss4Input<<"param \"robotScene\"= "<<robotScene<<" is NOT defined, see details in RobotMgr::initAllRobot()";
		g_logger.error(&ss4Input);
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
	//setTps("DoLogin",300);
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
		//other robot
	}
}




 