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
    Item *thirdItem = new Item("project", "day after", "there", "finish on gradescope", 1, "task", true);
    Item *fourthItem = new Item(false);
    Item *fifthItem = new Item(true);
    newList.Add(thirdItem);
    newList.Add(newItem);
    newList.Add(anotherItem);
    newList.Add(fourthItem);
    newList.Add(fifthItem);
    newList.DisplayAll(cout);
    newList.DisplayCompleted(cout);
    newList.DisplayIncompleted(cout);
    return 0;
}