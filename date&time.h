#include <ctime>

class Date
{
private:
    int day;
    int month;
    int year;

public:
    void inputDate()
    {
        int flag = 0;
        while (flag == 0)
        {
            int d, m, y;
            cout << "Enter day of your Date: ";
            cin >> d;

            cout << "Enter month of your Date: ";
            cin >> m;

            cout << "Enter year of your Date: ";
            cin >> y;

            if (1000 <= y <= 3000)
            {
                if ((m == 1 || m == 3 || m == 5 || m == 7 || m == 8 || m == 10 || m == 12) && d > 0 && d <= 31)
                    flag = 1;
                else if (m == 4 || m == 6 || m == 9 || m == 11 && d > 0 && d <= 30)
                    flag = 1;
                else if (m == 2)
                {
                    if ((y % 400 == 0 || (y % 100 != 0 && y % 4 == 0)) && d > 0 && d <= 29)
                        flag = 1;
                    else if (d > 0 && d <= 28)
                        flag = 1;
                    else
                        flag = 0;
                }
                else
                    flag = 0;
            }
            else
                flag = 0;

            if (flag == 1)
            {
                setDay(d);
                setMonth(m);
                setYear(y);
            }
            else
            {
                cout << "Wrong date Entered!\n";
            }
        }
    }

    void setDay(int temp) { day = temp; }
    void setMonth(int temp) { month = temp; }
    void setYear(int temp) { year = temp; }
    int getDay() { return day; }
    int getMonth() { return month; }
    int getYear() { return year; }
    void DisplayDate()
    {
        cout << setfill('0') << setw(2) << day << "/" << setfill('0') << setw(2) << month << "/" << setfill('0') << setw(4) << year;
    }
};

class Time
{
private:
    int hr;
    int min;

public:
    void inputTime()
    {
        cout << "Enter Time in 24 hour format\n"
             << "Enter hours: ";
        cin >> hr;
        cout << "Enter minutes: ";
        cin >> min;
    }
    void setHour(int temp) { hr = temp; }
    void setMinutes(int temp) { min = temp; }
    int getHour() { return hr; }
    int getMinutes() { return min; }
    void DisplayTime() { cout << setfill('0') << setw(2) << hr << ":" << setfill('0') << setw(2) << min; };
};

void CurrentDateTime()
{
    Time currentTime;
    Date currentDate;
    time_t t = time(NULL);
    tm *timePtr = localtime(&t);
    currentTime.setHour(timePtr->tm_hour);
    currentTime.setMinutes(timePtr->tm_min);

    currentDate.setDay(timePtr->tm_mday);
    currentDate.setMonth((timePtr->tm_mon) + 1);
    currentDate.setYear((timePtr->tm_year) + 1900);

    cout << "Date     ";
    currentDate.DisplayDate();
    cout << endl;
    cout << "Time     ";
    currentTime.DisplayTime();
    cout << endl;
}

/*
#include <iostream>
#include <cmath>
#include <ctime>
using namespace std;

int main()
{

    time_t t = time(NULL);
    tm *timePtr = localtime(&t);

    cout << "seconds= " << (timePtr->tm_sec) << endl;
    cout << "minutes = " << (timePtr->tm_min) << endl;
    cout << "hours = " << (timePtr->tm_hour) << endl;
    cout << "day of month = " << (timePtr->tm_mday) << endl;
    cout << "month of year = " << (timePtr->tm_mon) + 1 << endl;
    cout << "year = " << (timePtr->tm_year) + 1900 << endl;
    cout << "weekday = " << (timePtr->tm_wday) << endl;
    cout << "day of year = " << (timePtr->tm_yday) << endl;
    cout << "daylight savings = " << (timePtr->tm_isdst) << endl;
    cout << endl;
    cout << endl;

    cout << "Date     " << (timePtr->tm_mday) << "/" << (timePtr->tm_mon) + 1 << "/" << (timePtr->tm_year) + 1900 << endl;
    cout << "Time     " << (timePtr->tm_hour) << ":" << (timePtr->tm_min) << ":" << (timePtr->tm_sec) << endl;
    return 0;
}
*/