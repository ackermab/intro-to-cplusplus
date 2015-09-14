#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

int main()
{
	/**********************************
	Part 1: Count your many pizzas
	**********************************/
	
	//Prompt for number of guests
	int numguests;
	cout << "How many guests will be in attendance? ";
	cin >> numguests;

	//Calculate pizzas needed
	//1 large for every 7, for every 3 left over get a medium,
	//and for every one left over, get a small.
	int numlargepizzas;
	int nummediumpizzas;
	int numsmallpizzas;
	numlargepizzas = numguests / 7;
	nummediumpizzas = (fmod(numguests, 7)) / 3;
	numsmallpizzas = (fmod(fmod(numguests, 7), 3));

	/**********************************
	Part 2: Serving Size
	**********************************/

	//Compute and report the total area of pizza needed
	//Radii of pizzas: L-10, M-8, S-6
	double totalpizzaarea;
	const double PI = 3.14159;
	totalpizzaarea = numlargepizzas * PI * pow(10, 2)
		+ nummediumpizzas * PI * pow(8, 2)
		+ numsmallpizzas * PI * pow(6, 2);
	cout << "The total pizza area (in square inches) is: " << totalpizzaarea << endl;

	//Compute and report the total area of pizza each guest can eat
	double areapizzaperguest;
	areapizzaperguest = totalpizzaarea / numguests;
	cout << "The total pizza area each guest receives is: " << areapizzaperguest << endl;

	/**********************************
	Part 3: Supplementing the Budget
	**********************************/

	//Prompt the user for tip percentage
	int tippercentage;
	cout << "What percentage of the cost would you like to add as a tip? ";
	cin >> tippercentage;

	//Compute and report the total cost
	double totalcost;
	totalcost = numlargepizzas * 14.68
		+ nummediumpizzas * 11.48
		+ numsmallpizzas * 7.28;
	totalcost = totalcost + totalcost * tippercentage / 100;
	cout << "The total cost of your order will be: $" << fixed << setprecision(0) << totalcost << endl;

	system("pause()");

	return 0;
}