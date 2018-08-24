#include "Scenes.h"

bool Scenes::LoginScene()
{
	//connect
	bool result = pGameApi->connectToServer();

	if(result)
		cout<<"connect to server: ok!"<<endl;
	else
		cout<<"connect to server: error!"<<endl;

	//test tLoginGameic	
	int login_ret = pGameApi->tLoginGame(123456,"hazelnutlin","pwd_hazel");

	//disconnect
	pGameApi->disconnect();
	delete pGameApi;

	if(0 == login_ret)
	{
		return true;
	}
	else{
		return false;
	}
}

