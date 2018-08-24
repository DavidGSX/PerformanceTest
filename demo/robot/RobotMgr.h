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
* Copyright (c)  2016-2017, 腾讯科技有限公司互动娱乐研发部
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
	//获取场景列表，并写入至脚本中
	void getSceneList();
	//初始化所有机器人，由客户实现
	void initAllRobot(string robotScene);
	void initLoginSceneRobots(int totalNum, int indexStart, int tranTotal);
	void initBattleSceneRobots(int totalNum, int indexStart, int tranTotal);
	void initMultiSceneRobots(int totalNum, int indexStart, int tranTotal);
	void initCTestSceneRobots(int totalNum, int indexStart, int tranTotal);
	void setTpsInfo();
private:
	
	typedef void (RobotMgr::*sceneFun)(int totalNum, int indexStart, int tranTotal);
	typedef map<string,sceneFun> Scene2Fun; //场景和机器人初始化函数的映射类型
	Scene2Fun sceneCall; //定义变量
	ofstream m_osfLogFile;//文件流
	const char *m_pScenefile; //指向输出文件路径
};

#endif
