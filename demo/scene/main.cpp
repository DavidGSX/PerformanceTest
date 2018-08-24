#include <iostream>

#include "Scenes.h"

using namespace std;

//test case
int main()
{	
	bool result;

	Scenes *scenes = new Scenes();

	result = scenes->LoginScene();
	
	if(result){
		cout<<"test login scene success!"<<endl;
	}

	delete scenes;

	return 0; 
	
 }

