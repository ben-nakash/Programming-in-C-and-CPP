// Name: Ben Nakash
// ID:	 303140057
// Exercise 4

#include "person.h"

#pragma once
using namespace std;

class customer : public person
{
public:
	customer(string c_Name, string c_Id, string c_Phone, string c_Num, string c_Contact);
	string getCustomerNumber();
	void print();

private: 
	string contact, customerNumber;
};