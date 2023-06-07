#include <gtest/gtest.h>
#include "../header/item.h"
#include "../header/course.h"
#include "../header/mainMenu.h"
#include <string>
#include <iostream>

TEST(DateTests, testValidInput1) {
    mainMenu newMenu = mainMenu();

    const string date = "10/20/2030";

    EXPECT_TRUE(newMenu.isValidDateFormat(date));
}

TEST(DateTests, testValidInput2) {
    mainMenu newMenu = mainMenu();

    const string date = "05/01/2000";

    EXPECT_TRUE(newMenu.isValidDateFormat(date));
}

TEST(DateTests, testValidInput3) {
    mainMenu newMenu = mainMenu();

    const string date = "10/99/2010";

    EXPECT_FALSE(newMenu.isValidDateFormat(date));
}

TEST(DateTests, testInvalidInput1) {
    mainMenu newMenu = mainMenu();

    const string date = "99/01/1998";

    EXPECT_FALSE(newMenu.isValidDateFormat(date));
}

TEST(DateTests, testInvalidInput2) {
    mainMenu newMenu = mainMenu();

    const string date = "01/01/00000";

    EXPECT_FALSE(newMenu.isValidDateFormat(date));
}

TEST(DateTests, testInvalidInput3) {
    mainMenu newMenu = mainMenu();

    const string date = "0101/5000";

    EXPECT_FALSE(newMenu.isValidDateFormat(date));
}