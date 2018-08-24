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
* Copyright (c)  2016-2017, 腾讯科技有限公司互动娱乐研发部
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
	
	//发送队列
	list<BaseMsgCmdBiz*> msgSendLst;
	//接受队列
	list<BaseMsgCmdBiz*> msgRecvLst;

	MessageMgr()
	{
	}

public:
	virtual ~MessageMgr(){}
	static MessageMgr* getInstance();
	/**
	   * 取得接收队列大小
	   * @return
	   */
	  int getRecvMsgSize();
	  BaseMsgCmdBiz* getSendMsg();	 
	  void addRecvMsg(BaseMsgCmdBiz* msg);
	  void sendMsg(BaseMsgCmdBiz* msg);
	  ////////////////队列收包相关/////////////////////////////
	  
	  
	  /**
	   * 队列头取一消息
	   */
	 
	   BaseMsgCmdBiz* getRecvMsg();	  
	  /**
	   * 阻塞收包
	   * @param cmdid
	   * @return
	   */
	  
	    BaseMsgCmdBiz* recvMsgBlock(int cmdid);	  
	  /**
	   * 非阻塞收包
	   * @param cmdid
	   * @return
	   */
	  BaseMsgCmdBiz* recvMsg(int cmdid);



	  //---------------定义析构类，可以程序结束的时候自动析构该单例----------- 
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
	  static CGarbo garbo; // 声明一个静态成员，在程序结束时，系统会调用它的析构函数
	 

};

#endif 

