#pragma once

#include "State.h"
#include "Person.h"
#include "Voter.h"
#include "Candidate.h"
#include "Election.h"
#include <map>

using namespace std;

class ElectionCommision
{

	static int voterCount;
	static int candidateCount;
	static int electionCount;

private:
	map<int, Election *> electionsList; //map if ElectionId and Election *

public:
	map<int, State *> states; //map of stateId and State *

	ElectionCommision();
	// ~ElectionCommision();
	Voter *registerNewVoter();
	void registerNewCandidate();
	void addNewState(int, int);
	void showStates();
	void createElection();
	void showOngoingElectionDetails();
	void endElection();
	void verifyCandidate();
};