void admin_menu()
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
             << "   9. Back\n"
             << "   0. Exit\n"
             << "Your Input: ";
        cin >> choice;
        if (choice == 0)
        {
            exit(EXIT_SUCCESS);
        }
        else if (choice == 9)
        {
            return;
        }
        else if (choice == 1)
        {
            system("cls");
        }
        else if (choice == 2)
        {
        }
        else if (choice == 3)
        {
        }
        else if (choice == 4)
        {
        }
    }
};