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


class CourseList : public ToDoList {
    private:
        list<Item*> allItems; // used as list of courses
        int itemCount = 0;  // used as couse count
        string schoolName;

    public: 
        CourseList();
        // display all items when called on a course will only access the data saved to course

};

#endif