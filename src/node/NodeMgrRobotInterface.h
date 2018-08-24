/**
*
* @file     NodeMgrRobotInterface.h
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

#ifndef __NODEMGRROBOTINTERFACE_H__
#define __NODEMGRROBOTINTERFACE_H__

#include "node/UploadData.h"
using namespace std;

/**
 * 需要节点管理的机器人必须实现该接口
 * @author honyliu
 *
 */
class NodeMgrRobotInterface
{
public:
	
	 //停止机器人
	virtual  void stopRobot()=0;
	 //机器人是否都已经停止
	virtual  bool isTestStop()=0;
	 //统计数据上传队列的大小，只有这个队列有数据才会取数据上传
	virtual int getStatDataUploadSize()=0 ;
	 //取一个数据进行上传
	virtual UploadData * getStatDataUploadOneMsg()=0;
	virtual ~NodeMgrRobotInterface(){}
};

#endif
