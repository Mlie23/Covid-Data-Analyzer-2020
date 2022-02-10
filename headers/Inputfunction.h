#include "../headers/Cases.h"
#include "../headers/Deaths.h"
#include "../headers/Continent.h"
#include "../headers/Date.h"
#include "../headers/month.h"
#include "../headers/Deathpercountry.h"
#include "../headers/Checkvector.h"
#include "../headers/Outputfile.h"

//Purpose : updating the worldwide cases & worldwide death cases
//Parameter : number of days
//filename : Name for output file
void update(int &days, unsigned int &wwc, string filename)
{
	//updated days must beyond 0
	if (days > 0)
	{
		//last cases reported from the download file
		int futuremonth = 5;
		//last cases reported from day file
		int futureday = 14;
		//last cases reported from year file
		int futureyear = 2020;
		//make an output file
		ofstream additional;
		//open the file name
		additional.open(filename);
		// make a dynamic memory with the size of days
		int *pday = new int[days];
		//display the current case
		cout << "Current case: " << wwc << endl;
		//make a for loop to store the values
		for (int i = 0; i < days; i++)
		{
			//for month and day and year addition
			//if day exceeded 30, moth will be incremented
			if (futureday >= 30)
			{
				++futuremonth;
				futureday = 1;
				//if month exceeded 12, year will be incremented
				//reset month and day
				if (futuremonth >= 13)
				{
					futuremonth = 1;
					futureyear++;
					futureday = 1;
				}
			}
			//displaying the date to be added
			cout << "Enter the number of cases for date " << futuremonth << "/" << futureday++ << "/" << futureyear << endl;
			//input the cases of that date to the pointers
			cin >> *(pday + i);
			//output the date and total cases on that date to the file
			additional << futuremonth << "/" << futureday << "/" << futureyear << " , " << *(pday + i) << endl;
			//add the world wide count to current cases
			wwc += *(pday + i);
			//output the current cases after it has been updated
			cout << "Updated, current cases: " << wwc << endl;
		}
		additional << "Cases updated, Total cases worldwide: " << wwc << endl;

		//show the total case now after updated
		cout << "Total cases across the world for " << days << "days: " << wwc << endl<<endl;
		//cleanup memory space
		delete[] pday;
		//prevent for errors
		pday = NULL;
		//close the file
		additional.close();
	}
}

//Function purpose: Asking the user if they want to update the case according to current date
//taking the worldwide death and worldwide count to update it
void ask_user(unsigned int &wwd, unsigned int &wwc)
{
	//show the current date
	cout << "Current date: 5/13/2020" << endl;
	//show the current case
	cout << "Current case worldwide: " << wwc << endl;
	//show the current death
	cout << "Current death worldwide: " << wwd << endl;
	//the number of days we want to add to the report
	int days;
	//the answer of the user (Yes/ yes)
	string answer;
	cout << "Want to update cases? (type yes/Yes to update, others to close)" << endl;
	cin >> answer;
	//If the user answer yes, proceed to ask the date
	if (answer == "Yes" || answer == "yes")
	{
		cout << " Enter the number of days:" << endl;
		cin >> days;
		cout << "Enter the total cases for this date:" << endl;
		//call the update function to update the world wide cases
		update(days, wwc, "world cases update.csv");
		//call the update function to update the world wide death cases
		cout << "Enter total death cases for this date:" << endl;
		update(days, wwd, "World death update.csv");
	}
	//if user does not want to update
	else
	{
		cout << "Check the csv and png files!" << endl;
	}
}

