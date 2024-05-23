#include "Employee.h"
Employee::Employee()
{ // no arguman constructor
    name = "Elliot Alderson";
    id = "88*ER28072";
    hourWork = 0;
    salaryPerHour = 0;
    workDone = 0;
    workToDo = 0;
}
Employee::Employee(string nameinput, string idinput, int hourWorkinnput, int salaryPerHourinput, int workToDoinput, int workDoneinput) : name(nameinput), id(idinput), hourWork(hourWorkinnput), salaryPerHour(salaryPerHourinput), workDone(workDoneinput), workToDo(workToDoinput)
{
    if (!validate())
    {
        cout << "invalid id!\n";
        validvalue = false;
    }
}
// cpy constructor
Employee::Employee(const Employee &copy)
{
    name = copy.name;
    id = copy.id;
    hourWork = copy.hourWork;
    workDone = copy.workDone;
    address = copy.address;
    salaryPerHour = copy.salaryPerHour;
    workToDo = copy.workToDo;
}
Employee &Employee::operator =(const Employee &r)
{
    name = r.name;
    address = r.address;
    id = r.id;
    hourWork = r.hourWork;
    salaryPerHour = r.salaryPerHour;
    workDone = r.workDone;
    workToDo = r.workToDo;
    return *this;
}
void Employee::setId(string inputid)
{
    id = inputid;
    cin >> address;
    // check for valid id
    if (!validate())
    {
        cout << "invalid id!\n";
        validvalue = false;
    }
}
string Employee::getId()
{
    return id;
}
void Employee::setHourWork(int input)
{
    hourWork = input;
}
int Employee::getHourWork()
{
    return hourWork;
}
void Employee::setSalaryPerHour(int input)
{
    salaryPerHour = input;
}
int Employee::getSalaryPerHour()
{
    return salaryPerHour;
}
void Employee::setWorkToDo(int input)
{
    workToDo = input;
}
int Employee::getWorkToDo()
{
    return workToDo;
}
void Employee::setWorkDone(int input)
{
    workDone = input;
}
int Employee::getWorkDone()
{
    return workDone;
}
bool Employee::validate()
{
    if (id.length() >= 8 || id.length() <= 10)
    {
        int i;
        // check the id character by character by ascii codes
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
float Employee::calculateSalery()
{
    float salary;
    salary = ((float)workDone / (float)workToDo) * (float)hourWork * (float)salaryPerHour;
    return salary;
}
float Employee::efficiency()
{
    return ((float)workDone / (float)hourWork * 100);
}

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