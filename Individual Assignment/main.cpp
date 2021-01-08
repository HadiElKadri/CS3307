/* AUTHOR: HADI EL-KADRI
OCTOBER 7 2020
THIS PROGRAM WILL ALLOW A USER TO VIEW NUMEROUS CORONA CASES 
IN COUNTRIES AROUND THE WORLD IN ASCENDING OR DESCENDING ORDER
*/

//Include libraries that will help in code and country header for creation and utilization of country objects
#include "country.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

//Helper functions for function sort() to sort vector according based on case and order

bool dsortNewD(Country x, Country y) //Sort new death cases in descending order
{
    return x.getNewD() > y.getNewD(); 
}

bool dsortNewR(Country x, Country y) //Sort new recovery cases in descending order
{
    return x.getNewR() > y.getNewR();
}

bool dsortNewC(Country x, Country y) //Sort new confirmed cases in descending order
{
    return x.getNewC() > y.getNewC();
}

bool dsortTotalD(Country x, Country y) //Sort total death cases in descending order
{
    return x.getTotalD() > y.getTotalD();
}

bool dsortTotalR(Country x, Country y) //Sort total recovery cases in descending order
{
    return x.getTotalR() > y.getTotalR();
}

bool dsortTotalC(Country x, Country y) //Sort total confirmed cases in descending order
{
    return x.getTotalC() > y.getTotalC();
}

bool asortNewD(Country x, Country y) //Sort new death cases in ascending order
{
    return x.getNewD() < y.getNewD();
}

bool asortNewR(Country x, Country y) //Sort new recovery cases in ascending order
{
    return x.getNewR() < y.getNewR();
}

bool asortNewC(Country x, Country y) //Sort new confirmed cases in ascending order
{
    return x.getNewC() < y.getNewC();
}

bool asortTotalD(Country x, Country y) //Sort total death cases in ascending order
{
    return x.getTotalD() < y.getTotalD();
}

bool asortTotalR(Country x, Country y) //Sort total recovery cases in ascending order
{
    return x.getTotalR() < y.getTotalR();
}

bool asortTotalC(Country x, Country y) //Sort total confirmed cases in ascending order
{
    return x.getTotalC() < y.getTotalC();
}

