using namespace std;

class Account
{
protected:
    string Full_Name, username, password, status, email, id; // e.g student, faculty, head, society head, director, visitor

public:
    void setName(string temp) { Full_Name = temp; }
    string getUserName() { return username; }
    string getPassword() { return password; }
    // void virtual abstract_class() = 0;

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
                break;
            else
                cout << "Password not matched." << endl;
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