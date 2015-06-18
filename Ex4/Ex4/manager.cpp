// Name: Ben Nakash
// ID:	 303140057
// Exercise 4

#include "manager.h"

using namespace std;

// Constructor
manager::manager(string m_Name, string m_Id, string m_Phone, string m_Num, int m_Sal, string m_Dep, int m_Bonus, string m_lp, string m_sen) : employee(m_Name, m_Id, m_Phone, m_Num, m_Sal, m_Dep)
{
	managerBonus = m_Bonus;
	licencePlate = m_lp;
	secrateryEmployeeNumber = m_sen;
}

// Printing Method.
void manager::print()
{
	cout << "Manager : " << getName() << "	;	ID: " << getId() << "	;	Employee Number: " << getEmployeeNumber() << endl;
}