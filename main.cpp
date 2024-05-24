#include "main.h"
bool validvalue = true;
using namespace std;
int main()
{
    /* cout << "in this program we test our methods\n";
     Address home;
     cout << "----------------------------\n*Address class*\nthe default values of home :  " << home << endl;
     cin >> home;
     cout << "the new values of home:" << home << endl;
     cout << "+edite  :   the city name = " << home.getCity() << " \n            the new city name:";
     string newName;
     cin >> newName;
     home.setCity(newName);
     cout << "new value of home :  " << home;
     Person detective;
     cout << "\n----------------------------\n*Person class*\nthe default values of detective :  " << detective << endl;
     cin >> detective;
     if (validvalue == false)
         return 0;
     cout << "the new values of the detective:" << detective << endl;
     Person teacherCpy;
     teacherCpy = detective;
     cout << "*testing operator = *\nthe values of the teacher :  " << teacherCpy << endl;
     cout << "+edite  :   the name = " << teacherCpy.getName() << " \n            the new name = ";
     cin >> newName;
     teacherCpy.setName(newName);
     cout << " \n            the id = " << teacherCpy.getId() << " \n            the new id = ";
     string newId;
     cin >> newId;
     teacherCpy.setId(newId);
     if (validvalue == false)
         return 0;
     cout << "\nthe new values of the teacher:" << teacherCpy << endl;
     Employee cybersecurityEngineer;
     cout << "----------------------------\n*Employee class*\nthe default values of cybersecurity Engineer:" << cybersecurityEngineer << endl;
     cin >> cybersecurityEngineer;
     if (validvalue == false)
         return 0;
     cout << "the new values of cybersecurity Engineer:" << cybersecurityEngineer << endl;
     cout << "the salary:" << cybersecurityEngineer.calculateSalery() << endl;
     cout << "the efficiency:" << cybersecurityEngineer.efficiency() <<"%"<< endl;
     cout << "----------------------------\n*Point class*\n";
     Point point1;
     cout << "\n*Point1 and point2 are assumed to be constant during the implementation of the program,Changes are made on copies of these points*\n\nthe default value of point1 :    x:" << point1.getX() << "   y:" << point1.getY() << endl
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
     int b;
     cout<<"enter a number:";
     cin>>b;
     cpypoint /= b;
     cout << "point1/="<<b<<"   result= (" << cpypoint.getX() << " , " << cpypoint.getY() << ")" << endl;
     if (point1 >= point2)
         cout << "the point1 >= point2\n";
     else
         cout << "the point1 < point2\n";
         */
    Rectangle Rectangle1, Rectangle2, cpyRectangle;
    int heinput, widinput, xinput, yinput;
    Point pointInRegt;

    cout << "----------------------------\n*Rectangle class*\n\n*Rectangles are assumed to be constant during the implementation of the program,Changes are made on copies of these Rectangles*\n*also assumed height >= width*\nthe default value of Rectangle1:  height = " << Rectangle1.getHeight() << "   Width = " << Rectangle1.getWidth() << "   startPoint = " << "(" << Rectangle1.getStartPoint().getX() << "," << Rectangle1.getStartPoint().getY() << ")" << endl
         << "enter the new value of ( x , y ) and height and width : ";
    cin >> xinput >> yinput >> heinput >> widinput;
    Rectangle1.setHeight(heinput);
    Rectangle1.setWidth(widinput);
    pointInRegt.setX(xinput);
    pointInRegt.setY(yinput);
    Rectangle1.setStartPoint(pointInRegt);
    cout << "enter the new value of ( x , y ) and height and width : ";
    cin >> xinput >> yinput >> heinput >> widinput;
    Rectangle2.setHeight(heinput);
    Rectangle2.setWidth(widinput);
    pointInRegt.setX(xinput);
    pointInRegt.setY(yinput);
    Rectangle2.setStartPoint(pointInRegt);
    cpyRectangle = Rectangle1;
    /* cpyRectangle += Rectangle2;
     cout << "Rectangle1 += Rectangle2     Result =(" << "(" << cpyRectangle.getStartPoint().getX() << "," << cpyRectangle.getStartPoint().getY() << ")" << " , " << cpyRectangle.getHeight() << " , " << cpyRectangle.getWidth() << ")\n";
     cpyRectangle = Rectangle1;
     cpyRectangle -= Rectangle2;
     cout << "Rectangle1 -= Rectangle2     Result = (" << "(" << cpyRectangle.getStartPoint().getX() << "," << cpyRectangle.getStartPoint().getY() << ")" << " , " << cpyRectangle.getHeight() << " , " << cpyRectangle.getWidth() << ")\n";

     cpyRectangle = Rectangle1;
     Rectangle resultRegt = operator/(cpyRectangle, Rectangle2);
     cout << "Rectangle1 / Rectangle2 = ( (" << resultRegt.getStartPoint().getX() << "," << resultRegt.getStartPoint().getY() << ") , " << resultRegt.getHeight() << " , " << resultRegt.getWidth() << ")\n";
     cout << "Rectangle1 and Rectangle2 ";*/
    if (collisionDetection(Rectangle1, Rectangle2))
        cout << "have a collision\n";
    else
        cout << "haven't collision\n";
    Rectangle Rectangle3;
    cout << "enter the new value of ( x , y ) and height and width : ";
    cin >> xinput >> yinput >> heinput >> widinput;
    Rectangle3.setHeight(heinput);
    Rectangle3.setWidth(widinput);
    pointInRegt.setX(xinput);
    pointInRegt.setY(yinput);
    Rectangle3.setStartPoint(pointInRegt);
    cout << "Rectangle1 and Rectangle3 ";
    if (collisionDetection(Rectangle1, Rectangle3))
        cout << "have a collision\n";
    else
        cout << "haven't collision\n";
    cout << "press any character for exite :";
    char exitevalue;
    cin >> exitevalue;
}