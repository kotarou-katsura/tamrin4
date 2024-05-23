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
};
int main(){

}