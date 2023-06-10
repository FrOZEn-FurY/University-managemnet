// Including needed libraries
#include <iostream> 
#include <string>
#include <fstream>
#include "Class.h"
#include "Time.h"
#include "Date.h"
#include "Student.h"

using namespace std; // Working in the standard namespace

// A function that compares the two Classes with each other ( ClassRooms )
bool CompareStartTime(Class, Class);

// This function will compare which object has a longer time of happening
bool CompareDurationTime(Class, Class);

// This function will check wither two classes will get complex with each other or not
bool Interference(Class, Class);

// A function to make strings lowercase
string ToLower(string s);

const int maxn = 1000000; // A limit for the total amount of classes
int ClassCount = 0; // A class counter
Class CRs[maxn]; // The maximum amount of classes that this university can have

int main()
{
    cout << "Welcome to the university management program\nplease do not press any key until the program loads completely" << endl;
    _sleep(2);
    while (1)
    {
        cout << "Choose from options below :" << endl << "1.Insert a class and setting its location yourself ( manual insertion )"
            << endl << "2.Inserting a class's information and letting the program set its location ( manual insertion )" << endl
            << "3.Insert a class and setting its location yourself ( from a file )" << endl
            << "4.Inserting a class's information and letting the program set its location ( from a file )"
            << "5.Getting the report from the classes that had been set so far" << endl
            << "6.Exit the program" << endl;
        int opt;
        cin >> opt;
        switch (opt)
        {
            case 1:
            {
                Class C;
                int ID, Location, SN, H, M, NOS, markS[10000];
                string Proffesor, ClassName, DOW, Name;
                bool VP, FC;
                cout << "Enter Class ID ( It must be a 4 digit positive inteeger ):";
                cin >> ID;
                while (ID < 1000 or ID > 9999)
                {
                    cout << "Wrong input. Please try again:";
                    cin >> ID;
                }
                while (C.Ret_Marker(ID))
                {
                    cout << "The Id must not be repeated, please try again:" << endl;
                    cin >> ID;
                }
                C.Set_Marker(ID);
                cout << "Enter the class's name:";
                cin >> ClassName;
                cout << "Enter the Class's location ( From 1 to 10 ):";
                cin >> Location;
                while (Location < 0 or Location > 10)
                {
                    cout << "Wrong input. Please try again:";
                    cin >> Location;
                }
                cout << "Enter the proffesor of this class's name:";
                cin >> Proffesor;
                string temp;
                cout << "Does this class need video projector? ( type yes or true if it does ) :";
                cin >> temp;
                temp = ToLower(temp);
                if (temp == "yes" or temp == "true")
                    VP = true;
                else
                    VP = false;
                cout << "Is this class a forum class ? ( type yes or true if it is ) :";
                cin >> temp;
                temp = ToLower(temp);
                if (temp == "true" or temp == "yes")
                    FC = true;
                else
                    FC = false;
                if (FC)
                {
                    cout << "Enter number of sessions:";
                    cin >> NOS;
                }
                cout << "Enter the hour that the class starts at:";
                cin >> H;
                cout << "Enter the minute that the class starts at:";
                cin >> M;
                Time Strt(H, M);
                cout << "Enter the hour for the length of class:";
                cin >> H;
                cout << "Enter the minute for the length of class:";
                cin >> M;
                Time Dur(H, M);
                cout << "At what day of week the class needs to be held? :";
                cin >> DOW;
                cout << "Enter the student number and the name of students in order ( type -1 as id if u want to stop giving, also the student number must be 4 digit inteeger ) :";
                cin >> SN >> Name;
                Student s[40];
                int countS = 0;
                while (SN > 0)
                {
                    if (SN > 9999 or SN < 1000)
                    {
                        cout << "Wrong input, Please try again:" << endl;
                        continue;
                    }
                    if (markS[SN] == 1)
                    {
                        cout << "The student number must not be repeated, please try again:" << endl;
                        continue;
                    }
                    s[countS].Set_N(Name);
                    s[countS].Set_SN(SN);
                    markS[SN] = 1;
                    countS++;
                }
                C.Set_ID(ID);
                C.Set_CN(ClassName);
                C.Set_D(Date(0, 0, 0, DOW));
                C.Set_DT(Dur);
                C.Set_FC(FC);
                C.Set_L(Location);
                C.Set_P(Proffesor);
                C.Set_ST(Strt);
                C.Set_VP(VP);
                if (FC)
                    C.Set_NOS(NOS);
                for (int i = 0; i < countS; i++)
                    C.Set_STU(s[i].Ret_SN(), s[i].Ret_N(), i);
                bool Inter = false;
                for (int i = 0; i < ClassCount; i++)
                {
                    if (CRs[i].Ret_D().Ret_Dow() == DOW)
                    {
                        Class temp;
                        temp.Set_ST(Strt);
                        temp.Set_DT(Dur);
                        temp.Set_L(Location);
                        if (CRs[i].Ret_D().Ret_Dow() == C.Ret_D().Ret_Dow())
                            if (Interference(temp, CRs[i]))
                            {
                                Inter = true;
                                break;
                            }
                    }
                }
                if (Inter)
                {
                    cout << "The class you gave the program has interference with other classes." << endl;
                    break;
                }
                CRs[ClassCount] = C;
                ClassCount++;
                break;
            }
            case 2:
            {
                Class C;
                int ID, Location, SN, H, M, NOS, markS[10000];
                string Proffesor, ClassName, DOW, Name;
                bool VP, FC;
                cout << "Enter Class ID ( It must be a 4 digit positive inteeger ):";
                cin >> ID;
                while (ID < 1000 or ID > 9999)
                {
                    cout << "Wrong input. Please try again:";
                    cin >> ID;
                }
                while (C.Ret_Marker(ID))
                {
                    cout << "The Id must not be repeated, please try again:" << endl;
                    cin >> ID;
                }
                C.Set_Marker(ID);
                cout << "Enter the class's name:";
                cin >> ClassName;
                cout << "Enter the proffesor of this class's name:";
                cin >> Proffesor;
                string temp;
                cout << "Does this class need video projector? ( type yes or true if it does ) :";
                cin >> temp;
                temp = ToLower(temp);
                if (temp == "yes" or temp == "true")
                    VP = true;
                else
                    VP = false;
                cout << "Is this class a forum class ? ( type yes or true if it is ) :";
                cin >> temp;
                temp = ToLower(temp);
                if (temp == "true" or temp == "yes")
                    FC = true;
                else
                    FC = false;
                if (FC)
                {
                    cout << "Enter number of sessions:";
                    cin >> NOS;
                }
                cout << "Enter the hour that the class starts at:";
                cin >> H;
                cout << "Enter the minute that the class starts at:";
                cin >> M;
                Time Strt(H, M);
                cout << "Enter the hour for the length of class:";
                cin >> H;
                cout << "Enter the minute for the length of class:";
                cin >> M;
                Time Dur(H, M);
                cout << "At what day of week the class needs to be held? :";
                cin >> DOW;
                cout << "Enter the student number and the name of students in order ( type -1 as id if u want to stop giving, also the student number must be 4 digit inteeger ) :";
                cin >> SN >> Name;
                Student s[40];
                int countS = 0;
                while (SN > 0)
                {
                    if (SN > 9999 or SN < 1000)
                    {
                        cout << "Wrong input, Please try again:" << endl;
                        continue;
                    }
                    if (markS[SN] == 1)
                    {
                        cout << "The student number must not be repeated, please try again:" << endl;
                        continue;
                    }
                    s[countS].Set_N(Name);
                    s[countS].Set_SN(SN);
                    markS[SN] = 1;
                    countS++;
                }
                C.Set_ID(ID);
                C.Set_CN(ClassName);
                C.Set_D(Date(0, 0, 0, DOW));
                C.Set_DT(Dur);
                C.Set_FC(FC);
                C.Set_L(Location);
                C.Set_P(Proffesor);
                C.Set_ST(Strt);
                C.Set_VP(VP);
                if (FC)
                    C.Set_NOS(NOS);
                for (int i = 0; i < countS; i++)
                    C.Set_STU(s[i].Ret_SN(), s[i].Ret_N(), i);
                if (VP)
                {
                    for (int i = 6; i <= 10; i++)
                    {
                        Location = i;
                        bool Inter = false;
                        for (int j = 0; j < ClassCount; j++)
                        {
                            Class temp;
                            temp.Set_ST(Strt);
                            temp.Set_DT(Dur);
                            temp.Set_L(Location);
                            if (CRs[i].Ret_D().Ret_Dow() == C.Ret_D().Ret_Dow())
                                if (Interference(CRs[i], temp))
                                {
                                    Inter = true;
                                    break;
                                }
                        }
                        if (!Inter)
                        {
                            C.Set_L(Location);
                            break;
                        }
                    }
                }
                else
                {
                    for (int i = 1; i <= 5; i++)
                    {
                        Location = i;
                        bool Inter = false;
                        for (int j = 0; j < ClassCount; j++)
                        {
                            Class temp;
                            temp.Set_ST(Strt);
                            temp.Set_DT(Dur);
                            temp.Set_L(Location);
                            if (CRs[i].Ret_D().Ret_Dow() == C.Ret_D().Ret_Dow())
                                if (Interference(CRs[i], temp))
                                {
                                    Inter = true;
                                    break;
                                }
                        }
                        if (!Inter)
                        {
                            C.Set_L(Location);
                            break;
                        }
                    }
                }
                if (C.Ret_L() == 0)
                {
                    cout << "The class can not be set with this information, because it has interference with the other classes in any location." << endl;
                    break;
                }
                CRs[ClassCount] = C;
                ClassCount++;
                break;
            }
            case 3:
            {
                Class C;
                bool Problem = false;
                int ID, Location, SN, H1, M1, H2, M2, NOS, markS[10000];
                string Proffesor, ClassName, DOW, Name;
                bool VP, FC;
                cout << "Please enter the file address to read with the file name and prefix at the end of it. Please note that the file must contain only one class" <<
                    " information and the information must be in this order : Class ID, Class Name, Proffesor Name, Location, Video projector need, Forums Class condition, If its a forum class put the Number of sessions at the end of file, Starting time, Duration time, " <<
                    "Day of week, and the students with the Student number first and their name at second and also for the end of Students put a -1 as Student number :" << endl;
                string FileAddress;
                cin >> FileAddress;
                ifstream InFile(FileAddress, ios::in);
                string Vp, Fc;
                InFile >> ID >> ClassName >> Proffesor >> Location >> Vp >> Fc >> H1 >> M1 >> H2 >> M2 >> DOW;
                if (C.Ret_Marker(ID) == 1)
                {
                    cout << "The Class ID was repeated. Fix the problem and try again" << endl;
                    Problem = true;
                    break;
                }
                Student s[40];
                int countS = 0;
                InFile >> SN >> Name;
                while (SN > 0)
                {
                    if (SN < 1000 or SN > 9999)
                    {
                        cout << "The file has a problem in the student IDs, the IDs must be 4 digits. Fix the problem and try again" << endl;
                        Problem = true;
                        break;
                    }
                    if (markS[SN] == 1)
                    {
                        cout << "The file has a problem with student IDs, the IDs must not be repeated. Fix the problem and try again." << endl;
                        Problem = true;
                        break;
                    }
                    s[countS].Set_N(Name);
                    s[countS].Set_SN(SN);
                    markS[SN];
                    countS++;
                }
                if (Problem)
                    break;
                Vp = ToLower(Vp);
                Fc = ToLower(Fc);
                if (Vp == "true" or Vp == "yes")
                    VP = true;
                else
                    VP = false;
                if (Fc == "true" or Fc == "yes")
                    FC = true;
                else
                    FC = false;
                InFile >> NOS;
                Time Strt(H1, M1);
                Time Dur(H2, M2);
                C.Set_ID(ID);
                C.Set_CN(ClassName);
                C.Set_D(Date(0, 0, 0, DOW));
                C.Set_DT(Dur);
                C.Set_FC(FC);
                C.Set_L(Location);
                C.Set_P(Proffesor);
                C.Set_ST(Strt);
                C.Set_VP(VP);
                if (FC)
                    C.Set_NOS(NOS);
                for (int i = 0; i < countS; i++)
                    C.Set_STU(s[i].Ret_SN(), s[i].Ret_N(), i);
                for (int i = 0; i < ClassCount; i++)
                    if (CRs[i].Ret_D().Ret_Dow() == C.Ret_D().Ret_Dow())
                        if (Interference(CRs[i], C))
                        {
                            Problem = true;
                            break;
                        }
                if (Problem)
                {
                    cout << "The class you gave the program has interference with other classes" << endl;
                    break;
                }
                CRs[ClassCount] = C;
                ClassCount++;
                break;
            }
            case 4:
            {
                Class C;
                bool Problem = false;
                int ID, Location, SN, H1, M1, H2, M2, NOS, markS[10000];
                string Proffesor, ClassName, DOW, Name;
                bool VP, FC;
                cout << "Please enter the file address to read with the file name and prefix at the end of it. Please note that the file must contain only one class" <<
                    " information and the information must be in this order : Class ID, Class Name, Proffesor Name, Video projector need, Forums Class condition, If its a forum class put the Number of sessions at the end of file, Starting time, Duration time, " <<
                    "Day of week, and the students with the Student number first and their name at second and also for the end of Students put a -1 as Student number :" << endl;
                string FileAddress;
                cin >> FileAddress;
                ifstream InFile(FileAddress, ios::in);
                string Vp, Fc;
                InFile >> ID >> ClassName >> Proffesor >> Vp >> Fc >> H1 >> M1 >> H2 >> M2 >> DOW;
                if (C.Ret_Marker(ID) == 1)
                {
                    cout << "The Class ID was repeated. Fix the problem and try again" << endl;
                    Problem = true;
                    break;
                }
                Student s[40];
                int countS = 0;
                InFile >> SN >> Name;
                while (SN > 0)
                {
                    if (SN < 1000 or SN > 9999)
                    {
                        cout << "The file has a problem in the student IDs, the IDs must be 4 digits. Fix the problem and try again" << endl;
                        Problem = true;
                        break;
                    }
                    if (markS[SN] == 1)
                    {
                        cout << "The file has a problem with student IDs, the IDs must not be repeated. Fix the problem and try again." << endl;
                        Problem = true;
                        break;
                    }
                    s[countS].Set_N(Name);
                    s[countS].Set_SN(SN);
                    markS[SN] = 1;
                    countS++;
                }
                if (Problem)
                    break;
                InFile >> NOS;
                Time Strt(H1, M1);
                Time Dur(H2, M2);
                Vp = ToLower(Vp);
                Fc = ToLower(Fc);
                if (Vp == "true" or Vp == "yes")
                    VP = true;
                else
                    VP = false;
                if (Fc == "true" or Fc == "yes")
                    FC = true;
                else
                    FC = false;
                C.Set_ID(ID);
                C.Set_CN(ClassName);
                C.Set_D(Date(0, 0, 0, DOW));
                C.Set_DT(Dur);
                C.Set_FC(FC);
                C.Set_P(Proffesor);
                C.Set_ST(Strt);
                C.Set_VP(VP);
                if (FC)
                    C.Set_NOS(NOS);
                for (int i = 0; i < countS; i++)
                    C.Set_STU(s[i].Ret_SN(), s[i].Ret_N(), i);
                if (VP)
                {
                    for (int i = 6; i <= 10; i++)
                    {
                        Location = i;
                        bool Inter = false;
                        for (int j = 0; j < ClassCount; j++)
                        {
                            Class temp;
                            temp.Set_ST(Strt);
                            temp.Set_DT(Dur);
                            temp.Set_L(Location);
                            if (CRs[i].Ret_D().Ret_Dow() == C.Ret_D().Ret_Dow())
                                if (Interference(CRs[i], temp))
                                {
                                    Inter = true;
                                    break;
                                }
                        }
                        if (!Inter)
                        {
                            C.Set_L(Location);
                            break;
                        }
                    }
                }
                else
                {
                    for (int i = 1; i <= 5; i++)
                    {
                        Location = i;
                        bool Inter = false;
                        for (int j = 0; j < ClassCount; j++)
                        {
                            Class temp;
                            temp.Set_ST(Strt);
                            temp.Set_DT(Dur);
                            temp.Set_L(Location);
                            if (CRs[i].Ret_D().Ret_Dow() == C.Ret_D().Ret_Dow())
                                if (Interference(CRs[i], temp))
                                {
                                    Inter = true;
                                    break;
                                }
                        }
                        if (!Inter)
                        {
                            C.Set_L(Location);
                            break;
                        }
                    }
                }
                if (C.Ret_L() == 0)
                {
                    cout << "The class can not be set because it has interference with other classes in any location" << endl;
                    break;
                }
                CRs[ClassCount] = C;
                ClassCount++;
                break;
            }
            case 5:
            {
                for (int i = 0; i < ClassCount; i++)
                    CRs[i].Reporter(i + 1);
                cout << "The Report.txt is in the dirctory of the program and has reports in it." << endl;
                break;
            }
            case 6:
            {
                return 0;
                break;
            }
        }
    }
	return 0;
}

