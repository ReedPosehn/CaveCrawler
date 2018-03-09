// Reed Posehn, 2017
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include "Stats.h"
#include "Actions.h"
using namespace std;

void help()
{
	cout << "Possible commands --" << endl;
	cout << "look -- Gives a description of the surounding area." << endl;
	cout << "move -- Travel to a different area." << endl;
}

void look(room cur)
{
	cout << cur.desc << endl;
}

int move(room cur, int dir)
{	
	int temp = 1;
	int north = 0;
	int west = 0;
	int south = 0;
	int east = 0;
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
