#include "Person.h"
Person::Person()
{
    // the default values
    name = "Sherlock Holmes";
    id = "88bbs22119";
}
Person::Person(string nameInput, string idInput) : name(nameInput), id(idInput)
{
    cin >> address;
    if (!validate())
    {
        cout << "invalid id!\n";
        validvalue = false;
    }
}
Person::Person(const Person &copy)
{
    name = copy.name;
    id = copy.id;
    address = copy.address;
}
void Person::setName(string input)
{
    name = input;
}
void Person::setId(string input)
{
    id = input;
    if (!validate())
    {
        cout << "invalid id!\n";
        validvalue = false;
    }
}
void Person::setStreet(Address input)
{
    address = input;
}
string Person::getName()
{
    return name;
}
string Person::getId()
{
    return id;
}
Address Person::getAddress()
{
    return address;
}
Person &Person::operator=(const Person &r)
{
    name = r.name;
    address = r.address;
    id = r.id;
    return *this;
}
bool Person::validate()
{
    // check the id character by character by ascii codes
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
