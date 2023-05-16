#ifndef TODOLIST_H
#define TODOLIST_H

#include "../header/item.h"
#include <list> 
#include <iterator>

using namespace std;

class ToDoList{
private:
    list<Item*> AllItems;
    list<Item*> CompletedItems;
    list<Item*> IncompletedItems;
    int ItemCount; 
public:
    ToDoList();
    void Add();
    void DisplayAll() const;
    void DisplayCompleted() const;
    void DisplayIncompleted() const;
    int GetItemCount() const {return ItemCount;}
};

#endif