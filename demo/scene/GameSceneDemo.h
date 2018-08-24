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
* Copyright (c)  2016-2017, ��Ѷ�Ƽ����޹�˾���������з���
* All rights reserved.
*
*/

#ifndef __GAMESCENEDEMO_H__
#define __GAMESCENEDEMO_H__

#include <iostream>
using namespace std;


/**
 * ����DEMO
 * �ɿ�����ɫʵ��
 * 1��Ŀ��
 *   ���㲻�������ܿ�ܶ��������Գ���
 *   �����ƽ̨�����˵Ŀ�����Ϊ�ο�
 * 2��ÿ��������Ӧĳ���ܹ��������еĳ��� 
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


