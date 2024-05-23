#include <iostream>
#include <string>
#include <cmath>
using namespace std;
bool validvalue = true;
class Address
{
    string country, city, street;

public:
    Address()
    {
        country = "United Kingdom";
        city = "London";
        street = "Baker";
    }
    Address(string countryInput, string cityInput, string streetInput)
    {
        country = countryInput;
        city = cityInput;
        street = streetInput;
    }
    friend ostream &operator<<(ostream &, Address &);
    friend istream &operator>>(istream &, Address &);
    void setCountry(string input)
    {
        country = input;
    }
    void setCity(string input)
    {
        city = input;
    }
    void setStreet(string input)
    {
        street = input;
    }
    string getCountry()
    {
        return country;
    }
    string getCity()
    {
        return city;
    }
    string getStreet()
    {
        return street;
    }
};
ostream &operator<<(ostream &strm, Address &A)
{
    strm << "country = " << A.country << "   city = " << A.city << "   street = " << A.street;
    return strm;
}
istream &operator>>(istream &strm, Address &A)
{
    cout << "enter country city and street name in order:";
    strm >> A.country >> A.city >> A.street;
    return strm;
}
class Person 
{
    string name, id;
    Address address;

public:
    Person()
    {
        name = "Sherlock Holmes";
        id = "88bbs22119";
    }
    Person(string nameInput, string idInput) : name(nameInput), id(idInput)
    {
        cin >> address;
        if (!validate())
        {
            cout << "invalid id!\n";
            validvalue = false;
        }
    }
    Person(const Person &copy)
    {
        name = copy.name;
        id = copy.id;
        address = copy.address;
    }
    friend ostream &operator<<(ostream &strm, Person &A);
    friend istream &operator>>(istream &strm, Person &A);
    void setName(string input)
    {
        name = input;
    }
    void setId(string input)
    {
        id = input;
        if (!validate())
        {
            cout << "invalid id!\n";
            validvalue = false;
        }
    }
    void setStreet(Address input)
    {
        address = input;
    }
    string getName()
    {
        return name;
    }
    string getId()
    {
        return id;
    }
    Address getAddress()
    {
        return address;
    }
    Person &operator=(const Person &r)
    {
        name = r.name;
        address = r.address;
        id = r.id;
        return *this;
    }
    bool validate()
    {
        if (id.length() >= 8 || id.length() <= 10)
        {
            int i;
            if (((int)id[0] == 56 && ((int)id[1] <= 57 && (int)id[1] >= 53)) || ((int)id[0] == 57 && ((int)id[1] <= 56 && (int)id[1] >= 48)))
            {
                if (id.length() == 8)
                {
                    if (((int)id[2] >= 32 && (int)id[2] <= 47) || ((int)id[2] >= 58 && (int)id[2] <= 126))
                    {
                        i = 2;
                        int j = ++i;
                        int count = 0;
                        for (i; i < j + 5; i++)
                        {
                            if (((int)id[i] <= 51 && (int)id[i] >= 48) || ((int)id[i] <= 58 && (int)id[i] >= 55))
                            {
                                count++;
                            }
                        }
                        if (count == 5)
                            return true;
                    }
                }
                if (id.length() == 9)
                {
                    if ((((int)id[2] >= 32 && (int)id[2] <= 47) || ((int)id[2] >= 58 && (int)id[2] <= 126)) && (((int)id[3] >= 32 && (int)id[3] <= 47) || ((int)id[3] >= 58 && (int)id[3] <= 126)))
                    {
                        i = 3;
                        int j = ++i;
                        int count = 0;
                        for (i; i < j + 5; i++)
                        {
                            if (((int)id[i] <= 51 && (int)id[i] >= 48) || ((int)id[i] <= 58 && (int)id[i] >= 55))
                            {
                                count++;
                            }
                        }
                        if (count == 5)
                            return true;
                    }
                }
                if (id.length() == 10)
                {
                    if (
                        (((int)id[2] >= 32 && (int)id[2] <= 47) || ((int)id[2] >= 58 && (int)id[2] <= 126)) && (((int)id[3] >= 32 && (int)id[3] <= 47) || ((int)id[3] >= 58 && (int)id[3] <= 126)) && (((int)id[4] >= 32 && (int)id[4] <= 47) || ((int)id[4] >= 58 && (int)id[4] <= 126)))
                    {
                        i = 4;

                        int j = ++i;
                        int count = 0;
                        for (i; i < j + 5; i++)
                        {
                            if (((int)id[i] <= 51 && (int)id[i] >= 48) || ((int)id[i] <= 58 && (int)id[i] >= 55))
                            {
                                count++;
                            }
                        }
                        if (count == 5)
                            return true;
                    }
                }
            }
        }
        return false;
    }
};
ostream &operator<<(ostream &strm, Person &A)
{
    strm << "  name = " << A.name << "   id = " << A.getId() << "   address = " << A.address;
    if (!A.validate())
    {
        cout << "invalid id!\n";
        validvalue = false;
    }
    return strm;
}
istream &operator>>(istream &strm, Person &A)
{
    cout << "enter name and id and address in order:";
    strm >> A.name >> A.id;
    if (!A.validate())
    {
        cout << "invalid id!\n";
        validvalue = false;
        return strm;
    }
    strm >> A.address;

    return strm;
}
class Employee
{
    int hourWork, salaryPerHour, workToDo, workDone;

public:
    string name, id;
    Address address;
    Employee()
    {
        name = "Elliot Alderson";
        id = "88*ER28072";
        hourWork = 0;
        salaryPerHour = 0;
        workDone = 0;
        workToDo = 0;
    }
    Employee(string nameinput, string idinput, int hourWorkinnput, int salaryPerHourinput, int workToDoinput, int workDoneinput) : name(nameinput), id(idinput), hourWork(hourWorkinnput), salaryPerHour(salaryPerHourinput), workDone(workDoneinput), workToDo(workToDoinput)
    {
        if (!validate())
        {
            cout << "invalid id!\n";
            validvalue = false;
        }
    }
    Employee(const Employee &copy)
    {
        name = copy.name;
        id = copy.id;
        hourWork = copy.hourWork;
        workDone = copy.workDone;
        address = copy.address;
        salaryPerHour = copy.salaryPerHour;
        workToDo = copy.workToDo;
    }
    friend ostream &operator<<(ostream &strm, Employee &A);
    friend istream &operator>>(istream &strm, Employee &A);
    Employee &operator=(const Employee &r)
    {
        name = r.name;
        address = r.address;
        id = r.id;
        hourWork=r.hourWork;
        salaryPerHour=r.salaryPerHour;
        workDone=r.workDone;
        workToDo=r.workToDo;
        return *this;
    }
    void setId(string inputid)
    {
        id = inputid;
        cin >> address;
        if (!validate())
        {
            cout << "invalid id!\n";
            validvalue = false;
        }
    }
    string getId()
    {
        return id;
    }
    void setHourWork(int input)
    {
        hourWork = input;
    }
    int getHourWork()
    {
        return hourWork;
    }
    void setSalaryPerHour(int input)
    {
        salaryPerHour = input;
    }
    int getSalaryPerHour()
    {
        return salaryPerHour;
    }
    void setWorkToDo(int input)
    {
        workToDo = input;
    }
    int getWorkToDo()
    {
        return workToDo;
    }
    void setWorkDone(int input)
    {
        workDone = input;
    }
    int getWorkDone()
    {
        return workDone;
    }
    bool validate()
    {
        if (id.length() >= 8 || id.length() <= 10)
        {
            int i;
            if (((int)id[0] == 56 && ((int)id[1] <= 57 && (int)id[1] >= 53)) || ((int)id[0] == 57 && ((int)id[1] <= 56 && (int)id[1] >= 48)))
            {

                if (id.length() == 8)
                {
                    if ((int)id[2] == 42)
                    {
                        i = 2;
                        int j = ++i;
                        int count = 0;
                        for (i; i < j + 5; i++)
                        {
                            if (((int)id[i] <= 51 && (int)id[i] >= 48) || ((int)id[i] <= 58 && (int)id[i] >= 55))
                            {
                                count++;
                            }
                        }
                        if (count == 5)
                            return true;
                    }
                }

                if (id.length() == 9)
                {
                    if (((int)id[2] == 42) && (((int)id[3] >= 32 && (int)id[3] <= 47) || ((int)id[3] >= 58 && (int)id[3] <= 126)))
                    {
                        i = 3;
                        int j = ++i;
                        int count = 0;
                        for (i; i < j + 5; i++)
                        {
                            if (((int)id[i] <= 51 && (int)id[i] >= 48) || ((int)id[i] <= 58 && (int)id[i] >= 55))
                            {
                                count++;
                            }
                        }
                        if (count == 5)
                            return true;
                    }
                }

                if (id.length() == 10)
                {
                    if (
                        ((int)id[2] == 42) && (((int)id[3] >= 32 && (int)id[3] <= 47) || ((int)id[3] >= 58 && (int)id[3] <= 126)) && (((int)id[4] >= 32 && (int)id[4] <= 47) || ((int)id[4] >= 58 && (int)id[4] <= 126)))
                    {
                        i = 4;

                        int j = ++i;
                        int count = 0;
                        for (i; i < j + 5; i++)
                        {
                            if (((int)id[i] <= 51 && (int)id[i] >= 48) || ((int)id[i] <= 58 && (int)id[i] >= 55))
                            {
                                count++;
                            }
                        }
                        if (count == 5)
                            return true;
                    }
                }
            }
        }
        return false;
    }
    float calculateSalery()
    {
        float salary;
        salary = ((float)workDone /(float) workToDo) * (float)hourWork * (float)salaryPerHour;
        return salary;
    }
    float efficiency()
    {
        return ((float)workDone /(float) hourWork*100);
    }
};
ostream &operator<<(ostream &strm, Employee &A)
{
    strm << "   name = " << A.name << "   id = " << A.id << "   address = " << A.address << "    hour work = " << A.hourWork << "   salary per hour = " << A.salaryPerHour << "  work to do = " << A.workToDo << "    work Done = " << A.workDone;
    return strm;
}
istream &operator>>(istream &strm, Employee &A)
{
    cout << "enter name,id,address,hourwork ,salary per hour,work to do,work done in order:";
    strm >> A.name >> A.id;
    if (!A.validate())
    {
        cout << "invalid id!\n";
        validvalue = false;
        return strm;
    }
    strm >> A.address >> A.hourWork >> A.salaryPerHour >> A.workToDo >> A.workDone;
    return strm;
}
class Point
{
    int x, y;

public:
    Point()
    {
        x = 0;
        y = 0;
    }
    Point(int x, int y) : x(x), y(y)
    {
    }
    Point(const Point &copy)
    {
        x = copy.x;
        y = copy.y;
    }
    friend Point operator+(const Point &a, const Point &b)
    {

        return Point(a.x + b.x, a.y + b.y);
    }
    friend Point operator-(const Point &a, const Point &b)
    {

        return Point(a.x - b.x, a.y - b.y);
    }
    Point &operator/=(int b)
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
    Point &operator=(const Point &r)
    {
        x = r.x;
        y = r.y;
        return *this;
    }
    friend bool operator>=(const Point &f, const Point &s)
    {
        if (sqrt((f.x) * (f.x) + (f.y) * (f.y)) >= sqrt((s.x) * (s.x) + (s.y) * (s.y)))
        {
            return true;
        }
        else
            return false;
    }
    void setX(int input)
    {
        x = input;
    }
    void setY(int input)
    {
        y = input;
    }
    int getX()
    {
        return x;
    }
    int getY()
    {
        return y;
    }
};
class Rectangle
{
    Point startPoint;
    int width, height;

public:
    Rectangle()
    {
        // startPoint = ;
        width = 0;
        height = 0;
    }
    Rectangle(Point startPointinput, int heightinput, int widthinput) : startPoint(startPointinput), width(widthinput), height(heightinput)
    {
    }
    Rectangle(const Rectangle &copy)
    {
        width = copy.width;
        height = copy.height;
        startPoint = copy.startPoint;
    }
    Rectangle &operator+=(Rectangle &r)
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
    Rectangle &operator-=(Rectangle &r)
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
    friend Rectangle operator/(Rectangle a, Rectangle b)
    {
        Point st(((a.startPoint.getX() + b.startPoint.getX()) / 2), ((a.startPoint.getY() + b.startPoint.getY()) / 2));
        Rectangle z(st, a.height / b.height, a.width / b.width);
        return z;
    }
    void setStartPoint(Point startpointinput)
    {
        startPoint = startpointinput;
    }
    void setWidth(int widthinput)
    {
        width = widthinput;
    }
    void setHeight(int heightinput)
    {
        height = heightinput;
    }
    Point getStartPoint()
    {
        return startPoint;
    }
    int getWidth()
    {
        return width;
    }
    int getHeight()
    {
        return height;
    }
    friend bool collisionDetection(Rectangle &f, Rectangle &s)
    {   
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
};
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

