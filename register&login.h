/*
    ● Copy data to local variables when Account logs in
    ● https://www.geeksforgeeks.org/readwrite-class-objects-fromto-file-c/
*/

void add_student_account_file(Student &a)
{
    ofstream g("student_accounts.txt", std::ios_base::app);
    if (!g.is_open())
    {
        cout << "could not open file\n";
        exit(EXIT_FAILURE);
    }
    else
    {
        g.write((char *)&a, sizeof(Student));
        g.close();
    }
};
Student retrieve_student_account_file(string user, string pass)
{
    ifstream f("student_accounts.txt", ios::in);
    Student b;
    if (!f.is_open())
    {
        cout << "could not open file\n";
        exit(EXIT_FAILURE);
    }
    while (!f.eof())
    {
        f.read((char *)&b, sizeof(b));
        if ((b.getUserName() == user) && (b.getPassword() == pass))
        {
        }
        else
        {
            b.setName("not_found");
        }
    }
    f.close();
    return b;
};

void add_faculty_account_file(Faculty &a)
{
    ofstream g("Faculty_accounts.txt", std::ios_base::app);
    if (!g.is_open())
    {
        cout << "could not open file\n";
        exit(EXIT_FAILURE);
    }
    else
    {
        g.write((char *)&a, sizeof(Faculty));
        g.close();
    }
};
Faculty retrieve_faculty_account_file(string user, string pass)
{
    ifstream f("Faculty_accounts.txt", ios::in);
    Faculty b;
    if (!f.is_open())
    {
        cout << "could not open file\n";
        exit(EXIT_FAILURE);
    }
    while (!f.eof())
    {
        f.read((char *)&b, sizeof(b));
        if ((b.getUserName() == user) && (b.getPassword() == pass))
        {
        }
        else
        {
            b.setName("not_found");
        }
    }
    f.close();
    return b;
};

int login_menu()
{
    int choice;

    string name, password, inName, inPassword;

    while (1)
    {
        cout << "Press\n"
             << "   1. Register\n"
             << "   2. Login\n"
             << "   0. Exit\n"
             << "Your Input: ";
        cin >> choice;

        if (choice == 0)
        {
            return 0;
        }
        else if (choice == 1) // Register
        {
            cout << "Enter number which describes you! " << endl
                 << "1. Student\n"
                 << "2. Faculty\n"
                 << "Your choice: ";
            cin >> choice;
            if (choice == 1)
            {
                Student std;
                std.Account_register();
                add_student_account_file(std);
            }
            else if (choice == 2)
            {
                Faculty fac;
                fac.Account_register();
                add_faculty_account_file(fac);
            }
        }
        else if (choice == 2) // Login
        {

            cout << "\n*********** Account Login ***********\n"
                 << "Enter Username: ";
            fflush(stdin);
            getline(cin, inName);
            cout << "Enter Password: ";
            fflush(stdin);
            getline(cin, inName);

            Student std;
            std = retrieve_student_account_file(inName, inName);

            Faculty fac;
            fac = retrieve_faculty_account_file(inName, inName);

            if (!(std.getName() == "not_found" || fac.getName() == "not_found"))
                cout
                    << "incorrect name or password\n";
            else
            {
                cout << "Login Successful\n"
                     << "Welcome, "
                     << inName;
                std.DisplayAccountData();
                return 1;
            }
        }
        cout << "\n######################################\n\n";
        system("pause");
    }
}
