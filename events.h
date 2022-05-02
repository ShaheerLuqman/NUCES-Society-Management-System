using namespace std;
class Events
{
private:
     string Event_name;
     string Event_Description;
     date Start_date;
     // Time Start_time;
     date End_date;
     // Time End_time;
     string Event_Status; // past, Ongoing or Future. It will be determined not taken as input

public:
     void getEventData()
     {
          cout << string(50, '~') << endl
               << "Enter Event Details\n"
               << string(50, '~') << endl;
          cout << "Enter Event Name : ";
          fflush(stdin);
          getline(cin, Event_name);
          cout << "Enter Event Description : ";
          fflush(stdin);
          getline(cin, Event_Description);
          cout << string(50, '~') << endl;
          cout << "Enter Event Starting Date\n";
          cout << string(50, '~') << endl;
          Start_date.inputdate();
          cout << string(50, '~') << endl;
          // cout << "Enter Event Starting Time\n";
          // cout << string(50, '~') << endl;
          // Start_time.inputTime();
          // cout << string(50, '~') << endl;
          // cout << "Enter Event Ending Date\n";
          // cout << string(50, '~') << endl;
          // End_date.inputdate();
          // cout << string(50, '~') << endl;
          // cout << "Enter Event Ending Time\n";
          // cout << string(50, '~') << endl;
          // End_time.inputTime();
          // cout << string(50, '~') << endl;
     }

     void DisplayEventData()
     {
          cout << "Event Name : " << Event_name << endl
               << "Event Description :" << Event_Description << endl;
          cout << "Event Start Date :";
          Start_date.displaydate();
          cout << endl;
          //      << "Event End Date : ";
          // End_date.displaydate();
          // cout << endl;
          //      << "Event Start Time : ";
          // Start_time.DisplayTime();
          // cout << endl
          //      << "Event End Time : ";
          // End_time.DisplayTime();
          // cout << endl;
     }
};