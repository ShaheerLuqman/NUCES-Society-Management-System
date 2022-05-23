#include <algorithm>
#define Max_number_of_members 20
#define Max_number_of_events 20

/*
create new event
*/

class society
{
protected:
    string society_name;
    string society_description;
    int number_of_events = 0, number_of_members = 0;

public:
    string event_names[Max_number_of_events];
    string member_names[Max_number_of_members][3];

    string get_society_name() { return society_name; };
    void set_society_name(string n) { society_name = n; };
    string get_society_description() { return society_description; };
    void set_society_description(string n) { society_description = n; };
    void set_number_of_events(int temp) { number_of_events = temp; };
    void set_number_of_members(int temp) { number_of_members = temp; };
    int get_number_of_events() { return number_of_events; };
    int get_number_of_members() { return number_of_members; };

    void NewSociety()
    {
        cout << "\nEnter Society name: ";
        fflush(stdin);
        getline(cin, society_name);

        cout << "\nEnter Society Description: ";
        fflush(stdin);
        getline(cin, society_description);
    }

    void display_society()
    {
        cout << "Society Name: " << society_name
             << "\nSociety Description : " << society_description
             << "\nNumber Of Events: " << number_of_events
             << "\nNumber Of Members: " << number_of_members
             << "\n\nEvents: \n";
        for (int i = 0; i < number_of_events; i++)
            cout << "\t" << event_names[i] << endl;
        cout << "Members:" << endl;
        for (int i = 0; i < number_of_members; i++)
            cout << member_names[i][0] << "\t" << member_names[i][1] << "\t" << member_names[i][2] << endl;
    }
    void add_new_event()
    {
        number_of_events++;
        Events eve;
        eve.get_event_data();
        add_event_file(eve);
        event_names[number_of_events - 1] = eve.get_event_name();
    }
    void display_event_names()
    {
        for (int i = 0; i < number_of_events; i++)
            cout << event_names[i] << endl;
    }
    void add_new_member()
    {
        number_of_members++;
        string temp;
        cout << "Enter Member Name: ";
        fflush(stdin);
        getline(cin, temp);
        member_names[number_of_members - 1][0] = temp;

        cout << "Enter Member Role: ";
        fflush(stdin);
        getline(cin, temp);
        member_names[number_of_members - 1][1] = temp;

        cout << "Enter Member ID: ";
        fflush(stdin);
        getline(cin, temp);
        member_names[number_of_members - 1][2] = temp;
    }
};

void add_society_account_file(society &soc)
{
    string file_name = "society_" + soc.get_society_name() + ".csv";
    transform(file_name.begin(), file_name.end(), file_name.begin(), ::tolower);

    for (int i = 0; i < file_name.length(); i++)
    {
        if (file_name[i] == ' ')
            file_name[i] = '_';
    }
    fstream f(file_name, ios::out);
    if (!f.is_open())
    {
        cout << "could not open file\n";
        exit(EXIT_FAILURE);
    }
    else
    {
        f << soc.get_society_name() << endl
          << soc.get_society_description() << endl
          << soc.get_number_of_events() << endl
          << soc.get_number_of_members() << endl;
        for (int i = 0; i < soc.get_number_of_events(); i++)
            f << soc.event_names[i] << ',';
        if (soc.get_number_of_events() == 1)
            f << endl;
        for (int i = 0; i < soc.get_number_of_members(); i++)
            f << soc.member_names[i][0] << ',' << soc.member_names[i][1] << ',' << soc.member_names[i][2] << endl;
        f.close();
    }
};

society retrieve_society_account_file(string fname)
{
    fstream f;
    society temp;
    string line;
    string file_name = "society_" + fname + ".csv";
    transform(file_name.begin(), file_name.end(), file_name.begin(), ::tolower);

    for (int i = 0; i < file_name.length(); i++)
    {
        if (file_name[i] == ' ')
            file_name[i] = '_';
    }

    f.open(file_name);
    if (!f.is_open() && f.fail())
    {
        cout << "\nNo record of society found\n";
        f.close();
    }
    else
    {
        getline(f, line);
        temp.set_society_name(line);
        getline(f, line);
        temp.set_society_description(line);
        getline(f, line);
        temp.set_number_of_events(stoi(line));
        getline(f, line);
        temp.set_number_of_members(stoi(line));
        for (int i = 0; i < temp.get_number_of_events(); i++)
        {
            getline(f, line, ',');
            temp.event_names[i] = line;
        }

        for (int i = 0; i < temp.get_number_of_members(); i++)
        {
            getline(f, line, ',');
            temp.member_names[i][0] = line;
            getline(f, line, ',');
            temp.member_names[i][1] = line;
            getline(f, line);
            temp.member_names[i][2] = line;
        }
    }
    return temp;
};
void society_menu(society t)
{
    int choice;
    system("cls");
    while (1)
    {
        cout << "Welcome! " << t.get_society_name();
        cout << "\nPress\n"
             << "   1. View Society Details\n"
             << "   2. Add Member\n"
             << "   3. Add Events\n"
             << "   0. Back\n"
             << "Your Input: ";
        cin >> choice;
        if (choice == 0)
        {
            return;
        }
        else if (choice == 1)
        {
            t.display_society();
        }
        else if (choice == 2)
        {
            t.add_new_member();
            add_society_account_file(t);
        }
        else if (choice == 3)
        {
            t.add_new_event();
            add_society_account_file(t);
        }
    }
};