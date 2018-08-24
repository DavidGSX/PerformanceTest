#ifndef __ROBOTMGR_H__
#define __ROBOTMGR_H__

#include <iostream>
#include "core/AbstractRobotMgr.h"
using namespace std;

class RobotMgr :public AbstractRobotMgr
{
public:
	RobotMgr();
	//��ʼ�����л����ˣ��ɿͻ�ʵ��
	virtual void initAllRobot(string robotScene);
	void initLoginSceneRobots(int totalNum, int indexStart, int tranTotal);
	void initMultiSceneRobots(int totalNum, int indexStart, int tranTotal);
	void initCTestSceneRobots(int totalNum, int indexStart, int tranTotal);
	void setTpsInfo();
};

#endif
