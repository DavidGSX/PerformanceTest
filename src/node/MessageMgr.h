/**
*
* @file     MessageMgr.h
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

#ifndef __MESSAGEMGR_H__
#define __MESSAGEMGR_H__

#include <string>
#include <list>
#include "core/Logger.h"
#include "protocal/cmd/BaseMsgCmdBiz.h"

using namespace std;
extern Logger g_logger;

#ifdef _WIN32
extern CRITICAL_SECTION g_MessMgrLock;
#else
extern pthread_mutex_t g_MessMgrLock;
#endif

class MessageMgr{
private:
	static MessageMgr* messageMgr;
	
	//���Ͷ���
	list<BaseMsgCmdBiz*> msgSendLst;
	//���ܶ���
	list<BaseMsgCmdBiz*> msgRecvLst;

	MessageMgr()
	{
	}

public:
	virtual ~MessageMgr(){}
	static MessageMgr* getInstance();
	/**
	   * ȡ�ý��ն��д�С
	   * @return
	   */
	  int getRecvMsgSize();
	  BaseMsgCmdBiz* getSendMsg();	 
	  void addRecvMsg(BaseMsgCmdBiz* msg);
	  void sendMsg(BaseMsgCmdBiz* msg);
	  ////////////////�����հ����/////////////////////////////
	  
	  
	  /**
	   * ����ͷȡһ��Ϣ
	   */
	 
	   BaseMsgCmdBiz* getRecvMsg();	  
	  /**
	   * �����հ�
	   * @param cmdid
	   * @return
	   */
	  
	    BaseMsgCmdBiz* recvMsgBlock(int cmdid);	  
	  /**
	   * �������հ�
	   * @param cmdid
	   * @return
	   */
	  BaseMsgCmdBiz* recvMsg(int cmdid);



	  //---------------���������࣬���Գ��������ʱ���Զ������õ���----------- 
	  class CGarbo
	  {
	  public:
		  ~CGarbo()
		  { 
			  if (MessageMgr::messageMgr)
			  {
				  delete MessageMgr::messageMgr;
			  }
			  g_logger.info("destory MessageMgr::messageMgr");

		  }
	  };
	  static CGarbo garbo; // ����һ����̬��Ա���ڳ������ʱ��ϵͳ�����������������
	 

};

#endif 

