#include "../header/mainMenu.h"
#include "../header/toDoList.h"
#include "../header/item.h"
#include <iostream>

using namespace std;


int main()
{
    ToDoList newList;
    Item *newItem = new Item(false);
    Item *anotherItem = new Item("homework", "tomorrow", "here", "finish on canvas", 3, "task", false);
    Item *thirdItem = new Item("test", "day after", "there", "finish on gradescope", 1, "task", true);
    newList.Add(thirdItem);
    newList.Add(newItem);
    newList.Add(anotherItem);
    newList.DisplayAll(cout);
    return 0;
}