#include "Point.h"
#include <iostream>
#include <cmath>
Point::Point()
{
    x = 0;
    y = 0;
}
Point::Point(int x, int y) : x(x), y(y)
{
}
Point::Point(const Point &copy)
{
    x = copy.x;
    y = copy.y;
}
Point operator+(const Point &a, const Point &b)
{

    return Point(a.x + b.x, a.y + b.y);
}
Point operator-(const Point &a, const Point &b)
{

    return Point(a.x - b.x, a.y - b.y);
}
Point &Point::operator/=(int b)
{
    if (b == 0)
    {
        std::cout << "Error! division to zero\n";
        return *this;
    }
    else
    {
        x = x / b;
        y = y / b;
        return *this;
    }
}
Point &Point::operator=(const Point &r)
{
    x = r.x;
    y = r.y;
    return *this;
}
bool operator>=(const Point &f, const Point &s)
{
    if (sqrt((f.x) * (f.x) + (f.y) * (f.y)) >= sqrt((s.x) * (s.x) + (s.y) * (s.y)))
    {
        return true;
    }
    else
        return false;
}
void Point::setX(int input)
{
    x = input;
}
void Point::setY(int input)
{
    y = input;
}
int Point::getX()
{
    return x;
}
int Point::getY()
{
    return y;
}