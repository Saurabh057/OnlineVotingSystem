#include "ElectionCommision.h"

#include<iostream>
using namespace std;

ElectionCommision::ElectionCommision()
{

}

int ElectionCommision::voterCount=0;
int ElectionCommision::candidateCount=0;


Voter* ElectionCommision::registerNewVoter()
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
		voterObj->setVoterPersonPair(voterId,personObj);
		voterObj->setAssemblyId(assemblyId);
		voterObj->setStateId(stateId);

		states[stateId]->assemblyList[assemblyId]->setVoterList(voterId, voterObj);
		states[stateId]->assemblyList[assemblyId]->getVoterList()[1]->displayVoterDetails();

	}
	return voterObj;
}

void ElectionCommision::registerNewCandidate()
{
	Candidate *candidateObj;
	Person *personObj=new Person();
	personObj->acceptPersonDetails();
    /* Generate Voter_ID and Assembly_ID if the candidate is eligible based on the address after verification*/
	if(1)                                  
	{
		int candidateId = ++candidateCount;
        int assemblyId = 0;
        int stateId=0;
		candidateObj=new Candidate();
		candidateObj->setCandidatePersonPair(candidateId,personObj);
		states[stateId]->assemblyList[assemblyId]->setCandidateList(candidateId, candidateObj);
		states[stateId]->assemblyList[assemblyId]->setCandidateVotesList(candidateId, 0);
		states[stateId]->assemblyList[assemblyId]->getCandidateList()[1]->displayCandidateDetails();
	}

}

void ElectionCommision::addNewState(int i,int no)
{	
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
	std::cout<<"**********STATES DETAILS************"<<endl;
	for(auto x:states)
	{
		cout<<"State ID :"<<x.first<<endl;
		(x.second)->showAssemblyDetails();
	}
}
