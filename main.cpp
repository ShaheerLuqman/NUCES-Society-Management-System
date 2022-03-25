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
#include "date&time.h"
using namespace std;

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

class Events
{
private:
    string Event_name;
    string Event_Description;
    date Start_date;
    Time Start_time;
    date End_date;
    Time End_time;
    string Event_Status; // past, Ongoing or Future. It will be determined not taken as input

public:
    void getEventData()
    {
        cout << "-----------------------------\n"
             << "Enter Event Details\n"
             << "-----------------------------\n";
        cout << "Enter Event Name : ";
        cin >> Event_name;
        cout << "Enter Event Description : ";
        cin >> Event_Description;
        cout << "-----------------------------\n";
        cout << "Enter Event Starting Date\n";
        cout << "-----------------------------\n";
        Start_date.inputDate();
        cout << "-----------------------------\n";
        cout << "Enter Event Starting Time\n";
        cout << "-----------------------------\n";
        Start_time.inputTime();
        cout << "-----------------------------\n";
        cout << "Enter Event Ending Date\n";
        cout << "-----------------------------\n";
        End_date.inputDate();
        cout << "-----------------------------\n";
        cout << "Enter Event Ending Time\n";
        cout << "-----------------------------\n";
        End_time.inputTime();
        cout << "-----------------------------\n";
    }

    void DisplayEventData()
    {
        cout << "Event Name : " << Event_name << endl
             << "Event Description :" << Event_Description << endl;
        cout << "Event Start Date :";
        Start_date.DisplayDate();
        cout << endl
             << "Event End Date : ";
        End_date.DisplayDate();
        cout << endl
             << "Event Start Time : ";
        Start_time.DisplayTime();
        cout << endl
             << "Event End Time : ";
        End_time.DisplayTime();
        cout << endl;
    }
};

class Society
{
private:
    string Society_Name;
    string Society_Description;
    int Number_Of_Events;
    Events *events;
    Member *members;

public:
};

int main()
{
    int choice;
    system("cls");
    while (1)
    {
        cout << "Welcome to Nuces Society Management System";
        cout << "\nPress\n"
             << "   1. Log In or Register\n"
             << "   2. Enter an Event\n"
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
        else if (choice == 2)
        {
            Events event;
            event.getEventData();
            event.DisplayEventData();
        }
    }
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
