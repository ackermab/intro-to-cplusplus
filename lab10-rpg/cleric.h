#pragma once
#include "fighter.h"

class Cleric : public Fighter
{
public:
	Cleric(string name, int maxHP, int strength, int speed, int magic);
	~Cleric();
private:
	int getDamage();
	void reset();
	void regenerate();
	bool useAbility();
	int currentMana;
	int maxMana;
};
