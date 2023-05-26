#ifndef DAY_H
#define DAY_H

#include "../header/toDoList.h"
#include <ctime>

class Day{
private:
    string dayName;
    string monthName;
    int dayNumber;
    list<Item*> listOfItems;
    ToDoList* toDoList;

    // helper functions
    void printDashes(ostream& ss, int dashCount) const;
    void updateItems(const string& date);
public:
    Day(ToDoList* _toDoList, const string& date); 
    void displayDayInfo(ostream& ss) const;
};

#endif