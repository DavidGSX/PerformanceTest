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
* Copyright (c)  2016-2017, ��Ѷ�Ƽ����޹�˾���������з���
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
 * Description ��������
 * Details     ����¼ͳ����Ϣ
 */
class StatData {
		public:
			unsigned long long  m_total;//��������
			long  m_error;//����������
			long  m_avgMillisec;//ƽ����Ӧʱ��
			long  m_minMillisec;//��С��Ӧʱ��
			long  m_maxMillisec;//�����Ӧʱ��
			long  m_totalMillisec;//��Ӧʱ������
			long m_timeSectionCount;
			long m_statTimeMaxSection;
			long m_statTimePrecisionSection;

			UInt64 m_firstTranTime;//��һ�������ʱ��
			UInt64 m_lastTranTime;//���һ�������

			//���������
			long m_intervalTotal;//�������������
			long m_intervalError;//����ڴ�����
			long m_intervalAvgMillisec;//�����ƽ��Ӧʱ��
			long m_intervalMinMillisec;//��С��Ӧʱ��
			long m_intervalMaxMillisec;//�����Ӧʱ��
			long m_intervalTotalMillisec;//�������Ӧʱ������
			long *m_ptimeSection;

			UInt64 m_intervalFirstTranTime;//����ڵ�һ�������ִ��ʱ��
			UInt64 m_intervalLastTranTime;//��������һ�������ִ��ʱ��

			StatData(unsigned int mStatTimeMaxSection,int mStatTimePrecisionSection);//��ʼ�����ϲ���
			StatData(StatData &mStatData);
			~StatData();
	};



/**
 * 
 * Description ������ͳ����
 * Details     ���Ի�����ִ��������������ͳ��
 */
class Stat :public AbstractThread{
	private:
		map<string,StatData*> m_statMap;
		unsigned long long m_total;  //���е�������
		long m_intervalCount; //�����ڲ�������
		long m_interval;   //ͳ������
		
		char *m_pDataFile;

		int  m_robotNum;   //�����Ļ�������
		int  m_robotNumRun;//���߻�������
        int  m_robotNumStop;//���߻�������

		int  m_robotNumLast ;     //�ϴ�ͳ�ƵĻ�������
		int  m_robotNumRunLast;   //�ϴ�ͳ�Ƶ����߻�������
		int  m_robotNumStopLast;   //�ϴ�ͳ�Ƶ����߻�������

		UInt64 m_firstTranTime;
		UInt64 m_lastTranTime;

		UInt64 m_interval_firstTranTime; //
		UInt64 m_interval_endTranTime; //
		
		//�ֶ�ͳ���������Ĳ���
		static int timePrecision_section;//ʱ��ξ��ȣ�ÿ�ε�ʱ�䷶Χ ����
		static int timeMax_section;//ÿ���������ʱ�䣬������ʱ�������Ϊ��ʱ�䣬 ����
		static int timeSectionCount_section;//�ֶ��� 	
		
		BaseStatDataUpload *pStatDataUpload;
		DataProPkgUpload *pDataPkgUpload;

		bool m_allRobotInitDone;
		static Stat *  m_pStat;

		bool m_isInitSamplerSended; // init()��ʼ���еĲ��������Ƿ���ȫ������
		int  m_RobotInitFunDoneNum; // init()����ִ����ɵĻ���������
private: 	
	   Stat();
   public :
	   bool isStop;
	   ofstream m_osfDataFile;
	   long m_showStatCount;//ͳ�ƵĴ���
	   long m_timeSectionCount;//�ֶ��� ����
	   long m_statTimeMaxSection;
	   long m_statTimePrecisionSection;

	   //UInt64 m_lastSendTime;
	   UInt64 m_lastGapsTransTime; //�ϴη���������Ϣ��ʱ��
	   UInt64 m_lastGapsStatTime;  //�ϴη�������ͳ����Ϣ��ʱ��
	
	   
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
		//�߳�ִ�еĺ���
		virtual void runThread();
		
		void  statGlobalData(Sampler & sampler,StatData * data,int time,UInt64 curDate);//��������ȫ������ͳ��
		void  statIntervalData(Sampler & sampler,StatData * data,int tTime,UInt64 curDate);//����������������ͳ��
		//jennachen
		void statAllTranData(UInt64 curDate);//�ۺ�����ͳ�� 
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
		void addData(Sampler &pSampler);//����ͳ������ ����߳�ִ��
		void updateRunningRobotNum(int changedNum);//�����̲߳���ִ��
		void updateStopRobotNum(int changedNum);//�����̲߳���ִ��
		
		int getRunningRobotNum();
		int getStoppedRobotNum();

		int getRobotNumLast();
		void setRobotNumLast(int num);

		void updateInitFunDoneNum(int changedNum);
		int  getInitFunDoneNum();

};
#endif
