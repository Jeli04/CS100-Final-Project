#ifndef MAINMENU_H
#define MAINMENU_H

#include <iostream>
#include "item.h"
#include "course.h"
#include "event.h"
#include "task.h"
#include "courseList.h"
#include "calendar.h"
#include "toDoList.h"

using namespace std;


class MainMenu{
private:   
    ToDoList* toDoList = nullptr;
    CourseList* courseList = nullptr;
    Calendar* calendar = nullptr;
    char userChoice = ' ';
    string itemToAccess = "";
    char previousPrompt;    // used in the back function
    char currentPrompt;    // used in the back function

    const char back(const char prev, const char curr);
public:
    MainMenu();
    const char homePrompt();
    const char coursePrompt();
    const char taskPrompt();
    const char eventPrompt();
    const char manageCalendar(ostream& ss);
    const char dayPrompt(ostream& ss);
    const char manageCourseList(ostream& ss);
    const char manageToDoList(ostream& ss);
    bool isValidDateFormat(const string& date);

    void setPrevPrompt(const char prev){previousPrompt = prev;}
    void setCurrPrompt(const char curr){currentPrompt = curr;}
};

#endif
