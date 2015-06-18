// Name: Ben Nakash
// ID:	 303140057
// Exercise 4

#include "customer.h"

using namespace std;

// Constructor
customer::customer(string c_Name, string c_Id, string c_Phone, string c_Num, string c_Contact) : person(c_Name, c_Id, c_Phone)
{
	customerNumber = c_Num;
	contact = c_Contact;
}

// Printing method
void customer::print()
{
	cout << "Name: " << getName() << "	;	ID: " << getId() << "	;	Customer Number: " << getCustomerNumber() << endl;
}

// Get Client number method
string customer::getCustomerNumber()
{
	return customerNumber;
}