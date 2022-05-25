void add_student_account_file(Student &std)
{
    ofstream f("student_accounts.csv", ios::app);
    if (!f.is_open())
    {
        cout << "could not open file\n";
        exit(EXIT_FAILURE);
    }
    else
    {
        f << std.getUserName() << ","
          << std.getPassword() << ","
          << std.getName() << ","
          << std.getEmail() << ","
          << std.getID() << ","
          << std.getCGPA() << endl;
        f.close();
    }
};
Student retrieve_student_account_file(string user, string pass)
{
    ifstream f("student_accounts.csv", ios::in);
    Student b;
    if (!f.is_open())
    {
        cout << "could not open file\n";
        exit(EXIT_FAILURE);
    }
    while (!f.eof())
    {
        string line;
        getline(f, line, ','); // username
        b.setUserName(line);
        getline(f, line, ','); // pass
        b.setPassword(line);
        getline(f, line, ','); // name
        b.setName(line);
        getline(f, line, ','); // email
        b.setEmail(line);
        getline(f, line, ','); // id
        b.setID(line);
        getline(f, line); // cgpa
        b.setCGPA(line);

        if ((b.getUserName() == user) && (b.getPassword() == pass))
            break;

        else
        {
            string temp = "not_found";
            b.setName(temp);
        }
    }
    f.close();
    return b;
};

void add_faculty_account_file(Faculty &std)
{
    ofstream f("Faculty_accounts.csv", ios::app);
    if (!f.is_open())
    {
        cout << "could not open file\n";
        exit(EXIT_FAILURE);
    }
    else
    {
        f << std.getUserName() << "," << std.getPassword() << "," << std.getName() << "," << std.getEmail() << "," << std.getID() << "," << std.getDesignation() << endl;
        f.close();
    }
};
Faculty retrieve_faculty_account_file(string user, string pass)
{
    ifstream f("Faculty_accounts.csv", ios::in);
    Faculty b;
    if (!f.is_open())
    {
        cout << "could not open file\n";
        exit(EXIT_FAILURE);
    }
    while (!f.eof())
    {
        string line;
        getline(f, line, ','); // username
        b.setUserName(line);
        getline(f, line, ','); // pass
        b.setPassword(line);
        getline(f, line, ','); // name
        b.setName(line);
        getline(f, line, ','); // email
        b.setEmail(line);
        getline(f, line, ','); // id
        b.setID(line);
        getline(f, line); // designation
        b.setDesignation(line);

        if ((b.getUserName() == user) && (b.getPassword() == pass))
            break;

        else
        {
            string temp = "not_found";
            b.setName(temp);
        }
    }
    f.close();
    return b;
};

int login_menu()
{
    string choice;
    string name, password, inName, inPassword;

    while (1)
    {
        cout << "Press\n"
             << "   1. Register\n"
             << "   2. Login\n"
             << "   0. Back\n"
             << "Your Input: ";
        cin >> choice;

        if (choice == "0")
        {
            return 0;
        }
        else if (choice == "1") // Register
        {
            cout << "Enter number which describes you! " << endl
                 << "1. Student\n"
                 << "2. Faculty\n"
                 << "Your choice: ";
            cin >> choice;
            if (choice == "1")
            {
                Student std;
                std.Account_register();
                add_student_account_file(std);
            }
            else if (choice == "2")
            {
                Faculty fac;
                fac.Account_register();
                add_faculty_account_file(fac);
            }
        }
        else if (choice == "2") // Login
        {
            cout << "\n*********** Account Login ***********\n"
                 << "Enter Username: ";
            fflush(stdin);
            getline(cin, inName);
            cout << "Enter Password: ";
            fflush(stdin);
            getline(cin, inPassword);

            if (inName == "admin" && inPassword == "admin")
            {
                admin_menu();
                return 1;
            }

            Student std;
            std = retrieve_student_account_file(inName, inPassword);
            Faculty fac;
            fac = retrieve_faculty_account_file(inName, inPassword);

            if (std.getName() != "not_found")
            {
                cout << "Login Successful\n"
                     << "Welcome, "
                     << std.getName() << endl;
                system("pause");
                member_menu(std);
                return 1;
            }
            if (fac.getName() != "not_found")
            {
                cout << "Login Successful\n"
                     << "Welcome "
                     << fac.getName() << endl;
                system("pause");
                member_menu(fac);
                return 1;
            }
            if ((std.getName() == "not_found") && (fac.getName() == "not_found"))
            {
                cout << "incorrect name or password\n";
                system("pause");
            }
        }
    }
}
