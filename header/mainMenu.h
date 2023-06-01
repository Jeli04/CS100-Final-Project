#ifndef MAINMENU_H
#define MAINMENU_H

#include <iostream>
#include "courseList.h"
#include "calendar.h"
#include "toDoList.h"

using namespace std;

class MainMenu{
private:   
    // ToDoList* toDoList;
    // CourseList* courseList;
    // Calendar* calendar;
    char previousPrompt;
    char currentPrompt;

    void back(const char prev, const char curr);
public:
    void homePrompt(ostream& ss);
    void calendarPrompt(ostream& ss);
    void courseListPrompt(ostream& ss);
    void toDoLisetPrompt(ostream& ss);
};

#endif