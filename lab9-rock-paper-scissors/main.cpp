#include <iostream>
#include <vector>
#include <cmath>
#include "player.h"

using namespace std;

void changestats(vector<Player*> &players, string name, char wld)
{
	for (int i = 0; i < players.size(); i++)
	{
		if (players.at(i)->getname() == name)
		{
			players.at(i)->changewld(wld);
		}
	}
}

int determinewinner(string p1throw, string p2throw)
{
	if (p1throw == "rock")
	{
		if (p2throw == "scissors")
			return 0;
		if (p2throw == "paper")
			return 1;
		if (p2throw == "rock")
			return 2;
	}
	if (p1throw == "paper")
	{
		if (p2throw == "scissors")
			return 1;
		if (p2throw == "paper")
			return 2;
		if (p2throw == "rock")
			return 0;
	}
	if (p1throw == "scissors")
	{
		if (p2throw == "scissors")
			return 2;
		if (p2throw == "paper")
			return 0;
		if (p2throw == "rock")
			return 1;
	}
}

string getRPSthrow()
{
	int num = rand() % 3;
	
	if (num == 0)
		return "rock";
	else if (num == 1)
		return "paper";
	else
		return "scissors";
}

void fight(vector<Player*> &players, vector<Player*> &lineup)
{
	if (lineup.size() > 1)
	{
		string player1 = lineup.at(0)->getname();
		string player2 = lineup.at(1)->getname();

		if (player1 == player2)
		{
			cout << "\n" << player1 << " fights himself... Draw!" << endl;
			changestats(players, player1, 'd');
		}
		else
		{
			string p1throw = getRPSthrow();
			string p2throw = getRPSthrow();

			int winner = determinewinner(p1throw, p2throw);

			cout << "\nFight started between " << player1 << " and " << player2 << "!" << endl;
			cout << "\n" << player1 << " throws " << p1throw << endl;
			cout << player2 << " throws " << p2throw << endl;
			cout << endl;

			if (winner == 0)
			{
				cout << player1 << " is the winner!" << endl;
				changestats(players, player1, 'w');
				changestats(players, player2, 'l');
			}
			else if (winner == 1)
			{
				cout << player2 << " is the winner!" << endl;
				changestats(players, player1, 'l');
				changestats(players, player2, 'w');
			}
			else
			{
				cout << "Draw!" << endl;
				changestats(players, player1, 'd');
				changestats(players, player2, 'd');
			}
		}

		lineup.erase(lineup.begin());
		lineup.erase(lineup.begin());

	}
	else
		cout << "\nYou must have 2 or more players in the lineup to fight." << endl;

	cout << endl;
}

void showlineup(vector<Player*> &lineup)
{
	if (lineup.size() == 0)
		cout << "\nThere are no players yet added." << endl;
	else
	{
		cout << "\n--Line-Up----------" << endl;
		for (int i = 0; i < lineup.size(); i++)
		{
			cout << i + 1 << ": ";
			cout << lineup.at(i)->getname() << endl;
		}
	}

	cout << endl;
}

void addtolineup(vector<Player*> &players, vector<Player*> &lineup)
{
	string name_in;

	cout << "\nEnter name of player to add: ";
	getline(cin, name_in);

	bool nameexists = false;

	for (int i = 0; i < players.size(); i++)
	{
		if (players.at(i)->getname() == name_in)
			nameexists = true;
	}

	if (nameexists)
	{
		Player* newplayer = new Player(name_in);
		lineup.push_back(newplayer);

		cout << name_in << " was added to the line-up." << endl;
		//delete newplayer;
	}
	else
		cout << "There is no player by that name." << endl;

	cout << endl;
}

void addplayer(vector<Player*> &players)
{
	string name_in;

	cout << "\nEnter name for new player: ";
	getline(cin, name_in);

	bool namealreadyexists = false;

	for (int i = 0; i < players.size(); i++)
	{
		if (players.at(i)->getname() == name_in)
			namealreadyexists = true;
	}

	if (!namealreadyexists)
	{
		Player* newplayer = new Player(name_in);
		players.push_back(newplayer);

		cout << name_in << " was added to the player list." << endl;

		//delete newplayer;
	}
	else
		cout << "There is already a player by that name." << endl;

	cout << endl;
}

void showplayers(vector<Player*> &players)
{
	if (players.size() == 0)
		cout << "\nThere are no players yet added." << endl;
	else
	{
		cout << endl;
		for (int i = 0; i < players.size(); i++)
		{
			cout << "---Player " << i + 1 << " --------" << endl;
			cout << players.at(i)->printplayer();
		}
	}

	cout << endl;
}

int main()
{
	vector<Player*> players;
	vector<Player*> lineup;

	int response;

	cout << "Welcome to Rock Paper Scissors!" << endl;

	do
	{
		cout << "Main Menu" << endl;
		cout << "-------------------" << endl;
		cout << "1 - Show Players" << endl;
		cout << "2 - Add Player" << endl;
		cout << "3 - Add to Line-Up" << endl;
		cout << "4 - Show Line-Up" << endl;
		cout << "5 - Fight" << endl;
		cout << "0 - Quit" << endl;

		cout << ": ";

		cin >> response;
		cin.ignore();

		switch (response)
		{
		case 1:
			showplayers(players);
			break;
		case 2:
			addplayer(players);
			break;
		case 3:
			addtolineup(players, lineup);
			break;
		case 4:
			showlineup(lineup);
			break;
		case 5:
			fight(players, lineup);
			break;
		case 0:
			break;
		default:
			cout << "Invalid response." << endl;
			break;
		}

	} while (response != 0);

	system("pause()");

	return 0;
}
