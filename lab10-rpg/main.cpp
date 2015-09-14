#include <iostream>
#include <vector>
#include "factory.h"
#include "arena.h"
using namespace std;
int testDriverMain(); // defined elsewhere, you don't need to worry about this.






const bool USE_PROVIDED_TEST_DRIVER = true; // if you want to use your test code, set this to false

int main()
{
	if (USE_PROVIDED_TEST_DRIVER)
	{
		testDriverMain();
	}
	else
	{
		// Put your test code here and change the value of USE_PROVIDED_TEST_DRIVER to false
		cout << "This is my test code!!" << endl;

		ArenaInterface* newArena = Factory::createArena();

		//Arena::newArena.addFighter("Fumblemore C 100 10 10 100");

		system("pause()");
	}
	return 0;
}
