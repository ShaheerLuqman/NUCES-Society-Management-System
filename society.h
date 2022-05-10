#include <algorithm>
#include <cstring>
#include <string.h>
#include <bits/stdc++.h>
#define Max_number_of_members 5
#define Max_number_of_events 5

using namespace std;
class society
{
protected:
    string society_name, file_name;
    string society_description;
    int number_of_events = 0, number_of_members = 0;
    string event_names[Max_number_of_events];
    string member_names[Max_number_of_members];

public:
    string get_file_name() { return file_name; };
    string get_society_name() { return society_name; };
    void set_society_name(string n) { society_name = n; };
    string get_society_description() { return society_description; };
    void set_society_description(string n) { society_description = n; };

    int get_number_of_events() { return number_of_events; };
    void set_number_of_events(int n) { number_of_events = n; };

    void NewSociety()
    {
        ofstream fileo;
        ifstream filei;
        string fname;

        cout << "\nEnter Society name: ";
        fflush(stdin);
        getline(cin, society_name);

        cout << "\nEnter Society Description: ";
        fflush(stdin);
        getline(cin, society_description);

        file_name = "society_" + society_name + ".csv";
        fname = file_name;
        for (int i = 0; i < fname.length(); i++)
        {
            if (fname[i] == ' ')
                fname[i] = '_';
        }

        cout << fname << endl;

        fileo.open(fname.c_str());
        fileo << society_name << endl
              << society_description << endl
              << number_of_events << endl;
        fileo.close();
    }

    void display_society()
    {
        cout << "Society Name: " << society_name << endl;
        cout << "Society Description : " << society_description << endl;
        cout << "Number Of Events: " << number_of_events << endl;
        // for (int i = 0; i < number_of_events; i++)
        // {
        //     events[i].DisplayEventData();
        // }
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
    void add_new_member() {}
};

society read_society()
{
    society temp;
    ifstream filei;
    string num_of_events, name, society_name, society_description;
    cout << "Enter society name:";
    cin >> name;
    string fname = "society_" + name + ".csv";
    transform(fname.begin(), fname.end(), fname.begin(), ::tolower);
    cout << fname << endl;
    filei.open(fname.c_str());
    if (!filei.is_open() && filei.fail())
    {
        cout << "\nNo record of society found\n";
        filei.close();
    }
    else
    {
        getline(filei, society_name);
        temp.set_society_name(society_name);
        getline(filei, society_description);
        temp.set_society_description(society_description);
        getline(filei, num_of_events);
        temp.set_number_of_events(stoi(num_of_events));
    }
    return temp;
};