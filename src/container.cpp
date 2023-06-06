#include "../header/toDoList.h"
#include "../header/item.h"
#include "../header/courseList.h"
#include <iostream>
#include <ostream>

Container::~Container(){
    for(auto item : allItems){
        delete item;
        item = nullptr;
    }    
}

list<Item*> Container::getAllItems() const
{
    return allItems;
}

Item* Container::getItem(const string& itemName){
    for(Item* item : allItems)
    {
        if (item->getName() == itemName)
        {
            return item;
        }
    }
    return nullptr;
}


void Container::add(Item* newItem) {
    if(getItem(newItem->getName()) != nullptr){
        cout << "Item alreay exists!" << endl;
        return;
    }
    ++itemCount;

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
}

void Container::deleteItem(const string& itemName)
{
    auto itr = allItems.begin();
    while (itr != allItems.end())
    {
        if ((*itr)->getName() == itemName)
        {
            // need to call delete???
            allItems.erase(itr);
            break;
        }
        ++itr;
    }
}

void Container::printTitle(ostream& ss) const{
    // prints the title 
    ss << "Completion | Name";
    printSpaces(ss, 16);
    ss << "| Priority | Time" << endl;
    printDashes(ss, 52);
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
