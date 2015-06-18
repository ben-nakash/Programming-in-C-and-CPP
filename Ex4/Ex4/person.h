// Name: Ben Nakash
// ID:	 303140057
// Exercise 4

#include <iostream>
#include <string>

#pragma once
using namespace std;

class person
{
public:
	person(string p_Name, string p_Id, string phone);
	string getName();
	string getId();
	void setPhoneNumber(const string phone);
	virtual void print();

private:
	string name, phoneNumber, id;
};