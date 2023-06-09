#ifndef DAY_H
#define DAY_H
using namespace std;

#include "toDoList.h"
#include "courseList.h"
#include "course.h"
#include <ctime>
#include <string>

using namespace std;

class Day{
private:
    string dayName;
    string monthName;
    int dayNumber;
    string date;
    list<Item*> listOfItems;
    ToDoList* toDoList;
    CourseList* courseList;

    // helper functions
    void updateItems(const string& date);
public:
    Day(ToDoList* _toDoList, CourseList* _courseList, const string& date); 
    void displayDayInfo(ostream& ss);
    string getDate() const {return date;}
};

#endif