/*
OBJECTIVES:
Partially Done:
    ● Account registry
    ● Information Regarding Events (Past, Ongoing and Future)

To be done later:
    ● Allocation of accessibility to different accounts (example, Personal accounts can be updated
        by the people personally, Society head can update info regarding their society, etc.)
    ● Calendar (to display important dates)
    ● Notifications (to notify users about upcoming events and deadlines.)
    ● Registration process for students to apply for society’s membership.
    ● Evaluation of the applicants on the basis of information provided by applicants (It will help
        faculty/Society managers in considering who should be the best candidate)
*/

#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>
#include "login.h"
using namespace std;

void menu()
{
    int choice;
    system("cls");
    cout << "Welcome to Nuces Society Management System";
    cout << "\nPress\n"
         << "   1. Log In or Register\n"
         // << "   2. Login\n"
         << "   0. Exit\n"
         << "Your Input: ";
    cin >> choice;
    if (choice == 0)
    {
        exit(EXIT_SUCCESS);
    }
    else if (choice == 1)
    {
        system("cls");
        login();
    }
};

class date
{
private:
    int day;
    int month;
    int year;

public:
    void setDay(int temp) { day = temp; }
    void setMonth(int temp) { month = temp; }
    void setYear(int temp) { year = temp; }
    int getDay() { return day; }
    int getMonth() { return month; }
    int getYear() { return year; }
    void DisplayDate()
    {
        cout << setfill('0') << setw(2) << day << "/" << setfill('0') << setw(2) << month << "/" << setfill('0') << setw(4) << year;
    }
};

class Time
{
private:
    int hr;
    int min;

public:
    void setHour(int temp) { hr = temp; }
    void setMinutes(int temp) { min = temp; }
    int getHour() { return hr; }
    int getMinutes() { return min; }
    void DisplayTime(){}; // Time class display function has to be completed
};

class Account
{
private:
    string Full_Name;
    int Age;
    string username;
    string password;
    string type;              // e.g student, faculty, head, society head, director, visitor
    bool Modification_rights; // head, society head, director can apply
    string id;

public:
    void setName(string temp) { Full_Name = temp; }
    void setAge(int temp) { Age = temp; }
    string getName() { return Full_Name; }
    int getAge() { return Age; }
};

class Member : public Account
{
private:
    string Member_Role;

public:
};

class Events // Inherited classes will be past events and future events
{
private:
    string Event_name;
    string Event_Description;
    date Start_date;
    Time Start_time;
    date End_date;
    Time End_time;

public: // Functions are to be made
};

class Society
{
private:
    string Society_Name;
    string Society_Description;
    int Number_Of_Events;
    Events events[1];  // value to be modified according to number of events
    Member members[1]; // value to be modified according to number of members

public:
};

int main()
{
    menu();
    return 0;
}

/*
- Following OOP concepts are expected to be part of the project:
    - Abstraction
    - Classes and Objects
    - Encapsulations
    - Inheritances
    - Polymorphism (Both overloading and overriding)
    - Conditional and looping structures
    - Data structure such as arrays, array of objects, arraylists, etc.
    - Constructors and destructors
    - Filing and data storage systems
    - Exception handling
*/
