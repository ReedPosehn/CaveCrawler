// Reed Posehn, 2017
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include "Stats.h"
#include "Intro.h"
#include "Init.h"
using namespace std;

string cmd; // the users command
int state;
const int STATE_RUN = 0;
const int STATE_QUIT = 1;

int running(player you, string arg)
{
	if(arg.compare("quit") == 0)
	{
		state = STATE_QUIT;
	}
	return 0;
}

int main()
{	
	Intro();
	cmd = "";
	player Me = initPlayer();	
	while(state == STATE_RUN)
	{
		cout << "What would you like to do?\n";
		getline(cin, cmd);
		running(Me, cmd);
	}
	return 0;
}
