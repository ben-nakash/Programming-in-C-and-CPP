// Name: Ben Nakash
// ID:	 303140057
// Exercise 4

#include <iostream>
#include <Windows.h>
#include <conio.h>
#include <string>
#include <stdlib.h>
#include <list>


#include "person.h"
#include "employee.h"
#include "manager.h"
#include "customer.h"

using namespace std;

void printMenu();
void gotoxy(int x, int y);
void loadingScreen();
void goodbyeScreen();
void addEmployee(list<person*> &personList, string &name, string &id, string &phone, string &employeeNum, int &salary, string &department, char &input, int &bonus, string &licencePlate, string &secretary);
void deleteEmployee(list<person*> &personList, string &employeeNumber, bool &isTrue);
void addCustomer(list<person*> &personList, string &name, string &id, string &phone, string &customerNumber, string &contact);
void deleteCustomer(list<person*> &personList, bool &isTrue, string &customerNumber);
void employeesList(list<person*> &personList, bool &isTrue);
void customersList(list<person*> &personList, bool &isTrue);
void clearDate(list<person*> &personList);

void main()
{
	list<person*> personList;
	string name, id, phone, employeeNum, department, licencePlate, secretary, customerNumber, contact;
	char input = ' ';
	int salary, bonus;
	bool isTrue = false;
	system("color 17");

	personList.push_back(new manager("John"    , "101010101", "054-1111111", "1"  , 50000, "Executive", 10000, "7777777", "213"));
	personList.push_back(new manager("Mike"    , "202020202", "054-2222222", "2"  , 50000, "Executive", 10000, "6666666", "214"));
	personList.push_back(new employee("Asher"  , "111111111", "054-1234567", "100", 5000,  "Factory"));
	personList.push_back(new employee("Simha"  , "222222222", "054-2312354", "101", 5000,  "Factory"));
	personList.push_back(new employee("Moshe"  , "333333333", "054-6985225", "102", 5000,  "Bakery"));
	personList.push_back(new employee("Igal"   , "444444444", "054-5656842", "103", 5000,  "Bakery"));
	personList.push_back(new employee("Hava"   , "555555555", "054-9883212", "104", 5000,  "Store"));
	personList.push_back(new customer("Shimon" , "909090909", "050-3235688", "513", "Ben"));
	personList.push_back(new customer("Shiri"  , "808080808", "050-3287223", "514", "Dov"));
	personList.push_back(new customer("Mor"    , "707070707", "050-9880164", "515", "Moshe"));

	loadingScreen();

	printMenu();
	gotoxy(8,11);

	while (input != '7')
	{
		system("CLS");
		printMenu();
		gotoxy(8, 11);
		input = _getch();
		switch (input)
		{
			case '1':	addEmployee(personList, name, id, phone, employeeNum, salary, department, input, bonus, licencePlate, secretary);
						break;

			case '2':	deleteEmployee(personList, employeeNum, isTrue);
						break;

			case '3':	addCustomer(personList, name, id, phone, customerNumber, contact);
						break;

			case '4':	deleteCustomer(personList, isTrue, customerNumber);
						break;

			case '5':	employeesList(personList, isTrue);
						break;

			case '6':	customersList(personList, isTrue);
						break;
			defult:
						break;
		}
		isTrue = false;
	}

	for (person *p : personList)
		delete(p);
	goodbyeScreen();
}


// Method that prints the menu.
void printMenu()
{
	gotoxy(30, 0);
	cout << "Company Managment Software \n" << endl;
	cout << "Please Select the Desired Operation:\n";
	cout << "   1) Add new employee.\n";
	cout << "   2) Delete employee.\n";
	cout << "   3) Add new customer.\n";
	cout << "   4) Delete customer.\n";
	cout << "   5) Print employees.\n";
	cout << "   6) Print customers.\n";
	cout << "   7) Exit.\n\n";
	cout << "Option: \n";
}


// Method that take the cursor to an (x,y) position according to a given coordinates.
void gotoxy(int x, int y)
{
	COORD coord;
	coord.X = x;
	coord.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}


// A personal method i added as exit screen from the program.
void goodbyeScreen()
{
	system("CLS");
	gotoxy(18, 7);
	cout << "Thanks for using my Company Managment System!!";
	gotoxy(31, 11);
	cout << "Have a nice day :)";
	gotoxy(25, 15);
}


// Method to add a new employee to the list, while checking if the new employee is a manager or employee, and
// according to that it asks for the needed details to fill.
void addEmployee(list<person*> &personList, string &name, string &id, string &phone, string &employeeNum, int &salary, string &department, char &input, int &bonus, string &licencePlate, string &secretary)
{
	system("CLS");
	gotoxy(30, 0);
	cout << "New Employee Screen \n" << endl;
	cout << "  Welcome to New Employee wizard. Please Enter the following details as asked. \n\n";
	cout << "Enter name: ";
	cin >> name;
	cout << "Enter ID: ";
	cin >> id;
	cout << "Enter Phone Number: ";
	cin >> phone;
	cout << "Enter Employee Number: ";
	cin >> employeeNum;
	cout << "Enter Salary: ";
	cin >> salary;
	cout << "Enter Department: ";
	cin >> department;
	cout << endl;
	cout << "Which type of employee it is? Insert 'm' for manager, or 'e' for employee.\n" << endl;
	while (true) {
		input = _getch();
		if (input == 'e') {
			personList.push_back(new employee(name, id, phone, employeeNum, salary, department));
			cout << "\n" << "The Employee: " << name << " has succesfully added\n" << endl << "Press any key to continue.." << endl;
			_getch();
			break;
		}
		else if (input == 'm') {
			cout << "Enter Managers Bonus: ";
			cin >> bonus;
			cout << "Enter Licence Plate: ";
			cin >> licencePlate;
			cout << "Enter Secretary Employee Number: ";
			cin >> secretary;
			personList.push_back(new manager(name, id, phone, employeeNum, salary, department, bonus, licencePlate, secretary));
			cout << "\n" << "The Manager: " << name << " has been succesfully added. \n" << endl << "Press any key to continue.." << endl;
			_getch();
			break;
		}
	}
}


