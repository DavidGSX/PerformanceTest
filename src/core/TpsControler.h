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
* Copyright (c)  2016-2017, ��Ѷ�Ƽ����޹�˾���������з���
* All rights reserved.
*
*/

#pragma once
#include <string>
#include <map>
#include <iostream>
#include "core/CommonFunction.h"
#include "core/Distributor.h"

#define MAX_LOCK_NUM                    200  //��������������
#define TIME_SECTION_NUM                100  //ʱ��Ƭ����
#define TPS_CRITICAL                    10   //tps������ٽ�㣬�������ֵ�Ĳ���ʱ��Ƭ�ָ�ķ������������ֵ��ֱ�Ӽ���ÿ������ִ�к���Ҫ���ߵ�ʱ��
#define TPS_CONTROL_TOTAL_SECTION_LEN   1000 //����tps�Ļ���ʱ�䣬һ������Ϊ1000ms

using namespace std;


class Distributor;
/*
* ���ݸ�����
*/
class TpsData
{
public:
	double      tps;//�����Ӧ��tps
	int         lockIndex;//�����Ӧ�������±�
	Distributor *pDstributor;
};

/*
*   ���ݸ�����
*/
class DataMap
{

private:
	map<string, TpsData*> * m_pMapKey2TpsData;	
public:
	DataMap();
	~DataMap();
	/**
	*  ��������
	*/
	void insertData(string key, TpsData* pTpsData);
	/**
	*  ��������
	*/
	void findItemBykey(string key,map<string, TpsData*>::iterator *pIter, bool *keyIsInMap);

};

/**
*   tps������
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

	//ע��tps������Ϣ
	void setTps(string key,double tps);
	//���߳������г�ʼ������
	int initLocks();
	//����Ƿ����tps����
	void controlTps(string key);
	//ִ��tps����
	void tpsOver0(string key);
};





