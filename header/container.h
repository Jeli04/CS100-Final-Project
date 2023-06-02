#ifndef CONTAINER_H
#define CONTAINER_H

#include "../header/item.h"
// #include "../header/courseList.h"
#include <iostream>
#include <string>
#include <sstream>
#include <iterator>
#include <list>

using namespace std;

class Container{
protected:
    list<Item*> allItems;
    int itemCount = 0; 
  
    // helper functions
    virtual void printTitle(ostream& ss) const = 0;
    virtual void printBody(ostream& ss, const list<Item*>& toDoListType) const = 0;
    void printSpaces(ostream& ss, int spaceCount) const;
    void printDashes(ostream& ss, int numDashes) const;
    void printPadding(ostream& ss, const string& itemName) const;
public:
    // ToDoList();
    void add(Item* NewItem);
    void deleteItem(string itemName);
    virtual void displayAll(ostream& ss) const = 0;
    int getItemCount() const {return itemCount;}
    list<Item*> getAllItems() const;

    friend class Day;
    friend class Calendar;
    // friend class CourseList;
};

#endif