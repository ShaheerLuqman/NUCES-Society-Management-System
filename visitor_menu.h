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
        }
    }
};