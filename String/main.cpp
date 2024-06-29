#include "String.h"

//#define CONSTRUCTORS_CHECK
#define OPERATOR_PLUS_CHECK
//#define MOVE_ASSIGNMENT_CHECK
//#define CALLING_CONSTRUCTORS

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

#ifdef CALLING_CONSTRUCTORS
	String str1;
	str1.print();

	//String str2 = 8;	//explisit constructor так вызвать нельзя
	String str2(8);		//explisit constructor можно вызвать только так
	str2.print();

	String str3 = "Hello";	//Single-Argument constructor 'char'
	str3.print();

	String str4();		//не вызывается никакой конструктор, и не создается объект, здесь объявляется функция str4(), которая не принимает никаких параметров
						//которая не принимает никаких параметров и возвращает значение типа 'String'
	//str4.print();

	String str5{};		//явный вызов конструктора по умолчанию
	str5.print();

	//String str6 = str3;	//CopyConstructor
	//String str6(str3);	//CopyConstructor
	String str6{ str3 };	//CopyConstructor
	str6.print();
#endif // CALLING_CONSTRUCTORS

}