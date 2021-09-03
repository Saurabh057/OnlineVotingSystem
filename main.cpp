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

	Voter* voter1 = e.registerNewVoter();
	Voter* voter2 = e.registerNewVoter();

	e.createElection();
	e.showOngoingElectionDetails();
	voter1->registerAsCandidate();


	// s[0].showAssemblyDetails();
	voter1->vote();
	voter2->vote();

	e.showOngoingElectionDetails();

	return 0;
}
