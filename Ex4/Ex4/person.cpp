// Name: Ben Nakash
// ID:	 303140057
// Exercise 4

#include "person.h"

using namespace std;

// Constructor.
person::person(string p_Name, string p_Id, string phone)
{
	name = p_Name;
	id = p_Id;
	phoneNumber = phone;
}


// Get Name method.
string person::getName()
{
	return name;
}


// Get method to get the ID of a person.
string person::getId()
{
	return id;
}


// Method that changes the phone number.
void person::setPhoneNumber(const string phone)
{
	phoneNumber = phone;
}


// Printing method.
void person::print()
{
	cout << "Person: " << "Name: " << name << " ; ID: " << id << endl;
}