    Rectangle regtangle1, regtangle2, cpyregtangle;
    int heinput, widinput, xinput, yinput;
    Point pointInRegt;
    cout << "*Rectangle class*\nthe default value of regtangle1:\nheight = " << regtangle1.getHeight() << "   Width = " << regtangle1.getWidth() << "   startPoint = " << "(" << regtangle1.getStartPoint().getX() << "," << regtangle1.getStartPoint().getY() << ")" << endl
         << "enter the new value of ( x , y ) and height and width and x:";
    cin >> xinput >> yinput >> heinput >> widinput;
    regtangle1.setHeight(heinput);
    regtangle1.setWidth(widinput);
    pointInRegt.setX(xinput);
    pointInRegt.setY(yinput);
    regtangle1.setStartPoint(pointInRegt);
    cout << "enter the new value of ( x , y ) and height and width and x:";
    cin >> xinput >> yinput >> heinput >> widinput;
    regtangle2.setHeight(heinput);
    regtangle2.setWidth(widinput);
    pointInRegt.setX(xinput);
    pointInRegt.setY(yinput);
    regtangle2.setStartPoint(pointInRegt);
    cpyregtangle = regtangle1;
    cpyregtangle += regtangle2;
    cout << "regtangle1 += regtangle2     regtangle1 =(" << "(" << regtangle1.getStartPoint().getX() << "," << regtangle1.getStartPoint().getY() << ")" << " , " << regtangle1.getHeight() << " , " << regtangle1.getWidth() << ")\n";
    cpyregtangle = regtangle1;
    cpyregtangle -= regtangle2;
    cout << "regtangle1 -= regtangle2     regtangle1 = (" << "(" << regtangle1.getStartPoint().getX() << "," << regtangle1.getStartPoint().getY() << ")" << " , " << regtangle1.getHeight() << " , " << regtangle1.getWidth() << ")\n";

    cpyregtangle = regtangle1;
    Rectangle resultRegt = operator/(cpyregtangle, regtangle2);
    cout << "regtangle1 / regtangle2 = ( (" << resultRegt.getStartPoint().getX() << "," << resultRegt.getStartPoint().getY() << ") , " << resultRegt.getHeight() << " , " << resultRegt.getWidth() << ")\n";
    if (collisionDetection(regtangle1, regtangle2))
        cout << "have a collision\n";
    else
        cout << "haven't collision\n";
}