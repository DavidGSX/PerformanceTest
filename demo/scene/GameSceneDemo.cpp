#include <iostream>

#include "GameSceneDemo.h"
#include "GameAPI.h"

using namespace std;

/**
 * 
 * Description ����ʼ����������������˵�id
 */
GameSceneDemo::GameSceneDemo(int robotIndex)
{
	m_robotIndex = robotIndex;
}

/**
 * 
 * Description ��Login����ʾ����ִ��һ�������ĵ���ǳ�����
 */
bool GameSceneDemo::LoginScene()
{
	GameAPI *client = new GameAPI();
	bool result = false;
	
	//��¼
	result = client->Login(m_robotIndex);
	//�˳�
	result = client->Logout();
	delete client;
	
	return result;
	
}

/**
 * 
 * Description ��Battle����ʾ����ִ��һ��������ս������
 */
bool GameSceneDemo::BattleScene()
{
	GameAPI *client = new GameAPI();
	bool result = false;
	
	//��¼
	result = client->Login(m_robotIndex);
	//��ʼ��Ϸ
	result = client->StartGame();
	//������Ϸ
	result = client->EndGame();
	//�˳�
	result = client->Logout();
	delete client;
	
	return result;
}
