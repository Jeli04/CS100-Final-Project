#include "../header/mainMenu.h"
#include "../header/toDoList.h"
#include "../header/item.h"
#include "../header/task.h"
#include <iostream>

using namespace std;


int main()
{
    ToDoList newList;
    Item *newItem = new Task(false);
    Item *anotherItem = new Task("homework", "tomorrow", "here", "finish on canvas", 3, "task", false);
    Item *thirdItem = new Task("project", "day after", "there", "finish on gradescope", 1, "task", true);
    Item *fourthItem = new Task(false);
    Item *fifthItem = new Task(true);
    newList.add(thirdItem);
    newList.add(newItem);
    newList.add(anotherItem);
    newList.add(fourthItem);
    newList.add(fifthItem);
    newList.displayAll(cout);
    newList.displayCompleted(cout);
    newList.displayIncompleted(cout);

    newList.deleteItem("homework");
    newList.deleteItem("project");
    newList.displayAll(cout);
    newList.displayCompleted(cout);
    newList.displayIncompleted(cout);
    return 0;
}
