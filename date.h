#include <ctime>

class date
{
private:
    int day;
    int month;
    int year;

public:
    void inputdate()
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
                    if ((y % 4 == 0) && d > 0 && d <= 29)
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
                cout << "Wrong date Entered!\n";
        }
    }
    int endOfMonth()
    {
        if ((month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12))
            return 31;
        else if (month == 4 || month == 6 || month == 9 || month == 11)
            return 30;
        else if (month == 2)
        {
            if (year % 4 == 0)
                return 29;
            else
                return 28;
        }
    }

    void setDay(int temp) { day = temp; }
    void setMonth(int temp) { month = temp; }
    void setYear(int temp) { year = temp; }
    int getDay() { return day; }
    int getMonth() { return month; }
    int getYear() { return year; }
    void displaydate() { cout << setfill('0') << setw(2) << day << "/" << setfill('0') << setw(2) << month << "/" << setfill('0') << setw(4) << year << endl; }
};

int compare_date(date &d1, date &d2)
{
    if (d1.getDay() == d2.getDay() && d1.getMonth() == d2.getMonth() && d1.getYear() == d2.getYear())
        return 1;
    else if (d1.getYear() > d2.getYear())
        return 2;
    else if (d1.getYear() < d2.getYear())
        return 3;
    else if (d1.getYear() == d2.getYear())
    {
        if (d1.getMonth() > d2.getMonth())
            return 2;
        else if (d1.getMonth() < d2.getMonth())
            return 3;
        else if (d1.getMonth() == d2.getMonth())
        {
            if (d1.getDay() > d2.getDay())
                return 2;
            else if (d1.getDay() < d2.getDay())
                return 3;
        }
    }
}

date current_date()
{
    date currentdate;
    time_t t = time(NULL);
    tm *timePtr = localtime(&t);

    currentdate.setDay(timePtr->tm_mday);
    currentdate.setMonth((timePtr->tm_mon) + 1);
    currentdate.setYear((timePtr->tm_year) + 1900);

    return currentdate;
}
date operator+(const date &a, int b)
{
    date myDate = a;
    int temp;

    myDate.setDay(myDate.getDay() + b);

    while (1)
    {
        if (myDate.getDay() > myDate.endOfMonth())
        {
            myDate.setDay(myDate.getDay() - myDate.endOfMonth());
            myDate.setMonth(myDate.getMonth() + 1);

            if (myDate.getMonth() > 12)
            {
                myDate.setMonth(1);
                myDate.setYear(myDate.getYear() + 1);
            }
        }
        else
            break;
    }
    return myDate;
}