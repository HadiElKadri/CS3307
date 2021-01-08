/* AUTHOR: Hadi El-Kadri
OCTOBER 7 2020
HEADER FILE FOR CLASS COUNTRY
*/
#ifndef COUNTRY_H
#define COUNTRY_H

//Include libraries
#include <iostream>
#include <string>

using namespace std;

class Country
{

private:
    
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

public:
    Country(string); //Class constructor takes in string parameter

    void setName(string); //Setname will manually set country name to string parameter

    string getName(); //Getter to get country name

    void setCode(string); //Setter to set country code to string parameter 

    string getCode(); //Getter to get country code

    void setNewC(int); //Setter to set new confirmed to int parameter 

    int getNewC(); //Getter to get new confirmed cases

    void setNewD(int); //Setter to set new death to int parameter 

    int getNewD(); //Getter to get new death cases

    void setNewR(int); //Setter to set new recovered to int parameter 

    int getNewR(); //Getter to get new recovered cases

    void setTotalC(int); //Setter to set total confirmed to int parameter 

    int getTotalC(); //Getter to get total confirmed cases

    void setTotalD(int); //Setter to set total death to int parameter

    int getTotalD(); //Getter to get total death cases

    void setTotalR(int); //Setter to set total recovered to int parameter

    int getTotalR(); //Getter to get total recovered cases

    ~Country(); //Class deconstructor
};
#endif
