#include "../headers/Cases.h"
#ifndef DEATHS_H
#define DEATHS_H

//Purpose: Keeping track the death per each date
//Inherit from Cases class
class Deaths : public Cases
{
    protected:
    //number of death on certain date
    int death;
    //the exact date
    string date;

    public:
    //empty constructor
    Deaths()
    {

    }

    //Argument constructor
    Deaths(int ttl,string cntry, string dt,int dth) : Cases (ttl,cntry), date(dt),death(dth)
    {

    }

    //gettor function for death
    int get_death()
    {
        return death;
    }

    //gettor function for date
    string get_date()
    {
        return date;
    }

        //incrementing the total death if the same date has been found
        void add_totaldeath(int add_num)
    {
        //total = total + add_num
        death += add_num;
    }

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    //make operator overloads to compare the objects
    //bigger than, checking the total death of the objects
    //comparing which one is bigger
    bool operator>(const Deaths &otherDate)
    {
        if (this-> death> otherDate.death)
        {
            return true;
        }
        return false;

    }

    //less than, checking the total of the objects
    //compare which one is smaller
    bool operator<(const Deaths &otherDate)
    {
        if (this->death < otherDate.death)
        {
            return true;
        }
        else
        {
            return false;
        }
    
    }

    //operator overload ==
    //comparing if the total of death is the same
    bool operator==(const Deaths &otherDate)
    {
        if (this->death == otherDate.death)
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
