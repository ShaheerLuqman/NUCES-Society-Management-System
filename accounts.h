using namespace std;

class Account
{
protected:
    string Full_Name, username, password, email, id; // e.g student, faculty, head, society head, director, visitor

public:
    void setName(string temp) { Full_Name = temp; }
    string getName() { return Full_Name; }
    void setUserName(string temp) { username = temp; }
    string getUserName() { return username; }
    void setPassword(string temp) { password = temp; }
    string getPassword() { return password; }
    void setEmail(string temp) { email = temp; }
    string getEmail() { return email; }
    void setID(string temp) { id = temp; }
    string getID() { return id; }
    void virtual abstract_class() = 0;

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
        cout << "\nName: " << Full_Name
             << "\nE-mail Address: " << email;
    };
};

class Student : public Account
{
private:
    string cgpa;

public:
    string getCGPA() { return cgpa; }
    void setCGPA(string temp) { cgpa = temp; }
    void virtual abstract_class(){};
    void Account_register()
    {
        Account::Account_register();
        cout << "Student ID (e.g: 21K-XXXX): ";
        fflush(stdin);
        getline(cin, id);
        cout << "CGPA: ";
        fflush(stdin);
        getline(cin, cgpa);
    };
    void DisplayAccountData()
    {
        Account::DisplayAccountData();
        cout << "\nStudent ID: " << id
             << "\nCGPA: " << cgpa << endl;
    };
};
class Faculty : public Account
{
private:
    string designation;

public:
    string getDesignation() { return designation; }
    void setDesignation(string temp) { designation = temp; }
    void virtual abstract_class(){};
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
             << "\nDesignation: " << designation << endl;
    };
};