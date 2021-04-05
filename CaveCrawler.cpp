// Reed Posehn, 2017
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <ctime>
#include "Stats.h"
#include "Intro.h"
#include "Init.h"
#include "Actions.h"
#include "Events.h"
using namespace std;


string cmd; // the users command
int state;
const int STATE_RUN = 0;
const int STATE_QUIT = 1;
player Me;
room *Rooms;
mob *mobs;
int cur;

// Run user commands
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
		int itemRoll;
		int monster;
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
		// Check if eligible to spawn an item
		if(Rooms[cur].item == 1)
		{
			itemRoll = spawnItem();
			if(itemRoll != 0)
			{
				if(itemRoll == 1)
				{
					Me.belt.berry++;
					cout << "You've found a berry." << endl;
				}
				if(itemRoll == 2)
               	{
					Me.belt.mushroom++;
					cout << "You've found a mushroom." << endl;
                }
				if(itemRoll == 3)
				{
					Me.belt.water++;
					cout << "You've found some water." << endl;
				}
				if(itemRoll == 4)
				{
					Me.belt.meat++;
					cout << "You've found a piece of meat." << endl;
				}
			}
			Rooms[cur].item = 0;
		}
		// Potentially spawn monster
		monster = spawnMon(Rooms[cur].mobSpw, mobs, &Me);
		/*if (monster == 1) {
			
		}*/
	}
	else if(arg.compare("supplies") == 0)
	{
		supplies(Me);
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
	mobs = initMobs();
	// Seeding time based off of Epoch time
	srand(time(NULL));
	// Gamestate run loop
	while(state == STATE_RUN)
	{
		cout << "What would you like to do?\n";
		getline(cin, cmd);
		running(Me, cmd);
	}
	return 0;
}
