#ifndef TODOLIST_H
#define TODOLIST_H

#include "../header/item.h"
#include <list> 
#include <iterator>
#include <queue>

using namespace std;

class ToDoList{
private:
    list<Item*> AllItems;
    list<Item*> CompletedItems;
    list<Item*> IncompletedItems;

    int ItemCount = 0; 
public:
    ToDoList();
    void Add(Item*);
    void DisplayAll() const;
    void DisplayCompleted() const;
    void DisplayIncompleted() const;
    int GetItemCount() const {return ItemCount;}
    list<Item*> GetAllItems() const;
};

#endif