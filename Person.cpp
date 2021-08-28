#include<iostream>
#include<string.h>
#include"Person.h"
#include "AadharDetails.h"

using namespace std;

Person::Person(){
	
		name = "";
		age = 0;
		gender = 'N';
		qualification = "";
}

void Person::acceptPersonDetails(){
	std::cout<<"\n$$$$ Enter Personal Details $$$$$"<<endl;
	std::cout<<"Enter Name :"<<std::endl;
	cin>>this->name;
	std::cout<<"Enter Age :"<<std::endl;
	std::cin>>this->age;
	std::cout << "Enter Gender: " << std::endl;
	std::cin >> this->gender;
	// std::cout << "Enter Date Of Birth(DD/MM/YYYY): " << std::endl;
	// std::cin >> ptrDb.day>>ptrDb.month>>ptrDb.year;
	// std::cout << "Enter Full Address: " << std::endl;
	// std::cout<<"House No: ";
	// std::cin >> ptrAddress.houseNo;
	// std::cout<<endl;
	// std::cout<<"Street: ";
	// std::cin >> ptrAddress.street;
	// std::cout<<endl;
	// std::cout<<"Landmark: ";
	// std::cin >> ptrAddress.landmark; 
	// std::cout<<endl;
	// std::cout<<"City: ";
	// std::cin >> ptrAddress.city;
	// std::cout<<endl;	
	// std::cout<<"State: ";
	// std::cin >> ptrAddress.state;
	// std::cout<<endl;
	// std::cout<<"PinCode: ";
	// std::cin >> ptrAddress.pinCode;
	// std::cout<<endl;
	// std::cout << "Please Enter Qualification: " << std::endl;
	// std::cin >> qualification;
	cout<<"Details accepted"<<endl;
}

void Person::displayPersonalDetails(){
	DOB datePtr;
	Address addrPtr;
	std::cout<<"Name :"<<getName()<<std::endl;
	// std::cout<<"ID :"<<getId()<<std::endl;
	std::cout<<"Aadhar :"<<getAadharId()<<std::endl;
	std::cout<<"Age : "<<getAge()<<std::endl;
	std::cout<<"Gender : "<<getGender()<<std::endl;
	datePtr = getDb();
	addrPtr = getAddress();
	std::cout << "Date of Birth : " << datePtr.day << "/" << datePtr.month << "/" << datePtr.year << std::endl;
	std::cout << "Address : " << addrPtr.houseNo << "," << addrPtr.street << "," << addrPtr.landmark << "," << addrPtr.city << "," << addrPtr.state << "," << addrPtr.pinCode << std::endl;
	std::cout << "Qualification: " << this->getQualification() << std::endl;
	std::cout << "Aadhar ID: " << this->getAadharId() << std::endl;
	std::cout << "Assembly ID: " << this->getAssemblyId() << std::endl;

}

/*int Person::getId(){
	return this->id;
}

void Person::setId(int id){
	this->id = id;
}*/

std::string Person::getName(){
	return name;
}

void Person::setName(std::string n){
	name=n;
}

int Person::getAge(){
	return age;
}

void Person::setAge(int a){
	age = a;
}

char Person::getGender()
{
	return gender;
}

void Person::setGender(char g)
{
	gender = g;
}

DOB Person::getDb(){
	return ptrDb;
}

void Person::setDb(DOB db){
	ptrDb = db; //Need to overload '=' operator here
}

DOB Person :: operator =  (DOB dateOfBirth)
{
	DOB date;
	date.day = dateOfBirth.day;
	date.month = dateOfBirth.month;
	date.month = dateOfBirth.year;
	return date;
}

ADDRESS Person :: operator = (Address addr)
{
	Address address;
	address.houseNo = addr.houseNo;
	address.street = addr.street;
	address.landmark = addr.landmark;
	address.city = addr.city;
	address.state = addr.state;
	address.pinCode = addr.pinCode;
	return address;

}

void Person::setAddress(ADDRESS addr){
	ptrAddress = addr; //Need to Overload '=' operator
}

ADDRESS Person::getAddress(){
	return ptrAddress;
}

int Person::getAssemblyId(){
	return assemblyId;
}

void Person::setAssemblyId(int Id){
	assemblyId = Id;
}

std::string Person::getQualification(){
	return qualification;
}

void Person::setQualification(std::string qual){
	qualification = qual;
}

void Person :: setAadharId(long id)
{
	aadharNo = id;
}

long Person::getAadharId()
{
	return aadharNo;
}


// int main(){
// 	DOB date(1, 10, 2014);
// 	Address addr(1, "road", "temple", "city", "state", 411021);
// 	Person p1;
// 	AadharDetails a;
// 	// p1->setId(1234);
// 	p1.setName("Rahul Shinde");
// 	p1.setAssemblyId(101);
// 	p1.setQualification("BE");
// 	p1.setAge(21);
// 	p1.setGender('M');
// 	p1.setDb(date);
// 	p1.setAddress(addr);
// 	a.verify(1);
// 	// p1.getPersonDetails();
// 	p1.displayPersonalDetails();
// }
