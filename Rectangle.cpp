#include "Rectangle.h"
#include <iostream>
Rectangle:: Rectangle()
{
    width = 0;
    height = 0;
}
Rectangle::Rectangle(Point startPointinput, int heightinput, int widthinput) : startPoint(startPointinput), width(widthinput), height(heightinput)
{
}
Rectangle::Rectangle(const Rectangle &copy)
{
    width = copy.width;
    height = copy.height;
    startPoint = copy.startPoint;
}
Rectangle &Rectangle::operator+=(Rectangle &r)
{
    if ((startPoint.getX() != r.startPoint.getX()) && (startPoint.getY() != r.startPoint.getY()))
    {
        std::cout << "Error!the start Points are different.\n";
        return *this;
    }
    else
    {
        if (r.height >= height)
        {
            height = r.height;
        }
        if (r.width >= width)
        {
            width = r.width;
        }
        return *this;
    }
}
Rectangle &Rectangle::operator-=(Rectangle &r)
{
    if ((startPoint.getX() != r.startPoint.getX()) && (startPoint.getY() != r.startPoint.getY()))
    {
        std::cout << "Error!the start Points are different.\n";
        return *this;
    }
    else
    {
        if (r.height <= height)
        {
            height = r.height;
        }
        if (r.width <= width)
        {
            width = r.width;
        }
        return *this;
    }
}
Rectangle operator /(Rectangle a, Rectangle b)
{
    Point st(((a.startPoint.getX() + b.startPoint.getX()) / 2), ((a.startPoint.getY() + b.startPoint.getY()) / 2));
    Rectangle z(st, a.height / b.height, a.width / b.width);
    return z;
}
void Rectangle::setStartPoint(Point startpointinput)
{
    startPoint = startpointinput;
}
void Rectangle::setWidth(int widthinput)
{
    width = widthinput;
}
void Rectangle::setHeight(int heightinput)
{
    height = heightinput;
}
Point Rectangle::getStartPoint()
{
    return startPoint;
}
int Rectangle::getWidth()
{
    return width;
}
int Rectangle::getHeight()
{
    return height;
}
bool collisionDetection(Rectangle &f, Rectangle &s)
{ // assume the startpoint is the top left point and also regard the oposite point (right down point)
    int fx2, fy2, sx2, sy2;
    fx2 = f.getStartPoint().getX() + f.width;
    fy2 = f.getStartPoint().getY() - f.height;
    sx2 = s.getStartPoint().getX() + s.width;
    sy2 = s.getStartPoint().getY() - s.height;
    if (fx2 > s.getStartPoint().getX() && f.getStartPoint().getX() < sx2 && f.getStartPoint().getY() < sy2 && fy2 > s.getStartPoint().getY())
        return true;
    else
        return false;
}