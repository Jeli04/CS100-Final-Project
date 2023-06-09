#include "../header/toDoList.h"
#include "../header/item.h"
#include "../header/courseList.h"
#include <iostream>
#include <ostream>

ToDoList::ToDoList() {
    itemCount = 0;
}

ToDoList::~ToDoList() {
    auto itr = allItems.begin();
    while (itr != allItems.end()) 
    {
        delete *itr;
        ++itr;
    }
}


void ToDoList::displayAll(ostream& ss) const  {
    printTitle(ss);
    printBody(ss, allItems);
}

void ToDoList::displayCompleted(ostream& ss)  {
    printTitle(ss);
    list<Item*> completedItems;
    auto itr = allItems.begin();
    while (itr != allItems.end()) 
    {
        if ((*itr)->getStatus() == true) 
        {
            completedItems.push_back(*itr);
        }
        ++itr;
    }
    printBody(ss, completedItems);
}

void ToDoList::displayIncompleted(ostream& ss) {
    printTitle(ss);
    list<Item*> incompletedItems;
    auto itr = allItems.begin();
        while (itr != allItems.end()) 
        {
            if ((*itr)->getStatus() == false) 
            {
                incompletedItems.push_back(*itr);
            }
            ++itr;
        }
    printBody(ss, incompletedItems);
}


void ToDoList::printTitle(ostream& ss) const{
    // prints the title 
    ss << "Completion | Name";
    printSpaces(ss, 16);
    ss << "| Priority | Time" << endl;
    printDashes(ss, 52);
}


void ToDoList::printBody(ostream& ss, const list<Item*>& toDoListType) const{
    // prints the body
    for(Item* listItem : toDoListType){
        printSpaces(ss, 4);
        ss << "[";
        if(listItem->getStatus()){ss << "X";}
        else {ss << " ";}
        ss << "] ";
        printSpaces(ss, 3);

        ss << "| ";

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
