#pragma once
#include "fighter.h"

class Archer : public Fighter
{
public:
	Archer(string name, int maxHP, int strength, int speed, int magic);
	~Archer();
private:
	int getDamage();
	void reset();
	void regenerate();
	bool useAbility();
	int initialSpeed;
};
