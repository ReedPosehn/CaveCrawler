// Reed Posehn, 2017
using namespace std;

typedef struct room room;
typedef struct weapon weapon;
typedef struct status status;
typedef struct belt belt;
typedef struct player player;
typedef struct enemy enemy;

struct weapon
{
	bool type; // 0 null, 1 phys, 2 ranged
	int baseDmg; // base damage, not taking into account stats
	int value; // ammount it can be sold to a merchant
};

struct status
{
	int wounded;
	int sick;
	int dying;
	int poisoned;
	int hallucinating;
	int food_poisoning;
};

struct belt
{
	int berry; // can be poisonous, heal 5
	int mushroom; // can be poisonous, heal 10
	int meat; // can cause food poisoning, heal 20
	int water; // can cause hallucinations, heal 20
	struct weapon list[10]; // weapons on hand
	int upgrade; // can be applied to a physical weapon for a dmg boost
};

struct player
{
	int health; 
	int phyStr; // Dmg for physical weapons
	int specStr; // Dmg for technical weapons that don't rely on physical
		     // strength
	int speed;
	int barehand;
	struct weapon wep; // currently wielded weapon
	struct status stat; // holds the ailments that are applicable
	struct belt belt; // holds the items that player can use
};

struct enemy
{
	int health;
	int str;
	int speed;
};

struct room
{
	int id; // room id
	int north; // directionals -- if 1, then yes
	int west;
	int east;
	int south;
	room* northR; // pointers to adjacent rooms
	room* westR;
	room* eastR;
	room* southR;
	int item; // 1 if unclaimed item; spawns using rng
	int mob; // chance of mob spawning -- 0 is never, 10 is always
	string desc;
};
