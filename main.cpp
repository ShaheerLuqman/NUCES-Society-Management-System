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

/*
OBJECTIVES:
Partially Done:
    ● Account registry
    ● Allocation of accessibility to different accounts (example, Personal accounts can be updated
    by the people personally, Society head can update info regarding their society, etc.)
    ● Information Regarding Events (Past, Ongoing and Future)

To be done later:
    ● Calendar (to display important dates)
    ● Notifications (to notify users about upcoming events and deadlines.)
    ● Registration process for students to apply for society’s membership.
    ● Evaluation of the applicants on the basis of information provided by applicants (It will help
    faculty/Society managers in considering who should be the best candidate)
*/

#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

void SignUp(){}; // Input will be taken, then input will be validated and verified, then respective account object will be created
void SignIn(){};

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

public:
    void setName(string temp) { Full_Name = temp; }
    void setAge(int temp) { Age = temp; }
    string getName() { return Full_Name; }
    int getAge() { return Age; }
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

int main()
{
    return 0;
}