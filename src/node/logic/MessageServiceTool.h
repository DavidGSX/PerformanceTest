/**
*
* @file     MessageServiceTool.h
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

#ifndef __MESSAGESERVICETOOL_H__
#define __MESSAGESERVICETOOL_H__

#include "node/logic/AbstractService.h"
#include "node/logic/RobotConnResService.h"
#include "node/logic/RobotStartReqService.h"
#include "node/logic/RobotStopReqService.h"
#include "node/logic/RobotUploadResService.h"
#include "node/logic/RobotQuitReqService.h"

#include "node/messages/RobotConnectReq.h"
#include "node/messages/RobotConnectRes.h"
#include "node/messages/RobotUploadRes.h"
#include "node/messages/StartRobotReq.h"
#include "node/messages/StopRobotReq.h"
#include "node/messages/QuitRobotReq.h"

#include <map>
#include "core/Logger.h"

extern Logger g_logger;

using namespace std;

/**
 * Client 消息跟处理类对应关系
 *
 */
class MessageServiceTool
{
private:
	static MessageServiceTool* pMsgserviceTool;
	
	map<int,AbstractService*>  m_mapMsgService;	
	MessageServiceTool();
public:
	~MessageServiceTool();	
	static MessageServiceTool* getInstance();
	AbstractService* getMsgServiceInstance(int cmdid);
	//注册消息
	void initMsg();
	void regeditMsg(int cmdid, AbstractService* service);

	//---------------定义析构类，可以程序结束的时候自动析构该单例----------- 
	class CGarbo
	{
	public:
		~CGarbo()
		{ 
			if (MessageServiceTool::pMsgserviceTool)
			{
				delete MessageServiceTool::pMsgserviceTool;
			}
			g_logger.info("destory MessageServiceTool::pMsgserviceTool");
				
		}
	};
private :
	static CGarbo garbo; // 声明一个静态成员，在程序结束时，系统会调用它的析构函数

};

#endif