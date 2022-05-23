/*
society details
calender
login check for society membership
registeration form
*/

void visitor_menu()
{
    int choice;
    system("cls");
    while (1)
    {
        cout << "Welcome to Nuces Society Management System";
        cout << "\nPress\n"
             << "   1. View Society Details\n"
             << "   2. View Events\n"
             << "   3. View Notifications\n"
             << "   4. Important Dates\n"
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
    }
};