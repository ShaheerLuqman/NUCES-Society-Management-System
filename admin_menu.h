#include <sstream>
void admin_menu()
{
    int choice;
    while (1)
    {
        system("cls");
        cout << "Welcome Admin";
        cout << "\nPress\n"
             << "   1. Create New Society\n"
             << "   2. Manage Society\n"
             << "   3. View Event Details\n"
             << "   0. Back\n"
             << "Your Input: ";
        cin >> choice;
        if (choice == 0)
        {
            return;
        }
        else if (choice == 1)
        {
            society test;
            test.NewSociety();
            add_society_account_file(test);
        }
        else if (choice == 2)
        {
            society t;
            string temp;
            cout << "Enter the name of society you want to manage: ";
            fflush(stdin);
            getline(cin, temp);

            t = retrieve_society_account_file(temp);
            if (t.get_society_name() != "")
                society_menu(t);
            else
                system("pause");
        }
        else if (choice == 3)
        {
            string temp;
            cout << "Enter the name of event: ";
            fflush(stdin);
            getline(cin, temp);
            Events t = retrieve_events_file(temp);
            t.display_event_data();
            system("pause");
        }
    }
};