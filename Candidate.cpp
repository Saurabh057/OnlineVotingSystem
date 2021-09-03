#include<iostream>
#include "Candidate.h"

void Candidate::regist()
{

}

pair<int,Person *> Candidate::getCandidatePersonPair()
{
    return personalDetails;
}
void Candidate::setCandidatePersonPair(int candidateid,Person *p)
{
    personalDetails.first=candidateid;
    personalDetails.second=p;
}

void Candidate::displayCandidateDetails()
{
    cout<<"\n*************Candidate Details**************"<<endl;
    cout<<"Candidate ID:"<<candidateId<<endl;
    personalDetails.second->displayPersonalDetails();
}

int Candidate::getStateId()
{
    return this->stateId;
}

void Candidate::setStateId(int stateId)
{
    this->stateId = stateId;
}
int* Candidate::getAssemblyId()
{
    return this->assemblyId;
}

bool Candidate::setAssemblyId(int asmId)
{
    if(assemblyId[0] == -1){
        assemblyId[0] = asmId;
    }else if(assemblyId[1] == -1){
        assemblyId[1] = asmId;
    }else{
        return false;
    }
    return true;
}

int Candidate::getElectionId()
{

    return this->electionId;
}
void Candidate::setElectionId(int electionId)
{
    this->electionId = electionId;
}


