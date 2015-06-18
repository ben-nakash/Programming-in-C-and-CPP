// Name: Ben Nakash
// ID:	 303140057

#include <iostream>
#include <Windows.h>
#include <conio.h>
#include <string>
#include "complex.h"
using namespace std;

// Declaring the methods needed for the program.
void gotoxy(int x, int y);
void helpScreen();
void printScreen();
void clear(complex& complex1, complex& complex2, complex& result);
void extractComplex(complex& num1, complex& num2, complex& result, int& counter);
void exitProgram();

int main()
{
	int counter = -1, operation = 0;
	char input;
	complex complex1(0, 0), complex2(0, 0), result(0, 0);

	printScreen();
	input = _getch();

	while (input != 'q') 
	{
		system("CLS");
		printScreen();
		gotoxy(10, 2);
		switch (input) {
			case 'e':	extractComplex(complex1, complex2, result, counter);
						break;

			case '+':	operation = PLUS;
						break;

			case '-':	operation = MINUS;
						break;

			case '*':	operation = MULTIPLY;
						break;

			case '/':	operation = DEVIDE;
						break;

			case '=':	if (operation == PLUS)				result = complex1 + complex2;
						else if (operation == MINUS)		result = complex1 - complex2;
						else if (operation == MULTIPLY)		result = complex1 * complex2;
						else if (operation == DEVIDE)		result = complex1 / complex2;
						result.print();
						break;

			case 'h':	system("CLS");
						helpScreen();
						break;

			case 'c':	clear(complex1, complex2, result);
						break;

			case 'r':	cout << result.getReal();
						break;

			case 'm':	cout << result.getImag();
						break;

			case 'o':	result.print();
						break;

			case 'a':	cout << result.abs();
						break;
			defult:
						break;
			}
			gotoxy(0, 24);
			input = _getch();
	}
	exitProgram();
	return 0;
}

// Method that prints the calculator screen.
void printScreen()
{
	cout << " --------------------------------------------------------\n";
	cout << "|                                                        |\n";
	cout << "|                                                        |\n";
	cout << "|                                                        |\n";
	cout << " --------------------------------------------------------\n";
	cout << "|       |       |       |        |     |     |     |     |\n";
	cout << "|   1   |   2   |   3   |        |  +  |  -  |  /  |  *  |\n";
	cout << "|       |       |       |        |     |     |     |     |\n";
	cout << "|--------------------------------------------------------|\n";
	cout << "|       |       |       |        |           |           |\n";
	cout << "|   4   |   5   |   6   |        |  Real(r)  |  Imag(m)  |\n";
	cout << "|       |       |       |        |           |           |\n";
	cout << "|--------------------------------------------------------|\n";
	cout << "|       |       |       |        |           |           |\n";
	cout << "|   7   |   8   |   9   |        |   Abs(a)  |  Help(h)  |\n";
	cout << "|       |       |       |        |           |           |\n";
	cout << "|--------------------------------------------------------|\n";
	cout << "|       |       |       |        |                       |\n";
	cout << "|   C   |   0   |   =   |        |       Complex(o)      |\n";
	cout << "|       |       |       |        |                       |\n";
	cout << "|--------------------------------------------------------|\n";
	cout << "|                                |     Enter Complex     |\n";
	cout << "|                                |       Number(e)       |\n";
	cout << "|________________________________|_______________________|\n";
}

// Method that prints the Help menu.
void helpScreen()
{
	cout << " ________________________________                                          \n";
	cout << "|         |                      |                                         \n";
	cout << "|   0-9   |        Digits        |                                         \n";
	cout << "|    =    |   Calculate Result   |    *     *   *******   *          ***** \n";
	cout << "|    +    |         Plus         |    *     *   *         *          *   * \n";
	cout << "|    -    |         Minus        |    *******   *******   *          ****  \n";
	cout << "|    *    |       Multiply       |    *     *   *         *          *     \n";
	cout << "|    /    |        Devide        |    *     *   *******   ********   *     \n";
	cout << "|    r    |     Display Real     |                                         \n";
	cout << "|    m    |  Display Imaginary   |                                         \n";
	cout << "|         |                      |                ***       ***            \n";
	cout << "|--------------------------------|                ***       ***            \n";
	cout << "|         |                      |                                         \n";
	cout << "|    h    |     Help Screen      |             *                 *         \n";
	cout << "|    a    |  Calculate Absolute  |               *             *           \n";
	cout << "|    e    |    Insert Complex    |                 ***********             \n";
	cout << "|    q    |         Exit         |                                         \n";
	cout << "|_________|______________________|                                         \n";
}

// Method that extracts a complex number from a given string. 
// It takes the string, and read it part by part to extract a complex number, while identifing if its negative/positive.
void extractComplex(complex& complex1, complex& complex2,complex& result, int& counter)
{
	int i = 0, operation = 0;
	double real, imag;
	bool negative1 = false, negative2 = false;
	string s = "", subString1 = "", subString2 = "";

	cin >> s;
	counter++;
	i = 0;
	if (s[i] == '-') {
		negative1 = true;
		i++;
	}
	while (s[i] != '+' && s[i] != '-') {
		subString1 += s[i];
		i++;
	}
	if (s[i] == '-')
		negative2 = true;
	i++;
	for (; i < s.length() - 1; i++) {
		subString2 += s[i];
	}
	real = atof(subString1.c_str());
	imag = atof(subString2.c_str());
	if (negative1 == true)		real *= -1;
	if (negative2 == true)		imag *= -1;
	if (counter % 2 == 0) {
		complex1.setValues(real, imag);
		result = complex1;
	}
	else {
		complex2.setValues(real, imag);
		result = complex2;
	}
}

// Method that clears the screen, and reseting the complex numbers values.
void clear(complex& complex1, complex& complex2, complex& result)
{
	result.setValues(0, 0);
	complex1.setValues(0, 0);
	complex2.setValues(0, 0);
	system("CLS");
	printScreen();
}

// Method that take the cursor to an (x,y) position according to a given coordinates.
void gotoxy(int x, int y) 
{
	COORD coord;
	coord.X = x;
	coord.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

// Extra method I wanted to add at the end of the program to print a few words.
void exitProgram()
{
	system("CLS");
	gotoxy(25, 9);
	cout << "Thanks for using my calculator!";
	gotoxy(31, 12);
	cout << "Have a nice day ;)";
	gotoxy(25, 15);

}