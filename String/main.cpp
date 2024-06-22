#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

#define delimiter "--------------------------------------------"

class String
{
	int size = 0;
	char* str;
public:
	int get_size()const
	{
		return size;
	}
	char* get_str()const
	{
		return str;
	}
	void set_size(int size)
	{
		this->size = size;
	}

	String()
	{
		size = 80;
		str = new char[size] {};
		cout << "DefaultConstructor:\t" << this << endl;
	}
	String(int size)
	{
		this->size = size;
		str = new char[size] {};
		cout << "SingleArgConstructor:\t" << this << endl;
	}
	String(const char* other)
	{
		size = strlen(other) + 1;
		str = new char[size] {};
		strcpy(str, other);
		cout << "Constructor:\t\t" << this << endl;
	}
	~String()
	{
		delete[] str;
		cout << "Destructor:\t\t" << this << endl;
	}

	String& operator=(const String& other)
	{
		delete[] str;
		this->size = other.get_size();
		this->str = other.get_str();
		for (int i = 0; i < size; i++)
			this->str[i] = other.get_str()[i];
		cout << "CopyAssignment:\t" << endl;
		return *this;
	}

	void print()
	{
		cout << "size:\t" << this->size << endl;
		cout << "str:\t" << this->str << endl;
	}

};
	
String operator+(const String& left, const String& right)
{
	String result = left.get_size() + right.get_size() - 1;
	for (int i = 0; i < left.get_size(); i++)
	{
		result.get_str()[i] = left.get_str()[i];
	}
	for (int i = 0; i < right.get_size(); i++)
	{
		result.get_str()[i + left.get_size() - 1] = right.get_str()[i];
	}
	return result;
}

std::ostream& operator<<(std::ostream& os, const String& str)
{
	return os << str.get_str();
}

void main()
{
	setlocale(LC_ALL, "");
	
	String str1;
	str1.print();
	cout << delimiter << endl;

	String str2(8);
	str2.print();
	cout << delimiter << endl;

	String str3 = "Hello";
	cout << str3 << endl;
	cout << delimiter << endl;

	String str4 = "World";
	cout << str4 << endl;
	cout << delimiter << endl;

	String str5 = str3 + " " + str4;
	/*String str5;
	str5 = str3 + str4;*/
	cout << str5 << endl;
	cout << delimiter << endl;
}