#include <iostream>
#include <cstdlib>
#include <cmath>
#include <cstring>
using namespace std;

bool isLeapYear(int year);
//Precondition: year is >=999 and <=3000.
//Returns true if year is a leap year and false if not.

int getCenturyValue(int year);
//Precondition: year is >=999 and <=3000.
//Returns the century value.

int getYearValue(int year);
//Precondition: year is >=999 and <=3000.
//Returns the year value.

int getMonthValue(char month[], int year);
//Precondition: year is >=999 and <=3000 and month is >=1 and <=12
//Returns the month value.

void getDayOfWeek(char date[]); 
//Precondition: month is >= 1 and <=12, day >=1 and <=31, and year is >=999 and <=3000.
//Returns the day of week.

void input();//Prompts user for input.

void output(char date[]);
//Precondition: month is >= 1 and <=12, day >=1 and <=31, and year is >=999 and <=3000.
//Outputs what day of the week it is.

int main ()
{
	input();
	return 0;
}

bool isLeapYear(int year)
{
	return ((year%400 == 0) || ((year%4 == 0) && (year%100 != 0)));
}

int getCenturyValue(int year)
{
	return ((3 -((year/100)%4)) * 2);
}

int getYearValue(int year)
{
	return ((year%100)+((year%100)/4));
}

int getMonthValue(char month[], int year)
{
	if (!strcmp(month, "January") && isLeapYear(year))
		return 6;
	else if (!strcmp(month, "January") && !isLeapYear(year))
		return 0;
	else if (!strcmp(month, "February") && isLeapYear(year))
		return 2;
	else if (!strcmp(month, "February") && !isLeapYear(year))
		return 3;
	else if (!strcmp(month, "March"))
		return 3;
	else if (!strcmp(month, "April"))
		return 6;
	else if (!strcmp(month, "May"))
		return 1;
	else if (!strcmp(month, "June"))
		return 4;
	else if (!strcmp(month, "July"))
		return 6;
	else if (!strcmp(month, "August"))
		return 2;
	else if (!strcmp(month, "September"))
		return 5;
	else if (!strcmp(month, "October"))
		return 0;
	else if (!strcmp(month, "November"))
		return 3;
	else if (!strcmp(month, "December"))
		return 5;
	else 
		return -1;
}

void getDayOfWeek(char date[])
{
    char *month = strtok(date, ", ");
    int day = atoi(strtok(NULL, ", "));
    int year = atoi(strtok(NULL, ", "));

	int dayOfWeek = (day + getMonthValue(month, year) + getYearValue(year) + getCenturyValue(year))%7;

	switch(dayOfWeek)
	{
	  case 0: 
		  cout<<"Sunday\n";
		  break;
	  case 1:
		  cout<<"Monday\n";
		  break;
	  case 2:
		  cout<<"Tuesday\n";
		  break;
	  case 3:
		  cout<<"Wednesday\n";
		  break;
	  case 4:
		  cout<<"Thursday\n";
		  break;
	  case 5:
		  cout<<"Friday\n";
		  break;
	  case 6:
		  cout<<"Saturday\n";
		  break;
	  default:
      {
		  cout<<"Fatal Error: Aborting program.\n";
		  exit(1);
		  break;
	  }
    }
}

void input()
{
    
	char date[19];
    
	cout<<"Enter date: ";
	cin.getline(date, 19);
    
	output(date);
}

void output(char date[])
{
	cout<<"The day of week is ";
	getDayOfWeek(date);
}
