#pragma once

#include<iostream>
#include<vector>
#include<map>
using namespace std;

 
class Voter;
class Candidate;

class Assembly
{

	int assemblyNo; 				// was AssemblyNo
	string assemblyName; 			// was AssemblyName
	int population; 				// was Population
	int eligibleVotersCount; 		// was EligibleVoters
	int currentCandidateId;
	
	public:
	map<int,int> candidateVotes;	
	map<int,Voter *> voterList; 			//Map Of VoterId and PersonDetails
	map<int,Candidate * > candidateList; 	//Map of CandidateId and PersonDetails.
		
		Assembly(); 
		Assembly(int,std::string,int,int,int,int); //AssemblyId,AssemblyName,Population,VoterCount will be given by State Class while initialising its Assemblylist in its instance.
		int getAssemblyNo();
		string getAssemblyName();
		int getPoulation();
		int getEligibleVoters();
		void showAssemblyDetails();

		// void addVoter(int voterId,Person* person); 
		void addVote(int candidateId);
		// 	void findWinner();
		void displayVoters();
		// ~Assembly();
		void showCandidateVotes();	
};

/* Voter Class will have to call Election Commission class to verify and add voter.
	ElectionCommission will see the stateId and will add accordingly, It will further call StateClass to add the 
	that Voter into respective AssemblyId's instance.
*/
