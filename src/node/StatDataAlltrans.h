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
* Copyright (c)  2016-2017, ��Ѷ�Ƽ����޹�˾���������з���
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
	//---��ʼ�������������ڵ�ͳ������

	int robotNumTotal ;//���û�������
	int robotNumRun  ;//���߻�������
	int robotNumStop ;//���߻�������
	double total ;	//����������  
	double  firstTranTime;//��һ������ʱ��
	double  endTranTime;//���һ�������ʱ��
	 
	string statDateTime;//ͳ��ʱ���ʱ���
	 
	 //----��������ڵ�ͳ������-----	
	 double intervalTotal ; //�����ڵ���Ϣ�� ����
	 double  intervalFirstTranTime;//��һ������ʱ��
	 double  intervalEndTranTime;//���һ�������ʱ��

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