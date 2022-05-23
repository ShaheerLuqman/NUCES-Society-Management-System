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
            fstream f;
            f.open("events.csv", ios::in);
            bool flag = false;

            Events eve;
            if (!f.is_open())
            {
                cout << "could not open file\n";
                exit(EXIT_FAILURE);
            }
            else
            {
                while (!f.eof())
                {
                    string line;
                    getline(f, line, ',');
                    if (line.empty())
                    {
                        eve.event_name = "";
                        eve.event_description = "";
                        eve.event_date.setDay(0);
                        eve.event_date.setMonth(0);
                        eve.event_date.setYear(0);
                        break;
                    }
                    eve.event_name = line;
                    getline(f, line, ',');
                    eve.event_description = line;
                    getline(f, line, ',');
                    int a = stoi(line);
                    eve.event_date.setDay(a);
                    getline(f, line, ',');
                    int b = stoi(line);
                    eve.event_date.setMonth(b);
                    getline(f, line);
                    int c = stoi(line);
                    eve.event_date.setYear(c);
                    eve.determine_event_status();
                    if (eve.event_status == "past")
                    {
                        eve.display_event_data();
                        flag = true;
                    }
                }
                if (flag == false)
                    cout << "No Past Events" << endl;
                system("pause");
            }
        }
        else if (choice == 3)
        {
            fstream f;
            f.open("events.csv", ios::in);
            bool flag = false;

            Events eve;
            if (!f.is_open())
            {
                cout << "could not open file\n";
                exit(EXIT_FAILURE);
            }
            else
            {
                while (!f.eof())
                {
                    string line;
                    getline(f, line, ',');
                    if (line.empty())
                    {
                        eve.event_name = "";
                        eve.event_description = "";
                        eve.event_date.setDay(0);
                        eve.event_date.setMonth(0);
                        eve.event_date.setYear(0);
                        break;
                    }
                    eve.event_name = line;
                    getline(f, line, ',');
                    eve.event_description = line;
                    getline(f, line, ',');
                    int a = stoi(line);
                    eve.event_date.setDay(a);
                    getline(f, line, ',');
                    int b = stoi(line);
                    eve.event_date.setMonth(b);
                    getline(f, line);
                    int c = stoi(line);
                    eve.event_date.setYear(c);
                    eve.determine_event_status();
                    if (eve.event_status == "ongoing")
                    {
                        eve.display_event_data();
                        flag = true;
                    }
                }
                if (flag == false)
                    cout << "No Ongoing Events" << endl;
                system("pause");
            }
        }
        else if (choice == 4)
        {

            fstream f;
            f.open("events.csv", ios::in);
            bool flag = false;

            Events eve;
            if (!f.is_open())
            {
                cout << "could not open file\n";
                exit(EXIT_FAILURE);
            }
            else
            {
                while (!f.eof())
                {
                    string line;
                    getline(f, line, ',');
                    if (line.empty())
                    {
                        eve.event_name = "";
                        eve.event_description = "";
                        eve.event_date.setDay(0);
                        eve.event_date.setMonth(0);
                        eve.event_date.setYear(0);
                        break;
                    }
                    eve.event_name = line;
                    getline(f, line, ',');
                    eve.event_description = line;
                    getline(f, line, ',');
                    int a = stoi(line);
                    eve.event_date.setDay(a);
                    getline(f, line, ',');
                    int b = stoi(line);
                    eve.event_date.setMonth(b);
                    getline(f, line);
                    int c = stoi(line);
                    eve.event_date.setYear(c);
                    eve.determine_event_status();
                    if (eve.event_status == "future")
                    {
                        eve.display_event_data();
                        flag = true;
                    }
                }
                if (flag == false)
                    cout << "No Future Events" << endl;
                system("pause");
            }
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