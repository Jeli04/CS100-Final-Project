#include <gtest/gtest.h>
#include "../header/item.h"
#include "../header/course.h"
#include "../header/mainMenu.h"
#include <string>
#include <iostream>


int main() {
    mainMenu newMenu = mainMenu();

    //char k = newMenu.addCourse();

    char s = newMenu.addTask();

    cout << s << endl;
}