#pragma once
/*
	In this project we assume that we have ten classes, numbered and named from 1 to 20.
	classes 1 to 10 doesn't have video projector and 11 to 20 does have.
	Also each class has the capacity of 40 students, and each student will have a 4 digit student number.
	We won't make a constructor for this class so if we needed to get values, we will get using set and get functions.
*/

#include <string> // To use strings
#include <fstream> // To save the output in a file
#include "Time.h" // To use the class for storing time data
#include "Date.h" // To use the class for storing date data
#include "Student.h" // To use the class to store the students

using namespace std; // Just in case

class Class // A class for ClassRooms ( lessons )
{
	friend bool Interference(Class c1, Class c2);
	int ID, Location = 0, Number_Of_Sessions, Number_Of_Studnets = 0; // ID will be the class id and location will be set later for the class
	string Proffessor, ClassName; // Variable to store the proffesor's name and the class name
	bool VP = false, FC = false; // The first boolean if for checking the video projector need and the second one is for forume classes
	Student s[40]; // Stores the students of a class
	Date date; // Stores date, spacificlly using this for DayOfWeek
	Time DurationTime, StartingTime; // Stores the duration and starting time of a class
	static int mark[10000]; // An array to check wither the ID is reapeted or not
public:
	Class(int id = 0, string p = "", string cn = "", bool vp = false, bool fc = false, Date d = Date(0, 0, 0, ""), Time dt = Time(0, 0), Time st = Time(0, 0))
	{ // Constractor
		ID = id;
		mark[ID] = 1;
		Proffessor = p;
		ClassName = cn;
		VP = vp;
		FC = fc;
		date = d;
		DurationTime = dt;
		StartingTime = st;
	}
	void Set_ID(int id) { ID = id; } // The start of the Set functions for each variable
	void Set_L(int l) { Location = l; }
	void Set_P(string p) { Proffessor = p; }
	void Set_CN(string cn) { ClassName = cn; }
	void Set_VP(bool vp) { VP = vp; }
	void Set_FC(bool fc) { FC = fc; }
	void Set_STU(int id, string n, int i) { s[i].Set_N(n); s[i].Set_SN(id); Number_Of_Studnets++; }
	void Set_D(Date d) { date = d; }
	void Set_DT(Time dt) { DurationTime = dt; }
	void Set_NOS(int nos) { Number_Of_Sessions = nos; }
	void Set_ST(Time st) { StartingTime = st; } // The end of the Set functions
	int Ret_ID() { return ID; } // The start of the Ret functions for each variable
	int Ret_L() { return Location; }
	string Ret_P() { return Proffessor; }
	string Ret_CN() { return ClassName; }
	bool Ret_VP() { return VP; }
	bool Ret_FC() { return FC; }
	Date Ret_D() { return date; }
	Time Ret_DT() { return DurationTime; }
	Time Ret_ST() { return StartingTime; }
	int Ret_NOS() { return Number_Of_Sessions; }
	Student Ret_STU(int i) { return s[i]; } // The end of the Ret functions
	bool operator>(Class ob) // This fucntion, ralted to the operator> function in Time class, 
		// returns wither the first object starts later than the second object or not. 
	{
		return this->StartingTime > ob.StartingTime;
	}
	Time EndTime() // This function returns the Time when class ends
	{
		return this->StartingTime + this->DurationTime;
	}
	void Set_Marker(int id) { mark[id] = 1; } // Using this function and the function below, we check whether the class id was repeated or not
	int Ret_Marker(int id) { return mark[id]; }
	void Reporter(int i)
	{
		ofstream OutFile("Report.txt", ios::app);
		OutFile << i << "." << endl << "--------------" << endl << "Class ID : " << ID << endl
			<< "Class Name : " << ClassName << endl << "Professor Name : " << Proffessor << endl
			<< "Class' Location : " << Location << endl
			<< "Start Time : " << StartingTime.Ret_H() << ":" << StartingTime.Ret_M() << endl
			<< "Lenght of Class : " << DurationTime.Ret_H() << ":" << DurationTime.Ret_M() << endl
			<< "Day that the class holds : " << date.Ret_Dow() << endl;
		if (VP)
			OutFile << "Video projector : True" << endl;
		else
			OutFile << "Video projector : False" << endl;
		if (FC)
			OutFile << "Forums Class : True" << endl << "Number Of Sessions : " << Number_Of_Sessions << endl;
		else
			OutFile << "Forums Class : False" << endl;
		OutFile << "Students list : " << endl;
		for (int i = 0; i < Number_Of_Studnets; i++)
			OutFile << s[i].Ret_SN() << " " << s[i].Ret_N() << endl;
		OutFile << "--------------" << endl;
	}
};

int Class::mark[10000] = {}; // Filling the array with zeros