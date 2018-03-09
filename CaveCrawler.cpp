// Reed Posehn, 2017
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include "Stats.h"
#include "Intro.h"
#include "Init.h"
#include "Actions.h"
using namespace std;

string cmd; // the users command
int state;
const int STATE_RUN = 0;
const int STATE_QUIT = 1;
player Me;
room *Rooms;
int cur;

int running(player you, string arg)
{
	if(arg.compare("quit") == 0)
	{	
		state = STATE_QUIT;
	}
	else if(arg.compare("help") == 0)
	{
		help();
	}
	else if(arg.compare("look") == 0)
	{
		look(Rooms[cur]);
	}
	else if(arg.compare("move") == 0)
	{
		int temp = 1;
		int dir;
		cout << "Which direction would you like to go?" << endl;
		if(Rooms[cur].north == 1)
		{
			cout << "North - " << temp <<  endl;
			temp++;
		}
		if(Rooms[cur].west == 1)
                {
                        cout << "West - " << temp <<  endl;
                        temp++;
                }
		if(Rooms[cur].east == 1)
                {
                        cout << "East - " << temp <<  endl;
                        temp++;
                }
		if(Rooms[cur].south == 1)
                {
                        cout << "South - " << temp <<  endl;
                        temp++;
                }
		cin >> dir;
		cur = move(Rooms[cur], dir);
		cin.ignore();
	}
	else
	{
		cout << "For a list of commands, type 'help'." << endl;
	}
	cout << endl;
	return 0;
}

int main()
{	
	Intro();
	cmd = "";
	cur = 0;
	Me = initPlayer();	
	Rooms = initRooms();
	while(state == STATE_RUN)
	{
		cout << "What would you like to do?\n";
		getline(cin, cmd);
		running(Me, cmd);
	}
	return 0;
}
