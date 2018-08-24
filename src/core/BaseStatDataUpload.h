/**
*
* @file     BaseStatDataUpload.h
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

#ifndef __BASESTATDATAUPLOAD_H__
#define __BASESTATDATAUPLOAD_H__


#include <queue>
#include "core/AbstractThread.h"
#include "core/Sampler.h"
#include "node/UploadData.h"

class Stat;
class BaseStatDataUpload: public AbstractThread
{
protected:
	queue<UploadData*> m_msgqueue;
	queue<Sampler> m_samplerque; //����������ݵĶ���
	bool stateDataUpload_isUpload  ;  //�ϴ�����
    bool gaps_isUpload;
	Stat  *m_pStat ;

public:
	bool isStop;
	static int transCount;

public:
	BaseStatDataUpload();
	~BaseStatDataUpload();
	void addMsg(UploadData* msg);
	UploadData* getMsg();
	int msgSize();

	void addSampler(Sampler Pkg);
	Sampler getSampler();
	int samplerSize();

	void sendSampleQue();

	bool isStatDataUpload();
	bool isGapsDataUpload();

	void setStop(bool isStop);
	virtual void setStat(Stat  * pStat);
	virtual void runThread();//�߳����������еĺ���
	
};

#endif