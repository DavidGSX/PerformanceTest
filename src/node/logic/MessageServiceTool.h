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
* Copyright (c)  2016-2017, ��Ѷ�Ƽ����޹�˾���������з���
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
 * Client ��Ϣ���������Ӧ��ϵ
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
	//ע����Ϣ
	void initMsg();
	void regeditMsg(int cmdid, AbstractService* service);

	//---------------���������࣬���Գ��������ʱ���Զ������õ���----------- 
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
	static CGarbo garbo; // ����һ����̬��Ա���ڳ������ʱ��ϵͳ�����������������

};

#endif