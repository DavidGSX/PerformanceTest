/**
*
* @file     AbstractRobotMgr.h
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

#ifndef __ABSTRACTROBOTMGR_H__
#define __ABSTRACTROBOTMGR_H__

#include <string>
#include <vector>
#include "core/AbstractRobot.h"
#include "core/CommonFunction.h"
#include "core/Logger.h"
#include "core/TpsControler.h"

using namespace std;
class AbstractRobot;

class AbstractRobotMgr
{
	private:  
		vector<AbstractRobot*>  * m_pRobotLs;
		int m_robotNum ;//��������
		long m_tranTotal;
		TpsControler * m_pTpsControler ;
	public:
		AbstractRobotMgr();
		~AbstractRobotMgr();
		void initRobotMgr(int robotnum,long tranTotal,long robotStartIndex);
		void addRobot(AbstractRobot * robot);
		virtual void setTpsInfo();
		vector<AbstractRobot *> *  getRobotLs();
		int getRobotNum();
		long getTranTotal();
		void setTps(string key,double tps);
		//��ʼ�����л����ˣ��ɿͻ�ʵ��
		virtual void initAllRobot(string robotScene)=0;
		long m_robotStartIndex;
		int getIndexStart();
};


#endif

