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

    int ItemCount = 0; 
public:
    ToDoList();
    void add(Item* NewItem);
    void displayAll(ostream& ss) const;
    void displayCompleted(ostream& ss) ;
    void DisplayIncompleted(ostream& ss) ;
    int GetItemCount() const {return ItemCount;}
    list<Item*> GetAllItems() const;

    void printTitle(ostream& ss) const;
    void printBody(ostream& ss, const list<Item*>& toDoListType) const;
    void PrintSpaces(ostream& ss, int SpaceCount) const;
    void printDashes(ostream& ss, int numDashes) const;
    void printPadding(ostream& ss, const string& itemName) const;
};

#endif