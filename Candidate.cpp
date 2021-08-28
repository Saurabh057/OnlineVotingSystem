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


