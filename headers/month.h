#ifndef MONTH_H
#define MONTH_H
#include "../headers/Cases.h"

//Class called Month
//Inherit from Cases class
//purpiose : Keeping trach of the cases per month
class Month : public Cases
{
private:
    //actual month: Month of the cases
    int actual_month;

public:
    //Empty constructor
    Month()
    {
    }

    //Argument constructor
    Month(int ttl, string cntry, int mnth) : Cases(ttl, cntry), actual_month(mnth)
    {
    }

    //gettor function fro month
    int get_month()
    {
        return actual_month;
    }

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    //make operator overloads to compare the objects
    //bigger than, checking the totalcase of the objects
    //comparing which one is bigger
    bool operator>(const Month &otherMonth)
    {
        if (this->total_case > otherMonth.total_case)
        {
            return true;
        }
        return false;
    }

    //less than, checking the totalcase of the objects
    //compare which one is smaller
    bool operator<(const Month &otherMonth)
    {
        if (this->total_case < otherMonth.total_case)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    //operator overload ==
    //comparing if the totalcase of the objects is the same
    bool operator==(const Month &otherMonth)
    {
        if (this->total_case == otherMonth.total_case)
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