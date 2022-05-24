class Events
{
private:
     string event_name;
     string event_description;
     date event_date;
     string event_status;

public:
     void set_event_name(string temp) { event_name = temp; }
     void set_event_description(string temp) { event_description = temp; }

     void get_event_data()
     {
          // cout << string(50, '~') << endl;
          // cout << "Enter Event Details\n";
          cout << "Enter Event Name : ";
          fflush(stdin);
          getline(cin, event_name);
          cout << "Enter Event Description : ";
          fflush(stdin);
          getline(cin, event_description);
          cout << "Enter Event Date\n";
          event_date.inputdate();
          // cout << string(50, '~') << endl;
     }
     string get_event_name() { return event_name; }
     // friend void visitor_menu();
     // friend void member_menu();
     friend void add_event_file(Events &eve);
     friend Events retrieve_events_file(string evename);
     friend void display_upcoming_events();
     friend void display_future_events();
     friend void display_ongoing_events();
     friend void display_past_events();
     void display_event_data()
     {
          // cout << string(50, '~') << endl;
          cout << "\nEvent Name: " << event_name
               << "\nEvent Description: " << event_description
               << "\nEvent Date: ";
          event_date.displaydate();
     }
     void determine_event_status()
     {
          date curr_date = current_date();
          int a = compare_date(curr_date, event_date);
          if (a == 1)
               event_status = "ongoing";
          else if (a == 2)
               event_status = "past";
          else if (a == 3)
               event_status = "future";
     }
};

void add_event_file(Events &eve)
{

     fstream f("events.csv", ios::app);
     if (!f.is_open())
     {
          cout << "could not open file\n";
          exit(EXIT_FAILURE);
     }
     else
     {
          f << eve.event_name << ","
            << eve.event_description << ","
            << eve.event_date.getDay() << ","
            << eve.event_date.getMonth() << ","
            << eve.event_date.getYear() << endl;
          f.close();
     }
};
Events retrieve_events_file(string evename)
{
     fstream f;
     f.open("events.csv", ios::in);

     Events eve;
     if (!f.is_open())
     {
          cout << "could not open file\n";
          exit(EXIT_FAILURE);
     }
     else
     {
          while (!f.eof())
          {
               string line;
               getline(f, line, ',');
               if (line.empty())
               {
                    eve.event_name = "";
                    eve.event_description = "";
                    eve.event_date.setDay(0);
                    eve.event_date.setMonth(0);
                    eve.event_date.setYear(0);
                    break;
               }
               eve.event_name = line;
               getline(f, line, ',');
               eve.event_description = line;
               getline(f, line, ',');
               int a = stoi(line);
               eve.event_date.setDay(a);
               getline(f, line, ',');
               int b = stoi(line);
               eve.event_date.setMonth(b);
               getline(f, line);
               int c = stoi(line);
               eve.event_date.setYear(c);
               if (eve.event_name == evename)
                    return eve;
          }
          cout << "No record found!" << endl;
     }
}

void display_upcoming_events()
{
     fstream f;
     f.open("events.csv", ios::in);

     Events eve;
     if (!f.is_open())
     {
          cout << "could not open file\n";
          exit(EXIT_FAILURE);
     }
     else
     {
          while (!f.eof())
          {
               string line;
               getline(f, line, ',');
               if (line.empty())
               {
                    break;
               }
               eve.event_name = line;
               getline(f, line, ',');
               eve.event_description = line;
               getline(f, line, ',');
               int a = stoi(line);
               eve.event_date.setDay(a);
               getline(f, line, ',');
               int b = stoi(line);
               eve.event_date.setMonth(b);
               getline(f, line);
               int c = stoi(line);
               eve.event_date.setYear(c);
               eve.determine_event_status();
               date curr = current_date();
               date sevendayslater = curr + 7;
               if (compare_date(eve.event_date, curr) <= 2 && compare_date(eve.event_date, sevendayslater) == 3)
                    eve.display_event_data();
          }
          f.close();
     }
}
void display_future_events()
{
     fstream f;
     f.open("events.csv", ios::in);
     bool flag = false;

     Events eve;
     if (!f.is_open())
     {
          cout << "could not open file\n";
          exit(EXIT_FAILURE);
     }
     else
     {
          while (!f.eof())
          {
               string line;
               getline(f, line, ',');
               if (line.empty())
               {
                    eve.event_name = "";
                    eve.event_description = "";
                    eve.event_date.setDay(0);
                    eve.event_date.setMonth(0);
                    eve.event_date.setYear(0);
                    break;
               }
               eve.event_name = line;
               getline(f, line, ',');
               eve.event_description = line;
               getline(f, line, ',');
               int a = stoi(line);
               eve.event_date.setDay(a);
               getline(f, line, ',');
               int b = stoi(line);
               eve.event_date.setMonth(b);
               getline(f, line);
               int c = stoi(line);
               eve.event_date.setYear(c);
               eve.determine_event_status();
               if (eve.event_status == "future")
               {
                    eve.display_event_data();
                    flag = true;
               }
          }
          if (flag == false)
               cout << "No Future Events" << endl;
          system("pause");
     }
}
void display_ongoing_events()
{
     fstream f;
     f.open("events.csv", ios::in);
     bool flag = false;

     Events eve;
     if (!f.is_open())
     {
          cout << "could not open file\n";
          exit(EXIT_FAILURE);
     }
     else
     {
          while (!f.eof())
          {
               string line;
               getline(f, line, ',');
               if (line.empty())
               {
                    eve.event_name = "";
                    eve.event_description = "";
                    eve.event_date.setDay(0);
                    eve.event_date.setMonth(0);
                    eve.event_date.setYear(0);
                    break;
               }
               eve.event_name = line;
               getline(f, line, ',');
               eve.event_description = line;
               getline(f, line, ',');
               int a = stoi(line);
               eve.event_date.setDay(a);
               getline(f, line, ',');
               int b = stoi(line);
               eve.event_date.setMonth(b);
               getline(f, line);
               int c = stoi(line);
               eve.event_date.setYear(c);
               eve.determine_event_status();
               if (eve.event_status == "ongoing")
               {
                    eve.display_event_data();
                    flag = true;
               }
          }
          if (flag == false)
               cout << "No Ongoing Events" << endl;
          system("pause");
     }
}
void display_past_events()
{
     fstream f;
     f.open("events.csv", ios::in);
     bool flag = false;

     Events eve;
     if (!f.is_open())
     {
          cout << "could not open file\n";
          exit(EXIT_FAILURE);
     }
     else
     {
          while (!f.eof())
          {
               string line;
               getline(f, line, ',');
               if (line.empty())
               {
                    eve.event_name = "";
                    eve.event_description = "";
                    eve.event_date.setDay(0);
                    eve.event_date.setMonth(0);
                    eve.event_date.setYear(0);
                    break;
               }
               eve.event_name = line;
               getline(f, line, ',');
               eve.event_description = line;
               getline(f, line, ',');
               int a = stoi(line);
               eve.event_date.setDay(a);
               getline(f, line, ',');
               int b = stoi(line);
               eve.event_date.setMonth(b);
               getline(f, line);
               int c = stoi(line);
               eve.event_date.setYear(c);
               eve.determine_event_status();
               if (eve.event_status == "past")
               {
                    eve.display_event_data();
                    flag = true;
               }
          }
          if (flag == false)
               cout << "No Past Events" << endl;
          system("pause");
     }
}