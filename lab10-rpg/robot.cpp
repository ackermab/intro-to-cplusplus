#include "robot.h"
#include <iostream>
#include <cmath>

using namespace std;

Robot::Robot(string name_in, int maxHP_in, int strength_in, int speed_in, int magic_in)
{
	name = name_in;
	maxHP = maxHP_in;
	currentHP = maxHP;
	strength = strength_in;
	speed = speed_in;
	magic = magic_in;
	electricity = 2 * magic_in;
	maxElectricity = 2 * magic_in;
	bonusDamage = 0;
}
Robot::~Robot(){}

int Robot::getDamage()
{
	int damage = strength + bonusDamage;
	bonusDamage = 0;
	return damage;
}

void Robot::reset()
{
	currentHP = maxHP;
	electricity = maxElectricity;
	bonusDamage = 0;
}

void Robot::regenerate()
{
	//cout << "Regenerate\n" << currentHP << endl;
	//cout << strength << endl;
	//cout << strength / 6 << endl;
	if (currentHP == maxHP)
		currentHP = currentHP;
	else if ((strength / 6) == 0)
		currentHP++;
	else
		currentHP += (strength / 6);

	if (currentHP > maxHP)
		currentHP = maxHP;
}

bool Robot::useAbility()
{
	cout << "Robot special ability" << endl;
	//cout << electricity << endl;
	if (electricity >= ROBOT_ABILITY_COST)
	{
		bonusDamage = ((double)strength * pow(((double)electricity / (double)maxElectricity), 4));
		electricity -= ROBOT_ABILITY_COST;
		return true;
	}
	return false;
}
