#pragma once

#include"State.h"
#include"Person.h"
#include"Voter.h"
#include"Candidate.h"
#include<map>

using namespace std;

class ElectionCommision
{

	static int voterCount;
	static int candidateCount;
	private:	
		map<std::string,int>mapStateNameStateID;
		// map<int, Election *> currentElections;     //map if ElectionId and Election *

		// map<int ,Election *> electionStatus;		//map of electionId and Election Status
	public:
		map<int,State *> states;                   //map of stateId and State *
		
		ElectionCommision();
		// ~ElectionCommision();
		Voter* registerNewVoter();
		bool verifyNewVoter( Person* personObj,pair<int,int>& pairStateIdAsmId);
		void registerNewCandidate(Person* person);
    	void addNewState(int,int );
    	void showStates();
		void createElection();
		void endElection();
		map<std::string,int> getMapStateNameStateId();
		void setMapStateNameStateId(std::string,int stateId);
		void verifyNewCandidate(Person* person);


};	