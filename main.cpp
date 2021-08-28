#include <iostream>
#include "ElectionCommision.h"
using namespace std;

ElectionCommision e;

int main(int argc, char const *argv[])
{
	int temp;
	// State s[29];
	for (int i = 0; i < 2; i++)
	{
		cout << "How many Assembly?\t";
		cin >> temp;
		e.addNewState(i, temp);
	}
	e.showStates();
	e.createElection();
	Voter *voter = e.registerNewVoter();
	e.registerNewCandidate();
	e.showOngoingElectionDetails();
	// s[0].showAssemblyDetails();
	voter->vote();

	e.showOngoingElectionDetails();

	return 0;
}
