#include <gtest/gtest.h>
#include "../header/item.h"
#include "../header/course.h"
#include "../header/mainMenu.h"
#include <string>
#include <sstream>
#include <iostream>

using namespace std;

TEST(CreateCourseTests, testDisplay) {
    stringstream ss;
    mainMenu newMenu = mainMenu();
    newMenu.addCourse(ss);
    EXPECT_EQ("\t\tCreate a Course\n--------------------------------------------------\n\n\tEnter Name of Course: CS010A\n\n\tEnter Instructor Name: Mrs. Kelley\n\n\tEnter number of days a week: 1\n\n\tEnter Day  : Monday\n\n\tEnter Location of Class: BCOE\n\n\tEnter Priority (Urgency): 1\n\n--------------------------------------------------\n\tNew Class has been created!\n--------------------------------------------------\n\n1) Home 2) Calendar 3) Course List 4) Todo List\t\n\tEnter Your Choice: 1\n", ss.str());
}