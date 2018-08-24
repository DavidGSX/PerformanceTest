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
* Copyright (c)  2016-2017, ��Ѷ�Ƽ����޹�˾���������з���
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
	 	bool m_enableSampler;//�Ƿ���в���
		long m_tranTotal;//���д���
		int  m_index;//������Ψһ��־
		bool m_initSucc;

		bool m_stopRobot;
		Stat * m_pStat;//ͳ���߳�
		AbstractRobotMgr * m_pRobotMgr ;

	public:
		AbstractRobot(int index,long tranTotal);
		bool isEnableSampler();
		void setEnableSampler(bool enableSampler);	
		void setStat(Stat * stat);
		Stat * getStat();
		void setRobotMgr(AbstractRobotMgr * robotMgr);
		AbstractRobotMgr * getRobotMgr();
		//�߳�ִ�еĺ���
		virtual void runThread();
		void run(); 
	
		//��������Ϊ���ɿͻ�ʵ��
		virtual int runAction()=0;
		
		virtual bool init()=0;
		//�������߳� ִ����runAction()ѭ�������Ķ�����
		virtual bool close();

		bool isInitSucc();
		void setInitSucc(bool initSucc);
		
		int getRobotIndex();

		bool isStopRobot();
		void setStopRobot(bool stopRobot);
		
	
		virtual ~AbstractRobot();

};

#endif
