#ifndef TODOLIST_H
#define TODOLIST_H

#include "../header/item.h"
#include <list> 
#include <iterator>
#include <queue>

using namespace std;

class ToDoList{
private:
    priority_queue<Item*> AllItems;
    priority_queue<Item*> CompletedItems;
    priority_queue<Item*> IncompletedItems;
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