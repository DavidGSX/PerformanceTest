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
 * Description ��init robot
 */
RobotCTest::RobotCTest(int index,long tranTotal):AbstractRobot(index, tranTotal) 
{

}

/**
 * 
 * Description ��connect to server first
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
 * Description ��repeat doing something 
 */
inline int RobotCTest::runAction()
{	
	//int iResult;

	Sampler sampler("CTest",this);
	//��ʼ����
	sampler.sampleStart();
	
	//iResult = ROBOT_MISSION_SUCCESS;
	int iResult = m_pGameAPI->tLoginGame(this->getRobotIndex(),"123","456");	

	//ROBOT_MISSION_SUCCESS 0;	ROBOT_MISSION_FAIL 1;	ROBOT_DUMP -1
	if(iResult == ROBOT_MISSION_SUCCESS) //ִ������ɹ�
	{
		sampler.sampleEnd(true);
		return 0;
	}
	else if(iResult == ROBOT_MISSION_FAIL)//ִ������ʧ��
	{
		sampler.sampleEnd(false);
		return 0;
	}
	else if(iResult == ROBOT_DUMP)//�����˳������⣬׼���˳�
	{
		sampler.sampleEnd(false);
		return -1;
	}
	
	return 0;
 }
 

 /**
 * 
 * Description �����������������ӵĴ������ж�̬������Դ�Ķ����������������ͷŵ������������ڴ�й¶
 */
 RobotCTest::~RobotCTest()
 { 
	delete m_pGameAPI;
 }

 
 
