// Name: Ben Nakash
// ID:	 303140057
// Exercise 4

#include "person.h"

#pragma once
using namespace std;

class employee : public person
{
public:
	employee(string e_Name, string e_Id, string phone, string e_Number, int e_Salary, string e_Department);
	string getEmployeeNumber();
	void changeSalary(int num);
	void print();

private:
	int salary;
	string department, employeeNumber;
};