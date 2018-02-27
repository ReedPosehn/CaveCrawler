// Reed Posehn, 2017
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include "Stats.h"
#include "Init.h"
using namespace std;

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
