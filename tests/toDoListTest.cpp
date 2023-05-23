#include "gtest/gtest.h"
#include <gmock/gmock.h>
#include <gmock/gmock-matchers.h>
#include "../header/toDoList.h"
#include "../header/item.h"

TEST(ToDoList, ToDoListTests){
    ToDoList TestList = ToDoList();
    EXPECT_EQ(TestList.GetItemCount(), 0);
}

TEST(ToDoList, addToList)
{
    ToDoList testList;
    list<Item*> expectedList;
    Item *newItem = new Item("homework", "tomorrow", "there", "finish on canvas", 2, "task");
    Item *anotherItem = new Item("test", "today", "here", "finish on in person", 1, "test");
    Item *newItemExpect = new Item("homework", "tomorrow", "there", "finish on canvas", 2, "task");
    Item *anotherItemExpect = new Item("test", "today", "here", "finish on in person", 1, "test");
    testList.Add(newItem);
    testList.Add(anotherItem);
    expectedList.push_back(anotherItemExpect);
    expectedList.push_back(newItemExpect);

    ASSERT_EQ(testList.GetAllItems().size(), expectedList.size());

    // Iterate over the elements and compare them one by one
    list<Item*>::iterator it1 = testList.GetAllItems().begin();
    list<Item*>::iterator it2 = expectedList.begin();
    ASSERT_EQ((*it1)->getName(), (*it2)->getName());
    ++it1;
    ++it2;
    ASSERT_EQ((*it1)->getName(), (*it2)->getName());
    // for (; it1 != testList.GetAllItems().end() && it2 != expectedList.end(); ++it1, ++it2) {
    //     ASSERT_EQ((*it1)->getName(), (*it2)->getName());
    // }

}

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}