#pragma once

#include"Person.h"
#include"Assembly.h"

class Assembly;
class Voter
{
	int voterId;
	int assemblyId;
	pair<int,Person *> personalDetails;

	public:
		
		Voter()
		{
			voterId = 0;
			assemblyId = 0;
		}
		pair<int,Person *> getVoterPersonPair();
		void setVoterPersonPair(int ,Person *);
		void displayVoterDetails();
		void vote();
};
