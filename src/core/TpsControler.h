/**
*
* @file     TpsControler.h
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
#include <string>
#include <map>
#include <iostream>
#include "core/CommonFunction.h"
#include "core/Distributor.h"

#define MAX_LOCK_NUM                    200  //最大的事务锁数量
#define TIME_SECTION_NUM                100  //时间片数量
#define TPS_CRITICAL                    10   //tps处理的临界点，高于这个值的采用时间片分割的方法，低于这个值的直接计算每次任务执行后需要休眠的时间
#define TPS_CONTROL_TOTAL_SECTION_LEN   1000 //控制tps的基本时间，一般设置为1000ms

using namespace std;


class Distributor;
/*
* 数据辅助类
*/
class TpsData
{
public:
	double      tps;//事务对应的tps
	int         lockIndex;//事务对应的锁的下标
	Distributor *pDstributor;
};

/*
*   数据辅助类
*/
class DataMap
{

private:
	map<string, TpsData*> * m_pMapKey2TpsData;	
public:
	DataMap();
	~DataMap();
	/**
	*  插入数据
	*/
	void insertData(string key, TpsData* pTpsData);
	/**
	*  查找数据
	*/
	void findItemBykey(string key,map<string, TpsData*>::iterator *pIter, bool *keyIsInMap);

};

/**
*   tps控制类
*/
class TpsControler
{
private:
	static TpsControler *  m_pTpsControler;
	DataMap* m_pDataMap;
private:
	 TpsControler();	
public:
	static TpsControler* getInstance();
	static void releaseInstance();

	~TpsControler();
	int m_lockCounter;

	//注册tps控制信息
	void setTps(string key,double tps);
	//对线程锁进行初始化操作
	int initLocks();
	//检测是否进行tps控制
	void controlTps(string key);
	//执行tps控制
	void tpsOver0(string key);
};





