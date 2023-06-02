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

CourseList::CourseList(){
    itemCount = 0;
}

void CourseList::printBody(ostream& ss, const list<Item*>& toDoListType) const 
{
    for(Item* listItem : toDoListType){
        printSpaces(ss, 4);
        // ss << "[";
        // if(listItem->getCompletion()){ss << "X";}
        // else {ss << " ";}
        // ss << "] ";
        // printSpaces(ss, 3);

        // ss << "| ";

        ss << listItem->getName();
        
        printPadding(ss, listItem->getName());

        //printSpaces(ss, 16);

        ss << "| ";

        printSpaces(ss, 4);

        ss << listItem->getPriority();

        printSpaces(ss, 4);

        ss << "| ";

        ss << listItem->getDate() << endl;
    }
}

void CourseList::printTitle(ostream& ss) const{
    // prints the title 
    ss << "    Course Name";
    printSpaces(ss, 9);
    ss << "| Priority | Time" << endl;
    printDashes(ss, 52);
}

void CourseList::displayAll(ostream& ss) const 
{
    printTitle(ss);
    // cout<<allItems.size()<<endl;
    printBody(ss, allItems);
}