#include <algorithm>
#include <cstring>

using namespace std;
class Society
{
private:
    string Society_Name;
    string Society_Description;
    int Number_Of_Events;
    Events *events;
    string Members[25][5]; // array of member details   Name    ID      email

public:
    void NewSociety()
    {
        // ofstream fileo;
        // ifstream filei;
        string fname;

        cout << "\nEnter Society name:";
        fflush(stdin);
        getline(cin, Society_Name);

        cout << "\nEnter Society Description:";
        fflush(stdin);
        getline(cin, Society_Description);

        cout << "\nEnter Number of Events:";
        cin >> Number_Of_Events;

        fname = "society_" + Society_Name + ".txt";
        for (int i = 0; i < fname.length(); i++)
        {
            if (fname[i] == ' ')
                fname[i] = '_';
        }

        // fname.replace(fname.begin(), fname.end(), ' ', '_'); // replace all 'x' to 'y'
        // cout << fname << endl;

        // fileo.open(fname.c_str());
        // fileo << usn << endl
        //       << name << endl
        //       << psd << endl;
    };
};