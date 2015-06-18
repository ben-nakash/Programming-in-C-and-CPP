// Name: Ben Nakash
// ID:	 303140057
// Exercise 4

#include "employee.h"
#include "person.h"

#pragma once
using namespace std; 

class manager : public employee
{
public:
	manager(string m_Name, string m_Id, string m_Phone, string m_Num, int m_Sal, string m_Dep, int m_Bonus, string m_lp, string m_sen);
	int getLicencePlate();
	void raiseBonus();
	void print();

private:
	int managerBonus;
	string licencePlate, secrateryEmployeeNumber;
};