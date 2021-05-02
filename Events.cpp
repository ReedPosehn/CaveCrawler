// Reed Posehn, 2018
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include "Stats.h"
#include "Init.h"
#include "Actions.h"
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
int fight(mob* mobs, player* Me) {
	int fightRoll = rand() % 1;
	mob currMob = getMob(fightRoll, mobs);
	cout << "A " + currMob.name + " has appeared!" << endl;
	int playHealth = Me->health;
	int mobHealth = currMob.health;
	int playStr = Me->phyStr;
	int mobDmg = currMob.maxDmg;
	int fighting = 1;
	int opt;
	while (fighting == 1) {
		cout << "Choose an action: " << endl;
		cout << "1 - Attack		3 - Items" << endl;
		cout << "2 - Defend		4 - Run" << endl;
		cin >> opt;
		cin.ignore();
		// Reset mob damage in case player took defense last round
		mobDmg = currMob.maxDmg;
		if (opt == 1) {
			int dmg = (rand() % playStr);
			cout << "You strike the monster for " + to_string(dmg) + " damage." << endl;
			mobHealth = mobHealth - dmg;
			if (mobHealth <= 0) {
				cout << "The monster has been defeated!" << endl;
				Me->health = playHealth;
				break;
			}
		}
		else if (opt == 2) {
			cout << "You take a defensive stance." << endl;
			mobDmg--;
		}
		else if (opt == 3) {
			cout << "You examine your belt." << endl;
			int* items;
			string itemTypes[4] = {"Berry", "Mushroom", "Water", "Meat"};
			int exists;
			string itemType = "";
			items = suppliesEx(*Me);
			cout << "What would you like to use? (Back for previous options)" << endl;
			for (int i = 0; i < 4; i++) {
				exists = *(items + i);
				if (exists != 0) {
					cout << itemTypes[i] << endl;
				}
			}
			cin >> itemType;
			cin.ignore();
			if (itemType == "Back") {
				continue;
			}
			else {
				useItem(itemType, Me);
			}
		}
		else if (opt == 4){
			int runChance = (rand() % 2);
			if (runChance == 1) {
				cout << "You manage to escape" << endl;
				break;
			}
			else {
				cout << "You can't escape!" << endl;
			}
		}
		else {
			cout << "Not a viable option" << endl;
		}
		// Monster attacks back
		int monDmg = (rand() % mobDmg);
		cout << "The " + currMob.name + " hits you for " + to_string(monDmg) + " damage." << endl;
		playHealth = playHealth - monDmg;
		if (playHealth <= 0) {
			cout << "You have died! Game over!" << endl;
			exit(0);
		}
	}
	return 0;
}

// Initiate a fight with a monster
int fightBoss(boss* boss, player* Me) {
	cout << boss->name + " has appeared!" << endl;
	int playHealth = Me->health;
	int bossHealth = boss->health;
	int playStr = Me->phyStr;
	int bossDmg = boss->maxDmg;
	int fighting = 1;
	int opt;
	while (fighting == 1) {
		cout << "Choose an action: " << endl;
		cout << "1 - Attack		3 - Items" << endl;
		cout << "2 - Defend" << endl;
		cin >> opt;
		cin.ignore();
		// Reset mob damage in case player took defense last round
		bossDmg = boss->maxDmg;
		if (opt == 1) {
			int dmg = (rand() % playStr);
			cout << "You strike the monster for " + to_string(dmg) + " damage." << endl;
			bossHealth = bossHealth - dmg;
			if (bossHealth <= 0) {
				cout << "The boss has been defeated!" << endl;
				Me->health = playHealth;
				boss->defeated = 1;
				break;
			}
		}
		else if (opt == 2) {
			cout << "You take a defensive stance." << endl;
			bossDmg--;
		}
		else if (opt == 3) {
			cout << "You examine your belt." << endl;
			int* items;
			string itemTypes[4] = {"Berry", "Mushroom", "Water", "Meat"};
			int exists;
			string itemType = "";
			items = suppliesEx(*Me);
			cout << "What would you like to use? (Back for previous options)" << endl;
			for (int i = 0; i < 4; i++) {
				exists = *(items + i);
				if (exists != 0) {
					cout << itemTypes[i] << endl;
				}
			}
			cin >> itemType;
			cin.ignore();
			if (itemType == "Back") {
				continue;
			}
			else {
				useItem(itemType, Me);
			}
		}
		else if (opt == 4){
			int runChance = (rand() % 2);
			if (runChance == 1) {
				cout << "You manage to escape" << endl;
				break;
			}
			else {
				cout << "You can't escape!" << endl;
			}
		}
		else {
			cout << "Not a viable option" << endl;
		}
		// Boss attacks back
		int monDmg = (rand() % bossDmg);
		cout << boss->name + " hits you for " + to_string(monDmg) + " damage." << endl;
		playHealth = playHealth - monDmg;
		if (playHealth <= 0) {
			cout << "You have died! Game over!" << endl;
			exit(0);
		}
	}
	return 0;
}

// Chance of spawning a monster upon entering a room
int spawnMon(int rng, mob* mobs, player* Me)
{
	int roll = (rand() % 10) + 1;
	if (rng >= roll) {
		// Spawn mob
		fight(mobs, Me);
		return 1;
	}
	return 0;
}

// Check if the room is a boss room
int spawnBoss(int roomID, boss* bosses, player* Me)
{
	for(int i = 0; i < 10; i++) {
		cout << bosses[i].room << endl;
		if (roomID == bosses[i].room) {
			fightBoss(&bosses[i], Me);
		}
		if (bosses[i].room == 0) {
			break;
		}
	}
	return 0;
}

// Check if an end game condition is met
void checkEndGame(boss* bosses) {
	if (bosses[0].defeated == 1) {
		cout << "The first boss has been slayed - you have finished the beta version of the game! Congratulations!" << endl;
		exit(0);
	}
}