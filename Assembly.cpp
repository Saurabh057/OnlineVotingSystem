//#include<iostream>
#include<list>
#include<map>
//#include<bits/stdc++.h>
#include"Assembly.h"
// #include"Voter.h"

using namespace std;

Assembly::Assembly()
{

 	assemblyNo=10;
	assemblyName="Baramati";
	population=2001;
	eligibleVotersCount=1953;
}

Assembly::Assembly(int assemblyId,std::string assemblyName,int population,int voterCount,int currentCandidateId,int candidateCount){

	this->assemblyNo = assemblyId;
	this->assemblyName = assemblyName;
	this->population = population;
	this->eligibleVotersCount = voterCount;
	this->currentCandidateId = currentCandidateId;
	/*for(int i=0;i<candidateCount;i++){
		this->candidateList.insert<pair<int,
	}
	map<int,Person * > candidateList;
	for(int i=0;i<candidateCount;i++){
		this->candidateVotes.insert(pair<int,int>(candidateId,0));
	}*/
}
int Assembly::getAssemblyNo()
{
	return assemblyNo;
}

string Assembly::getAssemblyName()
{
		return assemblyName;
}
int Assembly::getPoulation()
{
	return population;
}
int Assembly::getEligibleVoters()
{
	return eligibleVotersCount;
}

// void Assembly::addVoter(int voterId,Person* person){
// 	this->voterList.insert(pair<int,Person*>(voterId,person)); 
// }

void Assembly::displayVoters(){
	
	for(int i=0 ;i<getEligibleVoters();++i){
		//std::cout<<voterList[i]->getPersonDetails(); // Person Class Should have getPersonDetails()
	}
}

void Assembly::addVote(int candidateId){
	this->candidateVotes[candidateId]++;
}

// std::string Assembly::findWinner(){
// 	pair<int,int>temp  = make_pair(0,0);
// 	map<int,int>::iterator iter;
// 	for(iter = candidateVotes.begin();iter != candidateVotes.end();iter++){
// 		if(iter->second > temp.second){
// 			temp = make_pair(iter->first,iter->second);
// 		}
// 	}
// 	if(temp.first != 0){
// 		this->currentCandidateId = temp.first;
// 	}
// 	return 0;
// }

void Assembly::showAssemblyDetails()
{
	cout<<"\nBelow are Assembly Details\n\t";

	cout<<"\n\tAssembly Name:\t\t"<<getAssemblyName();
	cout<<"\n\tAssembly Population:\t\t"<<getPoulation();
	cout<<"\n\tNumber of Eiligible Voters:\t\t"<<getEligibleVoters();
	for(int i=0;i<getEligibleVoters();i++){
		//std::cout<<voterList[i]->getPersonDetails()<<std::endl; // Person Class Should have getPersonDetails()
	}
	cout<<endl;
}