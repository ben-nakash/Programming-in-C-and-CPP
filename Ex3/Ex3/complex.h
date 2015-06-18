// Name: Ben Nakash
// ID:	 303140057

#define PLUS 1
#define MINUS 2
#define MULTIPLY 3
#define DEVIDE 4

#pragma once 

class complex
{
	// Friend operator overload methods for 'Double (+, -, *, /) Complex'
	friend complex operator+(const complex&, const double num);
	friend complex operator-(const complex&, const double num);
	friend complex operator*(const complex&, const double num);
	friend complex operator/(const complex&, const double num);

private:
	double real, imag;

public:
	// Constructor
	complex(double real = 0. , double imag = 0.);  

	// Overload methods for 'Complex (+,-,*,/) Complex'.
	complex operator+(const complex&) const;       
	complex operator-(const complex&) const;
	complex operator*(const complex&) const;
	complex operator/(const complex&) const;

	// Overload methods for 'Complex (+,-,*,/) Double'.
	complex operator+(const double& real) const;
	complex operator-(const double& real) const;
	complex operator*(const double& real) const;
	complex operator/(const double& real) const;

	// Get and Set Methods
	double getReal();
	double getImag();
	void setReal(const double real);
	void setImag(const double imag);
	void setValues(double real, double imag); // The only difference in this set method is that
											  // it sets both real & imaginary values in one method.

	// Method that calculate the absolute value of a complex number and returns it.
	double abs();

	// Method that prints a Complex number on screen.
	void print();
};