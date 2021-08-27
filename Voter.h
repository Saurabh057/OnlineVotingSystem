#pragma once

#include"Person.h"
#include"Assembly.h"

class Assembly;
class Voter
{
	int voterId;
	int assemblyId;
	// Person voter;
	public:
	pair<int,Person *> personalDetails;
		
		Voter()
		{
			voterId = 0;
			assemblyId = 0;
		}
		void regist(Assembly &);
		int getVoterDetails();
		void vote();
};
