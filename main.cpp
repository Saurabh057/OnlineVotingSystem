#include<iostream>
#include"ElectionCommision.h"
using namespace std;

ElectionCommision e;

int main(int argc, char const *argv[])
{	
	int temp;
	// State s[29];
	for(int i=0;i<2;i++)
	{
		cout<<"How many Assembly?\t";
		cin>>temp;
		e.addNewState(i,temp);		

	}
	e.showStates();
	Voter* voter = e.registerNewVoter();
	e.registerNewCandidate();
	// s[0].showAssemblyDetails();
	voter->vote();

	return 0;
}

