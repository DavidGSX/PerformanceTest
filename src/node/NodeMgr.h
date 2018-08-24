/**
*
* @file     NodeMgr.h
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

#ifndef __NODEMGR_H__
#define __NODEMGR_H__

#include "node/MessageMgr.h"
#include "node/NodeStatus.h"
#include "core/Test.h"
#include "protocal/cmd/BaseMsgCmdBiz.h"
#include "node/NodeMgrRobotInterface.h"
#include "node/logic/MessageServiceTool.h"

using namespace std;

/**
 * 节点管理器主线程
 * 节点动作的处理入口，比如节点接收消息、节点发送消息
 * @author honyliu
 *
 */
class NodeMgr
{
private:
	MessageMgr * m_pMsgMgr;
	NodeMgrRobotInterface  * m_pTestRobot;//测试机器人管理类
	NodeStatus::NodeStatusEnum  nodeStatus;
	MessageServiceTool  * m_pMsgServiceTool;
	
	string m_nodeId;//master分配的ID
	int m_stat_interval;//统计周期，该周期由master分发，而不是读取配置文件中的
	static int max_upload;

public:
	NodeMgr(MessageMgr* msgMgr,MessageServiceTool * pMsgServiceTool);
	~NodeMgr();
	
	/**
	* 连接服务器动作
	*/
	void  connMasterAction();

	/**
	* 上传数据动作
	*/
	void  uploadMasterAction();

	/**
	* 节点机器人停止通知 动作
	* node停止，通知master
	*/
	void  stopNodeNotifyMasterAction();
  

	/**
	* 节点停止通知  动作
	*/
	void  quitNodeNotifyMasterAction();
  
	/**
	* 节点心跳动作
	* @param lastTime
	*/
    void  heartBeatAction();
	
	void sendMsg(BaseMsgCmdBiz* msg);
  
   /**
    * 停止机器人动作
    * @return
    */ 
    bool  stopTestRobotAction();
	void  freeTestRobot();
	/**
	* 停止节点动作
	*/
	void quitNodeAction();
   
   /**
    * 处理回包消息统一入口
    * 每个回包的处理函数由注册启动前注册的类进行处理
    * @return
    */
	int proc();
	static void  doWork();
    string getNodeId();
	void setNodeId(string nodeId);
	int getStat_interval();
	void setStat_interval(int stat_interval);
	void setNodeStatus(NodeStatus::NodeStatusEnum status);
	NodeStatus::NodeStatusEnum getNodeStatus();
	NodeMgrRobotInterface * getTestRobot(); 
	void setTestRobot(NodeMgrRobotInterface * testRobot); 

};

#endif
