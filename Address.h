#ifndef Address_H
#define Address_H
#include <string>
using namespace std;
class Address
{
    string country, city, street;

public:
    Address();
    Address(string countryInput, string cityInput, string streetInput);
    friend ostream &operator<<(ostream &, Address &);
    friend istream &operator>>(istream &, Address &);
    void setCountry(string input);
    void setCity(string input);
    void setStreet(string input);
    string getCountry();
    string getCity();
    string getStreet();
};
#endif