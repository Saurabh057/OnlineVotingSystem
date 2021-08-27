#include<iostream>
#include"ElectionCommision.h"
using namespace std;

int main(int argc, char const *argv[])
{
	ElectionCommision e;
	int temp;
	// State s[29];
	

	for(int i=0;i<2;i++)
	{
		cout<<"How many Assembly?\t";
	
		cin>>temp;
		e.addNewState(i,temp);		
	
	
	}

	e.showStates();




	e.registerNewVoter();
	// s[0].showAssemblyDetails();

	return 0;
}

