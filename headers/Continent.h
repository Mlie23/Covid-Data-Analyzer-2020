#ifndef CONTINENT_H
#define CONTINENT_H
#include "../headers/Cases.h"
using namespace std;


//Inheritance class
class Continental : public Cases
{
    private:
    //continents of which the case came from
    string continents;

    public:
    //eempty constructor
    Continental()
    {

    }
    //Argument constructor
    //taking total and country from the base case
    //continents from this class
    Continental (int ttl, string cntry, string cntnts) : Cases(ttl,cntry),continents(cntnts)
    {
    }

    //gettor function for continents
    string get_continents()
    {
        return continents;
    }

    //make operator overloads to compare the objects
    //bigger than, checking the total cases between continent
    //comparing which one is bigger
    bool operator>(const Continental &otherContinent)
    {
        //if this object total case is bigger than othercontinent total case
        if (this-> total_case> otherContinent.total_case)
        {
            return true;
        }
        //it is less than
        else
        {
            return false;
        }
        

    }

    //less than, checking the total of each cases from different continent
    //compare which one is smaller
    bool operator<(const Continental &otherContinent)
    {
        //if this object total case is less than othercontinent total case
        if (this->total_case < otherContinent.total_case)
        {
            return true;
        }
        //it is bigger than other continent
        else
        {
            return false;
        }
    
    }

    //operator overload ==
    //comparing if the total of the cases is the same
    bool operator==(const Continental &otherContinent)
    {
        //if this object total case  is equal to othercontinent total case
        if (this->total_case == otherContinent.total_case)
        {
            return true;
        }
        //it is not equal
        else
        {
            return false;
        }
    }



};

#endif