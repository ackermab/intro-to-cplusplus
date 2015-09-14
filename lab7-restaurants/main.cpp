#include <iostream>
#include <vector>
#include <string>
#include <cmath>

using namespace std;

bool ispoweroftwo(int n)
{
	while ((((n % 2) == 0) && n > 1))
		n = n / 2;

	return (n == 1);
}

int tournament(vector<string>& restaurants)
{
	bool isvalidresponse = false;
	int n = restaurants.size();
	string response;

	for (int i = 0; i < log2 (n); i++)
	{
		for (int j = 0; j < (n / pow(2,i+1)); j++)
		{
			do {
				isvalidresponse = false;

				cout << "Match " << j + 1 << "/" << n / (pow(2,i+1)) << ", Round " << i + 1 << "/" << log2 (n) << "--- ";
				cout << restaurants.at(j) << " or " << restaurants.at((j) + 1) << "? ";

				getline(cin, response);

				if (restaurants.at(j) == response)
				{
					isvalidresponse = true;
					restaurants.erase(restaurants.begin() + j + 1);
				}
				else if (restaurants.at(j + 1) == response)
				{
					isvalidresponse = true;
					restaurants.erase(restaurants.begin() + j);
				}

				if (!isvalidresponse)
				{
					cout << "Invalid response (" << response << ")" << endl;
				}

			} while (!isvalidresponse);
		}
	}

	cout << response << " is the winner!" << endl;

	return 0;
}

int shufflerestaurant(vector<string>& restaurants)
{
	int n = restaurants.size() - 1;

	for (int i = 0; i < n; i++)
	{
		swap(restaurants.at(i), restaurants.at(rand()%n));
	}

	return 0;
}

int removerestaurant(vector<string>& restaurants)
{
	string newrestaurant;
	cout << "Input restaurant name to remove: ";
	getline(cin, newrestaurant);

	bool exists = false;

	for (int i = 0; i < restaurants.size(); i++)
	{
		if (restaurants.at(i) == newrestaurant)
		{
			restaurants.erase(restaurants.begin() + i);
			exists = true;
		}
	}

	if (exists)
		cout << newrestaurant << " was removed from the list." << endl;
	else
		cout << "That restaurant is not on the list." << endl;

	return 0;
}

int addrestaurant(vector<string>& restaurants)
{
	string newrestaurant;
	cout << "Input new restaurant name: ";
	getline(cin, newrestaurant);

	bool exists = false;

	for (int i = 0; i < restaurants.size(); i++)
		if (restaurants.at(i) == newrestaurant)
			exists = true;

	if (exists)
		cout << "That restaurant is already on the list." << endl;
	else
	{
		restaurants.push_back(newrestaurant);
		cout << newrestaurant << " was added to the list." << endl;
	}

	return 0;
}

int displayrestaurants(vector<string>& restaurants)
{
	for (int i = 0; i < restaurants.size(); i++)
	{
		if (i < (restaurants.size() - 1))
			cout << restaurants[i] << ", ";
		else
			cout << restaurants[i] << endl;
	}
	return 0;
}

int printmenu(vector<string>& restaurants)
{
	int response = 1;

	do{
		cout << "Select option [0-5]:" << endl;
		cout << "1: Display all restaurants" << endl;
		cout << "2: Add a restaurant" << endl;
		cout << "3. Remove a restaurant" << endl;
		cout << "4. Shuffle the vector" << endl;
		cout << "5. Begin the tournament" << endl;
		cout << "0. Quit program" << endl;
		cout << ": ";

		cin >> response;
		cin.ignore();

		switch (response)
		{
		case 0:
			cout << "Thank you, come again." << endl;
			break;
		case 1:
			displayrestaurants(restaurants);
			break;
		case 2:
			addrestaurant(restaurants);
			break;
		case 3:
			removerestaurant(restaurants);
			break;
		case 4:
			shufflerestaurant(restaurants);
			break;
		case 5:
			if (ispoweroftwo(restaurants.size()))
			{
				tournament(restaurants);
				response = 0;
					break;
			}
			else
			{
				cout << "There are not 2^n restaurants. Add or remove more." << endl;
				break;
			}
		default:
			cout << "Invalid input..." << endl;
		}
	} while (response != 0);

	return 0;
}

int main()
{
	vector<string> restaurants;
	
	restaurants.push_back("Burger King");
	restaurants.push_back("McDonald's");
	restaurants.push_back("Wendy's");
	restaurants.push_back("Arby's");
	restaurants.push_back("In-n-Out");
	restaurants.push_back("Chick-fil-a");
	restaurants.push_back("Taco Bell");
	restaurants.push_back("Five Guys");
	restaurants.push_back("Jack in the Box");
	restaurants.push_back("KFC");
	restaurants.push_back("A&W");
	restaurants.push_back("Jimmy John's");
	restaurants.push_back("Subway");
	restaurants.push_back("Quizno's");
	restaurants.push_back("Sonic");
	restaurants.push_back("White Castle");
	/*
	restaurants.push_back("1");
	restaurants.push_back("2");
	restaurants.push_back("3");
	restaurants.push_back("4");
	restaurants.push_back("5");
	restaurants.push_back("6");
	restaurants.push_back("7");
	restaurants.push_back("8");
	restaurants.push_back("9");
	restaurants.push_back("10");
	restaurants.push_back("11");
	restaurants.push_back("12");
	restaurants.push_back("13");
	restaurants.push_back("14");
	restaurants.push_back("15");
	restaurants.push_back("16");
	*/

	printmenu(restaurants);

	system("pause()");
	return 0;
}