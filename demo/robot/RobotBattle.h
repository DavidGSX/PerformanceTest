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
* Copyright (c)  2016-2017, ��Ѷ�Ƽ����޹�˾���������з���
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
 * Description ���ͻ�������
 *              �����˵�¼��ȥ���ظ���ִ�п�ʼ��Ϸ��������Ϸ
 * Details     ��1������ʵ�ֻ����˳�ʼ���߼�Robot
 *               2������ʵ�ֻ����˳�ʼ�������߼�init
 *               3������ʵ�ֻ�����ִ�ж����߼�runAction
 */
class  RobotBattle : public AbstractRobot
{
public:
	 GameAPI *m_pGameAPI;
	 RobotBattle(int index,long tranTotal);
	 //��������Ϊ���ɿͻ�ʵ��
	 virtual int runAction();
	 virtual bool init();
	 ~RobotBattle();

};

#endif





