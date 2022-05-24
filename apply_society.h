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
};