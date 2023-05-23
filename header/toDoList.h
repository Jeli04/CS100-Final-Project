#ifndef TODOLIST_H
#define TODOLIST_H

#include "../header/item.h"
#include <iostream>
#include <string>
#include <sstream>
#include <iterator>
#include <list>

using namespace std;

class ToDoList{
private:
    list<Item*> AllItems;
    list<Item*> CompletedItems;
    list<Item*> IncompletedItems;
    int ItemCount; 

    // helper functions 
    void PrintSpaces(ostream& ss, int SpaceCount) const;
    void printDashes(ostream& ss, int numDashes) const;
    void printTitle(ostream& ss) const;
    void printBody(ostream& ss, const list<Item*>& toDoListType) const;
    void printPadding(ostream& ss, const string& itemName) const;
public:
    ToDoList();
    void Add(Item* NewItem);
    void DisplayAll(ostream& ss) const;
    void DisplayCompleted(ostream& ss) const;
    void DisplayIncompleted(ostream& ss) const;
    int GetItemCount() const {return ItemCount;}
};

#endif