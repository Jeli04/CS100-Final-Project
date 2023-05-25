#ifndef DAY_H
#define DAY_H

#include "../header/toDoList.h"
#include <ctime>

class Day : public ToDoList{
private:
    string dayName;
    int dayNumber;
    list<Item*> listOfItems;
public:
    Day(string date); 

};

#endif