// Reed Posehn 2018

int spawnItem();
int spawnMon(int rng, mob* mobs, player* Me);
int spawnBoss(int room, boss* bosses, player* Me);
int fight(mob* mobs, player* Me);
int fightBoss(boss* boss, player* Me);
void checkEndGame(boss* bosses);