int main()
{
    //Open csv file of countries for reading
    ifstream infile;
    infile.open("summary.csv");

    //Check to see if file was opened correctly, if not ERROR!
    if (!infile)
        cout << "error loading file" << endl;

    //Variable line will be used to hold information obtained from csv file
    string line;

    //Skip the first line of the csv (header of csv not needed)
    if (infile.good())
    {
        getline(infile, line);
    }

    //Initialize vector that will hold country objects
    vector<Country> countryv;

    //While file is readable
    while (infile.good())
    {
        //Construct an object with first word in csv file before the comma (delimiter) being the country object's name
        getline(infile, line, ',');
        Country one(line);

        //Deal with special case Iran, manually adjust name to Iran and skip the rest
        if (one.getName() == "\"Iran")
        {
            one.setName("\"Iran\"");
            getline(infile, line, ',');
        }

        //Deal with special case Macedonia, manually adjust name to Macedonia and skip the rest
        if (one.getName() == "\"Macedonia")
        {
            one.setName("\"Macedonia\"");
            getline(infile, line, ',');
        }

        //Deal with special case Taiwan, manually adjust name to Taiwan and skip the rest
        if (one.getName() == "\"Taiwan")
        {
            one.setName("\"Taiwan\"");
            getline(infile, line, ',');
        }

        //Deal with special case Tanzia, manually adjust name to Tanzia and skip the rest
        if (one.getName() == "\"Tanzania")
        {
            one.setName("\"Tanzania\"");
            getline(infile, line, ',');
        }

        //Set country objects country code
        getline(infile, line, ',');
        one.setCode(line);

        //Skip the uninmportant date
        getline(infile, line, ',');
        
        //Set country objects new confirmed cases
        getline(infile, line, ',');
        one.setNewC(stoi(line));

        //Set country objects new death cases
        getline(infile, line, ',');
        one.setNewD(stoi(line));

        //Set country objects new recovery cases
        getline(infile, line, ',');
        one.setNewR(stoi(line));

        //Skip unimportant premium and slug
        getline(infile, line, ',');
        getline(infile, line, ',');

        //Set country objects total confirmed cases
        getline(infile, line, ',');
        one.setTotalC(stoi(line));

        //Set country objects total death cases
        getline(infile, line, ',');
        one.setTotalD(stoi(line));

        //Set country objects total recovery cases
        getline(infile, line, '\n');
        one.setTotalR(stoi(line));
        
        //Push the country object into the vector of country objects
        countryv.push_back(one);

        //When the last country has been reached break from the loop
        if (one.getName() == "\"Zimbabwe\"")
        {
            break;
        }
    }
    
    //Helper boolean to exit from loop
    bool valid = false;

    //While loop to prompt the user for input throwing an error if unacceptable and re-prompting
    while (valid != true)
    {
        //String variables
        string c1;
        string c2;

        //Prompt the user to choose a number from the menu selecting the case wished to be viewed
        cout << "\nPlease choose cases to view (SELECT A NUMBER)\n1: New deaths \n2: New recoveries \n3: New confirmed \n4: Total deaths \n5: Total recoveries \n6: Total confirmed \n";
        
        //Store user input in c1
        cin >> c1;
        
        //!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!

        //PLEASE NOTE : COMMENTS FROM HERE ON APPLY TO ALL CASES 1-6 UP UNTIL THE ELSE STATEMENT

        //!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!

        //If user input is 1 for new deaths
        if (c1 == "1")
        {
            //Helper boolean to exit from loop
            bool no = false;

            //While loop to prompt the user for input throwing an error if unacceptable and re-prompting
            while (no != true)
            {
                //Prompt the user to choose order of the sort from ascending or descending
                cout << "\nPlease choose the order of the sort:\nA: Ascending order \nB: Descending order \n";

                //Store user input in c2
                cin >> c2;

                //If user input is a for ascending
                if (c2 == "a" || c2 == "A")
                {
                    //Sort the vector using helper function associated with case
                    sort(countryv.begin(), countryv.end(), asortNewD);
                    cout << "\n" << endl;
                    
                    //For loop to iterate through top 10 in vector and print out character symbol representing number of cases
                    for (int i = 0; i < 11; i++){
						int result = countryv[i].getNewD()/1;
						result = round(result);
						cout<< countryv[i].getCode() << "|" << string(result, '$') << endl;
						}
						
						cout << string(80, '-') << endl;
						cout << "\nNew death cases in ascending order; Each $ represents approximately 1 case. \n " << endl;

                        //Exit while loop and finish
						no = true;
                }
                
                //If user input is b for descending
                else if (c2 == "B" || c2 == "b")
                {
                    //Sort the vector using helper function associated with case
                    sort(countryv.begin(), countryv.end(), dsortNewD);
                    cout << "\n" << endl;
                    
                    //For loop to iterate through top 10 in vector and print out character symbol representing number of cases
                    for (int i = 0; i < 11; i++){
						int result = countryv[i].getNewD()/50;
						result = round(result);
						cout<< countryv[i].getCode() << "|" << string(result, '$') << endl;
						}
						
						cout << string(80, '-') << endl;
						cout << "\nNew death cases in descending order; Each $ represents approximately 50 cases. \n " << endl;

                        //Exit while loop and finish
						no = true;
                }
                
                else
                {
                    //If user enters incorrect input for order, re-prompt
                    cout << "\nERROR! Please choose A or B! \n"
                         << endl;
                }
            }
            //Exit initial while loop, program successfully finished
            valid = true;
        }

        else if (c1 == "2")
        {
            bool no = false;
            while (no != true)
            {

                cout << "\nPlease choose the order of the sort:\nA: Ascending order \nB: Descending order \n";
                cin >> c2;

                if (c2 == "a" || c2 == "A")
                {
                    sort(countryv.begin(), countryv.end(), asortNewR);
                    cout << "\n" << endl;
                   
                    for (int i = 0; i < 11; i++){
						int result = countryv[i].getNewR()/1;
						result = round(result);
						cout<< countryv[i].getCode() << "|" << string(result, '$') << endl;
						}
						
						cout << string(80, '-') << endl;
						cout << "New recovered cases in ascending order; Each $ represents approximately 1 case. \n " << endl;
						no = true;
                }

                else if (c2 == "b" || c2 == "B")
                {
                    sort(countryv.begin(), countryv.end(), dsortNewR);
                    cout << "\n" << endl;
                    
                    for (int i = 0; i < 11; i++){
						int result = countryv[i].getNewR()/1000;
						result = round(result);
						cout<< countryv[i].getCode() << "|" << string(result, '$') << endl;
						}
						
						cout << string(80, '-') << endl;
						cout << "New recovered cases in descending order; Each $ represents approximately 1000 cases.\n" << endl;
						no = true;
                }
                else
                {
                    cout << "\nERROR! Please choose A or B! \n"
                         << endl;
                }
            }
            valid = true;
        }

        else if (c1 == "3")
        {
            bool no = false;
            while (no != true)
            {

                cout << "\nPlease choose the order of the sort:\nA: Ascending order \nB: Descending order \n";
                cin >> c2;

                if (c2 == "a" || c2 == "A")
                {
                    sort(countryv.begin(), countryv.end(), asortNewC);
                    cout << "\n" << endl;
                    
                    for (int i = 0; i < 11; i++){
						int result = countryv[i].getNewC()/1;
						result = round(result);
						cout<< countryv[i].getCode() << "|" << string(result, '$') << endl;
						}
						
						cout << string(80, '-') << endl;
						cout << "New confirmed cases in ascending order; Each $ represents approximately 1 case. \n " << endl;
						no = true;
                }

                else if (c2 == "b" || c2 == "B")
                {
                    sort(countryv.begin(), countryv.end(), dsortNewC);
                    cout << "\n" << endl;
                    
                    for (int i = 0; i < 11; i++){
						int result = countryv[i].getNewC()/1000;
						result = round(result);
						cout<< countryv[i].getCode() << "|" << string(result, '$') << endl;
						}
						
						cout << string(80, '-') << endl;
						cout << "New confirmed cases in descending order; Each $ represents approximately 1000 cases. \n " << endl;
						no = true;
                }

                else
                {
                    cout << "\nERROR! Please choose A or B! \n"
                         << endl;
                }
            }
            valid = true;
        }

        else if (c1 == "4")
        {
            bool no = false;
            while (no != true)
            {

                cout << "\nPlease choose the order of the sort:\nA: Ascending order \nB: Descending order \n";
                cin >> c2;

                if (c2 == "a" || c2 == "A")
                {
                    sort(countryv.begin(), countryv.end(), asortTotalD);
                    cout << "\n" << endl;
                    
                    for (int i = 0; i < 11; i++){
						int result = countryv[i].getTotalD()/1;
						result = round(result);
						cout<< countryv[i].getCode() << "|" << string(result, '$') << endl;
						}
						
						cout << string(80, '-') << endl;
						cout << "Total death cases in ascending order; Each $ represents approximately 1 case. \n " << endl;
						no = true;
                }

                else if (c2 == "b" || c2 == "B")
                {
                    sort(countryv.begin(), countryv.end(), dsortTotalD);
                    cout << "\n" << endl;
                    
                    for (int i = 0; i < 11; i++){
						int result = countryv[i].getTotalD()/2500;
						result = round(result);
						cout<< countryv[i].getCode() << "|" << string(result, '$') << endl;
						}
						
						cout << string(80, '-') << endl;
						cout << "Total death cases in descending order; Each $ represents approximately 2500 cases. \n " << endl;
						no = true;
                }

                else
                {
                    cout << "\nERROR! Please choose A or B! \n"
                         << endl;
                }
            }
            valid = true;
        }

        else if (c1 == "5")
        {
            bool no = false;
            while (no != true)
            {

                cout << "\nPlease choose the order of the sort:\nA: Ascending order \nB: Descending order \n";
                cin >> c2;

                if (c2 == "a" || c2 == "A")
                {
                    sort(countryv.begin(), countryv.end(), asortTotalR);
                    cout << "\n" << endl;
                    
                    for (int i = 0; i < 11; i++){
						int result = countryv[i].getTotalR()/1;
						result = round(result);
						cout<< countryv[i].getCode() << "|" << string(result, '$') << endl;
						}
						
						cout << string(80, '-') << endl;
						cout << "Total recovered cases in ascending order; Each $ represents approximately 1 case. \n " << endl;
						no = true;
                }

                else if (c2 == "b" || c2 == "B")
                {
                    sort(countryv.begin(), countryv.end(), dsortTotalR);
                    cout << "\n" << endl;
                    
                    for (int i = 0; i < 11; i++){
						int result = countryv[i].getTotalR()/45000;
						result = round(result);
						cout<< countryv[i].getCode() << "|" << string(result, '$') << endl;
						}
						
						cout << string(80, '-') << endl;
						cout << "Total recovered cases in descending order; Each $ represents approximately 45000 cases. \n " << endl;
						no = true;
                }

                else
                {
                    cout << "\nERROR! Please choose A or B! \n"
                         << endl;
                }
            }
            valid = true;
        }

        else if (c1 == "6")
        {
            bool no = false;
            while (no != true)
            {

                cout << "\nPlease choose the order of the sort:\nA: Ascending order \nB: Descending order \n";
                cin >> c2;

                if (c2 == "a" || c2 == "A")
                {
                    sort(countryv.begin(), countryv.end(), asortTotalC);
                    cout << "\n" << endl;
                   
                    for (int i = 0; i < 11; i++){
						int result = countryv[i].getTotalC()/1;
						result = round(result);
						cout<< countryv[i].getCode() << "|" << string(result, '$') << endl;
						}
						
						cout << string(80, '-') << endl;
						cout << "Total confirmed cases in ascending order; Each $ represents approximately 1 case. \n " << endl;
						no = true;
                }

                else if (c2 == "b" || c2 == "B")
                {
                    sort(countryv.begin(), countryv.end(), dsortTotalC);
                    cout << "\n" << endl;
                    
                    for (int i = 0; i < 11; i++){
						int result = countryv[i].getTotalC()/85000;
						result = round(result);
						cout<< countryv[i].getCode() << "|" << string(result, '$') << endl;
						}
						
						cout << string(80, '-') << endl;
						cout << "Total confirmed cases in descending order; Each $ represents approximately 85000 cases. \n " << endl;
						no = true;
                }

                else
                {
                    cout << "\nERROR! Please choose A or B! \n"
                         << endl;
                }
            }
            valid = true;
        }

        //User has entered invalid input for choosing a case so re-prompt 
        else
        {
            cout << "\nERROR! Please select a number from 1-6!"
                 << endl;
        }
    }

    //Finish
    return 0;
}
