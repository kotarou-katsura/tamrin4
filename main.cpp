#include <iostream>
#include <string>
#include <cmath>
#include "Address.h"
#include "Employee.h"
#include "Person.h"
#include "Point.h"
#include "Rectangle.h"
using namespace std;
bool validvalue = true;
int main()
{
    cout << "in this program we test our methods\n";
    Address home;
    cout << "*Address class*\nthe default values of home :  " << home << endl;
    cin >> home;
    cout << "the new values of home:" << home << endl;
    cout << "+edite  :   the city name = " << home.getCity() << " \n            the new city name:";
    string newName;
    cin >> newName;
    home.setCity(newName);
    cout << "new value of home :  " << home;
    Person detective;
    cout << "\n*Person class*\nthe default values of detective :  " << detective << endl;
    cin >> detective;
    if (validvalue == false)
        return 0;
    cout << "the new values of the detective:" << detective << endl;
    Person teacherCpy;
    teacherCpy = detective;
    cout << "the values of the teacher :  " << teacherCpy << endl;
    cout << "+edite  :   the name = " << teacherCpy.getName() << " \n            the new name = ";
    cin >> newName;
    teacherCpy.setName(newName);
    cout << " \n            the id = " << teacherCpy.getId() << " \n            the new id = ";
    string newId;
    cin >> newId;
    teacherCpy.setId(newId);
    if (validvalue == false)
        return 0;
    cout << "\n*Employee class*\nthe new values of the teacher:" << teacherCpy << endl;
    Employee cybersecurityEngineer;
    cout << "the default values of cybersecurity Engineer:" << cybersecurityEngineer << endl;
    cin >> cybersecurityEngineer;
    if (validvalue == false)
        return 0;
    cout << "the new values of cybersecurity Engineer:" << cybersecurityEngineer << endl;
    cout << "the salary:" << cybersecurityEngineer.calculateSalery() << endl;
    cout << "the efficiency:" << cybersecurityEngineer.efficiency() << endl;
    cout << "----------------------------\n*Point class*\n";
    Point point1;
    cout << "the default value of point1 :    x:" << point1.getX() << "   y:" << point1.getY() << endl
         << "enter the new value of x and y:";
    int xx, yy;
    cin >> xx >> yy;
    point1.setX(xx);
    point1.setY(yy);
    Point point2;
    cout << "enter the value of x and y of point2:";
    cin >> xx >> yy;
    point2.setX(xx);
    point2.setY(yy);
    Point result = point1 + point2;
    cout << "point1+point2 = (" << result.getX() << " , " << result.getY() << ")" << endl;
    result = point1 - point2;
    cout << "point1-point2 = (" << result.getX() << " , " << result.getY() << ")" << endl;
    Point cpypoint = point1;
    cpypoint /= 2;
    cout << "point1/=2   point1= (" << cpypoint.getX() << " , " << cpypoint.getY() << ")" << endl;
    if (point1 >= point2)
        cout << "the point1 >= point2\n";
    else
        cout << "the point1 < point2\n";

    Rectangle Rectangle1, Rectangle2, cpyRectangle;
    int heinput, widinput, xinput, yinput;
    Point pointInRegt;
    cout << "*Rectangle class*\nthe default value of Rectangle1:\nheight = " << Rectangle1.getHeight() << "   Width = " << Rectangle1.getWidth() << "   startPoint = " << "(" << Rectangle1.getStartPoint().getX() << "," << Rectangle1.getStartPoint().getY() << ")" << endl
         << "enter the new value of ( x , y ) and height and width and x:";
    cin >> xinput >> yinput >> heinput >> widinput;
    Rectangle1.setHeight(heinput);
    Rectangle1.setWidth(widinput);
    pointInRegt.setX(xinput);
    pointInRegt.setY(yinput);
    Rectangle1.setStartPoint(pointInRegt);
    cout << "enter the new value of ( x , y ) and height and width and x:";
    cin >> xinput >> yinput >> heinput >> widinput;
    Rectangle2.setHeight(heinput);
    Rectangle2.setWidth(widinput);
    pointInRegt.setX(xinput);
    pointInRegt.setY(yinput);
    Rectangle2.setStartPoint(pointInRegt);
    cpyRectangle = Rectangle1;
    cpyRectangle += Rectangle2;
    cout << "Rectangle1 += Rectangle2     Rectangle1 =(" << "(" << Rectangle1.getStartPoint().getX() << "," << Rectangle1.getStartPoint().getY() << ")" << " , " << Rectangle1.getHeight() << " , " << Rectangle1.getWidth() << ")\n";
    cpyRectangle = Rectangle1;
    cpyRectangle -= Rectangle2;
    cout << "Rectangle1 -= Rectangle2     Rectangle1 = (" << "(" << Rectangle1.getStartPoint().getX() << "," << Rectangle1.getStartPoint().getY() << ")" << " , " << Rectangle1.getHeight() << " , " << Rectangle1.getWidth() << ")\n";

    cpyRectangle = Rectangle1;
    Rectangle resultRegt = operator/(cpyRectangle, Rectangle2);
    cout << "Rectangle1 / Rectangle2 = ( (" << resultRegt.getStartPoint().getX() << "," << resultRegt.getStartPoint().getY() << ") , " << resultRegt.getHeight() << " , " << resultRegt.getWidth() << ")\n";
    if (collisionDetection(Rectangle1, Rectangle2))
        cout << "have a collision\n";
    else
        cout << "haven't collision\n";
        cout<<"press any character for exite :";
        char exitevalue;
        cin>>exitevalue;
}