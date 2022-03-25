/*
    ● Option for accounts registered to remain saved
    ● New Questions for account register
    ● Copy data to local variables when Account logs in
    ● https://www.geeksforgeeks.org/readwrite-class-objects-fromto-file-c/
*/

using namespace std;
int login()
{
    int choice;
    string name, password, inName, inPassword, registerName, registerPassword;

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
            exit(EXIT_SUCCESS);
        }
        else if (choice == 1) // Register
        {
            ofstream g("registration.txt"); /* ofstream is the one for getting data from the file, and the file does not even have to exist.
                                                If it's ofstream, it'll take care of it for you. but be warned that if there is a file called "registration.txt"
                                                in the name folder as the .exe file, the contents will be deleted*/
            if (!g.is_open())               // if it's not open, then there is no such file with the given name inside
            {
                cout << "could not open file\n";
                exit(EXIT_FAILURE);
            }

            cout << "\n********** Account Register **********\n"
                 << "New Username: ";
            fflush(stdin);
            getline(cin, registerName);
            cout << "New Password: ";
            fflush(stdin);
            getline(cin, registerPassword);
            g << registerName;

            g << '\n';
            g << registerPassword;

            g.close();
        }
        else if (choice == 2) // Login
        {
            ifstream f("registration.txt"); // ifstream is the one for getting data from the file, and
            // let us assume you've already created a file called "registration.txt"
            if (!f.is_open()) // if it's not open, then there is no such file with the given name inside
            // the folder (that is, in the folder where the .exe file is going to be)
            {
                cout << "could not open file\n"; // just so that you know why it won't work if it doesn't
                exit(EXIT_FAILURE);
            }

            getline(f, name, '\n');     // reads the user name from file f (which is using "registration.txt")
            getline(f, password, '\n'); // reads the password from file f (which is using "registration.txt")
            // also, if you tell the file to get you that text up until '\n', that's when you know it reads
            // the whole line at most, and won't go any further
            // and that is done by the 3rd parameter
            f.close();

            while (1)
            {
                cout << "\n*********** Account Login ***********\n"
                     << "Enter Username: ";
                fflush(stdin);
                getline(cin, inName);
                cout << "Enter Password: ";
                fflush(stdin);
                getline(cin, inPassword);
                if (inName == name && inPassword == password)
                {
                    cout << "Login Successful\n"
                         << "Welcome, "
                         << inName;
                    return 1;
                    break;
                }
                cout << "incorrect name or password\n";
            }
        }
        cout << "\n######################################\n\n";
    }
}