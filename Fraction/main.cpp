#include <iostream>
using namespace std;

#define delimiter "---------------------------------------"

class Fraction
{
	int numerator;
	int denominator;

public:
	int get_numerator()const
	{
		return numerator;
	}
	int get_denominator()const
	{
		return denominator;
	}
	void set_numerator(int numerator)
	{
		this->numerator = numerator;
	}
	void set_denominator(int denominator)
	{
		this->denominator = denominator;
	}

	Fraction(int numerator = 1, int denominator = 1)
	{
		this->numerator = numerator;
		this->denominator = denominator;
		cout << "Constructor:\t\t" << this << endl;
	}
	~Fraction()
	{
		cout << "Destructor:\t\t" << this << endl;
	}

	Fraction& operator=(const Fraction other)
	{
		this->numerator = other.numerator;
		this->denominator = other.denominator;
		return *this;
	}

	void print()const
	{
		cout << "numerator = " << numerator << "\tdenominator = " << denominator << endl;
	}

	void power(const int index)
	{
		for (int i = 0; i < index - 1; i++)
		{
			numerator *= numerator;
			denominator *= denominator;
		}
	}
};

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

Fraction operator*(const Fraction& left, const Fraction& right)
{
	Fraction result;
	result.set_numerator(left.get_numerator() * right.get_numerator());
	result.set_denominator(left.get_denominator() * right.get_denominator());
	return result;
}

Fraction operator/(const Fraction& left, const Fraction& right)
{
	Fraction result;
	result.set_numerator(left.get_numerator() * right.get_denominator());
	result.set_denominator(left.get_denominator() * right.get_numerator());
	return result;
}

void main()
{
	Fraction A(2, 3);
	A.print();

	cout << delimiter << endl;

	Fraction B = A;
	B.print();

	cout << delimiter << endl;

	Fraction C(5, 7);
	C.print();

	cout << delimiter << endl;
	
	Fraction D = A + C;
	D.print();

	cout << delimiter << endl;
	
	Fraction E = A - D;
	E.print();

	cout << delimiter << endl;
	
	Fraction F = B * E;
	F.print();

	cout << delimiter << endl;
	
	Fraction G = A / C;
	G.print();

	cout << delimiter << endl;
	
	A.power(2);
	A.print();
	
	cout << delimiter << endl;
}