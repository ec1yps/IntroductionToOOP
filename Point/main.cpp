#include "Point.h"

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
