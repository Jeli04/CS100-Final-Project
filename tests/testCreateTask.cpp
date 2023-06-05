#include <gtest/gtest.h>
#include "../header/item.h"
#include "../header/task.h"
#include "../header/course.h"
#include "../header/mainMenu.h"
#include <string>
#include <sstream>
#include <iostream>

int main() {
    mainMenu newMenu = mainMenu();

    newMenu.addTask(cout);
}