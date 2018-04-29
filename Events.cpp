// Reed Posehn, 2018
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
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

// Chance of spawning a monster upon entering a room
int spawnMonster()
{
	return 0;
}
