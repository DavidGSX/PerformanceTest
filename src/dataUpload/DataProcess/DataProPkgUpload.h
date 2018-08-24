/**
*
* @file     DataProPkgUpload.h
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

#ifndef __DATAPROPKGUPLOAD_H__
#define __DATAPROPKGUPLOAD_H__

#include <queue>
#include "core/BaseStatDataUpload.h"

using namespace std;

/**
*  ��Ϣ�ϴ��࣬��Ҫά��һ����Ϣ���У����������Ϣ��ȡ����Ϣ��������Ϣ
*/
class DataProPkgUpload:public BaseStatDataUpload
{
protected:
	bool gaps_isUpload;
	queue<string> m_gapsmsgqueue;
	queue<Sampler> m_samplerque; //����������ݵĶ���
	//static int count;

public:
	bool isGapsStop;

	DataProPkgUpload(void);
	~DataProPkgUpload(void);

	void addSampler(Sampler Pkg);
	Sampler getSampler();
	int samplerSize();

	void addGapsMsg(string data);
	string getGapsMsg();
	int gapsMsgSize();

	bool isGapsDataUpload();
	void setStop(bool isStop);

	virtual void doWork();
	virtual void runThread();//�߳�ִ���߼�
};

#endif

