// Reed Posehn, 2017

struct weapon
{
	bool type;
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
	struct weapon; // currently wielded weapon
	struct status; // holds the ailments that are applicable
	struct belt; // holds the items that player can use
};

struct enemy
{
	int health;
	int str;
	int speed;
};
