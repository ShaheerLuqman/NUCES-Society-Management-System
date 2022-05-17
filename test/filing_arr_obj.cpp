#include <iostream>
#include <fstream>

using namespace std;

const int size = 3;
int events_added = 0;
class A
{
private:
    char name[40];
    int age;
    float height;
    char gender;
    char newline_chr;

public:
    void putdata()
    {
        cout << "Enter the name : ";
        cin.getline(name, 40);
        cout << "Enter the age : ";
        cin >> age;
        cout << "Enter the height : ";
        cin >> height;
        cout << "Enter the gender : ";
        cin >> gender;

        // This one captures the enter key(newline character) pressed after entering the gender.
        fflush(stdin);
        // cin.get(newline_chr);
        events_added++;
    };

    void getdata()
    {
        cout << "The name is : " << name << "\n";
        cout << "The age is : " << age << "\n";
        cout << "The height is : " << height << "\n";
        cout << "The gender is : " << gender << "\n";
    };
};

int main()
{
    ofstream out_event_filing;
    // out_event_filing.open("events.csv", ios::in);
    // out_event_filing << events_added << endl;
    // out_event_filing.close();

    out_event_filing.open("events.txt", ios::app);
    A ob1[size];
    for (int i = 0; i < size; i++)
        ob1[i].putdata();

    cout << events_added << endl;

    // Calling the write() function to write an array of objects to a file in a binary form.
    out_event_filing.write((char *)&ob1, sizeof(ob1));
    out_event_filing.seekp(0);
    out_event_filing << events_added << endl;

    cout << "Congrats! Your array of objects is successfully written to the file \n";
    out_event_filing.close();

    ifstream in_event_filing;
    in_event_filing.open("events.txt", ios::in);
    A ob2[size];

    cout << "\nReading an array of objects from a file : \n";
    in_event_filing.read((char *)&ob2, sizeof(ob2));

    for (int i = 0; i < size; i++)
        ob2[i].getdata();

    in_event_filing.close();
    return 0;
}
