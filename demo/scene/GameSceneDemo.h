/**
*
* @file     GameSceneDemo.h
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

#ifndef __GAMESCENEDEMO_H__
#define __GAMESCENEDEMO_H__

#include <iostream>
using namespace std;


/**
 * 场景DEMO
 * 由开发角色实现
 * 1、目的
 *   方便不依赖性能框架而独立调试场景
 *   方便给平台机器人的开发作为参考
 * 2、每个函数对应某个能够独立运行的场景 
 */
class GameSceneDemo
{
	private:
		int m_robotIndex;
	public:
		GameSceneDemo(int);
		bool LoginScene();
		bool BattleScene();

		~GameSceneDemo()
		{
		}
};

#endif


