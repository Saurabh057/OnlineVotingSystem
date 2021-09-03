#include "ElectionCommision.h"

#include <iostream>
using namespace std;

ElectionCommision::ElectionCommision()
{
}

int ElectionCommision::voterCount = 0;
int ElectionCommision::candidateCount = 0;
int ElectionCommision::electionCount = 0;

Voter *ElectionCommision::registerNewVoter()
{
	Voter *voterObj;
	Person *personObj = new Person();
	personObj->acceptPersonDetails();

	pair<int,int>pairStateIdAsmId;
    /* Generate Voter_ID and Assembly_ID if the candidate is eligible based on the address after verification*/
	if(verifyNewVoter(personObj,pairStateIdAsmId))                                  
	{
		int voterId = ++voterCount; 
		voterObj=new Voter();
		int stateId = pairStateIdAsmId.first;
		int assemblyId = pairStateIdAsmId.second;
		personObj->setAssemblyId(assemblyId);
		voterObj->setVoterPersonPair(voterId,personObj);
		voterObj->setAssemblyId(assemblyId);
		voterObj->setStateId(stateId);
		states[stateId]->assemblyList[assemblyId]->setVoterList(voterId, voterObj);
		states[stateId]->assemblyList[assemblyId]->getVoterList()[1]->displayVoterDetails();
	}

	std::cout<<"{{{{{{{{     Voter Registered       }}}}}}}"<<std::endl;

	return voterObj;
}

void ElectionCommision::registerNewCandidate(Person* person)
{
	Candidate *candidateObj;

	int stateId,asmId,inputElectionId;

	cout << "\n****************Here is List of All Ongoing Elections***************" << endl;
	cout << "\nElection Id\t\tElection Name" << endl;
	for (auto x : electionsList)
	{
		cout << x.first << "\t\t" << x.second->getElectionName() << endl;
	}

	cout << "Enter Election Id of Which You want to contest the Election" << endl;
	cin >> inputElectionId;

	cout << "\nHere is List of States in which this Election is going on" << endl;
	cout << "State Id \t\t State Name" << endl;
	for (auto x : electionsList[inputElectionId]->getstateIds())
	{
		cout << x << "\t\t" << states[x]->getStateName() << endl;
	}

	cout << "\nEnter State Id of which you want to see Details" << endl;
	cin >> stateId;

	std::cout<<"\nAssembly List. Enter Assembly Id In Which You Want To Contest :"<<endl;
	std::cout<<"AssemblyId "<<"Assembly Name"<<endl;
	for(auto x:states[stateId]->assemblyList){
		std::cout<< x.first << "\t" <<x.second->getAssemblyName() <<endl;
	}
	cout<<"INPUT :";
	cin>>asmId;

	if(1)                                  
	{
		int candidateId = ++candidateCount;
		candidateObj=new Candidate();
		if(candidateObj->setAssemblyId(asmId)){
			candidateObj->setCandidatePersonPair(candidateId,person);
			states[stateId]->assemblyList[asmId]->setCandidateList(candidateId, candidateObj);
			states[stateId]->assemblyList[asmId]->setCandidateVotesList(candidateId, 0);
			states[stateId]->assemblyList[asmId]->getCandidateList()[1]->displayCandidateDetails();
			candidateObj->setStateId(stateId);
			candidateObj->setElectionId(inputElectionId);
		}else{
			std::cout<<"Cannot contest in more than 2 assemblies"<<std::endl;
			delete candidateObj;
		}
	}
	std::cout<<"{{{{{{{{     Candidate Registered       }}}}}}}"<<std::endl;
}

void ElectionCommision::createElection()
{
	Election *electionObj = new Election();
	electionObj->setElectionId(++electionCount);
	electionObj->acceptElectionDetails();

	electionsList.insert({electionObj->getElectionId(), electionObj});
}

void ElectionCommision::showOngoingElectionDetails()
{
	int inputElectionId, inputStateId, inputAssemblyId;
	cout << "\n****************Here is List of All Ongoing Elections***************" << endl;
	cout << "\nElection Id\t\tElection Name" << endl;
	for (auto x : electionsList)
	{
		cout << x.first << "\t\t" << x.second->getElectionName() << endl;
	}

	cout << "Enter Election Id of Which You want to see Details" << endl;
	cin >> inputElectionId;

	cout << "\nHere is List of States in which this Election is going on" << endl;
	cout << "State Id \t\t State Name" << endl;
	for (auto x : electionsList[inputElectionId]->getstateIds())
	{
		cout << x << "\t\t" << states[x]->getStateName() << endl;
	}

	cout << "\nEnter State Id of which you want to see Details" << endl;
	cin >> inputStateId;

	cout << "\nHere is List of Asselmblies in This State" << endl;
	for (auto x : states[inputStateId]->assemblyList)
	{
		cout << x.first << "\t\t" << x.second->getAssemblyName() << endl;
	}
	cout << "\nEnter Assembly Id of which you want to see Details" << endl;
	cin >> inputAssemblyId;
	cout << "\nHere List of Candidates in this Assembly" << endl;
	cout << "\nCandidate ID \t\tCandidate Name\t\tCandidate Votes" << endl;
	for (auto x : states[inputStateId]->assemblyList[inputAssemblyId]->getCandidateList())
	{
		cout << x.first << "\t\t" << x.second->getCandidatePersonPair().second->getName() << "\t\t";
		//cout << states[inputStateId]->assemblyList[inputAssemblyId]->getCandidateVotesList()[x.first] << endl;
	}

}

void ElectionCommision::addNewState(int i, int no)
{
	State *stateObj = new State(i, no);
	if (states.find(i) == states.end())
	{
		states.insert({stateObj->getStateId(), stateObj});
		cout << "Record Inserted" << endl;
	}
	else
	{
		cout << "State ID alredy exist in Record" << endl;
	}
}

void ElectionCommision::showStates()
{
	std::cout << "**********STATES DETAILS************" << endl;
	for (auto x : states)
	{
		cout << "State ID :" << x.first << endl;
		(x.second)->showAssemblyDetails();
	}
}

bool ElectionCommision::verifyNewVoter( Person* personObj,pair<int,int>& pairStateIdAsmId){

	map<std::string,int>mapStateNameStateID;
	mapStateNameStateID.insert({"Maharashtra",0});
	mapStateNameStateID.insert({"Madhya Pradesh",1});
	mapStateNameStateID.insert({"Kerala",2});
	mapStateNameStateID.insert({"Manipur",4});

	//map<std::string,map<std::string,int>> mapCityAssembly;
	map<std::string,int> assemblyNameAssemblyId;

	assemblyNameAssemblyId.insert({"Kasba Peth",0});
	assemblyNameAssemblyId.insert({"Kothrud",1});
	assemblyNameAssemblyId.insert({"Baramati",2});

	//mapCityAssembly.insert({"Pune",assemblyNameAssemblyId});
	
	if(personObj->getAge() > 18){
		pairStateIdAsmId.first = mapStateNameStateID["Maharashtra"];//states[personObj->getAddress().state];
		pairStateIdAsmId.second = assemblyNameAssemblyId["Kasba Peth"];//mapAsmCity[personObj->getAddress().city]["Kothrud"];
		//states[pairStateIdAsmId.first]->getAssemblyNameAssemblyId()["Kasba Peth"];
		return true;
	}else{
		return false;
	}
}

map<std::string,int> ElectionCommision::getMapStateNameStateId() {
	return mapStateNameStateID;
}

void ElectionCommision::setMapStateNameStateId(std::string,int stateId){

}