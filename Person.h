#ifndef Person_H
#define Person_H
class Person
{
    string name, id;
    Address address;

public:
    Person();
    Person(string nameInput, string idInput);
    Person(const Person &copy);
    friend ostream &operator<<(ostream &strm, Person &A);
    friend istream &operator>>(istream &strm, Person &A);
    void setName(string input);
    void setId(string input);
    void setStreet(Address input);
    string getName();
    string getId();
    Address getAddress();
    Person &operator=(const Person &r);
    bool validate();
};
#endif