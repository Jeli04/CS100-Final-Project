#ifndef TODOLIST_H
#define TODOLIST_H

#include "../header/item.h"
#include <iostream>
#include <string>
#include <sstream>
#include <iterator>
#include <list>

using namespace std;

class ToDoList{
private:
    list<Item*> allItems;
    list<Item*> completedItems;
    list<Item*> incompletedItems;
    int itemCount; 

    // helper functions 
    void printSpaces(ostream& ss, int spaceCount) const;
    void printDashes(ostream& ss, int numDashes) const;
    void printTitle(ostream& ss) const;
    void printBody(ostream& ss, const list<Item*>& toDoListType) const;
    void printPadding(ostream& ss, const string& itemName) const;
public:
    ToDoList();
    void add(Item* newItem);
    void displayAll(ostream& ss) const;
    void displayCompleted(ostream& ss) const;
    void displayIncompleted(ostream& ss) const;
    int getitemCount() const {return itemCount;}

    friend class Day;
    friend class Calendar;
    friend class CourseList;
};

#endif