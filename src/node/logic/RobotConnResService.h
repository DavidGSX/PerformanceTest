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
* Copyright (c)  2016-2017, 腾讯科技有限公司互动娱乐研发部
* All rights reserved.
*
*/

#ifndef __ROBOTCONNRESSERVICE_H__
#define __ROBOTCONNRESSERVICE_H__

#include "node/logic/AbstractService.h"
#include "protocal/cmd/BaseMsgCmdBiz.h"

/**
 * 连接master回包处理逻辑
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
