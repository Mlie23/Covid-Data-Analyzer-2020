#ifndef DEATHPERCOUNTRY_H
#define DEATHPERCOUNTRY_H
#include "../headers/Cases.h"
#include "../headers/Deaths.h"

//Inheritance inside inheritance
//Deathpercountry inherit from Deaths class
//Deaths class inherit from Cases class
class Deathpercountry : public Deaths
{
    private:
    //population of each country
    int population;
    public:

    //empty constructor
    Deathpercountry()
    {

    }
    //Argument constructor
    //Inherit from Death class:
    //ttl = total cases
    //cntry = country name
    //dt = Deathpercountry of each classes
    //from Deathpercountry class
    //population : population of each country
    Deathpercountry(int ttl,string cntry, string dt, int dth,int ppl) : Deaths (ttl,cntry,dt,dth),population(ppl)
    {

    }

    //gettor function for country
      string get_country()
    {
        return country;
    }
    //gettor function for population
    int get_population()
    {
        return population;
    }

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    //Operator overoad to compare objects
    //bigger than, checking the total of each Death per country
    //comparing which one is bigger
    bool operator>(const Deathpercountry &otherDeathpercountry)
    {
        //if this death is bigger 
        if (this-> death> otherDeathpercountry.death)
        {
            return true;
        }
        //this death is smaller
        return false;

    }

    //less than, checking the total of each total case on different Deathpercountry
    //compare which one is smaller
    bool operator<(const Deathpercountry &otherDeathpercountry)
    {
        if (this->death < otherDeathpercountry.death)
        {
            //thisdeath is smaller
            return true;
        }
        else
        {
            //this death is bigger
            return false;
        }
    
    }

    //operator overload ==
    //comparing if the total of the cases between different Deathpercountrys is the same
    bool operator==(const Deathpercountry &otherDeathpercountry)
    {
        if (this->death == otherDeathpercountry.death)
        {
            //they are equals
            return true;
        }
        else
        {
            //not equal
            return false;
        }
    }



};
#endif