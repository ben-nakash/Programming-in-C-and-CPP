// Name: Ben Nakash
// ID:	 303140057

#include <iostream>
#include <math.h>
#include <string>
#include <conio.h>
#include "complex.h"
using namespace std;


// Constructor
complex::complex(double r, double i)
{
	real = r;
	imag = i;
}

// Overload '+' operator (Complex + Complex)
complex complex::operator+ (const complex& c) const
{
	complex result;
	result.real = this->real + c.real;
	result.imag = this->imag + c.imag;
	return result;
}

// Overload '+' operator (Complex + Double)
complex complex::operator+ (const double& real) const
{
	complex result;
	result.real = this->real + real;
	result.imag = this->imag;
	return result;
}

// Overload '+' operator (Double + Complex)
complex operator+(const complex& c, const double num)
{
	complex result;
	result.real = c.real + num;
	result.imag = c.imag;
	return result;
}

// Overload '-' operator (Complex - Complex)
complex complex::operator- (const complex& c) const
{
	complex result;
	result.real = this->real - c.real;
	result.imag = this->imag - c.imag;
	return result;
}

// Overload '-' operator (Complex - Double)
complex complex::operator- (const double& real) const
{
	complex result;
	result.real = this->real - real;
	result.imag = this->imag;
	return result;
}

// Overload '-' operator (Double - Complex)
complex operator-(const complex& c, const double num)
{
	complex result;
	result.real = num - c.real;
	result.imag = c.imag;
	return result;
}

// Overload '*' operator (Complex * Complex)
complex complex::operator* (const complex& c) const
{
	complex result;
	result.real = (this->real * c.real) - (this->imag * c.imag);
	result.imag = (this->real * c.imag) + (this->imag * c.real);
	return result;
}

// Overload '*' operator (Complex * Double)
complex complex::operator* (const double& num) const
{
	complex result;
	result.real = this->real * num;
	result.imag = this->imag * num;
	return result;
}

// Overload '*' operator (Double * Complex)
complex operator*(const complex& c, const double num)
{
	complex result;
	result.real = c.real * num;
	result.imag = c.imag * num;
	return result;
}

// Overload '/' operator (Complex / Complex)
complex complex::operator/ (const complex& comp) const
{
	double a = this->real ;  double b = this->imag;	
	double c = comp.real  ;  double d = comp.imag;			
	complex result;
	result.real = (a*c + b*d) / (c*c + d*d);	
	result.imag = (-a*d + b*c) / (c*c + d*d);
	return result;
}

// Overload '/' operator (Complex / Double)
complex complex::operator/ (const double& num) const
{
	complex result;
	result.real = this->real / num;
	result.imag = this->imag / num;
	return result;
}

// Overload '/' operator (Double / Complex)
complex operator/(const complex& c, const double num)
{
	complex result;
	result.real = num / c.real;
	result.imag = num / c.imag;
	return result;
}

// Method that returns the absolute value of a complex number
double complex::abs() 
{
	double result = sqrt(this->real*this->real + this->imag*this->imag);
	return result;
}


// Print method that prints a complex number.
void complex::print()
{
	if (this->imag < 0)
		cout << real << imag << "i";
	else
		cout << real << "+" << imag << "i";
}


// Set Methods
void complex::setValues(double real, double imag)
{
	this->real = real;
	this->imag = imag;
}

void complex::setReal(const double real)
{
	this->real = real;
}

void complex::setImag(const double imag)
{
	this->imag = imag;
}


// Get methods
double complex::getReal()
{
	return this->real;
}

double complex::getImag()
{
	return this->imag;
}
