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

	int iResult = m_pGameAPI->tLoginGame(123456,"hazelnutlin","pwd_hazel");	
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

	//no thing to do...
	Sampler sampler("NOTHING",this);
	//��ʼ����
	sampler.sampleStart();
	
	iResult = ROBOT_MISSION_SUCCESS;

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
 RobotLogin::~RobotLogin()
 { 
	delete m_pGameAPI;
 }

 
 
