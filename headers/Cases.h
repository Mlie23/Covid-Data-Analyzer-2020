///////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
// Name: Michael Lie
// Date: <5/16/2020>
// Course Code: CS-172-3
// License: CS172 students at whitworth may edit this file but not share this
// file electronically with other students.
// FINAL PROJECT CS2-173
// Copyright (C) Michael Lie 2020 - 2021
// Derived from work by Kent Jones and Scott Griffith
//
// Resources used:Scott Griffith Binary sort
// Coronacase.txt : (https://opendata.ecdc.europa.eu/covid19/casedistribution/csv/)
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


#ifndef CASES_H
#define CASES_H
#include <string>   //string headers
#include<iostream> //Input output stream
#include<fstream> //IO file
#include <vector>  //Vector header
using namespace std;//std::


//Base class for Inheritance implementation
class Cases
{
protected:
    //total cases each country
	int total_case;
    //name of the country
    string country;

public:
    //empty constructor
    Cases()
    {
    }

    //argument constructor
    //parameter : total cases and country name
    Cases(int ttl,string cntry)
    {
        total_case = ttl;
        country=cntry;
    }

    //gettor function for total
    int get_total()
    {
        return total_case;
    }

    //gettor function for country
    string get_country()
    {
        return country;
    }

    //addding the total cases
    //input add_num: another total case
    void add_totalcases(int add_num)
    {
        //total = total + add_num
        total_case += add_num;
    }


    //make operator overloads to compare the objects
    //bigger than, checking the total of each objects
    //comparing which one is bigger
    bool operator>(const Cases &otherCase)
    {
        //return true if this total is bigger
        if (this->total_case > otherCase.total_case)
        {
            return true;
        }
        return false;

    }

    //less than, checking the totalcase of each objects
    //compare which one is smaller
    bool operator<(const Cases &otherCase)
    {
        //return true if this total is smaller
        if (this->total_case < otherCase.total_case)
        {
            return true;
        }
        else
        {
            return false;
        }
    
    }

    //operator overload ==
    //comparing if the total of cases is the same
    bool operator==(const Cases &otherCase)
    {
        //return true if they are equals
        if (this->total_case == otherCase.total_case)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

};

#endif