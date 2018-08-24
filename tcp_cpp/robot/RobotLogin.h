
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
 * @author     ��  moosedong
 * @Aug 17, 2015
 */
class  RobotLogin : public AbstractRobot
{
public:
	 GameAPI *m_pGameAPI;
	 RobotLogin(int index,long tranTotal);
	 //��������Ϊ���ɿͻ�ʵ��
	 virtual int runAction();
	 virtual bool init();
	 ~RobotLogin();

};


#endif





