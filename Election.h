#pragma once
#include<iostream>
#include<vector>
#include "Candidate.h"

class Election
{
	private:
		int electionId;
		int stateId;
		int assemblyId;
		map<int,vector<Candidate>>candidateList; 			//map of electionId and Candidate 

	public:
		Election();
		void displayResult();
		void showElectionDetails();
	// ~Election();
	
};