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
* Copyright (c)  2016-2017, 腾讯科技有限公司互动娱乐研发部
* All rights reserved.
*
*/

#ifndef __DATAPROPKGUPLOAD_H__
#define __DATAPROPKGUPLOAD_H__

#include <queue>
#include "core/BaseStatDataUpload.h"

using namespace std;

/**
*  消息上传类，主要维护一个消息队列，包括添加消息、取出消息、发送消息
*/
class DataProPkgUpload:public BaseStatDataUpload
{
protected:
	bool gaps_isUpload;
	queue<string> m_gapsmsgqueue;
	queue<Sampler> m_samplerque; //保存采样数据的队列
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
	virtual void runThread();//线程执行逻辑
};

#endif

