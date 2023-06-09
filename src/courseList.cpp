#include "../header/courseList.h"
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

CourseList::CourseList(const string& _schoolName) {
    schoolName = _schoolName;
    itemCount = 0;
}

CourseList::~CourseList() {
    auto itr = allItems.begin();
    while (itr != allItems.end()) 
    {
        delete *itr;
        ++itr;
    }
}

void CourseList::printBody(ostream& ss, const list<Item*>& toDoListType) const 
{
    for(Item* listItem : toDoListType){
        printSpaces(ss, 4);

        ss << listItem->getName();
        
        printPadding(ss, listItem->getName());

        ss << "| ";

        printSpaces(ss, 4);

        ss << listItem->getPriority();

        printSpaces(ss, 4);

        ss << "| ";

        const vector<string>& dates = listItem->getOccuringDays();
        for (const string& date : dates) {
            ss << date << " ";
        }
        ss << endl;
    }
}

void CourseList::printTitle(ostream& ss) const{
    // prints the title 
    printSpaces(ss, 20);
    ss << schoolName << endl;

    ss << "    Course Name";
    printSpaces(ss, 9);
    ss << "| Priority | Time" << endl;
    printDashes(ss, 52);
}

void CourseList::displayAll(ostream& ss) const 
{
    printTitle(ss);
    printBody(ss, allItems);
}