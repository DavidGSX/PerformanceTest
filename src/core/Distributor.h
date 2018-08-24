/**
*
* @file     Distributor.h
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

#pragma once
#include <list>
#include <iostream>
#include "core/CommonFunction.h"
#include  "core/DataTypeDefine.h"

using namespace  std;
/**
*  数据分配类
*  1.把长度一定的时间分割为N块（可视为一个时间轮）
*  2.把一定的任务数尽量均匀地分配到这N个时间块之内
*  3.处理任务数为0的时间块
*  4.通过转动时间轮的方法来控制tps
*/
class Distributor
{
private:
	int m_sectionNum;//初始时间的分片数
	int m_intervalTime;//时间块大小
	int m_totalTimeInMsec;//总时间块大小
	int m_jobNum;//总时间块内的任务数
	int *m_pSectionTime;//初始时间块分布情况
	int *m_pDistributedJobNum;//初始任务分配情况
	int m_jobCounter;//时间section内放行任务数的计数器
	int m_sectionCounter;//时间seciotn记数器
	UInt64 m_lastTime;//上一次转动时间轮的时间
	int getListValue(int index,list<int>*pList);
	void setExtraJobToRandSections(int extraJobNum);
	void rearrangeJobs();//处理时间section内任务数为0的情况
	int m_realSectionNum;//最终时间块分块数
	int *m_pRealSectionTime;//最终时间块分布情况
	int *m_pRealDistributedJobNum;//最终任务在各个时间块的分布情况

public:
	Distributor(int sectionNum, int totalTime, int JobNum);
	~Distributor();
	void arrangeJobs();//将任务尽量均匀地分配到各个时间块内
	void turn();//转动时间轮，起到控制tps的作用
};

