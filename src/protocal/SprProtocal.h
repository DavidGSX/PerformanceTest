/**
*
* @file     SprProtocal.h
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

#ifndef __SPRPROTOCAL_H__
#define __SPRPROTOCAL_H__

/**
*  ���������������Ϣ���͵Ķ���
*/

/**
*  ����ͳ����Ϣ����Ϣ
*/
#define DP_STATDATAPROCESS "dp_StatDataProcessAction"

/**
*  ��ʼ���Ե���Ϣ
*/
#define DP_STARTTEST       "dp_StartTestAction"

/**
*  �������Ե���Ϣ
*/
#define DP_ENDTEST         "dp_endTestAction"

/*******��ΪNODEģ�����Ϣ */
#define SprProtocal_master_showReq           10000
#define SprProtocal_master_showRes           10001
#define SprProtocal_master_robotConnReq      10002
#define SprProtocal_master_robotConnRes      10003
#define SprProtocal_master_robotUploadReq    10004
#define SprProtocal_master_robotUploadRes    10005
#define SprProtocal_master_robotHeartBeatReq 10006

#define SprProtocal_robot_startReq 20000
#define SprProtocal_robot_startRes 20001
#define SprProtocal_robot_stopReq  20002
#define SprProtocal_robot_stopRes  20003
#define SprProtocal_robot_quitReq  20004
#define SprProtocal_robot_quitRes  20005

class BaseMsgCmdBiz;

class SprProtocal
{
	public:
    //��ȡNODE����Ϣʵ��
   static BaseMsgCmdBiz *  getMsgBizCmd(int cmdid);
};

#endif