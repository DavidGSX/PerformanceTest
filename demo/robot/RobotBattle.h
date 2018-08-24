/**
*
* @file     RobotBattle.h
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

#ifndef __ROBOTBATTLE_H__
#define __ROBOTBATTLE_H__

#include <string>
#include <vector>
#include "core/AbstractRobot.h"
#include "core/Sampler.h"

#include "scene/GameAPI.h"


using namespace std;


/**
 * 
 * Description ：客户机器人
 *              机器人登录进去后，重复的执行开始游戏、结束游戏
 * Details     ：1、负责实现机器人初始化逻辑Robot
 *               2、负责实现机器人初始化动作逻辑init
 *               3、负责实现机器人执行动作逻辑runAction
 */
class  RobotBattle : public AbstractRobot
{
public:
	 GameAPI *m_pGameAPI;
	 RobotBattle(int index,long tranTotal);
	 //机器人行为，由客户实现
	 virtual int runAction();
	 virtual bool init();
	 ~RobotBattle();

};

#endif





