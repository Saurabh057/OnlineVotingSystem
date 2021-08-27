#include<iostream>
#include "AadharDetails.h"

AadharDetails::AadharDetails()
{
	aadharDetailsList[1] = new Person("Soham",'M', 23, DOB(17,02,1999), Address(1,"road", "temple", "pune","mah",411021), "SWE", 1, 1);
	aadharDetailsList[2] = new Person("Saurabh",'M', 24, DOB(172,05,1998), Address(1,"road", "temple", "pune","mah",411021), "SWE", 2, 2);
	aadharDetailsList[3] = new Person("Rahul",'M', 23, DOB(14,06,1999), Address(1,"road", "temple", "pune","mah",411021), "SWE", 3, 2);
	aadharDetailsList[4] = new Person("Shweta",'F', 25, DOB(11,04,1996), Address(1,"road", "temple", "pune","mah",411021), "SWE", 4, 1);
	aadharDetailsList[5] = new Person("Renuka",'F', 24, DOB(17,02,1999), Address(1,"road", "temple", "pune","mah",411021), "SWE", 5, 4);
	aadharDetailsList[6] = new Person("Saurabh",'M', 22, DOB(17,02,1999), Address(1,"road", "temple", "pune","mah",411021), "SWE", 6, 1);
}

bool AadharDetails::verify(long id)
{
    if(aadharDetailsList.find(id) != aadharDetailsList.end())
    {
        Person* p = aadharDetailsList.find(id)->second;
        p->setAadharId(id);
        return 1;
    }
    return 0;
}

