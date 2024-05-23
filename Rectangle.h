#ifndef Rectangle_H
#define Rectangle_H
class Rectangle
{
    Point startPoint;
    int width, height;

public:
    Rectangle();
    Rectangle(Point startPointinput, int heightinput, int widthinput);
    Rectangle(const Rectangle &copy);
    Rectangle &operator+=(Rectangle &r);
    Rectangle &operator-=(Rectangle &r);
    friend Rectangle operator/(Rectangle a, Rectangle b);
    void setStartPoint(Point startpointinput);
    void setWidth(int widthinput);
    void setHeight(int heightinput);
    Point getStartPoint();
    int getWidth();
    int getHeight();
    friend bool collisionDetection(Rectangle &f, Rectangle &s);
};
#endif