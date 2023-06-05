#include <gtest/gtest.h>
#include <iostream>
#include "../header/item.h"
using namespace std;

TEST(ItemTests, testNameSetter) {
    Item newItem = Item();
    string classes = "CS010A";
    newItem.setName(classes);
    EXPECT_EQ(newItem.getName(), "CS010A");
}

TEST(ItemTests, testTimeSetter) {
    Item* newItem = new Item();
    string date = "10/21/23";
    newItem->setDate(date);
    EXPECT_EQ(newItem->getDate(), "10/21/23");
}

TEST(ItemTests, testLocationSetter) {
    Item* newItem = new Item();
    string loc = "Winston Chung Hall";
    newItem->setLocation(loc);
    EXPECT_EQ(newItem->getLocation(), "Winston Chung Hall");
}

TEST(ItemTests, testDescriptionSetter) {
    Item* newItem = new Item();
    string desc = "This task rules yayayaya!";
    newItem->setDescription(desc);
    EXPECT_EQ(newItem->getDescription(), "This task rules yayayaya!");
}

TEST(ItemTests, testPrioritySetter) {
    Item* newItem = new Item();
    int p = 1;
    newItem->setPriority(p);
    EXPECT_EQ(newItem->getPriority(), 1);
}

TEST(ItemTests, testStatusSetter) {
    Item* newItem = new Item();
    bool status = true;
    newItem->setItemCompletion(status);
    EXPECT_EQ(newItem->getStatus(), true);
}

int main(int argc, char** argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}