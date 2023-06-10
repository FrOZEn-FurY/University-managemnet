# University managment app
In this project we tried to get the information of each class and set the classes to the physical classes that we have.
we have the total of **10 classrooms** and the classes number 1 to 5 doesn't have video projector and and 6 to 10 does.
In the continue, we will describe each file of project.
Also it is needed to say that because of being short in time, there was no time to debug, so the project might contain some bugs, actually might have a lot of bugs, i really don't know =/
## Student header file
This file storest the data of students. a piece of code is shown below :
``` C++
class Student // A class that stores the data about students
{
	string name; // Stores student's name
	int StuNum; // Stored the student number
public:
	Student(int sn = 0, string n = "") :name(n) // A constructor if we needed to give the values when we were creating an object
	{
		StuNum = sn;
		name = n;
	}
	void Set_N(string n) { name = n; } // A function to set the value of name
	void Set_SN(int sn) { StuNum = sn; } // A function to set the value of StuNum
	string Ret_N() { return name; } // A function that returns the value of name 
	int Ret_SN() { return StuNum; } // A function that returns the value of StuNum 
};
```
## Time header file
This file is a class to store data about time. a piece of code is shown below :
```C++
class Time // A class to store time
{
	int hour, minute; // Variables for this class
public:
	Time(int h = 0, int m = 0) :hour(h), minute(m) {} // A constructor if we needed to give the values when we were creating an object
	void Set_H(int h) { hour = h; } // A function to set the value of hour
	void Set_M(int m) { minute = m; } // A function to set the value of minute
	int Ret_H() { return hour; } // A function that returns the value of hour 
	int Ret_M() { return minute; } // A function that returns the value of minute 
	bool operator>(Time ob) // This function will check wither the object that called the > operator is starting later than the other object
	{
		if (this->hour > ob.hour) // If the first object has a greater value of hour than the condition is true
			return true;
		else if (this->hour < ob.hour) // If the first object has a lower value of hour the condition is false
			return false;
		else // If none the above, than the minutes decide the condition
			return this->minute > ob.minute;
	}
	Time& operator+(Time& ob) // This is a function to set if a + operator came between to objects of this class, what should happen
	{
		this->hour += ob.hour;
		this->minute += ob.minute;
		return *this;
	}
};
```
## Date header file
This file is actually doesn't have a purpose despite storing the day of week.
A piece of code is shown below :
```C++
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
```
## Class header file
This is the header file for the classrooms. i will just show the functions in this class :
```C++
void Set_ID(int id) { ID = id; } // The start of the Set functions for each variable
	void Set_L(int l) { Location = l; }
	void Set_P(string p) { Proffessor = p; }
	void Set_CN(string cn) { ClassName = cn; }
	void Set_VP(bool vp) { VP = vp; }
	void Set_FC(bool fc) { FC = fc; }
	void Set_STU(int id, string n, int i) \
	{ 
		s[i].Set_N(n); 
		s[i].Set_SN(id); 
		Number_Of_Studnets++; // Storing the number of students for this class
	}
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
```
## The end
Becuase of time shortage, i also cannot make a good report, sorry for this.