// Method that delete an employee according to a given employee number.
void deleteEmployee(list<person*> &personList, string &employeeNum, bool &isTrue)
{
	system("CLS");
	gotoxy(26, 0);
	cout << "Delete Employee/Manager Screen \n" << endl;
	cout << "Welcome to Delete wizard!" << endl;
	cout << "Please Enter the desired Employee/Manager Number you wish to Delete. \n\n";
	cout << "Employee Number: ";
	cin >> employeeNum;
	cout << endl;
	for (person *p : personList)
	{
		if (dynamic_cast<manager*>(p)) {
			manager *mng = dynamic_cast<manager*>(p);
			if (mng->getEmployeeNumber() == employeeNum) {
				personList.remove(p);
				cout << "The Manager: " << mng->getName() << " has been succesfully deleted. \n" << endl;
				cout << "Press any key to continue.." << endl;
				isTrue = true;
				break;
			}
		}
		else if (dynamic_cast<employee*>(p)) {
			employee *emp = dynamic_cast<employee*>(p);
			if (emp->getEmployeeNumber() == employeeNum) {
				personList.remove(p);
				cout << "The employee: " << emp->getName() << " has been succesfully deleted. \n" << endl;
				cout << "Press any key to continue.." << endl;
				isTrue = true;
				break;
			}
		}
	}
	if (isTrue == false) {
		cout << "No such Employee/Manager in our system. \n" << endl;
		cout << "Press any key to continue.." << endl;
	}
	_getch();
}


// Method to add a new customer.
void addCustomer(list<person*> &personList, string &name, string &id, string &phone, string &customerNumber, string &contact)
{
	system("CLS");
	gotoxy(30, 0);
	cout << "New Customer Screen \n" << endl;
	cout << "  Welcome to New Customer wizard. Please Enter the following details as asked. \n\n";
	cout << "Enter Name: ";
	cin >> name;
	cout << "Enter ID: ";
	cin >> id;
	cout << "Enter Phone Number: ";
	cin >> phone;
	cout << "Enter Customer Number: ";
	cin >> customerNumber;
	cout << "Enter Contact Guy: ";
	cin >> contact;
	personList.push_back(new customer(name, id, phone, customerNumber, contact));
	cout << "\n" << "The Customer: " << name << " has been succesfully added. \n" << endl << "Press any key to continue.." << endl;
	_getch();
}


// Method that delete a customers according to a given customer number.
void deleteCustomer(list<person*> &personList, bool &isTrue, string &customerNumber)
{
	system("CLS");
	gotoxy(30, 0);
	cout << "Delete Customer Screen \n" << endl;
	cout << "Welcome to Delete wizard!" << endl;
	cout << "Please Enter the desired Customer Number you wish to Delete. \n\n";
	cout << "Customer Number: ";
	cin >> customerNumber;
	cout << endl;
	for (person *p : personList)
	{
		if (dynamic_cast<customer*>(p)) {
			customer *cst = dynamic_cast<customer*>(p);
			if (cst->getCustomerNumber() == customerNumber) {
				personList.remove(p);
				cout << "The Customer: " << cst->getName() << " has been succesfully deleted. \n" << endl;
				cout << "Press any key to continue.." << endl;
				isTrue = true;
				_getch();
				break;
			}
		}
	}
	if (isTrue == false) {
		cout << "No such Customer in our system. \n" << endl;
		cout << "Press any key to continue.." << endl;
		_getch();
	}
}


// Method that prints the list of the employees in the list.
void employeesList(list<person*> &personList, bool &isTrue)
{
	system("CLS");
	gotoxy(35, 0);
	cout << "Employees List" << "\n" << endl;
	for (person *p : personList) {
		if (dynamic_cast<employee*>(p)){
			employee *emp = dynamic_cast<employee*>(p);
			emp->print();
			isTrue = true;
		}
	}
	if (isTrue == false)
		cout << "No record of any employees in the system. \n" << endl;
	cout << "\n" << "Press any key to continue.." << endl;
	_getch();
}


// Method that prints the list of the customers in the list.
void customersList(list<person*> &personList, bool &isTrue)
{
	system("CLS");
	gotoxy(35, 0);
	cout << "Customers List" << "\n" << endl;
	for (person *p : personList) {
		if (dynamic_cast<customer*>(p)){
			customer *cst = dynamic_cast<customer*>(p);
			cst->print();
			isTrue = true;
		}
	}
	if (isTrue == false)
		cout << "No record of any customers in the system. \n" << endl;
	cout << "\n" << "Press any key to continue.." << endl;
	_getch();
}


// Personal method for "Loading Screen" at the start of the program.
void loadingScreen()
{
	system("CLS");
	gotoxy(20, 7);
	cout << "Company Managment System is now Loading";
	gotoxy(35, 11);
	cout << "Please Wait";
	gotoxy(36, 15);
	for (int i = 0; i < 4; i++) {
		Sleep(1000);
		cout << " .";
	}
}