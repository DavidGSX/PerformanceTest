/*
*
 * File         	: main.cpp
 * Version      	: V1.0
 * Description		: 
 * Details      	: 
 *
 * modification history
 * --------------------
 * author: honyliu 2015-7-21
 * --------------------
 * last modification info
 * --------------------
 * modified by jennachen 2017-10-23
 * --------------------
 **/

#include <iostream>
#include <sstream>
#include <string>
#include <map>
#include <list>

#include "core/Logger.h"
#include "core/SprConfig.h"
#include "core/Test.h"

//node
#include "node/logic/MessageServiceTool.h"
#include "node/NodeMgr.h"

//scene
#include "robot/RobotMgr.h"

#include "protocal/tdr/TdrData.h"

using namespace std;

Logger   g_logger;//全局对象，记录程序日志信息
map<string,string> argcInfo;//全局对象，记录用户自定义参数信息
/*****声明全局锁 */

#ifdef _WIN32
CRITICAL_SECTION g_statDataLock;
CRITICAL_SECTION g_LoggerLock;
CRITICAL_SECTION g_HttpMsgLock;
CRITICAL_SECTION g_statDataUploadInitLock;
CRITICAL_SECTION g_RobotNumLock;
CRITICAL_SECTION g_MessMgrLock;
CRITICAL_SECTION g_SamplerQueLock;
CRITICAL_SECTION g_DataPkgLock;
#else
pthread_mutex_t g_statDataLock               = PTHREAD_MUTEX_INITIALIZER;
pthread_mutex_t g_LoggerLock                 = PTHREAD_MUTEX_INITIALIZER;
pthread_mutex_t g_HttpMsgLock                = PTHREAD_MUTEX_INITIALIZER;
pthread_mutex_t g_statDataUploadInitLock     = PTHREAD_MUTEX_INITIALIZER;
pthread_mutex_t g_RobotNumLock               = PTHREAD_MUTEX_INITIALIZER;
pthread_mutex_t g_MessMgrLock                = PTHREAD_MUTEX_INITIALIZER;
pthread_mutex_t g_SamplerQueLock             = PTHREAD_MUTEX_INITIALIZER;
pthread_mutex_t g_DataPkgLock                = PTHREAD_MUTEX_INITIALIZER;
#endif


//以下为获取参数设置的辅助函数
template<typename T>
bool IsInArgv(map<string,string> * infoMap, string key, T &param);
void SplitArgv(int argc, char *argv[],map<string,string> * argvInfor);
void ReadParamFromFile(map<string,string> *pInfoMap);
void initLog();
//单机启动方式
int startTestSigle(map<string,string>  & argcInfo);


int main(int argc,char *argv[])
{ 
#ifdef _WIN32
	InitializeCriticalSection(&g_LoggerLock);
	InitializeCriticalSection(&g_statDataLock);
	InitializeCriticalSection(&g_HttpMsgLock);
	InitializeCriticalSection(&g_statDataUploadInitLock);
	InitializeCriticalSection(&g_RobotNumLock);
	InitializeCriticalSection(&g_MessMgrLock);
	InitializeCriticalSection(&g_SamplerQueLock);
	InitializeCriticalSection(&g_DataPkgLock);
#endif
	//读取sprconfig.xml配置文件信息、初始化全局日志
	initLog();

	//解析命令行参数
	SplitArgv(argc,argv,&argcInfo);//解析命令行传入的参数
	//运行模式 
	int testRunModel=0;//0：单进程模式；1：分布式模式；2：获取场景列表模式
	IsInArgv(&argcInfo,"nodeModel",testRunModel);
	
	switch(testRunModel)
	{
		case 0:
			//单机启动方式
			g_logger.info("robot start with sigle model . " );
			if(SprConfig::getInstance()->spr_isGapsUpload)
			{
				TdrData *data = TdrData::getInstance();
				//初始化开始测试消息
				data->initStartPkg();
				//发送开始测试消息
				bool res = data->sendPkg();
				if(res)
				{
					g_logger.info("Send GAPS_TESTSTART_REQ Success !");
				}
				else
				{
					string info = "Send GAPS_TESTSTART_REQ FAILED!";
					g_logger.error(info ,__FILE__,__FUNCTION__,__LINE__);
					exit(0);
				}

				startTestSigle(argcInfo);

				//发送结束测试消息
				data->initEndReqPkg();
				res = data->sendPkg();
				if(res)
				{
					g_logger.info("Send GAPS_TESTEND_REQ Success !");
				}
				else
				{
					string info = "Send GAPS_TESTEND_REQ FAILED!";
					g_logger.error(info ,__FILE__,__FUNCTION__,__LINE__);
					exit(0);
				}
				SleepMsec(1000);  //等待1s后关闭socket
				data->closeSocket();
				
			}
			else
			{
				//配置文件中gaps_isUpload开关被关闭，统计数据不会上传到gaps
				g_logger.info("The value of gaps_isUpload in sprconfig.xml is false! Data will not be sent to Wetest!");
				startTestSigle(argcInfo);
			}
			break;
		case 1:
			//节点启动方式	
			g_logger.info("robot start with node model . " );
			NodeMgr::doWork();
			break;
		case 2:
			//获取用户场景列表启动方式
			g_logger.info("start with getScene model . " );
			RobotMgr robotMgr;
			robotMgr.getSceneList();
			break;
	}
	return 0;
}


