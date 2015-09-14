#include "fighter.h"
#include <iostream>

using namespace std;

Fighter::Fighter()
{

}
Fighter::~Fighter(){}

string Fighter::getName()
{
	return name;
}

int Fighter::getMaximumHP()
{
	return maxHP;
}

int Fighter::getCurrentHP()
{
	return currentHP;
}

int Fighter::getStrength()
{
	return strength;
}

int Fighter::getSpeed()
{
	return speed;
}

int Fighter::getMagic()
{
	return magic;
}

void Fighter::takeDamage(int damage)
{
	//cout << "Attack of " << damage << " damage" << endl;
	//cout << speed << endl;
	//cout << (damage - (speed / 4)) << endl;
	//cout << currentHP << endl;
	if ((damage - (speed / 4)) <= 0)
		currentHP -= 1;
	else
		currentHP -= (damage - (speed / 4));
}
