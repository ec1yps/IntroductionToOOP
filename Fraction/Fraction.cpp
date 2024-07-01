#include "Fraction.h"

int Fraction::get_integer()const
{
	return integer;
}
int Fraction::get_numerator()const
{
	return numerator;
}
int Fraction::get_denominator()const
{
	return denominator;
}
void Fraction::set_integer(int integer)
{
	this->integer = integer;
}
void Fraction::set_numerator(int numerator)
{
	this->numerator = numerator;
}
void Fraction::set_denominator(int denominator)
{
	if (denominator == 0) denominator = 1;
	this->denominator = denominator;
}

//	Constructors:

Fraction::Fraction()
{
	integer = 0;
	numerator = 0;
	set_denominator(1);
	cout << "DefaultConstructor:\t" << this << endl;
}
Fraction::Fraction::Fraction(int integer)
{
	this->integer = integer;
	this->numerator = 0;
	set_denominator(1);
	cout << "SingleArgumentConstructor: " << this << endl;
}
Fraction::Fraction(int numerator, int denominator)
{
	this->integer = 0;
	this->numerator = numerator;
	set_denominator(denominator);
	cout << "Constructor:\t\t" << this << endl;
}
Fraction::Fraction(int integer, int numerator, int denominator)
{
	set_integer(integer);
	set_numerator(numerator);
	set_denominator(denominator);
	cout << "Constructor:\t\t" << this << endl;
}
Fraction::~Fraction()
{
	cout << "Destructor:\t\t" << this << endl;
}

//	Operators:

Fraction& Fraction::operator=(const Fraction other)
{
	this->numerator = other.numerator;
	this->denominator = other.denominator;
	return *this;
}

//	Methods:

Fraction& Fraction::to_improper()
{
	numerator += integer * denominator;
	integer = 0;
	return *this;
}
Fraction& Fraction::to_proper()
{
	integer += numerator / denominator;
	numerator %= denominator;
	return *this;
}
void Fraction::print()const
{
	if (integer) cout << integer;
	if (numerator != 0)
	{
		if (integer)cout << "(";
		cout << numerator << "/" << denominator;
		if (integer)cout << ")";
	}
	else if (integer == 0) cout << 0;
	cout << endl;
}

Fraction operator*(Fraction& left, Fraction& right)
{
	left.to_improper();
	right.to_improper();
	Fraction result;
	result.set_numerator(left.get_numerator() * right.get_numerator());
	result.set_denominator(left.get_denominator() * right.get_denominator());
	return result;
}

Fraction operator+(const Fraction& left, const Fraction& right)
{
	Fraction result;
	if (left.get_denominator() == right.get_denominator())
	{
		result.set_numerator(left.get_numerator() + right.get_numerator());
		result.set_denominator(left.get_denominator());
	}
	else
	{
		result.set_numerator(left.get_numerator() * right.get_denominator() + right.get_numerator() * left.get_denominator());
		result.set_denominator(left.get_denominator() * right.get_denominator());
	}
	return result;
}
Fraction operator-(const Fraction& left, const Fraction& right)
{
	Fraction result;
	if (left.get_denominator() == right.get_denominator())
	{
		result.set_numerator(left.get_numerator() - right.get_numerator());
		result.set_denominator(left.get_denominator());
	}
	else
	{
		result.set_numerator(left.get_numerator() * right.get_denominator() - right.get_numerator() * left.get_denominator());
		result.set_denominator(left.get_denominator() * right.get_denominator());
	}
	return result;
}
Fraction operator/(const Fraction& left, const Fraction& right)
{
	Fraction result;
	result.set_numerator(left.get_numerator() * right.get_denominator());
	result.set_denominator(left.get_denominator() * right.get_numerator());
	return result;
}