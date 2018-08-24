/**
*
* @file     AbstractRobot.h
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

#ifndef __ABSTRACTROBOT_H__
#define __ABSTRACTROBOT_H__

#include <string>
#include <vector>
#include "core/AbstractThread.h"
using namespace std;

#define    ROBOT_MISSION_SUCCESS 1
#define    ROBOT_MISSION_FAIL 0
#define    ROBOT_DUMP -1
#define    ROBOT_MISSION_EXCEPTION 2
#define    ROBOT_CONNECT_TIMEOUT 3

class  Stat ;
class  AbstractRobotMgr;

class AbstractRobot : public AbstractThread
{
	private:  
	 	bool m_enableSampler;//是否进行采样
		long m_tranTotal;//运行次数
		int  m_index;//机器人唯一标志
		bool m_initSucc;

		bool m_stopRobot;
		Stat * m_pStat;//统计线程
		AbstractRobotMgr * m_pRobotMgr ;

	public:
		AbstractRobot(int index,long tranTotal);
		bool isEnableSampler();
		void setEnableSampler(bool enableSampler);	
		void setStat(Stat * stat);
		Stat * getStat();
		void setRobotMgr(AbstractRobotMgr * robotMgr);
		AbstractRobotMgr * getRobotMgr();
		//线程执行的函数
		virtual void runThread();
		void run(); 
	
		//机器人行为，由客户实现
		virtual int runAction()=0;
		
		virtual bool init()=0;
		//机器人线程 执行完runAction()循环后做的动作；
		virtual bool close();

		bool isInitSucc();
		void setInitSucc(bool initSucc);
		
		int getRobotIndex();

		bool isStopRobot();
		void setStopRobot(bool stopRobot);
		
	
		virtual ~AbstractRobot();

};

#endif
