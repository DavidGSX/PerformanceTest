/**
*
* @file     AbstractService.h
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

#ifndef __ABSTRACTSERVICE_H__
#define __ABSTRACTSERVICE_H__

#include "protocal/cmd/BaseMsgCmdBiz.h"

class NodeMgr;

using namespace std;

class AbstractService
{
protected:
	NodeMgr *nodeMgr;
public:
	AbstractService();
	virtual ~AbstractService();
	virtual void doCmd(BaseMsgCmdBiz* msgBiz);
	void setNodeMgr(NodeMgr* nodeMgr);
	NodeMgr* getNodeMgr(); 
	
};
#endif
