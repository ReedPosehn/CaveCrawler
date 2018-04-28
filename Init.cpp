// Reed Posehn, 2017
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include "Stats.h"
#include "Init.h"
using namespace std;

// Player attributes
player initPlayer()
{
        struct player *p = new player();
        p->health = 10;
        p->phyStr = 10;
        p->specStr = 10;
        p->speed = 10;
        p->barehand = 1;
        p->belt = initPlayerBelt();
        return *p;
}

// Player belt attributes and contents
belt initPlayerBelt()
{
	struct belt *b = new belt();
	b->berry = 0;
	b->mushroom = 0;
	b->meat = 0;
	b->water = 0;
	for(int i = 0; i < 10; i++)
	{
		b->list[i] = (weapon) {0, 0, 0};
	}
	b->upgrade = 0;
	return *b;
}

// Room setup and attributes
room* initRooms()
{
	room *rooms = new room[4];
	rooms[0].id = 0;
	rooms[0].north = 1;
	rooms[0].west = 0;
	rooms[0].east = 1;
	rooms[0].south = 0;
	rooms[0].item = 0;
	rooms[0].desc = "A cramped, musky room. Its empty, with the exception "
	"of torches lining the walls.\nThere are two exits, to the north and "
	"to the east.\n";
	rooms[0].northR = &rooms[1];
	rooms[0].eastR = &rooms[2];
	
	rooms[1].id = 1;
	rooms[1].north = 0;
        rooms[1].west = 0;
        rooms[1].east = 1;
        rooms[1].south = 1;
	rooms[1].item = 0;
	rooms[1].desc = "A wide cavern, with a large body of water. You cannot "
	"tell the depth of the water.\nThe room is extremely dark and damp. "
	"There are exits to the east and to the south.\n";
	rooms[1].southR = &rooms[0];
        rooms[1].eastR = &rooms[3];
	
	rooms[2].id = 2;
	rooms[2].north = 1;
        rooms[2].west = 1;
        rooms[2].east = 0;
        rooms[2].south = 0;
	rooms[2].item = 0;
	rooms[2].desc = "A small tiny room. There are odd scratchs and markings"
	" covering the walls.\nThe light is dim but penetrates from the west.\n"
	"There are exits to the north and to the west.";
	rooms[2].westR = &rooms[0];
        rooms[2].northR = &rooms[3];
	
	rooms[3].id = 3;
	rooms[3].north = 0;
        rooms[3].west = 1;
        rooms[3].east = 0;
        rooms[3].south = 1;
	rooms[3].item = 0;
	rooms[3].desc = "This room is wide and narrow, with a gentle breeze "
	"coming from north.\nIt looks like it exits to a forest.\nExits to the "
	"west and south continue further into the \ncave.";
	rooms[3].westR = &rooms[1];
        rooms[3].southR = &rooms[2];
	return rooms;
}
