#ifndef TODOLIST_H
#define TODOLIST_H

#include "../header/item.h"
#include "../header/container.h"
#include <iostream>
#include <string>
#include <sstream>
#include <iterator>
#include <list>

using namespace std;

class ToDoList : public Container{
private:  
    // helper functions
    void printTitle(ostream& ss) const override;
    void printBody(ostream& ss, const list<Item*>& toDoListType) const override;
public:
    ToDoList();
    void displayAll(ostream& ss) const override;
    void displayCompleted(ostream& ss);
    void displayIncompleted(ostream& ss);

    friend class Day;
    friend class CourseList;
};

#endif