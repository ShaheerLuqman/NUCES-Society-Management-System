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
             << "   3. Today's Date\n"
             << "   4. Create New Event\n"
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
            date current;
            current = current_date();
            current.displaydate();
            system("pause");
        }
        else if (choice == 4)
        {
            Events event;
            event.get_event_data();
            add_event_file(event);
            // event.get_event_data();
            // add_event_file(event);
            Events t = retrieve_events_file();
            t.display_event_data();
            system("pause");
        }
    }
};