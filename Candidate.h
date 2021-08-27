#pragma once
#include<iostream>
#include<map>
#include "Person.h"
using namespace std;
class Candidate
{
	private:
		int candidateId;
		std::string partyName;
		pair<int,Person *> personalDetails;
		int assemblyId[2];

	public:
		Candidate()
		{
			candidateId = 0;
			partyName = "";
			assemblyId[0]=assemblyId[0]=-1;
		}
		void regist();
		pair<int,Person *> getCandidatePersonPair();
		void setCandidatePersonPair(int ,Person *);
		void displayCandidateDetails();
};