#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;
using std::cout;
using std::cin;
using std::endl;

#define delimiter "--------------------------------------------"

class String
{
	int size;
	char* str;
public:
	int get_size()const
	{
		return size;
	}
	const char* get_str()const
	{
		return str;
	}
	char* get_str()
	{
		return str;
	}

	explicit String(int size = 80)
	{
		this->size = size;
		this->str = new char[size] {};
		cout << "DefaultConstructor:" << this << endl;
	}
	String(const char str[])
	{
		this->size = strlen(str) + 1;
		this->str = new char[size] {};
		strcpy(this->str, str);
		cout << "Constructor:\t" << this << endl;
	}
	String(const String& other)
	{
		this->size = other.size;
		this->str = new char[size] {};
		for (int i = 0; i < size; i++) this->str[i] = other.str[i];
		cout << "CopyConstructor:" << this << endl;
	}
	String(String&& other)noexcept
	{
		this->size = other.size;
		this->str = other.str;

		other.size = 0;
		other.str = nullptr;
		cout << "MoveConstructor:" << this << endl;
	}
	~String()
	{
		delete[] str;
		cout << "Destructor:\t" << this << endl;
	}

	String& operator=(const String& other)
	{
		if (this == &other) return *this;
		delete[] this->str;
		this->size = other.size;
		this->str = new char[size] {};
		for (int i = 0; i < size; i++) this->str[i] = other.str[i];
		cout << "CopyAssignment:\t" << this << endl;
		return *this;
	}
	String& operator=(String&& other)noexcept
	{
		if (this == &other) return *this;
		delete[] this->str;
		this->size = other.size;
		this->str = other.str;
		other.size = 0;
		other.str = nullptr;
		cout << "MoveAssignment:\t" << this << endl;
		return *this;
	}
	char& operator[](int i)
	{
		return str[i];
	}
	const char& operator[](int i)const
	{
		return str[i];
	}

	void print()
	{
		cout << "Obj:\t\t" << this << endl;
		cout << "Size:\t\t" << size << endl;
		cout << "Addr:\t\t" << &str << endl;
		cout << "Str:\t\t" << str << endl;
		cout << delimiter << endl;
	}
};
	
String operator+(const String& left, const String& right)
{
	//cout << delimiter << endl;
	cout << "Operator + " << endl;
	String buffer(left.get_size() + right.get_size() - 1);
	//buffer.print();
	for (int i = 0; i < left.get_size(); i++)
	{
		buffer[i] = left[i];
		//buffer.get_str()[i] = left.get_str()[i];
	}
	for (int i = 0; i < right.get_size(); i++)
	{
		buffer[i + left.get_size() - 1] = right[i];
		//buffer.get_str()[i + left.get_size() - 1] = right.get_str()[i];
	}
	return buffer;
}

std::ostream& operator<<(std::ostream& os, const String& str)
{
	return os << str.get_str();
}

//#define CONSTRUCTORS_CHECK
//#define OPERATOR_PLUS_CHECK
#define MOVE_ASSIGNMENT_CHECK

void main()
{
	setlocale(LC_ALL, "");
	
#ifdef CONSTRUCTORS_CHECK
	String str1;
	str1.print();

	String str2(8);
	str2.print();

	String str3 = "Hello";
	str3 = str3;
	str3.print();

	String str4 = "World";
	str4.print();

	cout << str3 << endl;
	cout << str4 << endl;

	//String str5 = str3 + str4;
	String str5;
	str5 = str3 + str4;
	cout << delimiter << endl;
	cout << str5 << endl;
	cout << delimiter << endl;
#endif // CONSTRUCTORS_CHECK

#ifdef OPERATOR_PLUS_CHECK
	String str1 = "Hello";
	String str2 = "World";

	cout << delimiter << endl;
	String str3;
	str3= str1 + str2;
	cout << str3 << endl;
	cout << delimiter << endl;

	str1 = str2;

	cout << str1 << endl;
	cout << str2 << endl;
#endif // OPERATOR_PLUS_CHECK

#ifdef MOVE_ASSIGNMENT_CHECK
	String str1 = "Hello";
	String str2 = "World";
	String str3;
	cout << delimiter << endl;
	str3 = str1 + str2;
	cout << delimiter << endl;
	cout << str3 << endl;
	cout << delimiter << endl;

	String str4;
	str4 = std::move(str3);
	cout << str4 << endl;
	cout << delimiter << endl;
#endif // MOVE_ASSIGNMENT_CHECK
}