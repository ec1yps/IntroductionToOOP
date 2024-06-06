#include <iostream>
using namespace std;

double Distance(double a, double b);

class Point
{
	double x;
	double y;

public:
	double get_x()const
	{
		return x;
	}
	double get_y()const
	{
		return y;
	}
	void set_x(double x)
	{
		this->x = x;
	}
	void set_y(double y)
	{
		this->y = y;
	}

	double distance(double x, double y)
	{
		return sqrt(x * x + y * y);
	}
};

void main()
{
	setlocale(LC_ALL, "");
	double x, y;
	cout << "Введите координаты первой точки (x, y): "; cin >> x >> y;
	double a, b;
	cout << "Введите координаты второй точки (a, b): "; cin >> a >> b;

	Point A;
	cout << "Расстояние до первой точки: " << A.distance(x, y) << endl;

	Point B;
	cout << "Расстояние до второй точки: " << B.distance(a, b) << endl;

	cout << "Расстояник между точками: " << Distance(A.distance(x, y), B.distance(a, b)) << endl;
}

double Distance(double a, double b)
{
	if (a > b) return a - b;
	else return b - a;
}