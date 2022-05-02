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

        fname = "society_" + society_name + ".csv";
        for (int i = 0; i < fname.length(); i++)
        {
            if (fname[i] == ' ')
                fname[i] = '_';
        }

        cout << fname << endl;

        fileo.open(fname.c_str());
        fileo << society_name << ", "
              << society_description << endl
              << number_of_events << endl;
        fileo.close();
    };
};