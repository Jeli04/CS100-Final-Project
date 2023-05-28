#ifndef CALENDAR_H
#define CALENDAR_H

#include "day.h"
#include <vector>
#include <map>
#include <iomanip>

using namespace std;

class Calendar{
private:
    string year;
    string month;
    list<Day*> dayList;
    int dayCount; 

    // helper variables
    tm tmCalendar;  // used for the display function to organize the days
    map<string, int> monthMap = {{"January", 1},{"February", 2},{"March", 3},{"April", 4},{"May", 5},{"June", 6},{"July", 7},{"August", 8},{"September", 9},{"October", 10},{"November", 11},{"December", 12}}; 

public:
    Calendar(string& _year, string&  _month, int _dayCount);
    void displayMonth(ostream& ss) const;
    void addDay(Day* day);
    int dayListSize() const;
};

#endif