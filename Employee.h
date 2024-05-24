#ifndef Employee_H
#define Employee_H
#include "Address.h"
class Employee
{
    int hourWork, salaryPerHour, workToDo, workDone;

public:
    string name, id;
    Address address;
    Employee();
    Employee(string nameinput, string idinput, int hourWorkinnput, int salaryPerHourinput, int workToDoinput, int workDoneinput);
    Employee(const Employee &copy);
    friend ostream &operator<<(ostream &strm, Employee &A);
    friend istream &operator>>(istream &strm, Employee &A);
    Employee &operator=(const Employee &r);
    void setId(string inputid);
    string getId();
    void setHourWork(int input);
    int getHourWork();
    void setSalaryPerHour(int input);
    int getSalaryPerHour();
    void setWorkToDo(int input);
    int getWorkToDo();
    void setWorkDone(int input);
    int getWorkDone();
    bool validate();
    float calculateSalery();
    float efficiency();
};
#endif