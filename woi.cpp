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
};
int main(){

}