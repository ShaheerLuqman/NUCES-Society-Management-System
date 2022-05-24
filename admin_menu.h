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
            system("pause");
        }
        else if (choice == 2)
        {
            int ch;
            fstream f("society.csv", ios::in);
            if (!f.is_open() && f.fail())
            {
                cout << "\nNo record of society found\n";
                f.close();
            }
            else
            {
                cout << "\nPress\n";
                int i = 0;
                string temp;
                while (!f.eof())
                {
                    getline(f, temp);
                    if (temp.empty())
                        break;

                    cout << "   " << i + 1 << ". " << temp << endl;
                    i++;
                }
                f.close();
                f.open("society.csv", ios::in);
                cout << "Your Input: ";
                cin >> ch;
                for (int i = 0; i < ch; i++)
                {
                    // cout << i;
                    getline(f, temp);
                }
                // cout << temp;
                f.close();
                society t = retrieve_society_account_file(temp);

                if (t.get_society_name() != "")
                    society_menu(t);
                else
                    system("pause");
            }
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