// Reed Posehn, 2018
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include "Stats.h"
#include "Init.h"
using namespace std;

// Chance of spawning an item upon entering a room
int spawnItem()
{
	int roll = rand() % 5;
	if(roll == 0)
	{
		int itemRoll = rand() % 5;
		if(itemRoll == 0 || itemRoll == 1)
		{
			return 1;
		}
        if(itemRoll == 2)
        {
			return 2;
        }
		if(itemRoll == 3)
        {
			return 3;
        }
		if(itemRoll == 4)
        {
			return 4;
        }
	}
	return 0;
}

// Initiate a fight with a monster
int fight(mob* mobs) {
	int fightRoll = rand() % 1;
	mob currMob = getMob(fightRoll, mobs);
	return 0;
}

// Chance of spawning a monster upon entering a room
int spawnMon(int rng, mob* mobs)
{
	int roll = (rand() % 10) + 1;
	if (rng >= roll) {
		// Spawn mob
		fight(mobs);
		return 1;
	}
	return 0;
}