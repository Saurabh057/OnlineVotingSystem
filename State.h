#pragma once

#include <map>
#include <vector>
#include "Assembly.h"

class State
{
private:
    int stateId;
    string stateName;

public:
    map<int, Assembly *> assemblyList; //map of AssemblyId and Assembly *

    State(int, int);
    int getStateId();
    void setStateId(int);
    string getStateName();
    void addNewAssembly(Assembly &);
    void showAssemblyDetails();
    void showAssemblyVoterList();
};