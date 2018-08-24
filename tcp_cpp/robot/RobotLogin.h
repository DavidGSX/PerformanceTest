
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
 * @author     ：  moosedong
 * @Aug 17, 2015
 */
class  RobotLogin : public AbstractRobot
{
public:
	 GameAPI *m_pGameAPI;
	 RobotLogin(int index,long tranTotal);
	 //机器人行为，由客户实现
	 virtual int runAction();
	 virtual bool init();
	 ~RobotLogin();

};


#endif





