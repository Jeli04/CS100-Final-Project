#ifndef MAINMENU_H
#define MAINMENU_H

#include <iostream>
#include <sstream>
#include "toDoList.h"
#include "courseList.h"
#include "calendar.h"
using namespace std;
class mainMenu {
    public:
        void addCourse(ostream&);
        void addTask(ostream&);
        void MainMenu() {cout << "hi" << endl;}
        void viewCalendar() {cout << "hi" << endl;}
        void viewCourseList() {cout << "hi" << endl;}
        void viewToDoList() {cout << "hi" << endl;}
};
#endif