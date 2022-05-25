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
            system("cls");
            display_society_details();
        }
        else if (choice == 2)
        {
            system("cls");
            display_past_events();
        }
        else if (choice == 3)
        {
            system("cls");
            display_ongoing_events();
        }
        else if (choice == 4)
        {
            system("cls");
            display_future_events();
        }
        else if (choice == 5)
        {
            system("cls");
            display_notifications();
        }
    }
};