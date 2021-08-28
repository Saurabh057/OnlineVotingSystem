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
	int stateId,asmId;

	std::cout<<"\nState List.Enter State You Want To Contest :"<<endl;
	std::cout<<"StateId  "<<"State Name"<<endl;
	for(auto x:states){
		std::cout<<x.first<<"\t"<<x.second->getStateName()<<endl;
	}
	cout<<"INPUT :";
	cin>>stateId;
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
		candidateObj->setCandidatePersonPair(candidateId,person);
		states[stateId]->assemblyList[asmId]->setCandidateList(candidateId, candidateObj);
		states[stateId]->assemblyList[asmId]->setCandidateVotesList(candidateId, 0);
		states[stateId]->assemblyList[asmId]->getCandidateList()[1]->displayCandidateDetails();
	}

	std::cout<<"{{{{{{{{     Candidate Registered       }}}}}}}"<<std::endl;
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

bool ElectionCommision::verifyNewVoter( Person* personObj,pair<int,int>& pairStateIdAsmId){

	/*map<std::string,int>mapStateNameStateID;
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
	*/
	if(personObj->getAge() > 18){
		pairStateIdAsmId.first = mapStateNameStateID["Maharashtra"];//states[personObj->getAddress().state];
		//pairStateIdAsmId.second = assemblyNameAssemblyId["Kasba Peth"];//mapAsmCity[personObj->getAddress().city]["Kothrud"];
		states[pairStateIdAsmId.first]->getAssemblyNameAssemblyId()["Kasba Peth"];
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