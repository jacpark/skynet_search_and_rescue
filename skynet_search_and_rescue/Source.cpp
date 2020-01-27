#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;
 
int main()
{
	//seed random number generator
	srand(static_cast<unsigned int>(time(0)));

	//represents numbers on 8x8 grid
	int searchGridLowNumber = 1;
	int searchGridHighNumber = 64;
	//Generate location of lost soul at a random number between 1 and 64
	int actualTargetLocation = rand() % searchGridHighNumber + searchGridLowNumber;

	//Integer keeps track of number or attemps 
	int tries = 0;
	//integer variable, actual number on grid the AI is currently seaching
	int attemptLocateTarget = 0;

	cout << "\tWelcome to search and rescue\n";

	//loop that continues until AI finds target
	do
	{
		//This is where the AI makes a guess where the target is located
		attemptLocateTarget = ((searchGridHighNumber - searchGridLowNumber) / 2) + searchGridLowNumber;;
		++tries;
		cout << "Real target location is at " << actualTargetLocation << endl;
		cout << "The AI guesses the lost soul is at location " << attemptLocateTarget << endl;

		//If the AI guess too high this happens
		if (attemptLocateTarget > actualTargetLocation)
		{
			cout << "The AI's attempted guess was too high!\n\n";
			//This is where we refine our search based on the last guess
			searchGridHighNumber = attemptLocateTarget - 1;
		}
		//If the AI guess too low this happens
		else if (attemptLocateTarget < actualTargetLocation)
		{
			cout << "The AI's attempted guess was too low\n\n";
			//This is where we refine our search based on the last guess
			searchGridLowNumber = attemptLocateTarget + 1;
		}
		//Once the AI guesses the correct location this will happen
		else
		{
			cout << "\nThat's it! You got it in " << tries << " guesses!\n";
		}
		//Maintains the loop until the AI guesses the correct location
	} while (attemptLocateTarget != actualTargetLocation);
	return 0;
}
