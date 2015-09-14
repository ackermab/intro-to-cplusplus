#include "cleric.h"
#include <iostream>

using namespace std;

Cleric::Cleric(string name_in, int maxHP_in, int strength_in, int speed_in, int magic_in)
{
	name = name_in;
	maxHP = maxHP_in;
	currentHP = maxHP;
	strength = strength_in;
	speed = speed_in;
	magic = magic_in;
	maxMana = 5 * magic_in;
	currentMana = 5 * magic_in;
}
Cleric::~Cleric(){}

int Cleric::getDamage()
{
	return magic;
}

void Cleric::reset()
{
	currentHP = maxHP;
	currentMana = maxMana;
}
/*
*	regenerate()
*
*	Increases the fighter's current hit points by an amount equal to one sixth of
*	the fighter's strength (minimum of one unless already at maximum).
*
*	Cleric:
*	Also increases a Cleric's current mana by an amount equal to one fifth of the
*	Cleric's magic (minimum of one unless already at maximum).
*/
void Cleric::regenerate()
{
	//cout << "Regenerate\n" << currentHP << " :: " << maxHP << endl;
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

	// Fighter :: regenerate();

	//cout << "Regenerate mana" << endl;
	//cout << currentMana << endl;
	//cout << magic << endl;
	if (currentMana == maxMana)
		currentMana = currentMana;
	else if ((magic / 5) == 0)
		currentMana++;
	else if ((currentMana + (magic / 5)) > maxMana)
	{
	}
	else
		currentMana += (magic / 5);

	//if (currentMana >= maxMana)
	//	currentMana = maxMana;

}
/*
*	useAbility()
*
*	Attempts to perform a special ability based on the type of fighter.  The
*	fighter will attempt to use this special ability just prior to attacking
*	every turn.
*
*	Robot: Shockwave Punch
*	Adds bonus damage to the Robot's next attack (and only its next attack) equal to (strength  * ((current_electricity/maximum_electricity)^4)).
*	Can only be used if the Robot has at least [ROBOT_ABILITY_COST] electricity.
*	Decreases the Robot's current electricity by [ROBOT_ABILITY_COST] (after calculating the additional damage) when used.
*	The bonus damage formula should be computed using double arithmetic, and only the final result should be cast into an integer.
*	Examples:
*		strength=20, current_electricity=20, maximum_electricity=20		=> bonus_damage=20
*		strength=20, current_electricity=15, maximum_electricity=20		=> bonus_damage=6
*		strength=20, current_electricity=10, maximum_electricity=20		=> bonus_damage=1
*		strength=20, current_electricity=5,  maximum_electricity=20		=> bonus_damage=0
*
*	Archer: Quickstep
*	Increases the Archer's speed by one point each time the ability is used.
*	This bonus lasts until the reset() method is used.
*	This ability always works; there is no maximum bonus speed.
*
*	Cleric: Healing Light
*	Increases the Cleric's current hit points by an amount equal to one third of its magic (minimum of one unless already at maximum).
*	Can only be used if the Cleric has at least [CLERIC_ABILITY_COST] mana.
*	Will be used even if the Cleric's current hit points is equal to their maximum hit points.
*	Decreases the Cleric's current mana by [CLERIC_ABILITY_COST] when used.
*
*	Return true if the ability was used; false otherwise.
*/
bool Cleric::useAbility()
{
	//cout << "Cleric special ability" << endl;
	//cout << currentMana << " :: " << maxMana << endl;
	//cout << currentHP << " :: " << maxHP << endl;
	if (currentMana >= CLERIC_ABILITY_COST)
	{
		currentMana -= CLERIC_ABILITY_COST;

		if (currentHP == maxHP)
			currentHP = currentHP;
		else if ((magic / 3) == 0)
			currentHP++;
		else
			currentHP += (magic / 3);

		if (currentHP > maxHP)
			currentHP = maxHP;

		return true;
	}

	return false;
}
