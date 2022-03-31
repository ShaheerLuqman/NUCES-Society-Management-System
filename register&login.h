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
    string Full_Name;
    int Age;
    string username;
    string password;
    string type;              // e.g student, faculty, head, society head, director, visitor
    bool Modification_rights; // head, society head, director can apply
    string id;

public:
    void setName(string temp) { Full_Name = temp; }
    void setAge(int temp) { Age = temp; }
    string getName() { return Full_Name; }
    int getAge() { return Age; }
};

class Member : public Account
{
private:
    string Member_Role;

public:
};
int login()
{
    int choice, faculty_year;
    long long int contact_number;
    float cgpa;
    string name, password, inName, inPassword, registerName, registerPassword, registerRePassword, designation,
        std_id, status, email, gender, alumni_academic, occupation, department, job, alumni_graduation, faculty_id;

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
            ofstream g("registration.txt", std::ios_base::app); /* ofstream is the one for getting data from the file, and the file does not even have to exist.
                                                If it's ofstream, it'll take care of it for you. but be warned that if there is a file called "registration.txt"
                                                in the name folder as the .exe file, the contents will be deleted*/
            if (!g.is_open())                                   // if it's not open, then there is no such file with the given name inside
            {
                cout << "could not open file\n";
                exit(EXIT_FAILURE);
            }

            cout << "\n********** Account Register **********\n"
                 << "New Username: ";
            fflush(stdin);
            getline(cin, registerName);
            cout << "E-mail Address: ";
            fflush(stdin);
            getline(cin, email);
            cout << "Contact Number: ";
            cin >> contact_number;
            cout << "Gender: ";
            fflush(stdin);
            getline(cin, gender);
            //            cout<<"Society: ";
            //            getline(cin,society);
            cout << "Status: " << endl;
            cout << "Enter your number" << endl
                 << "1.Student\n"
                 << "2.Faculty\n"
                 << "3.Alumni\n";
            cin >> choice;
            if (choice == 1)
            {
                status = "Student";
            }
            else if (choice == 2)
            {
                status = "Faculty";
            }
            else if (choice == 3)
            {
                status = "Alumni";
            }

            if (status == "Student")
            {
                cout << "Student ID (e.g: 21K-XXXX): ";
                fflush(stdin);
                getline(cin, std_id);
                cout << "CGPA: ";
                cin >> cgpa;
                cout << "Department: ";
                fflush(stdin);
                getline(cin, department);
            }
            else if (status == "Faculty")
            {
                cout << "Faculty ID (e.g: 21K-XXXX): ";
                fflush(stdin);
                getline(cin, faculty_id);
                cout << "designation: ";
                fflush(stdin);
                getline(cin, designation);
                cout << "Workin since: (year)";
                cin >> faculty_year;
                cout << "Department: ";
                fflush(stdin);
                getline(cin, department);
            }
            else if (status == "Alumni")
            {
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
            }
            cout << "New Password: ";
            fflush(stdin);
            getline(cin, registerPassword);
            cout << "Re-enter Password: ";
            fflush(stdin);
            getline(cin, registerRePassword);
            if (registerPassword == registerRePassword)
            {
                g << registerName;
                g << '\n';
                g << registerPassword;
                g << '\n';
                g << contact_number;
                g << '\n';
                g << gender;
                g << '\n';
                g << status;
                g << '\n';
                if (status == "Student")
                    g << std_id << ',' << cgpa << ',' << department;

                else if (status == "Faculty")
                    g << faculty_id << ',' << designation << ',' << faculty_year << ',' << department;

                else if (status == "Alumni")
                    g << std_id << ',' << cgpa << ',' << alumni_graduation << ',' << alumni_academic << ',' << job;

                g << '\n';
                g << ';';
                g << '\n';
                g.close();
            }
            else
            {
                cout << "Password not matched.";
                // control back to re-enter password.
            }
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
