/**
*
* @file     Stat.h
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

#ifndef __STAT_H__
#define __STAT_H__

#include <map>
#include <string>
#include <fstream>

#include "core/Sampler.h"
#include "core/AbstractThread.h"
#include "dataUpload/DataProcess/StatDataUpload.h"
#include "dataUpload/DataProcess/DataProPkgUpload.h"
#include "core/DataTypeDefine.h"

#define INIT_MAX_NUM 65535
#define INIT_MIN_NUM -65535

class BaseStatDataUpload;

using namespace std;

/**
 * 
 * Description ：数据类
 * Details     ：记录统计信息
 */
class StatData {
		public:
			unsigned long long  m_total;//总事务数
			long  m_error;//错误事务数
			long  m_avgMillisec;//平均响应时间
			long  m_minMillisec;//最小响应时间
			long  m_maxMillisec;//最大响应时间
			long  m_totalMillisec;//响应时间总数
			long m_timeSectionCount;
			long m_statTimeMaxSection;
			long m_statTimePrecisionSection;

			UInt64 m_firstTranTime;//第一个任务的时间
			UInt64 m_lastTranTime;//最后一个任务的

			//间隔内数据
			long m_intervalTotal;//间隔内总事务数
			long m_intervalError;//间隔内错误数
			long m_intervalAvgMillisec;//间隔内平响应时间
			long m_intervalMinMillisec;//最小响应时间
			long m_intervalMaxMillisec;//最大响应时间
			long m_intervalTotalMillisec;//间隔内响应时间总数
			long *m_ptimeSection;

			UInt64 m_intervalFirstTranTime;//间隔内第一个任务的执行时间
			UInt64 m_intervalLastTranTime;//间隔内最后一次任务的执行时间

			StatData(unsigned int mStatTimeMaxSection,int mStatTimePrecisionSection);//初始化以上参数
			StatData(StatData &mStatData);
			~StatData();
	};



/**
 * 
 * Description ：事物统计类
 * Details     ：对机器人执行任务的情况进行统计
 */
class Stat :public AbstractThread{
	private:
		map<string,StatData*> m_statMap;
		unsigned long long m_total;  //所有的任务数
		long m_intervalCount; //周期内采样次数
		long m_interval;   //统计周期
		
		char *m_pDataFile;

		int  m_robotNum;   //启动的机器人数
		int  m_robotNumRun;//在线机器人数
        int  m_robotNumStop;//离线机器人数

		int  m_robotNumLast ;     //上次统计的机器人数
		int  m_robotNumRunLast;   //上次统计的在线机器人数
		int  m_robotNumStopLast;   //上次统计的离线机器人数

		UInt64 m_firstTranTime;
		UInt64 m_lastTranTime;

		UInt64 m_interval_firstTranTime; //
		UInt64 m_interval_endTranTime; //
		
		//分段统计事务数的参数
		static int timePrecision_section;//时间段精度，每段的时间范围 毫秒
		static int timeMax_section;//每个事务最大时间，超过该时间就设置为该时间， 毫秒
		static int timeSectionCount_section;//分段数 	
		
		BaseStatDataUpload *pStatDataUpload;
		DataProPkgUpload *pDataPkgUpload;

		bool m_allRobotInitDone;
		static Stat *  m_pStat;

		bool m_isInitSamplerSended; // init()初始化中的采样事务是否已全部发送
		int  m_RobotInitFunDoneNum; // init()函数执行完成的机器人数量
private: 	
	   Stat();
   public :
	   bool isStop;
	   ofstream m_osfDataFile;
	   long m_showStatCount;//统计的次数
	   long m_timeSectionCount;//分段数 毫秒
	   long m_statTimeMaxSection;
	   long m_statTimePrecisionSection;

	   //UInt64 m_lastSendTime;
	   UInt64 m_lastGapsTransTime; //上次发送事务消息的时间
	   UInt64 m_lastGapsStatTime;  //上次发送人数统计消息的时间
	
	   
	public:
		//Stat(unsigned int mStatTimeMaxSection,int mStatTimePrecisionSection);
	    static Stat * getInstance();
		static void releaseInstance();
		~Stat();
		double getTps(long totalNum, long time);	
	    void setAllRobotInitDone(bool allRobotInitDone);
		void setRobotNum(int robotNum);
		int  getRobotNum();
	   	
		void SetInterval(long interval);
		long GetInterval();
		void initDataFile();
		bool openDataFile();
		string getTimeInfo();
		void writeStatToFile(string strToWrite);
		string percentERR(long error,long count);
		void ShowStat();
		//线程执行的函数
		virtual void runThread();
		
		void  statGlobalData(Sampler & sampler,StatData * data,int time,UInt64 curDate);//单个事务全局数据统计
		void  statIntervalData(Sampler & sampler,StatData * data,int tTime,UInt64 curDate);//单个事务间隔内数据统计
		//jennachen
		void statAllTranData(UInt64 curDate);//综合事务统计 
		BaseStatDataUpload* getStatDataUpload();
		void setStateDataUpload(BaseStatDataUpload* stateDataUpload);

		DataProPkgUpload* getDataPkgUpload();
		void setDataProPkgUpload(DataProPkgUpload* dataProPkgUpload);

		StatDataTrans* getOneStatData(int id,string key, int percent90Time,string statDateTime,StatData data); 
		void getAllTransStatData(StatDataAlltrans * allTrans,int id,string statDateTime);

		void statGlobalData(Sampler samper,StatData &data);
		void statIntervalData(Sampler sampler,StatData &data);
		void statIntervalDataInit(StatData &data);
		
		//void statTimeDataSectoin(Sampler &sampler,StatData &data,int time);
		void statTimeDataSectoin(StatData &data,int time);
		int get90PercentTime(StatData &data);
		void addData(Sampler &pSampler);//增加统计数据 会多线程执行
		void updateRunningRobotNum(int changedNum);//会多个线程并发执行
		void updateStopRobotNum(int changedNum);//会多个线程并发执行
		
		int getRunningRobotNum();
		int getStoppedRobotNum();

		int getRobotNumLast();
		void setRobotNumLast(int num);

		void updateInitFunDoneNum(int changedNum);
		int  getInitFunDoneNum();

};
#endif
