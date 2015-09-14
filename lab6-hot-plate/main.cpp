#include <iostream>
#include <fstream>

using namespace std;

const int HEIGHT = 20;
const int WIDTH = 20;
const int UDTEMP = 100;
const int LRTEMP = 0;


int printarraytofile(double array[][WIDTH])
{
	ofstream fout;
	fout.open("final.csv");

	for (int k = 0; k < HEIGHT; k++)
	{
		for (int l = 0; l < WIDTH; l++)
		{
			fout << array[k][l] << ",";
		}

		fout << "\n";

	}

	return 0;
}

//This function will print the array with basic formatting of tabs and newlines
int printarray(double array[][WIDTH])
{
	for (int k = 0; k < HEIGHT; k++)
	{
		for (int l = 0; l < WIDTH; l++)
		{
			cout << array[k][l] << ",\t";
		}

		cout << "\n";

	}

	return 0;
}

double calculatetemp(double hotplate[][WIDTH])
{
	//Part 2, Updates the elements of the array
	double changetovalue;
	double maxchange = 0;

	for (int i = 1; i < (HEIGHT - 1); i++)
	{
		for (int j = 1; j < (WIDTH - 1); j++)
		{
			changetovalue = ((hotplate[i-1][j] + hotplate[i][j-1] + hotplate[i+1][j] + hotplate[i][j+1]) / 4);		

			if ((changetovalue - hotplate[i][j]) > maxchange)
				maxchange = (changetovalue - hotplate[i][j]);

			hotplate[i][j] = changetovalue;
		}
	}

	return maxchange;
}

int main()
{
	double hotplate[HEIGHT][WIDTH] = { 0 }; //Initialize hotplate as all zeroes

	//Part 1, Create initial array
	for (int i = 0; i < HEIGHT; i++)
	{
		for (int j = 0; j < WIDTH; j++)
		{
			if (j == 0 || j == (WIDTH - 1))
				hotplate[i][j] = LRTEMP; //Left and right sides are LRTEMP
			else if (i == 0 || i == (HEIGHT - 1))
				hotplate[i][j] = UDTEMP; //Top and bottom (not corners) are UDTEMP
		}
	}

	//printarray(hotplate);

	//Part 3, Repeats as long as the change is greater than .1
	while (calculatetemp(hotplate) > 0.1);
	
	//Part 4, print to .csv file
	printarraytofile(hotplate);

	system("pause()");

	return 0;
}