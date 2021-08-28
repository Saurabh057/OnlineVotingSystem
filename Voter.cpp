#include<iostream>
#include"Voter.h"
#include "ElectionCommision.h"
using namespace std;

extern ElectionCommision e;

pair<int,Person *> Voter::getVoterPersonPair()
{
    return personalDetails;
}

void Voter::setVoterPersonPair(int voterid,Person *p)
{
    personalDetails.first=voterid;
    personalDetails.second=p;
}
 
void Voter::vote()
{
    int voteNum;
    cout <<"\n********Select a Candidate to Vote :**********"<< endl;
    cout<<"Candidate Id.\tName OF Candidate\tParty Name "<<endl;
    for(auto x : e.states[stateId]->assemblyList[assemblyId]->getCandidateList())
    {
        cout<<x.first<<"\t\t"<<x.second->getCandidatePersonPair().second->getName()<<"\t\t\t"<<"Congress"<<endl;
    }
    cin >> voteNum;
    std::cout<<"\n<<<<<<<<<<<<<<<<DUMMY>>>>>>>>>>>>>>"<<std::endl;

    (*(e.states[stateId]->assemblyList[assemblyId]->getCandidateVotesList()))[voteNum]++;
    e.states[stateId]->assemblyList[assemblyId]->showCandidateVotes();
}

void Voter::displayVoterDetails()
{
    cout<<"\n**************Voter Details **************"<<endl;
    cout<<"Voter ID:"<<voterId<<endl;
    personalDetails.second->displayPersonalDetails();
}

void Voter::setStateId(int stateId){
    this->stateId = stateId;
}

int Voter::getStateId(){
    return stateId;
}

void Voter::setAssemblyId(int assemblyId){
    this->assemblyId = assemblyId;
}

int Voter::getAssemblyId(){
    return assemblyId;
}