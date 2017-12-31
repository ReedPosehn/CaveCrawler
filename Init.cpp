// Reed Posehn, 2017
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include "Stats.h"
using namespace std;

int Init()
{
	struct player *p = new player();
	if(p == NULL)
	{
		return -1;
	}
	p->health = 10;
	p->phyStr = 10;
	p->specStr = 10;
	p->speed = 10;
	p->barehand = 1;
	return 0;
}
