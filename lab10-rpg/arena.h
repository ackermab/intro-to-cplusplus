#pragma once
#include "arenaInterface.h"
#include "fighter.h"
#include <vector>

class Arena : public ArenaInterface
{
public:
	Arena();
	~Arena();
	bool addFighter(string info);
	bool removeFighter(string name);
	FighterInterface* getFighter(string name);
	int getSize();
private:
	vector<Fighter*> fighters;
};
