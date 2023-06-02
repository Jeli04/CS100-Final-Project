#ifndef TODOLIST_H
#define TODOLIST_H

#include "../header/item.h"
#include "../header/container.h"
// #include "../header/courseList.h"
#include <iostream>
#include <string>
#include <sstream>
#include <iterator>
#include <list>

using namespace std;

class ToDoList : public Container{
// private:
//     list<Item*> allItems;
//     int itemCount = 0; 
  
//     // helper functions
//     void printTitle(ostream& ss) const;
//     void printBody(ostream& ss, const list<Item*>& toDoListType) const;
//     void printSpaces(ostream& ss, int spaceCount) const;
//     void printDashes(ostream& ss, int numDashes) const;
//     void printPadding(ostream& ss, const string& itemName) const;
public:
    ToDoList();
    // void add(Item* NewItem);
    // void deleteItem(string itemName);
    // void displayAll(ostream& ss) const;
    void displayCompleted(ostream& ss);
    void displayIncompleted(ostream& ss);
    // int getItemCount() const {return itemCount;}
    // list<Item*> getAllItems() const;

    friend class Day;
    friend class Calendar;
    friend class CourseList;
};

#endif