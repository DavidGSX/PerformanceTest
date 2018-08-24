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
	* �����˹��췽��
	* �ڳ�ʼ����ʱ�����һ��
	* һ�����ڴ��ݻ����˲������߳�ʼ���߼�
	* @param index  �����˱��
	* @param tranTotal   ����ִ�еĴ���
*/
RobotBattle::RobotBattle(int index,long tranTotal):AbstractRobot(index, tranTotal) 
{
	
}

/**
	* ��ʼ������
	* ֻ����һ�Σ��������false������runAction��������ִ��
	* һ������ʵ�ֻ����˳�ʼ���߼�
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
	 * ������ִ�еĶ���
	 * 1����Ҫ����
	 *   ִ�л�������Ϊ���ο�GameSceneDemo.battleScene()ʵ��
	 *   ��ÿ����������������ƣ�����ƽ̨����ͳ��tps/��Ӧʱ������ܲ���	   
	 * 2��ÿ���������Զ���
	 *    ���ÿ���/�����������
	 *    Sampler sampler("������",...);
	 *    sampler.sampleStart();
	 *          //todo ִ�о�������Ĵ���	   
	 *    sampler.sampleEnd(true);//��ʾ����ɹ������ʧ������false
	 * 3��runAction������������ִ��tranTotal�� 
	 * 4������ֵ�����Ϊ��0�������˳�������
*/
inline int RobotBattle::runAction()
{	
	int iResult;
	Sampler sampler("Start_Game",this);
	sampler.sampleStart();
	iResult = m_pGameAPI->StartGame();

	SleepMsec(500);

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
	 
	Sampler sampler1("End_Game",this);
	sampler1.sampleStart();
	
	iResult = m_pGameAPI->EndGame();

	SleepMsec(500);

	if(iResult == ROBOT_MISSION_SUCCESS){  //ִ������ɹ�
		sampler1.sampleEnd(ROBOT_MISSION_SUCCESS);//spr�Ľ���ͳ��
	}
	else if(iResult == ROBOT_MISSION_FAIL){  //ִ������ʧ��
		sampler1.sampleEnd(ROBOT_MISSION_FAIL);
	}
	else if(iResult == ROBOT_DUMP){  //�����˳������⣬׼���˳�
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
 * Description �����������������ӵĴ������ж�̬������Դ�Ķ����������������ͷŵ������������ڴ�й¶
 */
 RobotBattle::~RobotBattle()
 { 
	delete m_pGameAPI;
 }


 
 
