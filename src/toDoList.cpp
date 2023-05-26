#include "../header/toDoList.h"
#include "../header/item.h"
#include <iostream>
#include <ostream>

ToDoList::ToDoList(){
    ItemCount = 0;
}

list<Item*> ToDoList::GetAllItems() const
{
    return AllItems;
}

void ToDoList::Add(Item* newItem) {
    if (AllItems.empty()) 
    {
        AllItems.push_back(newItem);
    } 
    else 
    {
        auto itr = AllItems.begin();
        while (itr != AllItems.end() && newItem->getPriority() >= (*itr)->getPriority()) 
        {
            if (newItem->getPriority() == (*itr)->getPriority()) 
            {
                AllItems.insert(itr, newItem);
                return;
            }
            ++itr;
        }
        AllItems.insert(itr, newItem);
    }
    ++ItemCount;
}

void ToDoList::DisplayAll(ostream& ss) const {
    printTitle(ss);
    printBody(ss, AllItems);
}

void ToDoList::DisplayCompleted(ostream& ss) const {
    printTitle(ss);
    printBody(ss, CompletedItems);
}

void ToDoList::DisplayIncompleted(ostream& ss) const {
    printTitle(ss);
    printBody(ss, IncompletedItems);
}

void ToDoList::printTitle(ostream& ss) const{
    // prints the title 
    ss << "Completion | Name";
    PrintSpaces(ss, 16);
    ss << "| Priority | Time" << endl;
    printDashes(ss, 52);
}

void ToDoList::printBody(ostream& ss, const list<Item*>& toDoListType) const{
    // prints the body
    for(Item* ListItem : toDoListType){
        PrintSpaces(ss, 4);
        ss << "[";
        if(ListItem->GetCompletion()){ss << "X";}
        else {ss << " ";}
        ss << "] ";
        PrintSpaces(ss, 3);

        ss << "| ";

        ss << ListItem->GetName();
        
        printPadding(ss, ListItem->GetName());

        //PrintSpaces(ss, 16);

        ss << "| ";

        PrintSpaces(ss, 4);

        ss << ListItem->GetPriority();

        PrintSpaces(ss, 4);

        ss << "| ";

        ss << ListItem->GetTime() << endl;
    }
}

void ToDoList::PrintSpaces(ostream& ss, int SpaceCount) const{
    for(unsigned i = 0; i < SpaceCount; i++){
        ss << " ";
    }
}

void ToDoList::printDashes(ostream& ss, int numDashes) const{
    for(unsigned i = 0; i < numDashes; i++){
        ss << "-";
    }
    ss << endl;
}

void ToDoList::printPadding(ostream& ss, const string& itemName) const{
    for (unsigned i = 0; i < 20-itemName.size(); i++){ss<<" ";}
}
