#pragma once
#include "fighter.h"

class Robot : public Fighter
{
public:
	Robot(string name, int maxHP, int strength, int speed, int magic);
	~Robot();
private:
	int getDamage();
	void reset();
	void regenerate();
	bool useAbility();
	int electricity;
	int maxElectricity;
	int bonusDamage;
};
