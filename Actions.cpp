// Reed Posehn, 2017
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include "Stats.h"
#include "Init.h"
#include "Actions.h"
using namespace std;


// Prints a list of commands for the user
void help()
{
	cout << "Possible commands --" << endl;
	cout << "look -- Gives a description of the surounding area." << endl;
	cout << "move -- Travel to a different area." << endl;
	cout << "supplies -- Check your on-hand supplies." << endl;
}


// Provides a description of the room
void look(room cur)
{
	cout << cur.desc << endl;
}


// Allows the user to move to a different room
int move(room cur, int dir)
{	
	// Allows the user to pick the room they want to move to
	int temp = 1;
	int north = 0;
	int west = 0;
	int south = 0;
	int east = 0;

	// Increment room choices
	if(cur.north == 1)
	{
		north = temp;
		temp++;
	}
	if(cur.west == 1)
	{
		west = temp;
		temp++;	
	}
	if(cur.east == 1)
    {
        east = temp;
        temp++;
	}
	if(cur.south == 1)
	{
		south = temp;
		temp++;
	}

	// Return new room
	if(north == dir)
	{
		return cur.northR->id;
	}
	else if(west == dir)
	{
		return cur.westR->id;
	}
	else if(east == dir)
	{
		return cur.eastR->id;
	}
	else if(south == dir)
	{
		return cur.southR->id;
	}
	cout << "Cannot go that direction." << endl;
	return 0;
}

// Prints the players current supplies
void supplies(player you)
{
	int empty = 0;
	if(you.belt.berry != 0)
	{
		empty = 1;
		cout << you.belt.berry << " berries." << endl;	
	}
	if(you.belt.mushroom != 0)
	{
		empty = 1;
		cout << you.belt.mushroom << " mushrooms." << endl;
	}
	if(you.belt.water != 0)
	{
		empty = 1;
		cout << you.belt.water << " drinks of water." << endl;
	}
	if(you.belt.meat != 0)
	{
		empty = 1;
		cout << you.belt.meat << " pieces of meat." << endl;
	}
	if(empty == 0)
	{
		cout << "You have nothing on you." << endl;
	}
}