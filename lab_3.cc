#include <iostream>
#include <string>
#include <stdexcept>
#include <iomanip>

using namespace std;

class Calendar
{
private:
    int day;
    int month;
    int year;
    string event;

    bool isValidDate(int d, int m, int y) const
    {
        if (y < 1 || m < 1 || m > 12 || d < 1) return false;
        int daysInMonth[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
        if (isLeapYear(y)) daysInMonth[1] = 29;
        return d <= daysInMonth[m - 1];
    }

    bool isLeapYear(int y) const
    {
        return (y % 4 == 0 && y % 100 != 0) || (y % 400 == 0);
    }

public:
    Calendar() : day(1), month(1), year(2000), event("No event") {}

    Calendar(int d, int m, int y, const string& e = "No event")
    {
        if (!isValidDate(d, m, y))
            throw invalid_argument("Invalid date!");
        day = d;
        month = m;
        year = y;
        event = e;
    }

    Calendar(const Calendar& other)
    {
        day = other.day;
        month = other.month;
        year = other.year;
        event = other.event;
    }

    ~Calendar() {}

    Calendar& operator=(const Calendar& other)
    {
        if (this != &other)
        {
            day = other.day;
            month = other.month;
            year = other.year;
            event = other.event;
        }
        return *this;
    }

    bool operator==(const Calendar& other) const
    {
        return (day == other.day && month == other.month && year == other.year);
    }

    bool operator!=(const Calendar& other) const { return !(*this == other); }

    bool operator<(const Calendar& other) const
    {
        if (year != other.year) return year < other.year;
        if (month != other.month) return month < other.month;
        return day < other.day;
    }

    bool operator>(const Calendar& other) const { return other < *this; }
    bool operator<=(const Calendar& other) const { return !(*this > other); }
    bool operator>=(const Calendar& other) const { return !(*this < other); }

    Calendar& operator+=(int days)
    {
        while (days > 0)
        {
            int daysInMonth[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
            if (isLeapYear(year)) daysInMonth[1] = 29;

            if (day + 1 <= daysInMonth[month - 1])
            {
                day++;
            }
            else
            {
                day = 1;
                if (month == 12)
                {
                    month = 1;
                    year++;
                }
                else month++;
            }
            days--;
        }
        return *this;
    }

    Calendar& operator-=(int days)
    {
        while (days > 0)
        {
            if (day > 1)
            {
                day--;
            }
            else
            {
                if (month == 1)
                {
                    month = 12;
                    year--;
                }
                else month--;
                int daysInMonth[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
                if (isLeapYear(year)) daysInMonth[1] = 29;
                day = daysInMonth[month - 1];
            }
            days--;
        }
        return *this;
    }

    void setDate(int d, int m, int y)
    {
        if (!isValidDate(d, m, y))
            throw invalid_argument("Invalid date!");
        day = d;
        month = m;
        year = y;
    }

    void setEvent(const string& e) { event = e; }

    int getDay() const { return day; }
    int getMonth() const { return month; }
    int getYear() const { return year; }
    string getEvent() const { return event; }

    void print() const
    {
        cout << setw(2) << setfill('0') << day << "."
            << setw(2) << month << "." << year
            << "  Event: " << event << endl;
    }


    bool find(int d) const { return day == d; }
    bool find(int d, int m) const { return day == d && month == m; }
    bool find(int d, int m, int y) const { return day == d && month == m && year == y; }
    bool find(const string& e) const { return event == e; }
};

int main()
{
    try
    {
        int d1, m1, y1;
        string e1;

        cout << "Enter day for first event: ";
        cin >> d1;
        cout << "Enter month: ";
        cin >> m1;
        cout << "Enter year: ";
        cin >> y1;
        cin.ignore();
        cout << "Enter event description: ";
        getline(cin, e1);

        Calendar date1(d1, m1, y1, e1);

        int d2, m2, y2;
        string e2;

        cout << "\nEnter day for second event: ";
        cin >> d2;
        cout << "Enter month: ";
        cin >> m2;
        cout << "Enter year: ";
        cin >> y2;
        cin.ignore();
        cout << "Enter event description: ";
        getline(cin, e2);

        Calendar date2(d2, m2, y2, e2);

        cout << "\nYou entered the following events:\n";
        date1.print();
        date2.print();

        cout << "\nComparing dates:\n";
        if (date1 == date2)
            cout << "Dates are equal.\n";
        else if (date1 < date2)
            cout << "First date is earlier than second.\n";
        else
            cout << "First date is later than second.\n";

        int days;
        cout << "\nEnter number of days to add to first event: ";
        cin >> days;
        date1 += days;
        cout << "After adding days: ";
        date1.print();

        cout << "\nEnter number of days to subtract from second event: ";
        cin >> days;
        date2 -= days;
        cout << "After subtracting days: ";
        date2.print();

        int yearCheck;
        cout << "\nEnter year to search for events: ";
        cin >> yearCheck;
        if (date1.getYear() == yearCheck)
            cout << "Event in this year: " << date1.getEvent() << endl;
        if (date2.getYear() == yearCheck)
            cout << "Event in this year: " << date2.getEvent() << endl;
        if (date1.getYear() != yearCheck && date2.getYear() != yearCheck)
            cout << "No events found for this year.\n";

     
        if (date1.find("Birthday")) cout << "First event is a Birthday.\n";
        if (date2.find(d1, m1, y1)) cout << "Second event has the same date as first.\n";

        int searchDay, searchMonth, searchYear;
        string searchEvent;

        cout << "Enter day to search: ";
        cin >> searchDay;
        if (date1.find(searchDay)) cout << "Found day in first event.\n";
        if (date2.find(searchDay)) cout << "Found day in second event.\n";

        cout << "\nEnter day and month to search: ";
        cin >> searchDay >> searchMonth;
        if (date1.find(searchDay, searchMonth)) cout << "Found day+month in first event.\n";
        if (date2.find(searchDay, searchMonth)) cout << "Found day+month in second event.\n";

        cout << "\nEnter full date (day month year): ";
        cin >> searchDay >> searchMonth >> searchYear;
        if (date1.find(searchDay, searchMonth, searchYear)) cout << "Found full date in first event.\n";
        if (date2.find(searchDay, searchMonth, searchYear)) cout << "Found full date in second event.\n";

        cin.ignore();
        cout << "\nEnter event name to search: ";
        getline(cin, searchEvent);
        if (date1.find(searchEvent)) cout << "Found event in first record.\n";
        if (date2.find(searchEvent)) cout << "Found event in second record.\n";
    }
    catch (exception& e)
    {
        cerr << "Error: " << e.what() << endl;
    }

    return 0;
}
