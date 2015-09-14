#include "archer.h"
#include <iostream>

using namespace std;

Archer::Archer(string name_in, int maxHP_in, int strength_in, int speed_in, int magic_in)
{
	name = name_in;
	maxHP = maxHP_in;
	currentHP = maxHP;
	strength = strength_in;
	speed = speed_in;
	magic = magic_in;
	initialSpeed = speed_in;
}
Archer::~Archer(){}

int Archer::getDamage()
{
	return speed;
}

void Archer::reset()
{
	currentHP = maxHP;
	speed = initialSpeed;

}

void Archer::regenerate()
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

bool Archer::useAbility()
{
	cout << "Archer special ability" << endl;
	speed++;
	return true;
}
