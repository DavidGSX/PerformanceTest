/**
*
* @file     RobotMgr.h
* @brief
*
* @author honyliu jennachen
* @version 1.0
* @date 2017-11-08
*
*
* Copyright (c)  2016-2017, ��Ѷ�Ƽ����޹�˾���������з���
* All rights reserved.
*
*/

#ifndef __ROBOTMGR_H__
#define __ROBOTMGR_H__

#include <iostream>
#include <fstream>
#include <map>
#include "core/AbstractRobotMgr.h"
using namespace std;

class RobotMgr :public AbstractRobotMgr
{
public:
	RobotMgr();
	//��ȡ�����б���д�����ű���
	void getSceneList();
	//��ʼ�����л����ˣ��ɿͻ�ʵ��
	void initAllRobot(string robotScene);
	void initLoginSceneRobots(int totalNum, int indexStart, int tranTotal);
	void initBattleSceneRobots(int totalNum, int indexStart, int tranTotal);
	void initMultiSceneRobots(int totalNum, int indexStart, int tranTotal);
	void initCTestSceneRobots(int totalNum, int indexStart, int tranTotal);
	void setTpsInfo();
private:
	
	typedef void (RobotMgr::*sceneFun)(int totalNum, int indexStart, int tranTotal);
	typedef map<string,sceneFun> Scene2Fun; //�����ͻ����˳�ʼ��������ӳ������
	Scene2Fun sceneCall; //�������
	ofstream m_osfLogFile;//�ļ���
	const char *m_pScenefile; //ָ������ļ�·��
};

#endif
