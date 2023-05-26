#include <gtest/gtest.h>
#include <iostream>
#include "../header/item.h"
using namespace std;

TEST(ItemTests, testNameSetter) {
    Items newItem = Items();
    string classes = "CS010A";
    newItem.setName(classes);
    EXPECT_EQ(newItem.getName(), "CS010A");
}

TEST(ItemTests, testTimeSetter) {
    Items* newItem = new Items();
    string date = "10/21/23";
    newItem->setDate(date);
    EXPECT_EQ(newItem->getDate(), "10/21/23");
}

TEST(ItemTests, testLocationSetter) {
    Items* newItem = new Items();
    string loc = "Winston Chung Hall";
    newItem->setLocation(loc);
    EXPECT_EQ(newItem->getLocation(), "Winston Chung Hall");
}

TEST(ItemTests, testDescriptionSetter) {
    Items* newItem = new Items();
    string desc = "This task rules yayayaya!";
    newItem->setDescription(desc);
    EXPECT_EQ(newItem->getDescription(), "This task rules yayayaya!");
}

TEST(ItemTests, testPrioritySetter) {
    Items* newItem = new Items();
    int p = 1;
    newItem->setPriority(p);
    EXPECT_EQ(newItem->getPriority(), 1);
}

TEST(ItemTests, testStatusSetter) {
    Items* newItem = new Items();
    bool status = true;
    newItem->setItemCompletion(status);
    EXPECT_EQ(newItem->getStatus(), true);
}