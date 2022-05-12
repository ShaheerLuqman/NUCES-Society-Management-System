/*
New society
add event to society
add member to society
create new event
*/

void admin_menu()
{
    int choice;
    system("cls");
    while (1)
    {
        cout << "Welcome to Nuces Society Management System";
        cout << "\nPress\n"
             << "   1. \n"
             << "   2. Enter an Event\n"
             << "   3. Current Date And Time\n"
             << "   4. Test\n" // new society,
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
        else if (choice == 2)
        {
            Events event;
            event.getEventData();
            event.DisplayEventData();
        }
        else if (choice == 3)
        {
            date current;
            current = Currentdate();
            current.displaydate();
        }
        else if (choice == 4)
        {
            society test;
            while (1)
            {
                test.add_new_event();
                test.display_event_names();
            }
        }
    }
};