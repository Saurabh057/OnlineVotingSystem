#include "State.h"

State::State(int stateID, int no)
{
	stateId = stateID;
	Assembly *assemblyObj;
	for (int i = 0; i < no; i++)
	{
		assemblyObj = new Assembly(i, "Baramati", 2001, 1002, 101, 5);

		assemblyList.insert({assemblyObj->getAssemblyNo(), assemblyObj});
	}
}

int State::getStateId()
{
	return stateId;
}

void State::setStateId(int p)
{
	stateId = p;
}
string State::getStateName()
{
	return stateName;
}

// void State::addNewAssembly(Assembly &assemblyObj)
// {
// 	int tempAssemblyNo;
// 	cout<<"Enter Assembly No\t";
// 	cin>>tempAssemblyNo;
// 	assemblyObj.setAssemblyNo(tempAssemblyNo);

// 	if(assemblyList.find(tempAssemblyNo) == assemblyList.end())
// 	{
// 		assemblyObj.acceptAssemblyDetails();
// 		assemblyList.insert({assemblyObj.getAssemblyNo(),&assemblyObj});
// 	}
// 	else
// 	{
// 		cout<<"Assembly NO already Exist"<<endl;
// 	}

// }
void State::showAssemblyDetails()
{
	for (auto x : assemblyList)
	{
		(x.second)->showAssemblyDetails();
	}
}
