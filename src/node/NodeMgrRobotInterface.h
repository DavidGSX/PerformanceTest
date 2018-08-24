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
* Copyright (c)  2016-2017, ��Ѷ�Ƽ����޹�˾���������з���
* All rights reserved.
*
*/

#ifndef __NODEMGRROBOTINTERFACE_H__
#define __NODEMGRROBOTINTERFACE_H__

#include "node/UploadData.h"
using namespace std;

/**
 * ��Ҫ�ڵ����Ļ����˱���ʵ�ָýӿ�
 * @author honyliu
 *
 */
class NodeMgrRobotInterface
{
public:
	
	 //ֹͣ������
	virtual  void stopRobot()=0;
	 //�������Ƿ��Ѿ�ֹͣ
	virtual  bool isTestStop()=0;
	 //ͳ�������ϴ����еĴ�С��ֻ��������������ݲŻ�ȡ�����ϴ�
	virtual int getStatDataUploadSize()=0 ;
	 //ȡһ�����ݽ����ϴ�
	virtual UploadData * getStatDataUploadOneMsg()=0;
	virtual ~NodeMgrRobotInterface(){}
};

#endif
