#pragma once
#include <string> // To use strings
#include <iostream>

using namespace std; // Just in case =)

class Student // A class that stores the data about students
{
	string name; // Stores student's name
	int StuNum; // Stored the student number
	static int mark[10000]; // An array to check wither the StuNum is reapeted or not
public:
	Student(int sn = 0, string n = "") :name(n) // A constructor if we needed to give the values when we were creating an object
	{
		while (mark[StuNum] == 1) // If the StuNum was reapeted, they need to try again giving the StuNum
		{
			cin >> sn;
		}
		StuNum = sn;
		mark[StuNum] = 1;
	}
	void Set_N(string n) { name = n; } // A function to set the value of name
	void Set_SN(int sn) { StuNum = sn; } // A function to set the value of StuNum
	string Ret_N() { return name; } // A function that returns the value of name 
	int Ret_SN() { return StuNum; } // A function that returns the value of StuNum 
};

int Student::mark[10000] = {}; // Filling the array with zeros

