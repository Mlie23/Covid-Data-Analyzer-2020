#ifndef CHECKVECTOR_H
#define CHECKVECTOR_H

//Purpose: Checking the cases per country
//		   Increment the total case of that country if the country has already existed inside the vector
//		   Create new object and store it back to the vector if it is not existed
void checkmostcases(vector<Cases> &countryname, string country, int total_case)
{
	//check whether if the country is already in the vector or not
	bool existed = false;
	//checking each elements of the vector with the country string
	for (int i = 0; i < countryname.size(); i++)
	{
		//if the country is already existed inside the countryname vector
		if (country == countryname[i].get_country())
		{
			//increment the total cases for that country
			countryname[i].add_totalcases(total_case);
			//country has existed
			existed = true;
			break;
		}
	}
	//if the name of the country is not existed inside the vector
	if (!existed)
	{
		//create new object called new country
		Cases new_country(total_case, country);
		//push back to the vector
		countryname.push_back(new_country);
	}
}

//check if the Cases is already in the list or not
//Input continentname : the vector of a contientname pointing to continental class
//      country : the country name
//      total : the total cases according to continent
//create a new object if it is not existed
//increment the total if it is already existed
void checkcontienentcases(vector<Continental> &continentname, string country, int total_case, string continent)
{
	//check whether if the continent is already in the vector or not
	bool existed = false;
	//Make for loop to check each elements in the vector
	for (int i = 0; i < continentname.size(); i++)
	{
		//if the country is already existed inside the vector
		if (continent == continentname[i].get_continents())
		{
			//increment the total cases of the continent
			continentname[i].add_totalcases(total_case);
			//continent has existed
			existed = true;
			break;
		}
	}
	if (!existed)
	{
		//create new object with new continent that will store new continent and its cases
		Continental new_continent(total_case, country, continent);
		//push back to continentname vector
		continentname.push_back(new_continent);
	}
}

//check if the Cases is already in the list or not
//Input countryname : the vector called countryname that is pointing to deathpercountry class
//      country : the name of the country
//      total : the total cases from each country
//		death : death cases
//		population: population of each country
//create a new object if it is not existed
//increment the total if it is already existed
void checkdeathpercountry(vector<Deathpercountry> &countryname, string country, int total_case, int death, int population, string date)
{
	//check whether if the country is already in the vector or not
	bool existed = false;
	//check each element of the vector
	for (int i = 0; i < countryname.size(); i++)
	{
		//if the country name is already existed inside the vector
		if (country == countryname[i].get_country())
		{
			//increment the total death
			countryname[i].add_totaldeath(death);
			//country has existed
			existed = true;
			break;
		}
	}
	if (!existed)
	{
		//create new objects with new country and its total_case
		Deathpercountry new_country(total_case, country, date, death, population);
		//push back to the countryname vector
		countryname.push_back(new_country);
	}
}

//check if the Cases is already in the list or not
//Parameter
// 		exactdate : the vector called exactdate that is pointing to Date class
//      country : the country name
//      total : the total cases
//		thisdate : the date of the cases
//Purpose:
//create a new object if it is not existed
//increment the total if it is already existed
void checkdailycases(vector<Date> &exactdate, string country, int total_case, string thisdate)
{
	//check whether if the country is already in the vector or not
	bool existed = false;
	//if it is already existed, add the
	for (int i = 0; i < exactdate.size(); i++)
	{
		//if the country is already existed inside the vector
		if (thisdate == exactdate[i].get_date())
		{
			//increment the total count
			exactdate[i].add_totalcases(total_case);
			//country has existed
			existed = true;
			break;
		}
	}
	if (!existed)
	{
		//create new Cases with new day
		Date new_day(total_case, country, thisdate);
		//push back a new date
		exactdate.push_back(new_day);
	}
}

//check if the Cases is already in the list or not
//Input thismonth : the vector of called thismonth that is pointing to Month class
//      country : the Cases country
//      total : the total country for the Cases
//		exactmonth: the month where the case occurs
//Purpose:
//create a new object if it is not existed
//increment the total if it is already existed
void checkmonthlycases(vector<Month> &thismonth, string country, int total_case, int exactmonth)
{
	//check whether if the month is already in the vector or not
	bool existed = false;
	//make a for loop to check whether the month is already inside the vector or not
	for (int i = 0; i < thismonth.size(); i++)
	{
		//if the country is already existed inside the vector
		if (exactmonth == thismonth[i].get_month())
		{
			//increment the total case for thismonth
			thismonth[i].add_totalcases(total_case);
			//country has existed
			existed = true;
			break;
		}
	}
	//if the month is not found inside the vector
	if (!existed)
	{
		//create new new month objects
		Month new_month(total_case, country, exactmonth);
		//push back to the thismonth vector
		thismonth.push_back(new_month);
	}
}

//check if the dates is already in the list or not
//Input exactdate : vector called exacdate that is pointing to Death class
//      country : the country name
//      total_case : the total cases
//		death: total death
//		date:date of each cases
//Purpose:
//create a new object if it is not existed
//increment the total death for that date if it is already existed
void checkdailydeathcases(vector<Deaths> &exactdate, string country, int total_case, int death, string date)
{
	//check whether if the date is already in the vector or not
	bool existed = false;
	//make for loop to check the dates of each vector 
	for (int i = 0; i < exactdate.size(); i++)
	{
		//if the date is already existed inside the exactdate vector
		if (date == exactdate[i].get_date())
		{
			//increment the death count
			exactdate[i].add_totaldeath(death);
			//country has existed
			existed = true;
			break;
		}
	}
	//if it is not found inside the vector
	if (!existed)
	{
		//create new Deaths object with new day
		Deaths new_day(total_case, country, date, death);
		//push back to the vector
		exactdate.push_back(new_day);
	}
}

#endif