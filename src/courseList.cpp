#include "../header/courseList.h"
#include "../header/toDoList.h"
#include "../header/item.h"
#include "../header/task.h"
#include "../header/course.h"
#include "../header/mainMenu.h"

#include <iostream>
#include <string>
#include <sstream>
#include <iterator>
#include <list>

CourseList::CourseList(){
    itemCount = 0;
}

void CourseList::displayAll(ostream& ss) const {
    printTitle(ss);
    printBody(ss, allItems);
}