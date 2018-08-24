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
 * Description ����ʼ��������
 */
RobotLogin::RobotLogin(int index,long tranTotal):AbstractRobot(index, tranTotal) 
{
	// g_logger.info("robot  , index="+StringTools::int2string(this->getRobotIndex()));   
	// SleepMsec(1000);
}




/**
 * 
 * Description ��������������ִ�е�½�Ĳ�����һ������½�����½һ��
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
 * Description ��������ִ�о�������
 */
inline int RobotLogin::runAction()
{	
	int iResult;

	Sampler sampler("DoLogin",this);
	//��ʼ����
	sampler.sampleStart();
	iResult = m_pGameAPI->Login(this->getRobotIndex());
	
	//SleepMsec(500);
	//SleepMsec(rand()%100);


	if(iResult == ROBOT_MISSION_SUCCESS)  {  //ִ������ɹ�
		sampler.sampleEnd(ROBOT_MISSION_SUCCESS);//spr�Ľ���ͳ��
	}
	else if(iResult == ROBOT_MISSION_FAIL){  //ִ������ʧ��
		sampler.sampleEnd(ROBOT_MISSION_FAIL);
	}
	else if(iResult == ROBOT_DUMP)  {  //�����˳������⣬׼���˳�
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
 * Description ��������ִ����runAction()ѭ�������Ķ�������ִ��һ��
 */
bool RobotLogin::close()
{
	return true;
}
 /**
 * 
 * Description �����������������ӵĴ������ж�̬������Դ�Ķ����������������ͷŵ������������ڴ�й¶
 */
 RobotLogin::~RobotLogin()
 { 
	delete m_pGameAPI;
	//destory robot, you can get info where debug
	//g_logger.info("robot have destory , index="+StringTools::int2string(this->getRobotIndex()));
 }

 
 
