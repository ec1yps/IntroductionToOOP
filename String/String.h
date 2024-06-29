#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;
using std::cout;
using std::cin;
using std::endl;

#define delimiter "--------------------------------------------"

/////////////////////////////////////////////////////
/////////			Class declaration		/////////
class String;
String operator+(const String& left, const String& right);
std::ostream& operator<<(std::ostream& os, const String& str);

class String
{
	int size;
	char* str;
public:
	int get_size()const;
	const char* get_str()const;
	char* get_str();

	explicit String(int size = 80);
	String(const char str[]);
	String(const String& other);
	String(String&& other)noexcept;
	~String();

	String& operator=(const String& other);
	String& operator=(String&& other)noexcept;
	char& operator[](int i);
	const char& operator[](int i)const;

	void print()const;
};

/////////		Class declaration end		/////////
/////////////////////////////////////////////////////
