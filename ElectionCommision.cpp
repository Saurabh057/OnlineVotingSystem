#include"ElectionCommision.h"

#include<iostream>
using namespace std;


ElectionCommision::ElectionCommision()
{

}
int ElectionCommision::voterCount=0;
void ElectionCommision::registerNewVoter()
{
	Voter *voterObj;
	Person *personObj=new Person();
	personObj->acceptPersonDetails();
    /* Generate Voter_ID and Assembly_ID if the candidate is eligible based on the address after verification*/
	if(1)                                  
	{
		int voterId = ++voterCount;
        int assemblyId = 0;
        int stateId=0;
		voterObj=new Voter();
		voterObj->personalDetails.first=voterId;
		voterObj->personalDetails.second=personObj;


		states[stateId]->assemblyList[assemblyId]->voterList.insert({voterId, voterObj});
		states[stateId]->assemblyList[assemblyId]->voterList[1]->personalDetails.second->displayPersonalDetails();

	}

}
void ElectionCommision::addNewState(int i,int no)
{
// 	int num;
// 	cout<<"\nEnter state Id\t";
// 	cin>>num;
// 	stateObj.setStateId(num);	
	State * stateObj=new State(i,no);
    if (states.find(i) == states.end()) {


		states.insert({stateObj->getStateId(),stateObj});
    	

    	cout<<"Record Inserted"<<endl;

	}
	else
	{
		cout<<"State ID alredy exist in Record"<<endl;
	}
}




void ElectionCommision::showStates()
{
	for(auto x:states)
	{
		cout<<"State ID"<<x.first<<endl;
		(x.second)->showAssemblyDetails();
	}
}
