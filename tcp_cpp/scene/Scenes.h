#ifndef __SCENES_H__
#define __SCENES_H__

#include "GameAPI.h"

class Scenes
{
	private:
		GameAPI *pGameApi;
	public:
		Scenes()
		{
			pGameApi = new GameAPI();
		}
		bool LoginScene();
};


#endif
