#include <iostream>
using namespace std;

#define delimiter "---------------------------------------"

class Fraction;
Fraction operator*(Fraction left, Fraction right);
Fraction operator/(const Fraction& left, const Fraction& right);

class Fraction
{
	int integer;
	int numerator;
	int denominator;

public:
	int get_integer()const
	{
		return integer;
	}
	int get_numerator()const
	{
		return numerator;
	}
	int get_denominator()const
	{
		return denominator;
	}
	void set_integer(int integer)
	{
		this->integer = integer;
	}
	void set_numerator(int numerator)
	{
		this->numerator = numerator;
	}
	void set_denominator(int denominator)
	{
		if (denominator == 0) denominator = 1;
		this->denominator = denominator;
	}

	//	Constructors:

	Fraction()
	{
		integer = 0;
		numerator = 0;
		set_denominator(1);
		cout << "DefaultConstructor:\t" << this << endl;
	}
	Fraction(int integer)
	{
		this->integer = integer;
		this->numerator = 0;
		set_denominator(1);
		cout << "SingleArgumentConstructor: " << this << endl;
	}
	Fraction(int numerator, int denominator)
	{
		this->integer = 0;
		this->numerator = numerator;
		set_denominator(denominator);
		cout << "Constructor:\t\t" << this << endl;
	}
	Fraction(int integer, int numerator, int denominator)
	{
		set_integer(integer);
		set_numerator(numerator);
		set_denominator(denominator);
		cout << "Constructor:\t\t" << this << endl;
	}
	~Fraction()
	{
		cout << "Destructor:\t\t" << this << endl;
	}

	//	Operators:

	Fraction& operator=(const Fraction& other)
	{
		this->numerator = other.numerator;
		this->denominator = other.denominator;
		return *this;
	}
	Fraction& operator*=(Fraction& other)
	{
		return *this = *this * other;
	}
	Fraction& operator/=(Fraction& other)
	{
		return *this = *this / other;
	}

	//	Methods:

	Fraction& to_improper()
	{
		numerator += integer * denominator;
		integer = 0;
		return *this;
	}
	Fraction& to_proper()
	{
		integer += numerator / denominator;
		numerator %= denominator;
		return *this;
	}
	Fraction inverted()const
	{
		Fraction inverted = *this;
		inverted.to_improper();
		swap(inverted.numerator, inverted.denominator);
		return inverted;
	}
	Fraction& reduce()
	{
		int more, less, rest;
		if (numerator > denominator) more = numerator, less = denominator;
		else less = numerator, more = denominator;
		do
		{
			rest = more % less;
			more = less;
			less = rest;
		} while (rest);
		int GCD = more;
		numerator /= GCD;
		denominator /= GCD;
		return *this;
	}
	void print()const
	{
		if (integer) cout << integer;
		if (numerator)
		{
			if (integer)cout << "(";
			cout << numerator << "/" << denominator;
			if (integer)cout << ")";
		}
		else if (integer == 0) cout << 0;
		cout << endl;
	}
};

Fraction operator*(Fraction left, Fraction right)
{
	left.to_improper();
	right.to_improper();
	/*Fraction result;
	result.set_numerator(left.get_numerator() * right.get_numerator());
	result.set_denominator(left.get_denominator() * right.get_denominator());
	return result;*/

	/*Fraction result
	{
		left.get_numerator() * right.get_numerator(),
		left.get_denominator() * right.get_denominator()
	};
	result.to_proper();
	return result;*/

	return Fraction
	(
		left.get_numerator() * right.get_numerator(),
		left.get_denominator() * right.get_denominator()
	).to_proper().reduce();
}
Fraction operator/(const Fraction& left, const Fraction& right)
{
	return left * right.inverted();
}
Fraction operator+( Fraction& left, Fraction& right)
{
	Fraction result;
	left.to_improper();
	right.to_improper();
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
Fraction operator-(Fraction& left, Fraction& right)
{
	Fraction result;
	left.to_improper();
	right.to_improper();
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

bool operator==(Fraction left, Fraction right)
{
	left.to_improper();
	right.to_improper();
	return left.get_numerator() * right.get_denominator() == left.get_denominator() * right.get_numerator();
}
bool operator!=(const Fraction& left, const Fraction& right)
{
	return !(left == right);
}
bool operator>(Fraction left, Fraction right)
{
	left.to_improper();
	right.to_improper();
	return left.get_numerator() * right.get_denominator() > left.get_denominator() * right.get_numerator();
}
bool operator<(Fraction left, Fraction right)
{
	left.to_improper();
	right.to_improper();
	return left.get_numerator() * right.get_denominator() < left.get_denominator() * right.get_numerator();
}
bool operator>=(const Fraction& left, const Fraction& right)
{
	return !(left < right);
}
bool operator<=(const Fraction& left, const Fraction& right)
{
	return !(left > right);
}

std::ostream& operator<<(std::ostream& os, const Fraction& obj)
{
	if (obj.get_integer()) os << obj.get_integer();
	if (obj.get_numerator())
	{
		if (obj.get_integer()) os << "(";
		os << obj.get_numerator() << "/" << obj.get_denominator();
		if (obj.get_integer()) os << ")";
	}
	else if (obj.get_integer() == 0) os << 0;
	return os;
} 
std::istream& operator>>(std::istream& is, Fraction& obj)
{
	int integer, numerator, denominator;
	cout << "Enter an integer: "; is >> integer; obj.set_integer(integer);
	cout << "Enter the numerator: "; is >> numerator; obj.set_numerator(numerator);
	cout << "Enter the denominator: "; is >> denominator; obj.set_denominator(denominator);
	return is;
}

//#define CONSTRUCTORS_CHECK
//#define ARITHMETICAL_OPERATORS_CHECK
//#define COMPARISON_OPERATORS_CHECK
#define	IO_OPERATORS_CHECK

void main()
{
	setlocale(LC_ALL, "");

#ifdef CONSTRUCTORS_CHECK
	Fraction A;
	A.print();

	Fraction B = 5;
	B.print();

	Fraction C(1, 2);
	C.print();

	Fraction D(2, 3, 4);
	D.print();
#endif // CONSTRUCTORS_CHECK

#ifdef ARITHMETICAL_OPERATORS_CHECK
	Fraction A(2, 3, 4);
	A.print();

	Fraction B(3, 4, 5);
	B.print();

	/*A.to_improper().print();
	A.to_proper().print();

	Fraction C = A / B;
	C.print();*/

	A *= B;
	A.print();

	A /= B;
	A.print();
#endif // ARITHMETICAL_OPERATORS_CHECK

#ifdef COMPARISON_OPERATORS_CHECK
	cout << (Fraction(1, 2) == Fraction(5, 10)) << endl;
	cout << delimiter << endl;
	cout << (Fraction(1, 3) != Fraction(5, 10)) << endl;
	cout << delimiter << endl;
	cout << (Fraction(4, 5) > Fraction(5, 10)) << endl;
	cout << delimiter << endl;
	cout << (Fraction(3, 5) < Fraction(3, 7)) << endl;
	cout << delimiter << endl;
	cout << (Fraction(2, 9) >= Fraction(3, 7)) << endl;
	cout << delimiter << endl;
	cout << (Fraction(4, 3) <= Fraction(3, 7)) << endl;
	cout << delimiter << endl;
#endif // COMPARISON_OPERATORS_CHECK

#ifdef IO_OPERATORS_CHECK
	Fraction A;
	cin >> A;
	cout << A << endl;
#endif // INPUT_OPERATOR_CHECK
}