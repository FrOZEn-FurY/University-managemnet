#pragma once

using namespace std; // Just in case =)

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
