/**
*
* @file     StatDataAlltrans.h
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

#ifndef __STATDATAALLTRANS_H__
#define __STATDATAALLTRANS_H__

#include <string>
using namespace std;

class StatDataAlltrans
{
public:
	int id;
	//---开始测试以来到现在的统计数据

	int robotNumTotal ;//配置机器人数
	int robotNumRun  ;//在线机器人数
	int robotNumStop ;//离线机器人数
	double total ;	//总体事务数  
	double  firstTranTime;//第一个事务时间
	double  endTranTime;//最后一个事务的时间
	 
	string statDateTime;//统计时候的时间点
	 
	 //----间隔周期内的统计数据-----	
	 double intervalTotal ; //周期内的消息数 周期
	 double  intervalFirstTranTime;//第一个事务时间
	 double  intervalEndTranTime;//最后一个事务的时间

	 int getId() {
		return id;
	}

	 void setId(int id) 
	 {
		this->id = id;
	 }

	 int getRobotNumTotal() 
	 {
		return robotNumTotal;
	 }
	
	 void setRobotNumTotal(int robotNumTotal) 
	 {
		this->robotNumTotal = robotNumTotal;
	 }

	 int getRobotNumRun() 
	 {
		return robotNumRun;
	 }

	 void setRobotNumRun(int robotNumRun) 
	 {
		this->robotNumRun = robotNumRun;
	 }
	  
	 int getRobotNumStop() 
	 {
		return robotNumStop;
	 } 

	 void setRobotNumStop(int robotNumStop)
	 {
		this->robotNumStop = robotNumStop;
	 }

	 double getTotal() 
	 {
		return total;
	 }

	
	 void setTotal(double total) 
	 {
		this->total = total;
	 }
	
	 double getFirstTranTime() 
	 {
		return firstTranTime;
	 }
	
	 void setFirstTranTime(double firstTranTime) 
	 {
		this->firstTranTime = firstTranTime;
	 }
    
	 double getEndTranTime() 
	 {
		return endTranTime;
	 }
	 
	 void setEndTranTime(double endTranTime)
	 {
		this->endTranTime = endTranTime;
	 }
	
	 double getIntervalTotal()
	 {
		return intervalTotal;
	 }

	 void setIntervalTotal(double intervalTotal) 
	 {
		this->intervalTotal = intervalTotal;
	 }

	 double getIntervalFirstTranTime()
	 {
		return intervalFirstTranTime;
	 }
	
	 void setIntervalFirstTranTime(double intervalFirstTranTime)
	 {
		this->intervalFirstTranTime = intervalFirstTranTime;
	 }
	
	 double getIntervalEndTranTime()
	 {
		return intervalEndTranTime;
	 }

	 void setIntervalEndTranTime(double intervalEndTranTime) 
	 {
		intervalEndTranTime = intervalEndTranTime;
	 }

	 string getStatDateTime() 
	 {
		return statDateTime;
	 }
	 
	 void setStatDateTime(string statDateTime) 
	 {
		this->statDateTime = statDateTime;
	 }
};

#endif