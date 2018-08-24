/**
*
* @file     RobotLogin.h
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

#ifndef __ROBOTLOGIN_H__
#define __ROBOTLOGIN_H__

#include <string>
#include <vector>
#include "core/AbstractRobot.h"
#include "core/Sampler.h"

#include "scene/GameAPI.h"


using namespace std;

/**
 * 
 * Description ：机器人类
 * Details     ：执行用户自定义的事务
 */
class  RobotLogin : public AbstractRobot
{
public:
	 bool m_isRobotFirstRun;
	 GameAPI *m_pGameAPI;
	 RobotLogin(int index,long tranTotal);
	 //机器人行为，由客户实现
	 virtual int runAction();
	 virtual bool init();
	 //机器人执行完runAction()循环后做的动作，仅执行一次
	 virtual bool close();
	 ~RobotLogin();

};


#endif





