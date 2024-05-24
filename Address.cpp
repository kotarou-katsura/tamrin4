#include "Address.h"
#include <iostream>
using namespace std;
Address::Address()
{
    // the default values
    country = "United Kingdom";
    city = "London";
    street = "Baker";
}
Address::Address(string countryInput, string cityInput, string streetInput)
{
    country = countryInput;
    city = cityInput;
    street = streetInput;
}
void Address::setCountry(string input)
{
    country = input;
}
void Address::setCity(string input)
{
    city = input;
}
void Address::setStreet(string input)
{
    street = input;
}
string Address::getCountry()
{
    return country;
}
string Address::getCity()
{
    return city;
}
string Address::getStreet()
{
    return street;
}
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