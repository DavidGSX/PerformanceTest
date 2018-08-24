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

Logger   g_logger;//ȫ�ֶ��󣬼�¼������־��Ϣ
map<string,string> argcInfo;//ȫ�ֶ��󣬼�¼�û��Զ��������Ϣ
/*****����ȫ���� */

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


//����Ϊ��ȡ�������õĸ�������
template<typename T>
bool IsInArgv(map<string,string> * infoMap, string key, T &param);
void SplitArgv(int argc, char *argv[],map<string,string> * argvInfor);
void ReadParamFromFile(map<string,string> *pInfoMap);
void initLog();
//����������ʽ
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
	//��ȡsprconfig.xml�����ļ���Ϣ����ʼ��ȫ����־
	initLog();

	//���������в���
	SplitArgv(argc,argv,&argcInfo);//���������д���Ĳ���
	//����ģʽ 
	int testRunModel=0;//0��������ģʽ��1���ֲ�ʽģʽ��2����ȡ�����б�ģʽ
	IsInArgv(&argcInfo,"nodeModel",testRunModel);
	
	switch(testRunModel)
	{
		case 0:
			//����������ʽ
			g_logger.info("robot start with sigle model . " );
			if(SprConfig::getInstance()->spr_isGapsUpload)
			{
				TdrData *data = TdrData::getInstance();
				//��ʼ����ʼ������Ϣ
				data->initStartPkg();
				//���Ϳ�ʼ������Ϣ
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

				//���ͽ���������Ϣ
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
				SleepMsec(1000);  //�ȴ�1s��ر�socket
				data->closeSocket();
				
			}
			else
			{
				//�����ļ���gaps_isUpload���ر��رգ�ͳ�����ݲ����ϴ���gaps
				g_logger.info("The value of gaps_isUpload in sprconfig.xml is false! Data will not be sent to Wetest!");
				startTestSigle(argcInfo);
			}
			break;
		case 1:
			//�ڵ�������ʽ	
			g_logger.info("robot start with node model . " );
			NodeMgr::doWork();
			break;
		case 2:
			//��ȡ�û������б�������ʽ
			g_logger.info("start with getScene model . " );
			RobotMgr robotMgr;
			robotMgr.getSceneList();
			break;
	}
	return 0;
}


/**
 * 
 * Description ���ܿس���
 * Details     ������ѿز��Գ��������
 */
int startTestSigle(map<string,string> & argcInfo)
{
	int robotNum;  
	int tranTotal; 
	int robotPerSec; 
	int startIndex;
	string robotScene;
	//�������ݴ������л�ȡ
	if( !IsInArgv(&argcInfo,"robotNum",robotNum) || robotNum<=0){//����������
		robotNum = 1;
	}
	if( !IsInArgv(&argcInfo,"tranTotal",tranTotal) || tranTotal<=0){//������ִ������Ĵ���
		tranTotal = -1;
	}
	if( !IsInArgv(&argcInfo,"robotPerSec",robotPerSec)|| robotPerSec<=0){//ÿ�뿪���Ļ���������
		robotPerSec = 1;
	}
	if( !IsInArgv(&argcInfo,"robotScene",robotScene)){//��ʼ�������˵�����
		robotScene = "defaultScene";
	}
	if( !IsInArgv(&argcInfo,"startIndex",startIndex)){//�������л�ȡ�����˵���ʼid
		startIndex = 0;
	}
		
	 Test *test=Test::doSigleStartTest(0,robotNum, startIndex, tranTotal,robotPerSec,robotScene);
	 //��������ʾ�Զ�ֹͣ�� 
	 delete  test;
	 return 0;
}
void initLog()
{
	//int interval ;//��־��������ڣ�һ������Ϊ5s
	int consoleOutput;//��־��Ϣ���������̨��1--->�� 0--->��
	int logFileOutput;//��־��Ϣ������ļ���1--->�� 0--->��
	int logLevel;//��־��������

   SprConfig *pSprConfig = SprConfig::getInstance();
   consoleOutput  = pSprConfig->main_consoleOutput;
   logFileOutput  = pSprConfig->main_logFileOutput;
   logLevel       = pSprConfig->main_logLevel;
   g_logger.initLogger(consoleOutput, logFileOutput,logLevel);//��ʼ����־��Ϣ
}
/**
 * 
 * Description ������main������argv����
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
 * Description ������main��������argv����Ϣ
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
