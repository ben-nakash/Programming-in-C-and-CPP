// Name: Ben Nakash
// ID:	 303140057
// Exercise 4

#include "employee.h"

using namespace std;


// Constructor.
employee::employee(string e_Name, string e_Id, string phone, string e_Number, int e_Salary, string e_Department) : person(e_Name, e_Id, phone)
{
	employeeNumber = e_Number;
	salary = e_Salary;
	department = e_Department;
}


// Get method to get the Employee number.
string employee::getEmployeeNumber()
{
	return employeeNumber;
}


// Method to change the salary of the employee.
void employee::changeSalary(int newSalary)
{
	salary = newSalary;
}


// Printing Method.
void employee::print()
{
	cout << "Employee: " << getName() << "	;	ID: " << getId() << "	;	Employee Number: " << getEmployeeNumber() << endl;
}
