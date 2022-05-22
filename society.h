#include <algorithm>
#define Max_number_of_members 5
#define Max_number_of_events 5

using namespace std;

/*
New society
add event to society
add member to society
create new event
*/

class society
{
protected:
    string society_name;
    string society_description;
    int number_of_events = 0, number_of_members = 0;
    string event_names[Max_number_of_events];
    string member_names[Max_number_of_members][3];

public:
    string get_society_name() { return society_name; };
    void set_society_name(string n) { society_name = n; };
    string get_society_description() { return society_description; };
    void set_society_description(string n) { society_description = n; };

    int get_number_of_events() { return number_of_events; };
    // void set_number_of_events(int n) { number_of_events = n; };

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
             << "\n\nEvents: ";
        for (int i = 0; i < number_of_events; i++)
            cout << "\t" << event_names[i] << endl;
        cout << "\n\nMembers: ";
        for (int i = 0; i < number_of_members; i++)
            cout << "\t" << member_names[i] << endl;
    }
    void add_new_event()
    {
        number_of_events++;
        string name;
        cout << "Enter Event Name: ";
        cin >> name;
        event_names[number_of_events - 1] = name;
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

// void add_society_account_file(society &soc)
// {
//     string file_name = "society_" + soc.get_society_name() + ".csv";
//     transform(file_name.begin(), file_name.end(), file_name.begin(), ::tolower);

//     for (int i = 0; i < file_name.length(); i++)
//     {
//         if (file_name[i] == ' ')
//             file_name[i] = '_';
//     }
//     fstream f(file_name, ios::out);
//     if (!f.is_open())
//     {
//         cout << "could not open file\n";
//         exit(EXIT_FAILURE);
//     }
//     else
//     {
//         // f << std.getUserName() << "," << std.getPassword() << "," << std.getName() << "," << std.getEmail() << "," << std.getID() << "," << std.getCGPA() << endl;
//         f.close();
//     }
// };

// society read_society()
// {
//     society temp;
//     fstream f;
//     string num_of_events, name, society_name, society_description;
//     cout << "Enter society name:";
//     cin >> name;
//     string fname = "society_" + name + ".csv";
//     transform(fname.begin(), fname.end(), fname.begin(), ::tolower);
//     cout << fname << endl;
//     f.open(fname.c_str());
//     if (!f.is_open() && f.fail())
//     {
//         cout << "\nNo record of society found\n";
//         f.close();
//     }
//     else
//     {
//         getline(f, society_name);
//         temp.set_society_name(society_name);
//         getline(f, society_description);
//         temp.set_society_description(society_description);
//         getline(f, num_of_events);
//         temp.set_number_of_events(stoi(num_of_events));
//     }
//     return temp;
// };