#ifndef Point_H
#define Point_H

class Point
{
    int x, y;
public:
    Point();
    Point(int x, int y);
    Point(const Point &copy);
    friend Point operator+(const Point &a, const Point &b);
    friend Point operator-(const Point &a, const Point &b);
    Point &operator/=(int b);
    Point &operator=(const Point &r);
    friend bool operator>=(const Point &f, const Point &s);
    void setX(int input);
    void setY(int input);
    int getX();
    int getY();
};
#endif 