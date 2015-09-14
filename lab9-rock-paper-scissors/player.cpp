#include "player.h"

using namespace std;

Player::Player(string name_in)
{
	name = name_in;
	wins = 0;
	losses = 0;
	draws = 0;
}
Player::~Player(){}

string Player::getname()
{
	return name;
}

int Player::getwins()
{
	return wins;
}

int Player::getlosses()
{
	return losses;
}

int Player::getdraws()
{
	return draws;
}

double Player::getwinpercentage()
{
	if ((wins + draws + losses) > 0)
		winpercentage = (double)wins / (wins + draws + losses);
	else
		winpercentage = 0;

	return winpercentage;
}

void Player::changewld(char wld)
{
	if (wld == 'w')
		wins++;
	else if (wld == 'l')
		losses++;
	else
		draws++;
}

string Player::printplayer()
{
	stringstream ss;

	ss << "Name: " << name << endl;
	ss << "Wins: " << wins << endl;
	ss << "Losses: " << losses << endl;
	ss << "Draws: " << draws << endl;
	ss << "Win %: " << fixed << setprecision(0) << getwinpercentage() * 100 << endl;

	return ss.str();
}
