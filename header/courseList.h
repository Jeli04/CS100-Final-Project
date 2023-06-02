#ifndef COURSELIST_H
#define COURSELIST_H

#include "../header/toDoList.h"
#include "../header/item.h"
#include "../header/task.h"
#include "../header/course.h"
#include "../header/mainMenu.h"

#include <iostream>
#include <string>
#include <sstream>
#include <iterator>
#include <list>

using namespace std;


class CourseList : public Container {
    private:
        // list<Item*> allItems; // used as list of courses
        // int itemCount = 0;  // used as couse count
        string schoolName;

    public: 
        CourseList();
        void printBody(ostream& ss, const list<Item*>& toDoListType) const override;
        void displayAll(ostream& ss) const override;
        void printTitle(ostream& ss) const override;
        // display all items when called on a course will only access the data saved to course

};

#endif