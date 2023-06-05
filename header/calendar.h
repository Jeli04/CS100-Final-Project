#ifndef CALENDAR_H
#define CALENDAR_H
using namespace std;


#include "day.h"
#include "container.h"
#include <vector>
#include <map>
#include <iomanip>

using namespace std;

class Calendar : public Container{
private:
    string year;
    string month;
    list<Day*> dayList;
    int dayCount; 

    // helper variables
    tm tmCalendar;  // used for the display function to organize the days
    map<string, int> monthMap = {{"January", 1},{"February", 2},{"March", 3},{"April", 4},{"May", 5},{"June", 6},{"July", 7},{"August", 8},{"September", 9},{"October", 10},{"November", 11},{"December", 12}}; 
    void printTitle(ostream& ss) const override;
    void printBody(ostream& ss, const list<Item*>& toDoListType) const override;

public:
    Calendar(const string& _year, const string& _month, const int _dayCount);
    void displayAll(ostream& ss) const override;
    void addDay(Day* day);
    int dayListSize() const;
};

class Calendar{

};

#endif