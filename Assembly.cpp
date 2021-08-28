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

void Assembly::displayVoters(){
	
	for(int i=0 ;i<getEligibleVoters();++i){
		//std::cout<<voterList[i]->getPersonDetails(); // Person Class Should have getPersonDetails()
	}
}

void Assembly::addVote(int candidateId){
	this->candidateVotes[candidateId]++;
}

void Assembly::showCandidateVotes()
{
	cout<<"Candidates Id\tTotal Votes"<<endl;
	for(auto x:candidateVotes)
	{
		cout<<x.first<<"\t\t"<<x.second<<endl;
	}
}	

/* 	ElectionClass will contain display Election results.
	It will call all assemblies findWinner();
	findWinner() will return winner's candidate ids.
	ElectionClass can store these candidate ids and then print the candidate details over there */

int Assembly::findWinner(){
 	pair<int,int>temp  = make_pair(0,0);
 	map<int,int>::iterator iter;
 	for(iter = candidateVotes.begin();iter != candidateVotes.end();iter++){
 		if(iter->second > temp.second){
 			temp = make_pair(iter->first,iter->second);
 		}
 	}
 	if(temp.first != 0){
 		this->currentCandidateId = temp.first;
 	}
 	return currentCandidateId;
}

void Assembly::showAssemblyDetails()
{
	cout<<"\nBelow are Assembly Details\n\t";

	cout<<"\n\tAssembly Name:\t\t\t\t"<<getAssemblyName();
	cout<<"\n\tAssembly Population:\t\t\t"<<getPoulation();
	cout<<"\n\tNumber of Eiligible Voters:\t\t"<<getEligibleVoters();
	for(int i=0;i<getEligibleVoters();i++){
		//std::cout<<voterList[i]->getPersonDetails()<<std::endl; // Person Class Should have getPersonDetails()
	}
	cout<<endl;
}

map<int,int>* Assembly::getCandidateVotesList(){

	return &candidateVotes;
}

map<int,Voter*> Assembly::getVoterList(){
	return voterList;
}

map<int,Candidate*> Assembly::getCandidateList(){
	return candidateList;
}

void Assembly::setCandidateList(int candidateId,Candidate* candidateObj){
	candidateList[candidateId] = candidateObj;
}

void Assembly::setVoterList(int voterId,Voter* voterObj){
	voterList[voterId] = voterObj;
}

void Assembly::setCandidateVotesList(int candidateId,int votes ){
	candidateVotes[candidateId] = votes;
}