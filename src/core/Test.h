/**
*
* @file     Test.h
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

#ifndef __TEST_H__
#define __TEST_H__

#include <string>
#include <map>
#include <iostream>

#include "core/CommonFunction.h"
#include "core/AbstractRobot.h"
#include "core/AbstractRobotMgr.h"
#include "core/Stat.h"
#include "core/RobotsService.h"
#include "core/AbstractThread.h"
#include "node/NodeMgrRobotInterface.h"

using namespace std;

/**
 * 
 * Description ��������
 * Details     �����ƻ����˹�����ĳ�ʼ���������˵ĳ�ʼ����ִ������
 */
class Test :public AbstractThread ,public NodeMgrRobotInterface
{
	private:  
		
		int m_robotNum;//��������
		int m_robotNumPerSec;//ÿ��������������
		long m_tranTotal ;// ����������-1��ʾ��ֹͣ
		string m_robotScene ;//���еĳ���

		AbstractRobotMgr *m_pRobotMgr;//�����˹����������û��Զ���
		RobotsService *  m_pRobotsService;
		Stat * m_pStat;//ͳ�ƹ�����
		BaseStatDataUpload* m_pStatDataUpload ;  //�ϴ�������
		DataProPkgUpload* m_pDataProPkgUpload ;  //�ϴ�wetest������
		

		int m_testRunModel;//0Ϊ������1Ϊ�ڵ㷽ʽ
		int m_mainLoopTime;//�������߳�ѭ�����ڣ� �����ڻ������ּ��
		int m_startindex;
		bool m_testStop;

		
	public:
		//Test(int robotnum,long tranTotal,int robotnumPerSec,string robotScene) ;
		Test(int robotnum,int startIndex,long tranTotal,int robotnumPerSec) ;
		virtual ~Test();
		AbstractRobotMgr * getRobotMgr();//�����˹�����
		
		void initRobot( string robotScene);
		void initStatAndUpload();
		void run();
		void tick(const string robotScene);//����ģʽ����ѭ��
		void tickByNode(const string robotScene);//�ڵ㷽ʽ���е� ��ѭ��
		virtual  void runThread();//�߳����������еĺ���
		bool checkAllTreadStop();
		int getTestRunModel() ;
	    void setTestRunModel(int testRunModel) ;
		BaseStatDataUpload* getStatDataUpload();
		DataProPkgUpload* getDataProPkgUpload();
		void setStatDataUpload(BaseStatDataUpload* statDataUpload);
		
		void setTestStop(bool testStop) ;
		
		//---------------------------����Ϊ�ڵ�������ʵ�ֵĽӿ�-----------------
		virtual void stopRobot();
		virtual bool isTestStop() ;
		virtual int getStatDataUploadSize() ;		
		virtual UploadData * getStatDataUploadOneMsg();//ȡһ�����ݽ����ϴ�
		//------------------------------������ʽ---------------------------------
		//��������
		static Test * doSigleStartTest(int testRunModel,int robotnum,int startIndex,long tranTotal,int robotnumPerSec,string robotScene);
		//�ڵ�����
		static NodeMgrRobotInterface * doNodeStartTest(int testRunModel,int robotnum,int startIndex,long tranTotal,int robotnumPerSec,string robotScene);
		
};


#endif

