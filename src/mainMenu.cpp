#include "../header/mainMenu.h"
#include "../header/toDoList.h"
#include "../header/item.h"
#include <iostream>

using namespace std;


int main()
{
    ToDoList newList;
    Item *newItem;
    Item *anotherItem = new Item("homework", "tomorrow", "here", "finish on canvas", 1, "task");
    newList.Add(newItem);
    newList.Add(anotherItem);
    return 0;
}