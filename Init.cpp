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
	room *rooms = new room[99];
	rooms[0].id = 0;
	rooms[0].north = 1;
	rooms[0].west = 0;
	rooms[0].east = 1;
	rooms[0].south = 0;
	rooms[0].item = 1;
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
	rooms[1].item = 1;
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
	rooms[2].item = 1;
	rooms[2].desc = "A small tiny room. There are odd scratchs and markings"
	" covering the walls.\nThe light is dim but penetrates from the west.\n"
	"There are exits to the north and to the west.\n";
	rooms[2].westR = &rooms[0];
    rooms[2].northR = &rooms[3];
	
	rooms[3].id = 3;
	rooms[3].north = 1;
	rooms[3].west = 1;
	rooms[3].east = 0;
	rooms[3].south = 1;
	rooms[3].item = 1;
	rooms[3].desc = "This room is wide and narrow, with a gentle breeze "
	"coming from north.\nIt looks like it exits to a forest.\nExits to the "
	"west and south continue further into the cave.\n";
	rooms[3].westR = &rooms[1];
    rooms[3].southR = &rooms[2];
	rooms[3].northR = &rooms[4];
	
	rooms[4].id = 4;
	rooms[4].north = 1;
	rooms[4].west = 0;
	rooms[4].east = 0;
	rooms[4].south = 1;
	rooms[4].item = 1;
	rooms[4].desc = "A claustrophobic path exiting the cave leads through "
	"a dense patch\nof trees. It feels unsafe; you should probably leave.\n";
    rooms[4].southR = &rooms[3];
	rooms[4].northR = &rooms[5];
	
	rooms[5].id = 5;
	rooms[5].north = 0;
	rooms[5].west = 1;
	rooms[5].east = 1;
	rooms[5].south = 1;
	rooms[5].item = 1;
	rooms[5].desc = "An abandonded clearing. You can barely make out refuse and "
	"various broken\ngoods scattered across the grass. To the west is more forest and trees.\n"
	"To the east you can make out some type of structure far in the distance.\n";
    rooms[5].southR = &rooms[4];
	rooms[5].westR = &rooms[6];
	rooms[5].eastR = &rooms[7];
	
	rooms[6].id = 6;
	rooms[6].north = 0;
	rooms[6].west = 0;
	rooms[6].east = 1;
	rooms[6].south = 0;
	rooms[6].item = 1;
	rooms[6].desc = "You've entered the dark, dense forest. Noises can be heard in the distance "
	"of various\ndifferentcreatures. The ground shifts between various highs and lows; it is tiring.\n"
	"You can continue west or return east where you came from.\n";
    rooms[6].eastR = &rooms[5];
	
	rooms[7].id = 7;
	rooms[7].north = 0;
	rooms[7].west = 1;
	rooms[7].east = 0;
	rooms[7].south = 0;
	rooms[7].item = 1;
	rooms[7].desc = "Clear of the forest, you can see the sun as it sets. The view is scenic as you "
	"approach\nthe cliffside. You can see a rickety bridge travel down eastward into the shore of a lake.\n"
	"On the other side of it you notice an entrance to the canyon across from it.";
    rooms[7].westR = &rooms[5];
	return rooms;
}
