#include <iostream>
#include <iomanip>
#include <vector>
#include "car.h"
#include <fstream>

using namespace std;

int savefile(vector<Car>& inventory, double& balance)
{
	string filename;

	cout << "Name of file to write to? ";
	cin >> filename;
	cin.ignore();

	ofstream fout;
	fout.open(filename);

	fout << balance << endl;

	int i = 0;

	while (i < inventory.size())
	{
		fout << inventory.at(i).getName() << " " << inventory.at(i).getColor() << " " << inventory.at(i).getPrice() << endl;
		i++;
	}

	return 0;
}

int getfile(vector<Car>& inventory, double& balance)
{
	string filename;
	double addbalance;

	string name;
	string color;
	double price;

	cout << "Open which file? ";
	cin >> filename;
	cin.ignore();

	ifstream fin;
	fin.open(filename);

	if (fin.is_open())
	{
		fin >> addbalance;
		balance += addbalance;

		while (fin >> name >> color >> price)
		{
			Car newcar(name, color, price);

			inventory.push_back(newcar);
		}
	}
	else
		cout << "Unable to open file." << endl;

	return 0;
}

int paintcar(vector<Car>& inventory)
{
	int n = inventory.size();
	string newcolor;

	if (n < 1)
	{
		cout << "You have no cars to paint." << endl;
		return 0;
	}
	else
	{
		string response;
		bool carexists = false;
		int i;

		cout << "Which car will you paint?";
		getline(cin,response);

		for (i = 0; i < n; i++)
		{
			if (inventory.at(i).getName() == response)
			{
				carexists = true;
				break;
			}
		}

		if (!carexists)
			cout << "You do not have a car by that name." << endl;
		else
		{
			cout << "Which color will you paint your car? ";
			getline(cin, newcolor);

			cout << "You painted the " << inventory.at(i).getName() << " " << newcolor << endl;
			inventory.at(i).paint(newcolor);
		}
	}

	return 0;
}

int sellcar(vector<Car>& inventory, double& balance)
{
	int n = inventory.size();

	if (n < 1)
	{
		cout << "You have no cars to sell." << endl;
		return 0;
	}
	else
	{
		string response;
		bool carexists = false;
		int i;

		cout << "Which car will you sell?";
		getline(cin, response);

		for (i = 0; i < n; i++)
		{
			if (inventory.at(i).getName() == response)
			{
				carexists = true;
				break;
			}
		}

		if (!carexists)
			cout << "You do not have a car by that name." << endl;
		else
		{
			balance += inventory.at(i).getPrice();
			cout << "You sold the " << inventory.at(i).getName() << " for $" << inventory.at(i).getPrice() << endl;
			inventory.erase(inventory.begin() + i);
		}
	}

	return 0;
}

int buycar(vector<Car>& inventory, double& balance)
{
	string name;
	string color;
	double price;
	bool carexists = false;
	int i;

	cout << "What is the name of the car you would like to buy? ";
	getline(cin, name);

	for (i = 0; i < inventory.size(); i++)
	{
		if (inventory.at(i).getName() == name)
		{
			carexists = true;
			break;
		}
	}

	if (carexists)
		cout << "You already have a car by that name." << endl;
	else
	{
		cout << "What is the color? ";
		getline(cin, color);

		cout << "Price? $";
		cin >> price;
		cin.ignore();

		if (price > balance)
		{
			cout << "You do not have enough money to buy that car." << endl;
			return 0;
		}

		Car newcar(name, color, price);
		balance -= price;

		inventory.push_back(newcar);
	}

	return 0;
}

int showinventory(vector<Car>& inventory)
{
	int n = inventory.size();

	if (n > 0)
	{
		for (int i = 0; i < n; i++)
		{
			cout << "Car " << i + 1 << endl;
			cout << "--------------------------" << endl;
			cout << inventory.at(i).toString();
			cout << "--------------------------" << endl;
		}
	}
	else
		cout << "You have no inventory" << endl;

	return 0;
}

int showbalance(double  balance)
{
	cout << "Current balance is: $" << fixed << setprecision(2) << balance << endl;

	return 0;
}

int main()
{
	double balance = 10000;

	int response;

	vector <Car> inventory;

	do {

		cout << "Choose an option [0-7]" << endl;
		cout << "1 - Show current inventory" << endl;
		cout << "2 - Show current balance" << endl;
		cout << "3 - Buy a car" << endl;
		cout << "4 - Sell a car" << endl;
		cout << "5 - Paint a car" << endl;
		cout << "6 - Load file" << endl;
		cout << "7 - Save file" << endl;
		cout << "0 - Quit program" << endl;
		cout << ":";

		cin >> response;
		cin.ignore();

		switch (response)
		{
		case 1:
			showinventory(inventory);
			break;
		case 2:
			showbalance(balance);
			break;
		case 3:
			buycar(inventory, balance);
			break;
		case 4:
			sellcar(inventory, balance);
			break;
		case 5:
			paintcar(inventory);
			break;
		case 6:
			getfile(inventory, balance);
			break;
		case 7:
			savefile(inventory, balance);
			break;
		case 0:
			break;
		default:
			cout << "Invalid response." << endl;
		}
	} while (response != 0);

	system("pause()");

	return 0;
}
