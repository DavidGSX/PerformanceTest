#include <iostream>

#include "GameSceneDemo.h"
#include "GameAPI.h"

using namespace std;

/**
 * 
 * Description ：初始化场景，传入机器人的id
 */
GameSceneDemo::GameSceneDemo(int robotIndex)
{
	m_robotIndex = robotIndex;
}

/**
 * 
 * Description ：Login场景示例，执行一套完整的登入登出操作
 */
bool GameSceneDemo::LoginScene()
{
	GameAPI *client = new GameAPI();
	bool result = false;
	
	//登录
	result = client->Login(m_robotIndex);
	//退出
	result = client->Logout();
	delete client;
	
	return result;
	
}

/**
 * 
 * Description ：Battle场景示例，执行一套完整的战斗操作
 */
bool GameSceneDemo::BattleScene()
{
	GameAPI *client = new GameAPI();
	bool result = false;
	
	//登录
	result = client->Login(m_robotIndex);
	//开始游戏
	result = client->StartGame();
	//结束游戏
	result = client->EndGame();
	//退出
	result = client->Logout();
	delete client;
	
	return result;
}
