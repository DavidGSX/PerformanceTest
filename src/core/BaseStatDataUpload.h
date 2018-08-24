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
* Copyright (c)  2016-2017, 腾讯科技有限公司互动娱乐研发部
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
	queue<Sampler> m_samplerque; //保存采样数据的队列
	bool stateDataUpload_isUpload  ;  //上传开关
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
	virtual void runThread();//线程启动后运行的函数
	
};

#endif