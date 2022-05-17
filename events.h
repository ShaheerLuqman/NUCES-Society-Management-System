using namespace std;
class Events
{
private:
     string event_name;
     string event_description;
     date event_date;
     string event_status;

public:
     void get_event_data()
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

     void display_event_data()
     {
          cout << string(50, '~') << endl;
          cout << "Event Name : " << event_name
               << "\nEvent Description :" << event_description
               << "\nEvent Date :";
          event_date.displaydate();
     }

     void determine_event_status()
     {
          date curr_date = current_date();
          int temp = compare_date(curr_date, event_date);
          if (temp == 1)
               event_status = "ongoing";
          else if (temp == 2)
               event_status = "past";
          else if (temp == 3)
               event_status = "future";
     }
};