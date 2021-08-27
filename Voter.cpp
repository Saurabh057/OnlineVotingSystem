#include<iostream>
#include"Voter.h"
// #include"Assembly.h"
// #include"Person.h"
using namespace std;

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
    cout << "Select a Candidate to Vote :" << endl;
    cout<<"Candidate Id.\tName OF Candidate\tParty Name"<<endl;
    for(auto x:candidateList)
    {
        cout<<x.first<<x.second->personalDetails().second->getName();
    }

    // //Display Candidate list
    cin >> voteNum;

    candidateVotes[voteNum]++;
    // if (/*candidate_vote_count*/ == vote_num)
    // {
    //     candidate_vote_count++;
    // }

}

void Voter::displayVoterDetails()
{
    cout<<"Voter ID:"<<voterId<<endl;
    personalDetails.second->displayPersonalDetails();
}


