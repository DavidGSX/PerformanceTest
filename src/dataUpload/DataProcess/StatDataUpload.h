/**
*
* @file     StatDataUpload.h
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

#ifndef __STATDATAUPLOAD_H__
#define __STATDATAUPLOAD_H__

#include <queue>
#include "core/CommonFunction.h"
#include "protocal/SprProtocal.h"
#include "dataUpload/DataProcess/SprClientAPI.h"
#include "dataUpload/Messages/StatDataProcessReq.h"
#include "core/BaseStatDataUpload.h"
#include "protocal/tdr/TdrData.h"

using namespace std;

/**
*  ��Ϣ�ϴ��࣬��Ҫά��һ����Ϣ���У����������Ϣ��ȡ����Ϣ��������Ϣ
*/
class StatDataUpload:public BaseStatDataUpload
{
private:
	SprClientAPI*   m_pSprClientAPI;
public:
	StatDataUpload(void);
	~StatDataUpload(void);
	StatDataProcessReq* getMsgOfReq();
	void sendMsg(StatDataProcessReq* req);
	virtual void doWork();
	virtual void runThread();//�߳�ִ���߼�
};

#endif


