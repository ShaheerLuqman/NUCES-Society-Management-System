/*
society details
calender
login check for society membership
registeration form
*/

void member_menu(Student &std)
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
             << "   6. Apply To A Society\n"
             << "   0. Back\n"
             << "Your Input: ";
        cin >> choice;
        if (choice == 0)
        {
            return;
        }
        else if (choice == 1)
        {
            display_society_details();
        }
        else if (choice == 2)
        {
            display_past_events();
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
            display_notifications();
        }
        else if (choice == 6)
        {
            Application app(std);
            app.apply_to_society();
        }
    }
};

void member_menu(Faculty &fac)
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
             << "   6. Applications For Society\n"
             << "   0. Back\n"
             << "Your Input: ";
        cin >> choice;
        if (choice == 0)
        {
            return;
        }
        else if (choice == 1)
        {
            display_society_details();
        }
        else if (choice == 2)
        {
            display_past_events();
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
            display_notifications();
        }
        else if (choice == 6)
        {
        }
    }
};