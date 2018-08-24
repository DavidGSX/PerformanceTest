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
* Copyright (c)  2016-2017, 腾讯科技有限公司互动娱乐研发部
* All rights reserved.
*
*/

#ifndef __SPRPROTOCAL_H__
#define __SPRPROTOCAL_H__

/**
*  与服务器交互的消息类型的定义
*/

/**
*  传输统计信息的消息
*/
#define DP_STATDATAPROCESS "dp_StatDataProcessAction"

/**
*  开始测试的消息
*/
#define DP_STARTTEST       "dp_StartTestAction"

/**
*  结束测试的消息
*/
#define DP_ENDTEST         "dp_endTestAction"

/*******作为NODE模块的消息 */
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
    //获取NODE的消息实例
   static BaseMsgCmdBiz *  getMsgBizCmd(int cmdid);
};

#endif