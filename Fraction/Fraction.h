#pragma once
#include <iostream>
using namespace std;

#define delimiter "---------------------------------------"

class Fraction;
Fraction operator*(Fraction& left, Fraction& right);
Fraction operator+(const Fraction& left, const Fraction& right);
Fraction operator-(const Fraction& left, const Fraction& right);
Fraction operator/(const Fraction& left, const Fraction& right);

class Fraction
{
	int integer;
	int numerator;
	int denominator;

public:
	int get_integer()const;
	int get_numerator()const;
	int get_denominator()const;
	void set_integer(int integer);
	void set_numerator(int numerator);
	void set_denominator(int denominator);

	//	Constructors:

	Fraction();
	Fraction(int integer);
	Fraction(int numerator, int denominator);
	Fraction(int integer, int numerator, int denominator);
	~Fraction();

	//	Operators:

	Fraction& operator=(const Fraction other);

	//	Methods:

	Fraction& to_improper();
	Fraction& to_proper();
	void print()const;
};