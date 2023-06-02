#include "../header/toDoList.h"
#include "../header/item.h"
#include "../header/courseList.h"
#include <iostream>
#include <ostream>

// Container::Container(){
//     itemCount = 0;
// }

list<Item*> Container::getAllItems() const
{
    return allItems;
}

void Container::add(Item* newItem) {
    if (allItems.empty()) 
    {
        allItems.push_back(newItem);
    } 
    else 
    {
        auto itr = allItems.begin();
        while (itr != allItems.end() && newItem->getPriority() >= (*itr)->getPriority()) 
        {
            if (newItem->getPriority() == (*itr)->getPriority()) 
            {
                allItems.insert(itr, newItem);
                return;
            }
            ++itr;
        }
        allItems.insert(itr, newItem);
    }
    ++itemCount;
}

void Container::deleteItem(string itemName)
{
    auto itr = allItems.begin();
    while (itr != allItems.end())
    {
        if ((*itr)->getName() == itemName)
        {
            allItems.erase(itr);
            break;
        }
        ++itr;
    }
}

// void Container::displayAll(ostream& ss) const {
//     printTitle(ss);
//     printBody(ss, allItems);
// }

/*
void Container::displayCompleted(ostream& ss)  {
    printTitle(ss);
    list<Item*> completedItems;
    auto itr = allItems.begin();
        while (itr != allItems.end()) 
        {
            if ((*itr)->getCompletion() == true) 
            {
                completedItems.push_back(*itr);
            }
            ++itr;
        }
    printBody(ss, completedItems);
}

void Container::displayIncompleted(ostream& ss) {
    printTitle(ss);
    list<Item*> incompletedItems;
    auto itr = allItems.begin();
        while (itr != allItems.end()) 
        {
            if ((*itr)->getCompletion() == false) 
            {
                incompletedItems.push_back(*itr);
            }
            ++itr;
        }
    printBody(ss, incompletedItems);
}
*/

void Container::printTitle(ostream& ss) const{
    // prints the title 
    ss << "Completion | Name";
    printSpaces(ss, 16);
    ss << "| Priority | Time" << endl;
    printDashes(ss, 52);
}

void Container::printBody(ostream& ss, const list<Item*>& toDoListType) const{
    // prints the body
    for(Item* listItem : toDoListType){
        printSpaces(ss, 4);
        ss << "[";
        if(listItem->getCompletion()){ss << "X";}
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

void Container::printSpaces(ostream& ss, int spaceCount) const{
    for(unsigned i = 0; i < spaceCount; i++){
        ss << " ";
    }
}

void Container::printDashes(ostream& ss, int numDashes) const{
    for(unsigned i = 0; i < numDashes; i++){
        ss << "-";
    }
    ss << endl;
}

void Container::printPadding(ostream& ss, const string& itemName) const{
    for (unsigned i = 0; i < 20-itemName.size(); i++){ss<<" ";}
}
