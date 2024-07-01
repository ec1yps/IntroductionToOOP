#include "Point.h"

double Point::get_x()const
{
	return x;
}
double Point::get_y()const
{
	return y;
}
void Point::set_x(double x)
{
	this->x = x;
}
void Point::set_y(double y)
{
	this->y = y;
}

double Point::distance(double x, double y)
{
	return sqrt(x * x + y * y);
}

double Distance(double a, double b)
{
	if (a > b) return a - b;
	else return b - a;
}