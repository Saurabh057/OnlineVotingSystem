#pragma once

class Election
{

	private:
		int electionId;
		int stateId;
		// map<int,vector<Candidate>> candidateList; 			//map of assemblyId and Candidate 

	public:
		Election();
		void displayResult();
		void showElectionDetails();
	// ~Election();
	
};