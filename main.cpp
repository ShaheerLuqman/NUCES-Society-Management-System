/*
OBJECTIVES:
Partially Done:
    ● change all string functions with cin to getline
    ● Logged in acc can update their profile.

To be done later:
    ● Allocation of accessibility to different accounts (example, Personal accounts can be updated
        by the people personally, Society head can update info regarding their society, etc.)
    ● Registration process for students to apply for society’s membership.
    ● Evaluation of the applicants on the basis of information provided by applicants (It will help
        faculty/Society managers in considering who should be the best candidate)
*/

#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>
#include <Windows.h>
#include <cstdlib>
using namespace std;

#include "accounts.h"
#include "date.h"
#include "events.h"
#include "society.h"
#include "admin_menu.h"
#include "visitor_menu.h"
#include "member_menu.h"
#include "register&login.h"
#include "apply_society.h"

int main()
{
    int choice;
    while (1)
    {
        system("cls");
        cout << "Welcome to Nuces Society Management System";
        cout << "\nPress\n"
             << "   1. Log In or Register\n"
             << "   2. Continue as Guest\n"
             << "   3. Continue as Admin\n"
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
            login_menu();
        }
        else if (choice == 2)
        {
            cout << "Welcome Visitor!";
            visitor_menu();
        }
        else if (choice == 3)
        {
            cout << "Welcome Admin!";
            admin_menu();
        }
    }
    return 0;
}