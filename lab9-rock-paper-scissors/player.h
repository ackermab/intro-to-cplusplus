#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>

using namespace std;

class Player
{
	private:
		string name;
		int wins;
		int losses;
		int draws;
		double winpercentage;

	public:
		Player(string name_in);
		virtual ~Player();

		string getname();
		int getwins();
		int getlosses();
		int getdraws();
		double getwinpercentage();
		void changewld(char wld);

		string printplayer();
};
