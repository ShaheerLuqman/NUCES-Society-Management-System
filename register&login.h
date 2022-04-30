/*
    ● Copy data to local variables when Account logs in
    ● https://www.geeksforgeeks.org/readwrite-class-objects-fromto-file-c/
*/

using namespace std;
class Account
{
protected:
    string Full_Name, username, password, status, email, id; // e.g student, faculty, head, society head, director, visitor

public:
    void setName(string temp) { Full_Name = temp; }
    string getUserName() { return username; }
    string getPassword() { return password; }
    void Account_register()
    {
        int choice;
        cout << "\n********** Account Register **********\n"
             << "New Username: ";
        fflush(stdin);
        getline(cin, username);
        while (1)
        {
            cout << "New Password: ";
            fflush(stdin);
            getline(cin, password);
            string registerRePassword;
            cout << "Re-enter Password: ";
            fflush(stdin);
            getline(cin, registerRePassword);
            if (password == registerRePassword)
            {
                break;
            }
            else
            {
                cout << "Password not matched." << endl;
            }
        }
        cout << "Full Name: ";
        fflush(stdin);
        getline(cin, Full_Name);
        cout << "E-mail Address: ";
        fflush(stdin);
        getline(cin, email);
        fflush(stdin);
    };
    void DisplayAccountData()
    {
        cout << "\nObect readed completely\n"
             << "\nUsername: " << username
             << "\nPassword: " << password
             << "\nE-mail Address: " << email;
    };
};

class Student : public Account
{
private:
    float cgpa;

public:
    void Account_register()
    {
        Account::Account_register();
        cout << "Student ID (e.g: 21K-XXXX): ";
        fflush(stdin);
        getline(cin, id);
        cout << "CGPA: ";
        cin >> cgpa;
    };
    void DisplayAccountData()
    {
        Account::DisplayAccountData();
        cout << "\nStudent ID: " << id
             << "\nCGPA: " << cgpa;
    };
};
class Faculty : public Account
{
private:
    string designation;

public:
    void Account_register()
    {
        Account::Account_register();
        cout << "Faculty ID (e.g: 21K-XXXX): ";
        fflush(stdin);
        getline(cin, id);
        cout << "Designation: ";
        fflush(stdin);
        getline(cin, designation);
    };
    void DisplayAccountData()
    {
        Account::DisplayAccountData();
        cout << "\nFaculty ID: " << id
             << "\nDesignation: " << designation;
    };
};
class Alumni : public Account
{
private:
    string graduating_year;

public:
    void Account_register()
    {
        Account::Account_register();
        cout << "Student ID (e.g: 21K-XXXX): ";
        fflush(stdin);
        getline(cin, id);
        cout << "Graduating Year: ";
        cin >> graduating_year;
    };
    void DisplayAccountData()
    {
        Account::DisplayAccountData();
        cout << "\nStudent ID: " << id
             << "\nGraduating Year: " << graduating_year;
    };
};

;
int login()
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
            ofstream g("registration.txt", std::ios_base::app);
            if (!g.is_open()) // if it's not open, then there is no such file with the given name inside
            {
                cout << "could not open file\n";
                exit(EXIT_FAILURE);
            }

            cout << "Enter number which describes you! " << endl
                 << "1. Student\n"
                 << "2. Faculty\n"
                 << "3. Alumni\n";
            cin >> choice;
            if (choice == 1)
            {
                ofstream g("registration.txt", std::ios_base::app);
                Student std;
                std.Account_register();
                g.write((char *)&std, sizeof(std));
                g.close();
            }
            else if (choice == 2)
            {
                // for Faculty
            }
            else if (choice == 3)
            {
                // for Alumni
            }
        }
        else if (choice == 2) // Login
        {
            ifstream f("registration.txt", ios::in);
            if (!f.is_open())
            {
                cout << "could not open file\n";
                exit(EXIT_FAILURE);
            }

            Student std1;
            f.read((char *)&std1, sizeof(std1));
            std1.DisplayAccountData();

            // getline(f, name, '\n');     // reads the user name from file f (which is using "registration.txt")
            // getline(f, password, '\n'); // reads the password from file f (which is using "registration.txt")
            // // also, if you tell the file to get you that text up until '\n', that's when you know it reads
            // // the whole line at most, and won't go any further
            // // and that is done by the 3rd parameter
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
                if (inName == std1.getUserName() && inPassword == std1.getPassword())
                {
                    cout << "Login Successful\n"
                         << "Welcome, "
                         << inName;
                    std1.DisplayAccountData();
                    return 1;
                    break;
                }
                cout << "incorrect name or password\n";
            }
        }
        cout << "\n######################################\n\n";
    }
}
