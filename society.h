#include <algorithm>
#include <cstring>

using namespace std;
class society
{
private:
    string society_name, file_name;
    string society_description;
    int number_of_events = 0, number_of_members = 0;
    Events *events;
    string members[25][5]; // array of member details   Name    ID      email

public:
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
    };

    void read_society()
    {
        ifstream filei;
        string num_of_events, name;
        cout << "Enter society name:";
        cin >> name;
        string fname = file_name;

        filei.open(fname.c_str());
        if (!filei.is_open() && filei.fail())
        {
            cout << "\nYou are not registered, please register before logging in.\n";
            filei.close();
        }
        getline(filei, society_name);
        getline(filei, society_description);
        getline(filei, num_of_events);
        number_of_events = stoi(num_of_events);
        cout << endl;
    };

    void display_society(){

    };
};
