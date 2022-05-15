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

    void setDay(int temp) { day = temp; }
    void setMonth(int temp) { month = temp; }
    void setYear(int temp) { year = temp; }
    int getDay() { return day; }
    int getMonth() { return month; }
    int getYear() { return year; }
    void displaydate() { cout << setfill('0') << setw(2) << day << "/" << setfill('0') << setw(2) << month << "/" << setfill('0') << setw(4) << year << endl; }
	int CompareDate(date d1, date d2){
        if(d1.day == d2.day && d1.month == d2.month && d1.year == d2.year){
            return 1;
        }
        else if(d1.day > d2.day)
        {
            if(d1.month > d2.month){
                if(d1.year > d2.year){
                    return 2;
                }
                else if(d1.year < d2.year){
                    return 3;
                }
                else{
                	return 2;
				}
            }
            else if(d1.month < d2.month){
                if(d1.year > d2.year){
                    return 2;
                }
                else if(d1.year < d2.year){
                    return 3;
                }
                else{
                	return 3;
				}
            }
            else{
                if(d1.year > d2.year){
                    return 2;
                }
                else if(d1.year < d2.year){
                    return 3;
                }
                else{
                	return 2;
				}
            }
        }
        else if(d1.day < d2.day){
            if(d1.month > d2.month){
                if(d1.year > d2.year){
                    return 2;
                }
                else if(d1.year < d2.year){
                    return 3;
                }
            }
            else if(d1.month < d2.month){
                if(d1.year > d2.year){
                    return 2;
                }
                else if(d1.year < d2.year){
                    return 3;
                }
            }
            else{
                if(d1.year > d1.year){
                    return 2;
                }
                else if(d1.year < d2.year){
                    return 3;
                }
                else{
                	return 2;
				}
            }
        }
    }
};

date Currentdate()
{
    date currentdate;
    time_t t = time(NULL);
    tm *timePtr = localtime(&t);

    currentdate.setDay(timePtr->tm_mday);
    currentdate.setMonth((timePtr->tm_mon) + 1);
    currentdate.setYear((timePtr->tm_year) + 1900);

    return currentdate;
}
