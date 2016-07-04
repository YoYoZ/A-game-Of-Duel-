#include <iostream>

using namespace std;
struct ability
{
	char *name;
	int cost;
	int dmg;
	int cooldown;
	char *description;
	int curCooldown = 0;
	ability(char* name, int cost, int dmg, int cooldown, char *description)
	{
		this->cooldown = cooldown;
		this->cost = cost;
		this->curCooldown = 0;
		this->dmg = dmg;
		this->name = name;
		this->description = description;
	}
};
#define numberOfAbilites  3
class unit
{
public:
	bool isPlayer;
	char *name;
	int health;
	int armor;
	int meleeDMG;
	int rangeDMG;
	int agility;
	int mana;
	ability *skills[numberOfAbilites];

	unit(int t_health, int t_meleeDMG, int t_rangeDMG, int t_agility, int  armor, int mana, char *name)
	{
		health = t_health;
		meleeDMG = t_meleeDMG;
		rangeDMG = t_rangeDMG;
		agility = t_agility;
		this->armor = armor;
		this->mana = mana;
		this->name = name;
	}
	void attackMelee(unit *enemy)
	{
		enemy->health -=  meleeDMG;
	}
	void attackRanged(unit *enemy)
	{
		enemy->health -= rangeDMG;
	}
	void useAbility(unit *enemy, ability* ab)
	{
			if (ab->curCooldown == 0)
			{
				enemy->health -= ab->dmg;
				this->mana = ab->cost;
				ab->curCooldown = ab->cooldown;
				cout << ab->description << endl;
			}
			else
			{
				cout << "We're still on cooldown" << endl;
				ab->curCooldown--;
			}
			system("PAUSE");
	}
	void defence()
	{
	}
};

enum canDo
{
	attackMelee, attackRanged, useAb1, useAb2, useAb3
};
