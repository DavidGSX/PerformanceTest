/**
*
* @file     RobotConnResService.h
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

#ifndef __ROBOTCONNRESSERVICE_H__
#define __ROBOTCONNRESSERVICE_H__

#include "node/logic/AbstractService.h"
#include "protocal/cmd/BaseMsgCmdBiz.h"

/**
 * ����master�ذ������߼�
 *
 */
class RobotConnResService:public AbstractService
{
public:
	void doCmd(BaseMsgCmdBiz* msgBiz);
	RobotConnResService();
	virtual ~RobotConnResService();
};
#endif // !__ROBOTCONNRESSERVICE_H__
