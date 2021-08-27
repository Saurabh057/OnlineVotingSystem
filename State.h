#pragma once

#include<bits/stdc++.h>
#include<vector>
#include"Assembly.h"

class State{
    private:
        int stateId;
        
 
    public :
        map<int,Assembly *> assemblyList;       //map of AssemblyId and Assembly *
        
    	State(int, int);
    	int getStateId();
    	void setStateId(int);
        void addNewAssembly(Assembly &);
        void showAssemblyDetails();
        void showAssemblyVoterList();

};