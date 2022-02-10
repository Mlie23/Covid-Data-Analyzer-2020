
#include "../headers/Cases.h"
#include "../headers/Deaths.h"
#include "../headers/Continent.h"
#include "../headers/Date.h"
#include "../headers/month.h"
#include "../headers/Deathpercountry.h"

//one function to print and seperate to different files output
//Parameter:vector countries : to check the cases per country
//          vector continents : to check number of cases per continent
//          vector mostcaseaday: to check the cases per day
//          vector casepermonth: to check the number of cases per month
//          vector  totaldeathpercountry: to check the total death per country
//          vector deathperday : to check the total death per day
//Purpose : Print all the statistic after they are already sorted
//          This will be seperated to 5 different files output

void printcase(vector<Cases> &countries,
               vector<Continental> &continents,
               vector<Date> &mostcaseaday,
               vector<Deaths> &deathperday,
               vector<Month> &casepermonth,
               vector<Deathpercountry> &totaldeathpercountry)
{

    //Create the ofstream object
    ofstream caseout;

    //Create an output file
    //outputting it to casepercountry.csv
    caseout.open("output_case_per_country.csv");

    //outputting the sorted cases per country 
    caseout << "Sorted Corona virus cases by Country, Total" << endl;
    //outputting from the biggest to the lowest
    for (int i = countries.size() - 1; i > 0; i--)
    {
        //get the country of the Cases at certain vector and get the total number of babies inside that element
        caseout << countries[i].get_country() << "," << countries[i].get_total() << endl;
    }
    //close the file, put it back to ios
    caseout.close();

    //create an output file
    //outputting the cases by continents into output_continents.csv file
    caseout.open("output_continents.csv");
    if (caseout.fail())
    {
        caseout << "Error, cant output file" << endl;
    }

    caseout << "Sorted Corona virus cases by continents, Total" << endl;
    //outputting from the biggest to the lowest
    for (int i = continents.size() - 1; i > 0; i--)
    {
        //get the continent of the Cases at certain vector and get the total number of cases inside that element
        caseout << continents[i].get_continents() << "," << continents[i].get_total() << endl;
    }
    caseout.close();

    //create an output file
    //output the most case a day
    caseout.open("output_case_a_day.csv");
    caseout << "Sorted Corona virus cases by date, Total" << endl;
    //outputting from the biggest to the lowest
    for (int i = mostcaseaday.size() - 1; i > 0; i--)
    {
        //get the number of the Cases at certain date and get the total number of cases on that date
        caseout << mostcaseaday[i].get_date() << "," << mostcaseaday[i].get_total() << endl;
    }

    //close the file, put it back to ios
    caseout.close();

    //create an output file
    //output the most case a day
    caseout.open("output_death_per_day.csv");
    caseout << "Sorted Corona virus death cases by date, Total" << endl;
    //outputting from the biggest to the lowest
    for (int i = deathperday.size() - 1; i > 0; i--)
    {
        //get the number of the Cases at certain date and get the total number of cases on that date
        caseout << deathperday[i].get_date() << "," << deathperday[i].get_death() << endl;
    }
    //close the file, put it back to ios
    caseout.close();

    //create an output file
    //open output_case_a_month to print the total case per month
    caseout.open("output_case_a_month.csv");
    //outputting from the biggest to the lowest
    caseout << "Sorted Corona virus cases by Month, total" << endl;
    //make a string to convert the arabical month to words month
    string month_string[12] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
    //from most cases to lowest
    for (int i = casepermonth.size() - 1; i > 0; i--)
    {
        //get the month of the Cases at certain vector and get the total number of cases inside that month
        caseout << month_string[casepermonth[i].get_month() - 1] << "," << casepermonth[i].get_total() << endl;
    }
    //close the file, put it back to ios
    caseout.close();

    //create an output file
    //open the output_death_per_country to print the death per country
    caseout.open("output_death_per_country.csv");
    caseout << "Sorted Corona Virus Death cases per country, Total" << endl;
    //output the total death from the biggest to lowest
    for (int i = totaldeathpercountry.size() - 1; i > 0; i--)
    {
        //get the country of the deathcases at certain vector and get the total number of death inside
        caseout << totaldeathpercountry[i].get_country() << "," << totaldeathpercountry[i].get_death() << endl;
    }
    //clsoe teh file store back to ios
    caseout.close();
}

//Reasoon I seperate this from output file is to show the country rates without sorting them
//printing the death rate from each country
//printing the infection rate from each country
void printrates(vector<Cases> &countries, vector<Deathpercountry> &totaldeathpercountry)
{
    //Create the ofstream for output file
    ofstream caseout;
    //open the file
    //Purpose: printing the deathrate of each country into this file
    caseout.open("output_deathrate.csv");
    caseout << "Deathrate per Country, Total" << endl;
    //sorted by alphabetical order
    for (int i = 0; i < countries.size(); i++)
    {
        //preventing arithmetic error
        if (totaldeathpercountry[i].get_death() > 0)
        {
            caseout << countries[i].get_country() << "," << ((static_cast<float>(totaldeathpercountry[i].get_death() * 100)) / static_cast<float>(countries[i].get_total())) << "%" << endl;
        }
    }
    //close the file, store back to ios
    caseout.close();

    //open the file
    //Purpose: Outputting the infectionrate between each country
    caseout.open("output_infectionrate.csv");
    caseout << "Infection rate per Country, Total" << endl;
    //Outputting each country and their infection rate total
    for (int i = 0; i < countries.size(); i++)
    {
        //preventing arithmetic error
        if (totaldeathpercountry[i].get_death() > 0)
        {
            //outputting the country name and the infection rate of the country
            caseout << countries[i].get_country() << "," << (static_cast<float>(countries[i].get_total() * 100) / (static_cast<float>(totaldeathpercountry[i].get_population()))) << "%" << endl;
        }
    }
    //close, store it back to ios
    caseout.close();
}
