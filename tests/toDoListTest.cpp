#include "gtest/gtest.h"
#include <gmock/gmock.h>
#include <gmock/gmock-matchers.h>
#include "../header/toDoList.h"
#include "../header/item.h"


TEST(ToDoList, addToList)
{
    ToDoList testList;
    list<Item*> expectedList;
    Item *newItem = new Item(false);
    Item *anotherItem = new Item("homework", "tomorrow", "here", "finish on canvas", 3, "task", false);
    Item *newItemExpect = new Item(false);
    Item *anotherItemExpect = new Item("homework", "tomorrow", "here", "finish on canvas", 3, "task", false);
    testList.add(anotherItem);
    testList.add(newItem);
    expectedList.push_back(newItemExpect);
    expectedList.push_back(anotherItemExpect);

    ASSERT_EQ(testList.getAllItems().size(), expectedList.size());

    // Iterate over the elements and compare them one by one
    list<Item*>::iterator it1 = testList.getAllItems().begin();
    list<Item*>::iterator it2 = expectedList.begin();
    ASSERT_EQ((*it1)->getName(), (*it2)->getName());

}


TEST(ToDoList, ItemCount){
    ToDoList TestList = ToDoList();
    TestList.add(new Item(true));

    // Test GetItemCount
    EXPECT_EQ(TestList.getItemCount(), 1);
}

TEST(ToDoList, DisplayAll1){
    ToDoList TestList = ToDoList();
    TestList.add(new Item(false));

    // Test displayAll function 
    stringstream ss;
    TestList.displayAll(ss);
    EXPECT_EQ("Completion | Name                | Priority | Time\n----------------------------------------------------\n    [ ]    | Name                |     0    | Time\n", ss.str());
}

TEST(ToDoList, DisplayAll2){
    ToDoList TestList = ToDoList();
    TestList.add(new Item(false));
    TestList.add(new Item(false));
    TestList.add(new Item(true));

    // Test displayAll function 
    stringstream ss;
    TestList.displayAll(ss);
    EXPECT_EQ("Completion | Name                | Priority | Time\n----------------------------------------------------\n    [X]    | Name                |     0    | Time\n    [ ]    | Name                |     0    | Time\n    [ ]    | Name                |     0    | Time\n", ss.str());
}

TEST(ToDoList, DisplayCompleted1){
    ToDoList TestList = ToDoList();
    TestList.add(new Item(true));

    // Test displayCompleted function 
    stringstream ss;
    TestList.displayCompleted(ss);
    EXPECT_EQ("Completion | Name                | Priority | Time\n----------------------------------------------------\n    [X]    | Name                |     0    | Time\n", ss.str());
}

TEST(ToDoList, DisplayCompleted2){
    ToDoList TestList = ToDoList();
    TestList.add(new Item(false));

    // Test displayCompleted function 
    stringstream ss;
    TestList.displayCompleted(ss);
    EXPECT_EQ("Completion | Name                | Priority | Time\n----------------------------------------------------\n", ss.str());
}

TEST(ToDoList, DisplayIncompleted1){
    ToDoList testList = ToDoList();
    testList.add(new Item(false));

    // Test displayIncompleted function 
    stringstream ss;
    testList.displayIncompleted(ss);
    EXPECT_EQ("Completion | Name                | Priority | Time\n----------------------------------------------------\n    [ ]    | Name                |     0    | Time\n", ss.str());
}

TEST(ToDoList, DisplayIncompleted2){
    ToDoList testList = ToDoList();
    testList.add(new Item(true));

    // Test displayIncompleted function 
    stringstream ss;
    testList.displayIncompleted(ss);
    EXPECT_EQ("Completion | Name                | Priority | Time\n----------------------------------------------------\n", ss.str());
}

int main(int argc, char** argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}