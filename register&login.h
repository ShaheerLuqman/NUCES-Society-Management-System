/*
    ● Option for accounts registered to remain saved
    ● New Questions for account register
    ● Copy data to local variables when Account logs in
    ● https://www.geeksforgeeks.org/readwrite-class-objects-fromto-file-c/
*/

using namespace std;

class Account
{
private:
    string Full_Name, username, password, status, email, gender, contact_number; // e.g student, faculty, head, society head, director, visitor
    bool Modification_rights;                                                    // head, society head, director can apply
    int Age;
    float cgpa;

public:
    void setName(string temp) { Full_Name = temp; }
    void setAge(int temp) { Age = temp; }
    string getUserName() { return username; }
    string getPassword() { return password; }
    int getAge() { return Age; }
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
        cout << "E-mail Address: ";
        fflush(stdin);
        getline(cin, email);
        cout << "Contact Number: ";
        cin >> contact_number;
        cout << "Gender: ";
        fflush(stdin);
        getline(cin, gender);
    };
    void DisplayAccountData()
    {
        cout << "\nObect readed completely\n"
             << "\nUsername: " << username
             << "\nPassword: " << password
             << "\nE-mail Address: " << email
             << "\nContact Number: " << contact_number
             << "\nGender: " << gender;
    };
};

class Student : public Account
{
private:
    string std_id;
    float cgpa;
    string department;

public:
    void Account_register()
    {
        Account::Account_register();
        cout << "Student ID (e.g: 21K-XXXX): ";
        fflush(stdin);
        getline(cin, std_id);
        cout << "CGPA: ";
        cin >> cgpa;
        cout << "Department: ";
        fflush(stdin);
        getline(cin, department);
    };
    void DisplayAccountData()
    {
        Account::DisplayAccountData();
        cout << "\nStudent ID: " << std_id
             << "\nCGPA: " << cgpa
             << "\nDepartment: " << department;
    };
};
class Faculty : public Account
{
private:
    string faculty_id, designation, department;
    int Joining_year;

public:
    void Account_register()
    {
        Account::Account_register();
        cout << "Faculty ID (e.g: 21K-XXXX): ";
        fflush(stdin);
        getline(cin, faculty_id);
        cout << "Designation: ";
        fflush(stdin);
        getline(cin, designation);
        cout << "Working since: (year)";
        cin >> Joining_year;
        cout << "Department: ";
        fflush(stdin);
        getline(cin, department);
    };
    void DisplayAccountData()
    {
        Account::DisplayAccountData();
        cout << "\nFaculty ID: " << faculty_id
             << "\nDesignation: " << designation
             << "\nWorking since: " << Joining_year
             << "\nDepartment: " << department;
    };
};
class Alumni : public Account
{
private:
    string std_id, alumni_graduation, alumni_academic, job;
    float cgpa;

public:
    void Account_register()
    {
        Account::Account_register();
        cout << "Student ID (e.g: 21K-XXXX): ";
        fflush(stdin);
        getline(cin, std_id);
        cout << "CGPA: ";
        cin >> cgpa;
        cout << "Graduation department: ";
        fflush(stdin);
        getline(cin, alumni_graduation);
        cout << "Current Academic program (if enrolled in any): ";
        fflush(stdin);
        getline(cin, alumni_academic);
        cout << "Current job: (if any)";
        fflush(stdin);
        getline(cin, job);
    };
    void DisplayAccountData()
    {
        Account::DisplayAccountData();
        cout << "\nStudent ID: " << std_id
             << "\nCGPA: " << cgpa
             << "\nGraduation department: " << alumni_graduation
             << "\nCurrent Academic program: " << alumni_academic
             << "\nCurrent job: " << job;
    };
};

class Member : public Account
{
private:
    string Member_Role;

public:
};
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
