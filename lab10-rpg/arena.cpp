#include "arena.h"
#include "robot.h"
#include "cleric.h"
#include "archer.h"
#include <sstream>
#include <iostream>

using namespace std;

Arena::Arena()
{
	
}
Arena::~Arena(){}

bool Arena::addFighter(string info)
{
	Fighter* newFighter;
	stringstream ss;
	ss << info;

	string name_in;
	ss >> name_in;

	char type_in;
	ss >> type_in;

	int maxHP_in;
	ss >> maxHP_in;

	if (maxHP_in <= 0)
	{
		//cout << "Non-positive maxHP required" << endl;
		return false;
	}

	int strength_in;
	ss >> strength_in;

	if (strength_in <= 0)
	{
		//cout << "Non-positive strength required" << endl;
		return false;
	}

	int speed_in;
	ss >> speed_in;

	if (speed_in <= 0)
	{
		//cout << "Non-positive speed required" << endl;
		return false;
	}

	int magic_in;
	ss >> magic_in;

	if (magic_in <= 0)
	{
		//cout << "Non-positive magic required" << endl;
		return false;
	}

	string extra;
	if (ss >> extra)
	{
		//cout << "Too much input" << endl;
		return false;
	}

	for (int i = 0; i < fighters.size(); i++)
	{
		if (fighters.at(i)->getName() == name_in)
		{
			//cout << "Fighter by that name already exists" << endl;
			return false;
		}
	}

	if (type_in == 'R')
	{
		//cout << "Creating Robot..." << endl;
		newFighter = new Robot(name_in, maxHP_in, strength_in, speed_in, magic_in);
	}
	else if (type_in == 'C')
	{
		//cout << "Creating Cleric..." << endl;
		newFighter = new Cleric(name_in, maxHP_in, strength_in, speed_in, magic_in);
	}
	else if (type_in == 'A')
	{
		//cout << "Creating Archer..." << endl;
		newFighter = new Archer(name_in, maxHP_in, strength_in, speed_in, magic_in);
	}
	else
		return false;

	fighters.push_back(newFighter);
	return true;
}

bool Arena::removeFighter(string name)
{
	bool fighterRemoved = false;
	for (int i = 0; i < fighters.size(); i++)
		if (fighters.at(i)->getName() == name)
		{
			//cout << "Removing " << name << "..." << endl;
			fighters.erase(fighters.begin() + i);
			fighterRemoved = true;
		}

	return fighterRemoved;
}

FighterInterface* Arena::getFighter(string name)
{
	for (int i = 0; i < fighters.size(); i++)
		if (fighters.at(i)->getName() == name)
			return fighters.at(i);

	return NULL;
}

int Arena::getSize()
{
	return fighters.size();
}
