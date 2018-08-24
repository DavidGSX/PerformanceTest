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
* Copyright (c)  2016-2017, ��Ѷ�Ƽ����޹�˾���������з���
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
*  ���ݷ�����
*  1.�ѳ���һ����ʱ��ָ�ΪN�飨����Ϊһ��ʱ���֣�
*  2.��һ�����������������ȵط��䵽��N��ʱ���֮��
*  3.����������Ϊ0��ʱ���
*  4.ͨ��ת��ʱ���ֵķ���������tps
*/
class Distributor
{
private:
	int m_sectionNum;//��ʼʱ��ķ�Ƭ��
	int m_intervalTime;//ʱ����С
	int m_totalTimeInMsec;//��ʱ����С
	int m_jobNum;//��ʱ����ڵ�������
	int *m_pSectionTime;//��ʼʱ���ֲ����
	int *m_pDistributedJobNum;//��ʼ����������
	int m_jobCounter;//ʱ��section�ڷ����������ļ�����
	int m_sectionCounter;//ʱ��seciotn������
	UInt64 m_lastTime;//��һ��ת��ʱ���ֵ�ʱ��
	int getListValue(int index,list<int>*pList);
	void setExtraJobToRandSections(int extraJobNum);
	void rearrangeJobs();//����ʱ��section��������Ϊ0�����
	int m_realSectionNum;//����ʱ���ֿ���
	int *m_pRealSectionTime;//����ʱ���ֲ����
	int *m_pRealDistributedJobNum;//���������ڸ���ʱ���ķֲ����

public:
	Distributor(int sectionNum, int totalTime, int JobNum);
	~Distributor();
	void arrangeJobs();//�����������ȵط��䵽����ʱ�����
	void turn();//ת��ʱ���֣��𵽿���tps������
};

