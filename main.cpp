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
#include "register&login.h"
#include "date&time.h"
#include "visitor_menu.h"
#include "events.h"
#include "society.h"
#include "admin_menu.h"

using namespace std;

void printLine() { cout << string(50, '~') << endl; }

int main()
{
    int choice;
    system("cls");
    while (1)
    {
        printLine();
        cout << "Welcome to Nuces Society Management System";
        cout << "\nPress\n"
             << "   1. Log In or Register\n"
             << "   2. Enter an Event\n"
             << "   3. Current Date And Time\n"
             << "   4. Continue as Guest\n"
             << "   5. Test\n"
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
            //     Events event;
            //     event.getEventData();
            //     event.DisplayEventData();
        }
        else if (choice == 3)
        {
            CurrentDateTime();
        }
        else if (choice == 4)
        {
            cout << "Welcome Visitor!";
            visitor_menu();
        }
        else if (choice == 5)
        {
            Society test;
            test.NewSociety();
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
