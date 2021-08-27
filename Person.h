/*  Personal Details Class. It's object will be created in the Voter and Candidate classes.
	
	Case 		: Camel Case
*/
#pragma once

#include<iostream>

typedef struct DateOfBirth{
	int day;
	int month;
	int year;
	DateOfBirth() : day(-1), month(-1), year(-1) {};
	DateOfBirth(int d, int m, int y) : day(d), month(m), year(y) {};
}DOB;

typedef struct Address
{
	int houseNo;
	std::string street;
	std::string landmark;
	std::string city;
	std::string state;
	int pinCode;
	Address() : houseNo(-1), street(""), landmark(""), city(""), state(""), pinCode(-1) {};
	Address(int hNo, std::string str, std::string la, std::string ci, std::string st, int pin)
	: houseNo(hNo), street(str), landmark(la), city(ci), state(st), pinCode(pin) {};

}ADDRESS; //Remove the typedef *

class Person 
{
	private:
		// int id; 
		std::string name; 
		char gender;
		int age; 		
		DOB ptrDb; 
		ADDRESS ptrAddress; 
		std::string qualification; 
		long aadharNo;
		int assemblyId;

	public:
		Person();
		Person(std::string n, char g, int a, DOB d, Address addr, std::string qual, long adhar, int aId) 
		: name(n), gender(g), age(a), ptrDb(d), ptrAddress(addr), qualification(qual), aadharNo(adhar), assemblyId(aId) {}; 
		// int getId();
		//void setId(int);
		std::string getName();
		void setName(std::string);
		int getAge();
		void setAge(int);
		char getGender();
		void setGender(char);
		DOB getDb();
		void setDb(DOB);
		ADDRESS getAddress();
		void setAddress(ADDRESS);
		int getAssemblyId();
		void setAssemblyId(int);
		std::string getQualification();
		void setQualification(std::string);
		long getAadharId();
		void setAadharId(long);
		void acceptPersonDetails();
		void displayPersonalDetails();
		DOB operator  = (DOB);
		Address operator  = (Address);
};
