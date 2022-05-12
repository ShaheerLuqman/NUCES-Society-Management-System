using namespace std;
class Events
{
private:
     string event_name;
     string event_description;
     date event_date;
     string event_status; // past, Ongoing or Future. It will be determined not taken as input

public:
     void getEventData()
     {
          cout << string(50, '~') << endl;
          cout << "Enter Event Details\n";

          cout << "Enter Event Name : ";
          fflush(stdin);
          getline(cin, event_name);
          cout << "Enter Event Description : ";
          fflush(stdin);
          getline(cin, event_description);
          cout << "Enter Event Date\n";
          event_date.inputdate();
          cout << string(50, '~') << endl;
     }

     void DisplayEventData()
     {
          cout << string(50, '~') << endl;
          cout << "Event Name : " << event_name
               << "\nEvent Description :" << event_description
               << "\nEvent Date :";
          event_date.displaydate();
     }

     void determine_event_status()
     {
          // if current
          //      time >
     }
};