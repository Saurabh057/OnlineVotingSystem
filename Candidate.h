#pragma once
#include<iostream>
#include<map>
#include "Person.h"
using namespace std;

class Candidate
{
	private:
		int candidateId;
		int electionId;
		int stateId;
		std::string partyName;
		pair<int,Person *> personalDetails;
		int assemblyId[2];

	public:
		Candidate()
		{
			candidateId = 0;
			partyName = "";
			assemblyId[0]=assemblyId[1]=-1;
		}
		void regist();
		pair<int,Person *> getCandidatePersonPair();
		void setCandidatePersonPair(int ,Person *);
		void displayCandidateDetails();
		int getStateId();
		void setStateId(int);
		int* getAssemblyId();
		bool setAssemblyId(int asmId);
		int getElectionId();
		void setElectionId(int electionId);
};