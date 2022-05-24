class Application
{
private:
    Student std;
    string society_name;
    int past_experience;     // number of semesters in which applicant worked in societies.
    int communication_skill; // 1 to 5
    int management_skill;    // 1 to 5
    int interpersonal_skill; // 1 to 5

public:
    void set_society_name(string temp) { society_name = temp; }
    void set_past_experience(int temp) { past_experience = temp; }
    void set_communication_skill(int temp) { communication_skill = temp; }
    void set_management_skill(int temp) { management_skill = temp; }
    void set_interpersonal_skill(int temp) { interpersonal_skill = temp; }
    Application(Student &std) : std(std){};
    void get_skills()
    {
        cout << "\nRate your Skills"
             << "\n   5. Very Good"
             << "\n   4. Good"
             << "\n   3. Average"
             << "\n   2. Not Good"
             << "\n   1. Needs Work";
        while (1)
        {
            cout << "\nCommunication Skill: ";
            cin >> communication_skill;
            if (communication_skill > 0 && communication_skill < 6)
                break;
            cout << "Enter value from 1 to 5" << endl;
        }
        while (1)
        {
            cout << "\nManagement Skill: ";
            cin >> management_skill;
            if (management_skill > 0 && management_skill < 6)
                break;
            cout << "Enter value from 1 to 5" << endl;
        }
        while (1)
        {
            cout << "\nInterpersonal Skill: ";
            cin >> interpersonal_skill;
            if (interpersonal_skill > 0 && interpersonal_skill < 6)
                break;
            cout << "Enter value from 1 to 5" << endl;
        }
    }
    void society_applied()
    {
        int ch;
        fstream f("society.csv", ios::in);
        if (!f.is_open() && f.fail())
        {
            cout << "\nNo record of society found\n";
            f.close();
        }
        else
        {
            cout << "\nPress\n";
            int i = 0;
            string temp;
            while (!f.eof())
            {
                getline(f, temp);
                if (temp.empty())
                    break;

                cout << "   " << i + 1 << ". " << temp << endl;
                i++;
            }
            f.close();
            f.open("society.csv", ios::in);
            cout << "Your Input: ";
            cin >> ch;
            for (int i = 0; i < ch; i++)
            {
                getline(f, temp);
            }
            f.close();
            society_name = temp;
        }
    }
    void apply_to_society()
    {
        society_applied();
        while (1)
        {
            cout << "\nHow many semesters have you worked in any of the Society: ";
            cin >> past_experience;
            if (past_experience > 0 && past_experience < 9)
                break;
            cout << "Enter value from 1 to 8" << endl;
        }
        get_skills();
    }
    void display_application()
    {
        std.DisplayAccountData();
        cout << "Society Applying to: " << society_name << endl
             << "Past Experience (Number of Semesters): " << past_experience << endl
             << "Communications Skill Rating (out of 5): " << communication_skill << endl
             << "Management Skills Rating (out of 5): " << communication_skill << endl
             << "Interpersonal Skills Rating (out of 5): " << communication_skill << endl;
    }
    void add_application_file()
    {
        ofstream f("Applications.csv", ios::app);
        if (!f.is_open())
        {
            cout << "could not open file\n";
            exit(EXIT_FAILURE);
        }
        else
        {
            f << society_name << ","
              << std.getUserName() << ","
              << std.getPassword() << ","
              << std.getName() << ","
              << std.getEmail() << ","
              << std.getID() << ","
              << std.getCGPA() << ","
              << past_experience << ","
              << communication_skill << ","
              << management_skill << ","
              << interpersonal_skill << endl;
            f.close();
        }
    };
};
Application retrieve_application_file()
{
    ifstream f("Applications.csv", ios::in);
    if (!f.is_open())
    {
        cout << "could not open file\n";
        exit(EXIT_FAILURE);
    }
    else
    {
        string soc;
        getline(f, soc, ',');
        Student std;
        string line;
        getline(f, line, ','); // username
        std.setUserName(line);
        getline(f, line, ','); // pass
        std.setPassword(line);
        getline(f, line, ','); // name
        std.setName(line);
        getline(f, line, ','); // email
        std.setEmail(line);
        getline(f, line, ','); // id
        std.setID(line);
        getline(f, line, ','); // cgpa
        std.setCGPA(line);
        Application temp(std);
        temp.set_society_name(soc);
        int a;
        getline(f, line, ',');
        a = stoi(line);
        temp.set_past_experience(a);
        getline(f, line, ',');
        a = stoi(line);
        temp.set_communication_skill(a);
        getline(f, line, ',');
        a = stoi(line);
        temp.set_management_skill(a);
        getline(f, line, ',');
        a = stoi(line);
        temp.set_interpersonal_skill(a);
        f.close();
        return temp;
    }
}
void display_all_applications()
{
    ifstream f("Applications.csv", ios::in);
    if (!f.is_open())
    {
        cout << "could not open file\n";
        exit(EXIT_FAILURE);
    }
    else
    {
        while (!f.eof())
        {
            string soc;
            getline(f, soc, ',');
            if (soc.empty())
                break;
            Student std;
            string line;
            getline(f, line, ','); // username
            std.setUserName(line);
            getline(f, line, ','); // pass
            std.setPassword(line);
            getline(f, line, ','); // name
            std.setName(line);
            getline(f, line, ','); // email
            std.setEmail(line);
            getline(f, line, ','); // id
            std.setID(line);
            getline(f, line, ','); // cgpa
            std.setCGPA(line);
            Application temp(std);
            temp.set_society_name(soc);
            int a;
            getline(f, line, ',');
            a = stoi(line);
            temp.set_past_experience(a);
            getline(f, line, ',');
            a = stoi(line);
            temp.set_communication_skill(a);
            getline(f, line, ',');
            a = stoi(line);
            temp.set_management_skill(a);
            getline(f, line);
            a = stoi(line);
            temp.set_interpersonal_skill(a);

            temp.display_application();
            cout << endl;
        }
    }
    system("pause");
    f.close();
}
void display_all_applications(string sname)
{
    ifstream f("Applications.csv", ios::in);
    if (!f.is_open())
    {
        cout << "could not open file\n";
        exit(EXIT_FAILURE);
    }
    else
    {
        while (!f.eof())
        {
            string soc;
            getline(f, soc, ',');
            if (soc.empty())
                break;
            Student std;
            string line;
            getline(f, line, ','); // username
            std.setUserName(line);
            getline(f, line, ','); // pass
            std.setPassword(line);
            getline(f, line, ','); // name
            std.setName(line);
            getline(f, line, ','); // email
            std.setEmail(line);
            getline(f, line, ','); // id
            std.setID(line);
            getline(f, line, ','); // cgpa
            std.setCGPA(line);
            Application temp(std);
            temp.set_society_name(soc);
            int a;
            getline(f, line, ',');
            a = stoi(line);
            temp.set_past_experience(a);
            getline(f, line, ',');
            a = stoi(line);
            temp.set_communication_skill(a);
            getline(f, line, ',');
            a = stoi(line);
            temp.set_management_skill(a);
            getline(f, line);
            a = stoi(line);
            temp.set_interpersonal_skill(a);
            if (soc == sname)
                temp.display_application();
            cout << endl;
        }
    }
    system("pause");
    f.close();
}