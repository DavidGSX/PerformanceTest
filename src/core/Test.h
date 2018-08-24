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
* Copyright (c)  2016-2017, 腾讯科技有限公司互动娱乐研发部
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
 * Description ：控制类
 * Details     ：控制机器人管理类的初始化、机器人的初始化及执行任务
 */
class Test :public AbstractThread ,public NodeMgrRobotInterface
{
	private:  
		
		int m_robotNum;//机器人数
		int m_robotNumPerSec;//每秒启动机器人数
		long m_tranTotal ;// 总事务数，-1表示不停止
		string m_robotScene ;//运行的场景

		AbstractRobotMgr *m_pRobotMgr;//机器人管理器，由用户自定义
		RobotsService *  m_pRobotsService;
		Stat * m_pStat;//统计管理器
		BaseStatDataUpload* m_pStatDataUpload ;  //上传管理器
		DataProPkgUpload* m_pDataProPkgUpload ;  //上传wetest管理器
		

		int m_testRunModel;//0为单机，1为节点方式
		int m_mainLoopTime;//测试主线程循环周期， 周期内会做各种检查
		int m_startindex;
		bool m_testStop;

		
	public:
		//Test(int robotnum,long tranTotal,int robotnumPerSec,string robotScene) ;
		Test(int robotnum,int startIndex,long tranTotal,int robotnumPerSec) ;
		virtual ~Test();
		AbstractRobotMgr * getRobotMgr();//机器人管理器
		
		void initRobot( string robotScene);
		void initStatAndUpload();
		void run();
		void tick(const string robotScene);//单点模式的主循环
		void tickByNode(const string robotScene);//节点方式运行的 主循环
		virtual  void runThread();//线程启动后运行的函数
		bool checkAllTreadStop();
		int getTestRunModel() ;
	    void setTestRunModel(int testRunModel) ;
		BaseStatDataUpload* getStatDataUpload();
		DataProPkgUpload* getDataProPkgUpload();
		void setStatDataUpload(BaseStatDataUpload* statDataUpload);
		
		void setTestStop(bool testStop) ;
		
		//---------------------------下面为节点管理必须实现的接口-----------------
		virtual void stopRobot();
		virtual bool isTestStop() ;
		virtual int getStatDataUploadSize() ;		
		virtual UploadData * getStatDataUploadOneMsg();//取一个数据进行上传
		//------------------------------启动方式---------------------------------
		//单机运行
		static Test * doSigleStartTest(int testRunModel,int robotnum,int startIndex,long tranTotal,int robotnumPerSec,string robotScene);
		//节点运行
		static NodeMgrRobotInterface * doNodeStartTest(int testRunModel,int robotnum,int startIndex,long tranTotal,int robotnumPerSec,string robotScene);
		
};


#endif

