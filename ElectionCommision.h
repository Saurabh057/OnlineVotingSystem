#pragma once

#include"State.h"
#include"Person.h"
#include"Voter.h"
#include"ElectionCommision.h"
#include<bits/stdc++.h>
using namespace std;

class ElectionCommision
{

	static int voterCount;
	private:	

		// map<int, Election *> currentElections;     //map if ElectionId and Election *

		// map<int ,Election *> electionStatus;		//map of electionId and Election Status
	public:
		map<int,State *> states;                   //map of stateId and State *
		
		ElectionCommision();
		// ~ElectionCommision();
		void registerNewVoter();
    	void addNewState(int,int );
    	void showStates();
		void createElection();
		void endElection();
		void verifyCandidate();

};	