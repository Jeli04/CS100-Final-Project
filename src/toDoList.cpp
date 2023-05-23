#include "../header/toDoList.h"
#include "../header/item.h"

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
