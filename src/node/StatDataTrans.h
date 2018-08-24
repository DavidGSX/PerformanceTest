/**
*
* @file     StatDataTrans.h
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
#ifndef __STATDATATRANS_H__
#define __STATDATATRANS_H__

#include <string>
using namespace std;

class StatDataTrans
{
public:
	int id;
	int type ;//0 �ۺ����� 1��������
    double  total;//��������
	double  error;//����������
	double  avgMillisec;//ƽ����Ӧʱ��
	double  minMillisec;//��С��Ӧʱ��
	double  maxMillisec;//�����Ӧʱ��
    double  totalMillisec;//��Ӧʱ������
	double  firstTranTime;//��һ������ʱ��
	double  endTranTime;//���һ�������ʱ��
	int   time90Percent;//90%��Ӧʱ��
	//----���������----
	double  intervalTotal;//�������������
	double  intervalError;//����ڴ�����
	double  intervalAvgMillisec;//�����ƽ����Ӧʱ��
	double  intervalMinMillisec;//�������С��Ӧʱ��
	double  intervalMaxMillisec;//����������Ӧʱ��
	double  intervalTotalMillisec;//�������Ӧʱ������
	double  intervalFirstTranTime;//��һ������ʱ��
	double  intervalEndTranTime;//���һ�������ʱ��
	string  action;
	
	string statDateTime;//ͳ��ʱ���ʱ���
	
	int getId()
	{
		return id;
	}
	
	void setId(int id) 
	{
		this->id = id;
	}
	
	int getType() 
	{
		return type;
	}
	
	void setType(int type)
	{
		this->type = type;
	}
	
	double getTotal()
	{
		return total;
	}
	
	void setTotal(double total)
	{
		this->total = total;
	}
	
	double getError() 
	{
		return error;
	}
	
	void setError(double error) 
	{
		this->error = error;
	}
	
	double getAvgMillisec() 
	{
		return avgMillisec;
	}
	
	void setAvgMillisec(double avgMillisec) 
	{
		this->avgMillisec = avgMillisec;
	}
	
	double getMinMillisec() 
	{
		return minMillisec;
	}
	
	void setMinMillisec(double minMillisec) 
	{
		this->minMillisec = minMillisec;
	}
	
	double getMaxMillisec() 
	{
		return maxMillisec;
	}
	
	void setMaxMillisec(double maxMillisec)
	{
		this->maxMillisec = maxMillisec;
	}
	
	double getTotalMillisec()
	{
		return totalMillisec;
	}
	
	void setTotalMillisec(double totalMillisec) 
	{
		this->totalMillisec = totalMillisec;
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
	
	double getIntervalError()
	{
		return intervalError;
	}
	
	void setIntervalError(double intervalError)
	{
		this->intervalError = intervalError;
	}
	
	double getIntervalMinMillisec() 
	{
		return intervalMinMillisec;
	}
	
	void setIntervalMinMillisec(double intervalMinMillisec) 
	{
		this->intervalMinMillisec = intervalMinMillisec;
	}
	
	double getIntervalMaxMillisec() 
	{
		return intervalMaxMillisec;
	}
	
	void setIntervalMaxMillisec(double intervalMaxMillisec) 
	{
		this->intervalMaxMillisec = intervalMaxMillisec;
	}
	
	double getIntervalTotalMillisec()
	{
		return intervalTotalMillisec;
	}
	
	void setIntervalTotalMillisec(double intervalTotalMillisec) 
	{
		this->intervalTotalMillisec = intervalTotalMillisec;
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
		this->intervalEndTranTime = intervalEndTranTime;
	}
	
	string getAction() 
	{
		return action;
	}
	
	void setAction(string action) 
	{
		this->action = action;
	}
	
	int getTime90Percent() 
	{
		return time90Percent;
	}
	
	void setTime90Percent(int time90Percent)
	{
		this->time90Percent = time90Percent;
	}
	
	double getIntervalAvgMillisec()
	{
		return intervalAvgMillisec;
	}
	
	void setIntervalAvgMillisec(double intervalAvgMillisec) 
	{
		this->intervalAvgMillisec = intervalAvgMillisec;
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