class Events
{
private:
     string Event_name;
     string Event_Description;
     Date Start_date;
     Time Start_time;
     Date End_date;
     Time End_time;
     string Event_Status; // past, Ongoing or Future. It will be determined not taken as input

public:
     void getEventData()
     {
          cout << "-----------------------------\n"
               << "Enter Event Details\n"
               << "-----------------------------\n";
          cout << "Enter Event Name : ";
          cin >> Event_name;
          cout << "Enter Event Description : ";
          cin >> Event_Description;
          cout << "-----------------------------\n";
          cout << "Enter Event Starting Date\n";
          cout << "-----------------------------\n";
          Start_date.inputDate();
          cout << "-----------------------------\n";
          cout << "Enter Event Starting Time\n";
          cout << "-----------------------------\n";
          Start_time.inputTime();
          cout << "-----------------------------\n";
          cout << "Enter Event Ending Date\n";
          cout << "-----------------------------\n";
          End_date.inputDate();
          cout << "-----------------------------\n";
          cout << "Enter Event Ending Time\n";
          cout << "-----------------------------\n";
          End_time.inputTime();
          cout << "-----------------------------\n";
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
          cout << endl
               << "Event Start Time : ";
          Start_time.DisplayTime();
          cout << endl
               << "Event End Time : ";
          End_time.DisplayTime();
          cout << endl;
     }
};