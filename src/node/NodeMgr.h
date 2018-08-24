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
* Copyright (c)  2016-2017, ��Ѷ�Ƽ����޹�˾���������з���
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
 * �ڵ���������߳�
 * �ڵ㶯���Ĵ�����ڣ�����ڵ������Ϣ���ڵ㷢����Ϣ
 * @author honyliu
 *
 */
class NodeMgr
{
private:
	MessageMgr * m_pMsgMgr;
	NodeMgrRobotInterface  * m_pTestRobot;//���Ի����˹�����
	NodeStatus::NodeStatusEnum  nodeStatus;
	MessageServiceTool  * m_pMsgServiceTool;
	
	string m_nodeId;//master�����ID
	int m_stat_interval;//ͳ�����ڣ���������master�ַ��������Ƕ�ȡ�����ļ��е�
	static int max_upload;

public:
	NodeMgr(MessageMgr* msgMgr,MessageServiceTool * pMsgServiceTool);
	~NodeMgr();
	
	/**
	* ���ӷ���������
	*/
	void  connMasterAction();

	/**
	* �ϴ����ݶ���
	*/
	void  uploadMasterAction();

	/**
	* �ڵ������ֹ֪ͣͨ ����
	* nodeֹͣ��֪ͨmaster
	*/
	void  stopNodeNotifyMasterAction();
  

	/**
	* �ڵ�ֹ֪ͣͨ  ����
	*/
	void  quitNodeNotifyMasterAction();
  
	/**
	* �ڵ���������
	* @param lastTime
	*/
    void  heartBeatAction();
	
	void sendMsg(BaseMsgCmdBiz* msg);
  
   /**
    * ֹͣ�����˶���
    * @return
    */ 
    bool  stopTestRobotAction();
	void  freeTestRobot();
	/**
	* ֹͣ�ڵ㶯��
	*/
	void quitNodeAction();
   
   /**
    * ����ذ���Ϣͳһ���
    * ÿ���ذ��Ĵ�������ע������ǰע�������д���
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
