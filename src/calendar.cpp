#include "../header/calendar.h"

Calendar::Calendar(const string& _year, const string& _month, const int _dayCount){
    year = _year;
    month = _month;
    dayCount = _dayCount;

    // gets the day of the week
    tmCalendar = {0, 0, 0, 1, monthMap[month]-1, stoi(year)-1900};   // day, month - 1, year - 1900
    mktime(&tmCalendar);    // normalizes the tm object 
}

void Calendar::addDay(Day* day){
    // error message should not occur since the days should correctly be handeled in main menu
    if(dayCount == dayListSize()){
        cout << "Month is full" << endl;
        return;
    }

    dayList.push_back(day);
}

void Calendar::displayMonth(ostream& ss) const{
    // gets the first weekday in the month
    int weekday = (tmCalendar.tm_wday) % 7;

    // displays the month name and year
    ss << setw(14) << month << " " << year << endl;

    ss << string(28, '-') << endl;

    // displays the week day names
    ss << "Sun Mon Tue Wed Thu Fri Sat" << endl;

    // displays the first week 
    for(unsigned i = 0; i < weekday; i++){
        ss << "    ";
    }

    for(int i = 1; i <= dayCount; i++){
        ss << setw(3) << i << " ";
        // if the end of the week is reached print a new line
        if((weekday+i) % 7 == 0){
            ss << endl;
        }
    }
    ss << endl;
}

int Calendar::dayListSize() const{return dayList.size();}