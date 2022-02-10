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
#include "../headers/Binarysort.h"
#include "../headers/Cases.h"
#include "../headers/Continent.h"
#include "../headers/Date.h"
#include "../headers/Deaths.h"
#include "../headers/month.h"
#include "../headers/Deathpercountry.h"
#include "../headers/Checkvector.h"
#include "../headers/Inputfunction.h"


int main()
{
	//define a vector called casepercountry that is holding the Cases class
	vector<Cases> casepercountry;
	//define a vector called continent that is holding the Continental class
	vector<Continental> continents;
	//define a vector called mostcaseaday that is holding the Date class
	vector<Date> mostcaseaday;
	//define a vector called deathperday that is holding the Deaths class
	vector<Deaths> deathperday;
	//define a vector called casepermonth that is holding the Month class
	vector<Month> casepermonth;
	//define a vector called deathpercountry that is holding the Deathrate class
	vector<Deathpercountry> totaldeathpercountry;
	//total current cases all over the world
	//use unsigned to store larger numbers
	static unsigned int worldwidedeath = 0;
	//total current death all over the world
	static unsigned int worldwidecase = 0;
	//read the file and seperate it
	get_file(casepercountry, continents, mostcaseaday, deathperday, casepermonth, totaldeathpercountry, worldwidedeath, worldwidecase);
	//print the deathrate o each country
	printrates(casepercountry, totaldeathpercountry);
	//print the infection rate of each country
	//sort the casepercountry vector
	//sorting the country by total cases
	binarysort(casepercountry, casepercountry.size());
	//sort the continents vector
	//sorting the continents by total cases
	binarysort(continents, continents.size());
	//sort the mostcaseaday vector
	//sorting the date based on total cases per day
	binarysort(mostcaseaday, mostcaseaday.size());
	//sort the deathperday vector
	//sorting the date based on total death per day
	binarysort(deathperday, deathperday.size());
	//sort the casepermonth vector
	//sorting the month based on total cases in a month
	binarysort(casepermonth, casepermonth.size());
	//sort the totaldeathpercountry vector
	//sorting the country based on total death in the country
	binarysort (totaldeathpercountry,totaldeathpercountry.size());
	//print all the information to divided files
	printcase(casepercountry, continents, mostcaseaday, deathperday, casepermonth, totaldeathpercountry);
	//ask the user if they want to make changes
	ask_user(worldwidedeath, worldwidecase);
	//return 0
	return 0;
}
