#pragma once

#include"Person.h"
#include"Assembly.h"

class Assembly;
class Voter
{
	int voterId;
	int assemblyId;
	int stateId;
	pair<int,Person *> personalDetails;

	public:
		
		Voter()
		{
			voterId = 0;
			assemblyId = 0;
			stateId = 0;
		}
		pair<int,Person *> getVoterPersonPair();
		void setVoterPersonPair(int ,Person *);
		void displayVoterDetails();
		void setStateId(int stateId);
		int getStateId();
		void setAssemblyId(int AssemblyId);
		void registerAsCandidate();
		int getAssemblyId();
		void vote();
};
