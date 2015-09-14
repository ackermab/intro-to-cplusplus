#pragma once
#include "fighterInterface.h"

class Fighter : public FighterInterface
{
public:
	Fighter();
	~Fighter();
	string getName();
	int getMaximumHP();
	int getCurrentHP();
	int getStrength();
	int getSpeed();
	int getMagic();
	void takeDamage(int damage);

	string name;
	int maxHP;
	int currentHP;
	int strength;
	int speed;
	int magic;
private:

};