//gettor function to get the information from input text
//Purpose : Seperate each information to 6 different vectors
//Keep track of the total cases and total deaths
//Parameter : 6 different vector with different class
//			  world wide death 
//			  world wide case
void get_file(vector<Cases> &countries,
			  vector<Continental> &continents,
			  vector<Date> &mostcaseaday,
			  vector<Deaths> &deathperday,
			  vector<Month> &casepermonth,
			  vector<Deathpercountry> &totaldeathpercountry,
			  unsigned int &worldwidedeath,
			  unsigned int &worldwidecase)
{
	//countryname label: taking the countryname after the country each line
	string country;
	//date : Taking the date which the case occurs
	string date;
	//taking the month from text
	int month;
	//taking the year from text
	int year;
	//taking number of cases from text
	int cases;
	//taking the total death of the day from text
	int deaths_cases;
	//taking the population data from text
	int popData2018;
	//continent of each cases (Asia, Africa, etc.)
	string continent_name;

	//create a new object to fill the vector (checker) for 6 vectors that is pointing to 6 different objects
	////////////////////////////////////////////////////////////////////////////////////////////////////////////
	Cases fillvector(-1, "Undefined");
	Continental fillingvector(-1, "NULL", "NULL");
	Date fillday(-1, "NULL", "NULL");
	Deaths filldeath(0, "NULL", "NULL", -1);
	Month fillmonth(-1, "NULL", -1);
	Deathpercountry fillrate(-1, "NULL", "NULL", -1, -1);
	////////////////////////////////////////////////////////////////////////////////////////////////////////////

	//push the created objects back to each vector
	////////////////////////////////////////////////////////////////////////////////////////////////////////////
	countries.push_back(fillvector);
	continents.push_back(fillingvector);
	mostcaseaday.push_back(fillday);
	deathperday.push_back(filldeath);
	casepermonth.push_back(fillmonth);
	totaldeathpercountry.push_back(fillrate);
	////////////////////////////////////////////////////////////////////////////////////////////////////////////

	//make a string called file_country
	//it will match the text files
	string file_country = "coronavirus.txt";
	//input the file to the stream
	fstream fin(file_country, ios::in | ios::out);
	//if it is fail to open / not match, show error to the code
	if (fin.fail())
	{
		cout << "File error, not found" << file_country << endl;
	}
	//make a string line that takes each line from the text
	string line;

///////////////////////////////////////////////////////////////////////////////////////////////////////////
	//taking the information line by line from the text
	//seperate it into different variables
	while (getline(fin, line))
	{
		//take the date from the line
		date = line.substr(0, line.find(","));
		line.erase(0, line.find(",") + 1);
		//erase unneeeded information
		line.erase(0, line.find(",") + 1);
		//take the month and store it into integer
		month = stoi(line.substr(0, line.find(",")));
		line.erase(0, line.find(",") + 1);
		//take the year and store it to an integer
		year = stoi(line.substr(0, line.find(",")));
		line.erase(0, line.find(",") + 1);
		//take the cases on that date and store it into integer
		cases = stoi(line.substr(0, line.find(",")));
		line.erase(0, line.find(",") + 1);
		//update worldwidecase to current cases
		worldwidecase += cases;
		//take the death from the line and store it into integer
		deaths_cases = stoi(line.substr(0, line.find(",")));
		//update worldwidedeath according to current death
		worldwidedeath += deaths_cases;
		line.erase(0, line.find(",") + 1);
		//take the country name from the line
		country = line.substr(0, line.find(","));
		//erase unneeded information
		line.erase(0, line.find(",") + 1);
		line.erase(0, line.find(",") + 1);
		line.erase(0, line.find(",") + 1);
		//take the population
		popData2018 = stoi(line.substr(0, line.find(",")));
		line.erase(0, line.find(",") + 1);
		//take the continent of each country
		continent_name = line.substr(0, line.find(","));
		line.erase(0, line.find(",") + 1);

		///////////////////////////////////////////////////////////////////////////////////////////////////////
		//check the cases from each country
		checkmostcases(countries, country, cases);
		//check the most cases from each continent
		checkcontienentcases(continents, country, cases, continent_name);
		//check the daily cases
		checkdailycases(mostcaseaday, country, cases, date);
		//check death cases from each country
		checkdailydeathcases(deathperday, country, cases, deaths_cases, date);
		//check monthly cases from each month
		checkmonthlycases(casepermonth, country, cases, month);
		//check death cases from each country
		checkdeathpercountry(totaldeathpercountry, country, cases, deaths_cases, popData2018, date);
		//////////////////////////////////////////////////////////////////////////////////////////////////////
	}
	//close the file store back to ios
	fin.close();
}
