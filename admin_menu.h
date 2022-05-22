void admin_menu()
{
    int choice;
    system("cls");
    while (1)
    {
        cout << "Welcome Admin";
        cout << "\nPress\n"
             << "   1. Create New Society\n"
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
            event.get_event_data();
            event.display_event_data();
        }
        else if (choice == 3)
        {
            date current;
            current = current_date();
            current.displaydate();
        }
        else if (choice == 4)
        {
            society test;
            test.NewSociety();
            // for (int i = 0; i < 3; i++)
            add_society_account_file(test);
            test.add_new_event();
            add_society_account_file(test);

            // for (int i = 0; i < 3; i++)
            test.add_new_member();
            add_society_account_file(test);
        }
        else if (choice == 5)
        {
            society t;
            t = retrieve_society_account_file("acm");
            t.display_society();
            t.add_new_event();
            add_society_account_file(t);
            t.add_new_member();
            add_society_account_file(t);
            t.display_society();
        }
    }
};