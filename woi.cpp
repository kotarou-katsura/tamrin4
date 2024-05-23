#include <iostream>
using namespace std;
class Address{
    string country, city, street;
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
};
ostream &operator<<(ostream &strm, Person &A)
{
    strm << "  name = " << A.name << "   id = " << A.id << "   address = " << A.address;
    return strm;
}
istream &operator>>(istream &strm, Person &A)
{
    cout << "enter name and id and address in order:";
    strm >> A.name >> A.id;
    strm >> A.address;
    return strm;
}
int main(){

}