/**
 * 
 * Description ：总控程序
 * Details     ：整体把控测试程序的运行
 */
int startTestSigle(map<string,string> & argcInfo)
{
	int robotNum;  
	int tranTotal; 
	int robotPerSec; 
	int startIndex;
	string robotScene;
	//以下数据从命令行获取
	if( !IsInArgv(&argcInfo,"robotNum",robotNum) || robotNum<=0){//机器人数量
		robotNum = 1;
	}
	if( !IsInArgv(&argcInfo,"tranTotal",tranTotal) || tranTotal<=0){//机器人执行任务的次数
		tranTotal = -1;
	}
	if( !IsInArgv(&argcInfo,"robotPerSec",robotPerSec)|| robotPerSec<=0){//每秒开启的机器人数量
		robotPerSec = 1;
	}
	if( !IsInArgv(&argcInfo,"robotScene",robotScene)){//初始化机器人的种类
		robotScene = "defaultScene";
	}
	if( !IsInArgv(&argcInfo,"startIndex",startIndex)){//从命令行获取机器人的起始id
		startIndex = 0;
	}
		
	 Test *test=Test::doSigleStartTest(0,robotNum, startIndex, tranTotal,robotPerSec,robotScene);
	 //返回来表示自动停止了 
	 delete  test;
	 return 0;
}
void initLog()
{
	//int interval ;//日志输出的周期，一般设置为5s
	int consoleOutput;//日志信息输出到控制台：1--->是 0--->否
	int logFileOutput;//日志信息输出到文件：1--->是 0--->否
	int logLevel;//日志级别设置

   SprConfig *pSprConfig = SprConfig::getInstance();
   consoleOutput  = pSprConfig->main_consoleOutput;
   logFileOutput  = pSprConfig->main_logFileOutput;
   logLevel       = pSprConfig->main_logLevel;
   g_logger.initLogger(consoleOutput, logFileOutput,logLevel);//初始化日志信息
}
/**
 * 
 * Description ：解析main函数的argv参数
 */
void SplitArgv(int argc, char *argv[],map<string,string> * argvInfor)
{
	string strKey;
	string strValue;
	int i = 0;

	for(i=1;i<argc;i++)
	{
		
		strKey = "";
		int j=0;
		while(argv[i][j] == ' ')
		{
			j++;	
		}
		while(j< strlen(argv[i]) && argv[i][j] != '=' &&argv[i][j] != ' ')
		{
			strKey += argv[i][j];
			j++;
		}
		j++;
		while(j< strlen(argv[i]) && argv[i][j] == ' ')
		{
			j++;
		}
		strValue = "";
		while(j< strlen(argv[i]) &&argv[i][j] != '='&&argv[i][j] != ' ')
		{
			strValue += argv[i][j];
			j++;
		}
		argvInfor->insert(pair<string,string>(strKey,strValue));
	}
}

/**
 * 
 * Description ：辅助main函数查找argv的信息
 */
template<typename T>
bool IsInArgv(map<string,string> * infoMap, string key, T &param)
{
	map<string,string>::iterator iter;
	stringstream tmpSS;
	iter = infoMap->find(key);
	if(iter != infoMap->end())
	{
		tmpSS<<iter->second;
		tmpSS>>param;
		return true;
	}
	else{
		return false;
	}
}
