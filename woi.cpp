#include <iostream>
sing namespace std;
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
        int calculateSalery()
    {
        float salary;
        salary = ((float)workDone / (float)workToDo) * (float)hourWork * (float)salaryPerHour;
        return salary;
    }
        int efficiency()
    {
        return ((float)workDone /(float) hourWork);
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
int main(){

}