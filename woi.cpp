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
};
int main(){

}