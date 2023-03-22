/*
Author : Samuel Wesley Rasquinha
Age : 10
Title : Calendar
Description : Generates a calendar for a year you want
Version : 1.0
*/

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string>
#include <vector>
#include <conio.h> // getch()

using namespace std ;

int first_day ;
int day ;
int date = 1 ;
int year = 0 ;
int month = 1 ;

int GetFirstDayOfYear(int year) ;
int GetAmountDays(int year, int month) ;
string Name_Get(int month) ;
void scrclr() ;

int main()
{
	int i ;
	int j ;
	string month_name_ ;

	cout << "Enter the year you want to generate a calendar for : " ;
	cin >> year ;
	scrclr() ;
	cout << endl << "January" << endl << endl ;
	cout << "  S  M  T  W  T  F  S" << endl ;
	cout << "  ________________________" << endl ;


	day = GetFirstDayOfYear(year) ;

	for (i = 0 ; i <= day ; i++)
	{
		cout << "  " ;
	}

	while (date != 31 + 1)
	{
		if (day > 6)
		{
			cout << endl ;
			day = 0 ;
		}

		else
		{
			cout << "  " << date ;
			day++ ;
			date++ ;
		}
	}

	if (month < 12)
	{
		month++ ;
	}

	for (j = 0 ; j < 11 ; j++)
	{
		month_name_ = Name_Get(month) ;
		cout << endl << endl << month_name_ << endl << endl ;
		cout << "  S  M  T  W  T  F  S" << endl ;
		cout << "  ________________________" << endl ;
		date = 1 ;

		for (i = 0 ; i <= day ; i++)
		{
			cout << "  " ;
		}

		while (date != GetAmountDays(year,month) + 1)
		{
			if (day > 6)
			{
				cout << endl ;
				day = 0 ;
			}

			else
			{
				cout << "  " << date ;
				day++ ;
				date++ ;
			}
		}

		if (month < 12)
		{
			month++ ;
		}
	}

    getch() ;
	cout << endl << endl ;


}

int GetFirstDayOfYear(int year)
{
	int x1 ;
	int x2 ;
	int x3 ;
	int return_value ;

	x1 = (year - 1) / 4 ;
	x2 = (year - 1) / 100 ;
	x3 = (year - 1) / 400 ;
	return_value = (year + x1 - x2 + x3) % 7 ;

	return return_value ;
}

int GetAmountDays(int year, int month)
{
	int return_val ;

	if (year % 4 && month == 2)
	{
		return 29 ;
	}

	switch (month)
	{
		case 1 :
		{
			return 31 ;
		}

		case 2 :
		{
			return 28 ;
		}

		case 3 :
		{
			return 31 ;
		}

		case 4 :
		{
			return 30 ;
		}

		case 5 :
		{
			return 31 ;
		}

		case 6 :
		{
			return 30 ;
		}

		case 7 :
		{
			return 31 ;
		}

		case 8 :
		{
			return 31 ;
		}

		case 9 :
		{
			return 30 ;
		}

		case 10 :
		{
			return 31 ;
		}

		case 11 :
		{
			return 30 ;
		}

		case 12 :
		{
			return 31 ;
		}

		default :
		{
			return 31 ;
		}
	}
}

string Name_Get(int month_)
{
	string month_name ;

	switch (month_)
	{
		case 1 :
		{
			month_name = "January" ;

			break ;
		}

		case 2 :
		{
			month_name = "Feburary" ;

			break ;
		}

		case 3 :
		{
			month_name = "March" ;

			break ;
		}

		case 4 :
		{
			month_name = "April" ;

			break ;
		}

		case 5 :
		{
			month_name = "May" ;

			break ;
		}

		case 6 :
		{
			month_name = "June" ;

			break ;
		}

		case 7 :
		{
			month_name = "July" ;

			break ;
		}

		case 8 :
		{
			month_name = "August" ;

			break ;
		}

		case 9 :
		{
			month_name = "September" ;

			break ;
		}

		case 10 :
		{
			month_name = "October" ;

			break ;
		}

		case 11 :
		{
			month_name = "November" ;

			break ;
		}

		case 12 :
		{
			month_name = "December" ;

			break ;
		}

		default :
		{
			month_name = "December" ;

			break ;
		}
	}

	return month_name ;
}

void scrclr()
{
	system("@cls") ;
}
