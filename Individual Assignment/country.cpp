/*AUTHOR: Hadi El-Kadri
OCTOBER 7 2020
Class country is a country object that stores data for a country and its cases
*/

//Include libraries and header file
#include "country.h"
#include <iostream>
#include <string>

using namespace std;

//String variables to contain countrys name and countrys code
string country_name;
string country_code;

//Integer variables to contain all cases
int new_confirmed;
int new_death;
int new_recovered;
int total_confirmed;
int total_death;
int total_recovered;

//Class constructor takes in parameter x that will be the countrys name
Country::Country(string x)
{
    country_name = x;
}

//Setname will manually set country name to string parameter name
void Country::setName(string name)
{
    country_name = name;
}

//Getter to get country name
string Country::getName()
{
    return country_name;
}

//Setter to set country code to string parameter x
void Country::setCode(string x)
{
    country_code = x;
}

//Getter to get country code
string Country::getCode()
{
    return country_code;
}

//Setter to set new confirmed to int parameter x
void Country::setNewC(int x)
{
    new_confirmed = x;
}

//Getter to get new confirmed cases
int Country::getNewC()
{
    return new_confirmed;
}

//Setter to set new death to int parameter x
void Country::setNewD(int x)
{
    new_death = x;
}

//Getter to get new death cases
int Country::getNewD()
{
    return new_death;
}

//Setter to set new recovered to int parameter x
void Country::setNewR(int x)
{
    new_recovered = x;
}

//Getter to get new recovered cases
int Country::getNewR()
{
    return new_recovered;
}

//Setter to set total confirmed to int parameter x
void Country::setTotalC(int x)
{
    total_confirmed = x;
}

//Getter to get total confirmed cases
int Country::getTotalC()
{
    return total_confirmed;
}

//Setter to set total death to int parameter x
void Country::setTotalD(int x)
{
    total_death = x;
}

//Getter to get total death cases
int Country::getTotalD()
{
    return total_death;
}

//Setter to set total recovered to int parameter x
void Country::setTotalR(int x)
{
    total_recovered = x;
}

//Getter to get total recovered cases
int Country::getTotalR()
{
    return total_recovered;
}

//Class deconstructor
Country::~Country(){};
