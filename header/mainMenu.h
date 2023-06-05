#ifndef MAINMENU_H
#define MAINMENU_H

#include <iostream>
#include "courseList.h"
#include "calendar.h"
#include "toDoList.h"

using namespace std;

class MainMenu{
private:   
    ToDoList* toDoList;
    CourseList* courseList;
    Calendar* calendar;
    char previousPrompt;
    char currentPrompt;

    void back(const char prev, const char curr);
public:
    void homePrompt(ostream& ss);
    void addCoursePrompt(ostream& ss);
    void addTaskPrompt(ostream& ss);
    void addEventPrompt(ostream& ss);

    void manageCalendar(ostream& ss);
    // void dayPrompt(ostream& ss);
    void manageCourseList(ostream& ss);
    void manageToDoList(ostream& ss);
};

#endif