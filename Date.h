#pragma once
#include <string> // To use strings

using namespace std; // Just in case

class Date // A class to store the day of the week and date
{
	int year, month, day; // Variables for date
	string DayOfWeek; // Variable to store that what day of week is needed
public:
	Date(int y = 0, int m = 0, int d = 0, string dow = "") :year(y), month(m), day(d), DayOfWeek(dow) {} // Constructor
	void Set_Y(int y) { year = y; } // Set function for year
	void Set_M(int m) { month = m; } // Set function for month
	void Set_D(int d) { day = d; } // Set function for day
	void Set_Dow(string dow) { DayOfWeek = dow; } // Set function for DayOfWeek
	int Ret_Y() { return year; } // Function to return year value 
	int Ret_M() { return month; } // Function to return month value
	int Ret_D() { return day; } // Function to return day value
	string Ret_Dow() { return DayOfWeek; } // Function to return DayOfWeek value
};

