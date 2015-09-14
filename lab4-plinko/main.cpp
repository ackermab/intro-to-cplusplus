#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;

int simulatedrop(int slot, bool showpaths)
{
	int winnings = 0;
	int movement = rand() % 2;

	if (showpaths)
		cout << "\nStarting location is: " << slot << endl;

	slot = slot * 2; //To keep this variable an int, for simplicity multiply by 2

	if (showpaths)
		cout << "The chip follows this path: " << endl;

	for (int i = 0; i < 12; i++)
	{
		if (slot == 0)
		{
			slot = slot + 1;

			if (showpaths)
				cout << slot / 2.0 << " ";
		}
		else if (slot == 16)
		{
			slot = slot - 1;

			if (showpaths)
				cout << slot / 2.0 << " ";
		}
		else
		{
			if (movement == 0)
				slot = slot - 1;
			else
				slot = slot + 1;

			if (showpaths)
				cout << slot / 2.0 << " ";

			movement = rand() % 2;
		}
	}

	slot = slot / 2; //We divide by two to go back to a number from 0 to 8

	return slot;
}

int determinewinnings(int slot)
{
	int winnings = 0;

	switch (slot)
	{
	case 0:
		winnings = 100;
		break;
	case 1:
		winnings = 500;
		break;
	case 2:
		winnings = 1000;
		break;
	case 3:
		winnings = 0;
		break;
	case 4:
		winnings = 10000;
		break;
	case 5:
		winnings = 0;
		break;
	case 6:
		winnings = 1000;
		break;
	case 7:
		winnings = 500;
		break;
	case 8:
		winnings = 100;
		break;
	}

	return winnings;
}

int droponechip()
{
	/*
	Part 2: Let the Chips Fall
	*/

	int slot = 9;
	int winnings = 0;

	while (slot > 8 || slot < 0)
	{
		cout << "Enter slot (0-8): ";
		cin >> slot;
	}

	slot = simulatedrop(slot, true);

	winnings = determinewinnings(slot);

	cout << "\n\nYou won $" << winnings << " with that chip drop!\n" << endl;

	return 0;
}

int dropmultiplechips()
{
	/*
	Part 3: Bowl of Chips
	*/

	int slotoriginal = 9;
	int slot = 9;
	int winnings = 0;
	int numchips = 0;

	while (slotoriginal > 8 || slotoriginal < 0)
	{
		cout << "Enter slot (0-8): ";
		cin >> slotoriginal;
	}

	slot = slotoriginal;

	cout << "How many chips will you drop? ";
	cin >> numchips;

	if (numchips <= 0)
	{
		cout << "Sorry invalid input.\n" << endl;
		return 0;
	}

	for (int i = 0; i < numchips; i++)
	{
		slot = simulatedrop(slot, false);
		winnings = winnings + determinewinnings(slot);

		slot = slotoriginal;
	}

	cout << "\n\nYou won a total of $" << winnings << "!\n" << endl;
	cout << "You one an average of $" << winnings / numchips << " per chip.\n" << endl;

	return 0;
}

int menu()
{
	/*
	Part 1: The Menu
	*/
	int response = 0;
	cout << "Choose an option:" << endl;
	cout << "1- Drop one chip into one slot" << endl;
	cout << "2- Drop multiple chips into one slot" << endl;
	cout << "3-Quit" << endl;

	cin >> response;
	int breakloop = 0; //used to determine whether or not to keep giving the user a menu choice

	switch (response)
	{
	case 1:
		droponechip();
		breakloop = 0;
		break;
	case 2:
		dropmultiplechips();
		breakloop = 0;
		break;
	case 3:
		breakloop = 1;
		cout << "Thank you for playing!" << endl;
		break;
	}

	return breakloop; //If menu returns 0, the menu repeats, if 1, while loop in main breaks
}

int main()
{
	cout << "Welcome to Plinko!" << endl;

	while(menu() == 0)
	{ }

	system("pause()");

	return 0;
}