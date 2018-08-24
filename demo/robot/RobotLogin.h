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
* Copyright (c)  2016-2017, ��Ѷ�Ƽ����޹�˾���������з���
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
 * Description ����������
 * Details     ��ִ���û��Զ��������
 */
class  RobotLogin : public AbstractRobot
{
public:
	 bool m_isRobotFirstRun;
	 GameAPI *m_pGameAPI;
	 RobotLogin(int index,long tranTotal);
	 //��������Ϊ���ɿͻ�ʵ��
	 virtual int runAction();
	 virtual bool init();
	 //������ִ����runAction()ѭ�������Ķ�������ִ��һ��
	 virtual bool close();
	 ~RobotLogin();

};


#endif





