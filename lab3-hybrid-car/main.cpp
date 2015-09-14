#include <iostream>
#include <string>
using namespace std;

/*********************************************************************
Test criteria to use
-----------------------
estmilesperyear: 10,000 : 15,000 : 20,000
gasprice:		 2.50	: 2.55	 : 2.60
hybridcost:		 32,000 : 28,000 : 36,000
hybridmpg:		 166.67 : 100	 : 60
hybridresale:	 24,000 : 21,000 : 27,000
nonhybridcost:   15,000 : 20,000 : 28,000
nonhybridmpg:	 25		: 20	 : 18
nonhybridresale: 11,250 : 15,000 : 21,000
buyingcriteria:	 Gas	: Gas	 : Total
**********************************************************************/

int main()
{
	/*************************************************************************************
	Part 1: User Input (estimated miles per year, estimated price of gas, cost of hybrid,
						hybrid mpg, resale value after 5yrs, cost of non-hybrid, 
						non-hybrid mpg, resale value of non-hybrid, buying criteria.
	*************************************************************************************/
	double estmilesperyear;
	double gasprice;
	double hybridcost;
	double hybridmpg;
	double hybridresale;
	double nonhybridcost;
	double nonhybridmpg;
	double nonhybridresale;
	string buyingcriteria;

	//Receive all input, with test to assure numbers are positive
	cout << "How many miles do you drive each year? ";
	cin >> estmilesperyear;
	if (estmilesperyear < 0)
	{
		cout << "ERROR: Please input a positive number: ";
		cin >> estmilesperyear;
	}

	cout << "What are gas prices (in dollars per gallon)? ";
	cin >> gasprice;
	if (gasprice < 0)
	{
		cout << "ERROR: Please input a positive number: ";
		cin >> gasprice;
	}

	cout << "What is the cost of a hybrid car? ";
	cin >> hybridcost;
	if (hybridcost < 0)
	{
		cout << "ERROR: Please input a positive number: ";
		cin >> hybridcost;
	}

	cout << "What is the efficiency of the hybrid (mpg)? ";
	cin >> hybridmpg;
	if (hybridmpg < 0)
	{
		cout << "ERROR: Please input a positive number: ";
		cin >> hybridmpg;
	}

	cout << "What will the resale value be after 5 years? ";
	cin >> hybridresale;
	if (hybridresale < 0)
	{
		cout << "ERROR: Please input a positive number: ";
		cin >> hybridresale;
	}

	cout << "What is the cost of a non-hybrid car? ";
	cin >> nonhybridcost;
	if (nonhybridcost < 0)
	{
		cout << "ERROR: Please input a positive number: ";
		cin >> nonhybridcost;
	}

	cout << "What is the efficiency of the non-hybrid (mpg)? ";
	cin >> nonhybridmpg;
	if (nonhybridmpg < 0)
	{
		cout << "ERROR: Please input a positive number: ";
		cin >> nonhybridmpg;
	}

	cout << "What will the resale value be after 5 years? ";
	cin >> nonhybridresale;
	if (nonhybridresale < 0)
	{
		cout << "ERROR: Please input a positive number: ";
		cin >> nonhybridresale;
	}

	cout << "What are you basing your purchase off of (\"Gas\" Consumption or \"Total\" Cost)? ";
	cin >> buyingcriteria;
	if (buyingcriteria != "Gas" && buyingcriteria != "Total")
	{
		cout << "ERROR: Please input \"Gas\" or \"Total\": ";
		cin >> buyingcriteria;
	}

	/*************************************************************************************
	Part 2: Output costs
	*************************************************************************************/
	//Determine which car type is better for the buying criteria
	double hybridgasfiveyear = (estmilesperyear * 5.0) / hybridmpg;
	double nonhybridgasfiveyear = (estmilesperyear * 5.0) / nonhybridmpg;
	double totalhybridcost = gasprice * hybridgasfiveyear + (hybridcost - hybridresale);
	double totalnonhybridcost = gasprice * nonhybridgasfiveyear + (nonhybridcost - nonhybridresale);

	//If Gas is chosen show car label for better gas car then label for worse
	if (buyingcriteria == "Gas")
	{
		if (hybridmpg > nonhybridmpg)
		{
			cout << "Hybrid Car Information" << endl;
			cout << "-----------------------------------------------" << endl;
			cout << "Gallons of gas used in 5 years: " << hybridgasfiveyear << endl;
			cout << "Total cost to own for 5 years: $" << totalhybridcost << endl;
			cout << "-----------------------------------------------" << endl << endl;

			cout << "Non-Hybrid Car Information" << endl;
			cout << "-----------------------------------------------" << endl;
			cout << "Gallons of gas used in 5 years: " << nonhybridgasfiveyear << endl;
			cout << "Total cost to own for 5 years: $" << totalnonhybridcost << endl;
			cout << "-----------------------------------------------" << endl << endl;
		}
		else
		{
			cout << "Non-Hybrid Car Information" << endl;
			cout << "-----------------------------------------------" << endl;
			cout << "Gallons of gas used in 5 years: " << nonhybridgasfiveyear << endl;
			cout << "Total cost to own for 5 years: $" << totalnonhybridcost << endl;
			cout << "-----------------------------------------------" << endl << endl;

			cout << "Hybrid Car Information" << endl;
			cout << "-----------------------------------------------" << endl;
			cout << "Gallons of gas used in 5 years: " << hybridgasfiveyear << endl;
			cout << "Total cost to own for 5 years: $" << totalhybridcost << endl;
			cout << "-----------------------------------------------" << endl << endl;
		}
	}
	//If Total cost is chosen show car label for better total cost then label for worse
	else
	{
		if (totalhybridcost < totalnonhybridcost)
		{
			cout << "Hybrid Car Information" << endl;
			cout << "-----------------------------------------------" << endl;
			cout << "Total cost to own for 5 years: $" << totalhybridcost << endl;
			cout << "Gallons of gas used in 5 years: " << hybridgasfiveyear << endl;
			cout << "-----------------------------------------------" << endl << endl;

			cout << "Non-Hybrid Car Information" << endl;
			cout << "-----------------------------------------------" << endl;
			cout << "Total cost to own for 5 years: $" << totalnonhybridcost << endl;
			cout << "Gallons of gas used in 5 years: " << nonhybridgasfiveyear << endl;
			cout << "-----------------------------------------------" << endl << endl;
		}
		else
		{
			cout << "Non-Hybrid Car Information" << endl;
			cout << "-----------------------------------------------" << endl;
			cout << "Total cost to own for 5 years: $" << totalnonhybridcost << endl;
			cout << "Gallons of gas used in 5 years: " << nonhybridgasfiveyear << endl;
			cout << "-----------------------------------------------" << endl << endl;

			cout << "Hybrid Car Information" << endl;
			cout << "-----------------------------------------------" << endl;
			cout << "Total cost to own for 5 years: $" << totalhybridcost << endl;
			cout << "Gallons of gas used in 5 years: " << hybridgasfiveyear << endl;
			cout << "-----------------------------------------------" << endl << endl;
		}
	}

	system("pause()");

	return 0;
}