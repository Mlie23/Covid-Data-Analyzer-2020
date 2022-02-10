#include "../headers/Cases.h"
#ifndef DATE_H
#define DATE_H

//Inheritance class from Cases class
class Date : public Cases
{
    private :
    //date : getting the date on the cases information
    string exactdate;

    public:
    //empty constructor
    Date()
    {

    }

    //Argument constructor
    Date(int ttl, string cntry, string dt) : Cases (ttl,cntry), exactdate(dt)
    {
    }

    //gettor function for date
    string get_date()
    {
        return exactdate;
    }

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    //make operator overloads to compare the objects
    //bigger than, checking the total of each objects
    //comparing which one is bigger
    bool operator>(const Date &otherDate)
    {
        if (this-> total_case> otherDate.total_case)
        {
            return true;
        }
        return false;

    }

    //less than, checking the total of each total case on different date
    //compare which one is smaller
    bool operator<(const Date &otherDate)
    {
        if (this->total_case < otherDate.total_case)
        {
            return true;
        }
        else
        {
            return false;
        }
    
    }

    //operator overload ==
    //comparing if the total of the cases between different dates is the same
    bool operator==(const Date &otherDate)
    {
        if (this->total_case == otherDate.total_case)
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