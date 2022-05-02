using namespace std;
class Events
{
private:
     string Event_name;
     string Event_Description;
     Date Start_date;
     // Time Start_time;
     Date End_date;
     // Time End_time;
     string Event_Status; // past, Ongoing or Future. It will be determined not taken as input

public:
     void getEventData()
     {
          cout << string(50, '~') << endl
               << "Enter Event Details\n"
               << string(50, '~') << endl;
          cout << "Enter Event Name : ";
          cin >> Event_name;
          cout << "Enter Event Description : ";
          cin >> Event_Description;
          printLine();
          cout << "Enter Event Starting Date\n";
          printLine();
          Start_date.inputDate();
          printLine();
          // cout << "Enter Event Starting Time\n";
          // printLine();
          // Start_time.inputTime();
          // printLine();
          cout << "Enter Event Ending Date\n";
          printLine();
          End_date.inputDate();
          printLine();
          // cout << "Enter Event Ending Time\n";
          // printLine();
          // End_time.inputTime();
          // printLine();
     }

     void DisplayEventData()
     {
          cout << "Event Name : " << Event_name << endl
               << "Event Description :" << Event_Description << endl;
          cout << "Event Start Date :";
          Start_date.DisplayDate();
          cout << endl
               << "Event End Date : ";
          End_date.DisplayDate();
          cout << endl;
          //      << "Event Start Time : ";
          // Start_time.DisplayTime();
          // cout << endl
          //      << "Event End Time : ";
          // End_time.DisplayTime();
          // cout << endl;
     }
};