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
* Copyright (c)  2016-2017, 腾讯科技有限公司互动娱乐研发部
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
	int type ;//0 综合事务 1单个事务
    double  total;//总事务数
	double  error;//错误事务数
	double  avgMillisec;//平均响应时间
	double  minMillisec;//最小响应时间
	double  maxMillisec;//最大响应时间
    double  totalMillisec;//响应时间总数
	double  firstTranTime;//第一个事务时间
	double  endTranTime;//最后一个事务的时间
	int   time90Percent;//90%响应时间
	//----间隔内数据----
	double  intervalTotal;//间隔内总事务数
	double  intervalError;//间隔内错误数
	double  intervalAvgMillisec;//间隔内平均响应时间
	double  intervalMinMillisec;//间隔内最小响应时间
	double  intervalMaxMillisec;//间隔内最大响应时间
	double  intervalTotalMillisec;//间隔内响应时间总数
	double  intervalFirstTranTime;//第一个事务时间
	double  intervalEndTranTime;//最后一个事务的时间
	string  action;
	
	string statDateTime;//统计时候的时间点
	
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