bool CompareStartTime(Class c1, Class c2) // This function using the operator> function in Class header,
// decides wither the first object starts sooner or later than the second object.
{
    return c1 > c2;
}

bool CompareDurationTime(Class c1, Class c2) // This function compares two classes duration time
{
    int h1 = c1.Ret_DT().Ret_H(), h2 = c2.Ret_DT().Ret_H();
    int m1 = c1.Ret_DT().Ret_M(), m2 = c2.Ret_DT().Ret_M();
    if (h1 > h2)
        return true;
    else if (h1 < h2)
        return false;
    else
        return m1 > m2;
    /*
        If the first object has a longer duration time, this function will return true,
        otherwise it will return false.
    */
}

bool Interference(Class c1, Class c2) // This function will check wither two classes will get complex with each other or not
{
    Time c1ET = c1.EndTime();
    Time c2ET = c2.EndTime();
    if (c1.StartingTime > c2ET or c2.StartingTime > c1ET)
        return false;
    else if (c1.Ret_L() == c2.Ret_L())
        return true;
    else
        return false;
    /*
        Using the operator> function in Time header and the EndTime function in Class header,
        we check if the classes have complexity or not.
    */
}

string ToLower(string s) // This function makes the input string lowercase
{
    for (int i = 0; i < s.size(); i++)
        if (s[i] >= 65 and s[i] <= 90)
            s[i] += 37;
    return s;
}