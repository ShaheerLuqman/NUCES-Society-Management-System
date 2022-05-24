/*
society details
calender
login check for society membership
registeration form
*/

void visitor_menu()
{
    int choice;
    while (1)
    {
        system("cls");
        cout << "Welcome to Nuces Society Management System";
        cout << "\nPress to view\n"
             << "   1. Society Details\n"
             << "   2. Past Events\n"
             << "   3. Ongoing Events\n"
             << "   4. Future Events\n"
             << "   5. Notifications\n"
             << "   0. Back\n"
             << "Your Input: ";
        cin >> choice;
        if (choice == 0)
        {
            return;
        }
        else if (choice == 1)
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
                t.display_society();
                system("pause");
            }
        }
        else if (choice == 2)
        {
            void display_past_events();
        }
        else if (choice == 3)
        {
            display_ongoing_events();
        }
        else if (choice == 4)
        {
            display_future_events();
        }
        else if (choice == 5)
        {
            cout << "**********  Upcoming Events  **********" << endl;
            display_upcoming_events();
            cout << "\n*************  Notices  *************" << endl;
            cout << "Type your notice here!" << endl;
            system("pause");
        }
    }
};