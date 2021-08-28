#include "Election.h"
#include "ElectionCommision.h"
#include <iostream>
using namespace std;

extern ElectionCommision e;

Election::Election()
{
	electionStatus = false;
}

void Election::acceptElectionDetails()
{
	cout<<"\n**************Accepting Election Details*************"<<endl;
	int no;
	cout << "Enter Election Name" << endl;
	cin >> electionName;
	cout << "Enter No of States in which you want to conduct Election" << endl;
	cin >> no;
	int temp;
	for (int i = 0; i < no; i++)
	{
		cout << "Enter State Id of State" << endl;
		cin >> temp;
		stateIds.push_back(temp);
	}
}

void Election::showElectionDetails()
{
	cout << "\n********Election Details***********" << endl;
	cout << "Election Name" << endl;
	cout << electionName;

	for (auto x : stateIds)
	{
		cout << x;
	}
}
string Election::getElectionName()
{
	return electionName;
}
vector<int> Election::getstateIds()
{
	return stateIds;
}

void Election::setElectionId(int no)
{
	electionId = no;
}
int Election::getElectionId()
{
	return electionId;
}