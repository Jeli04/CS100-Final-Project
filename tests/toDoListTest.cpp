#include "gtest/gtest.h"
#include <gmock/gmock.h>
#include <gmock/gmock-matchers.h>
#include "../header/toDoList.h"
#include "../header/item.h"

TEST(ToDoList, ItemCount){
    ToDoList TestList = ToDoList();
    EXPECT_EQ(TestList.GetItemCount(), 0);
}

// TEST(ToDoList, addToList)
// {
//     ToDoList testList;
//     list<Item*> expectedList;
//     Item *newItem = new Item(false);
//     Item *anotherItem = new Item("homework", "tomorrow", "here", "finish on canvas", 3, "task", false);
//     Item *newItemExpect = new Item(false);
//     Item *anotherItemExpect = new Item("homework", "tomorrow", "here", "finish on canvas", 3, "task", false);
//     testList.Add(newItem);
//     testList.Add(anotherItem);
//     expectedList.push_back(anotherItemExpect);
//     expectedList.push_back(newItemExpect);

//     ASSERT_EQ(testList.GetAllItems().size(), expectedList.size());

//     // Iterate over the elements and compare them one by one
//     list<Item*>::iterator it1 = testList.GetAllItems().begin();
//     list<Item*>::iterator it2 = expectedList.begin();
//     ASSERT_EQ((*it1)->getName(), (*it2)->getName());

// }

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
    TestList.Add(new Item(true));

    // Test GetItemCount
    EXPECT_EQ(TestList.GetItemCount(), 1);
}

TEST(ToDoList, DisplayAll1){
    ToDoList TestList = ToDoList();
    TestList.Add(new Item(false));

    // Test DisplayAll function 
    stringstream ss;
    TestList.DisplayAll(ss);
    EXPECT_EQ("Completion | Name                | Priority | Time\n----------------------------------------------------\n    [ ]    | Name                |     0    | Time\n", ss.str());
}

TEST(ToDoList, DisplayAll2){
    ToDoList TestList = ToDoList();
    TestList.Add(new Item(false));
    TestList.Add(new Item(false));
    TestList.Add(new Item(true));

    // Test DisplayAll function 
    stringstream ss;
    TestList.DisplayAll(ss);
    EXPECT_EQ("Completion | Name                | Priority | Time\n----------------------------------------------------\n    [ ]    | Name                |     0    | Time\n    [ ]    | Name                |     0    | Time\n    [X]    | Name                |     0    | Time\n", ss.str());
}

TEST(ToDoList, DisplayCompleted1){
    ToDoList TestList = ToDoList();
    TestList.Add(new Item(true));

    // Test DisplayCompleted function 
    stringstream ss;
    TestList.DisplayCompleted(ss);
    EXPECT_EQ("Completion | Name                | Priority | Time\n----------------------------------------------------\n    [X]    | Name                |     0    | Time\n", ss.str());
}

TEST(ToDoList, DisplayCompleted2){
    ToDoList TestList = ToDoList();
    TestList.Add(new Item(false));

    // Test DisplayCompleted function 
    stringstream ss;
    TestList.DisplayCompleted(ss);
    EXPECT_EQ("Completion | Name                | Priority | Time\n----------------------------------------------------\n", ss.str());
}

TEST(ToDoList, DisplayIncompleted1){
    ToDoList TestList = ToDoList();
    TestList.Add(new Item(false));

    // Test DisplayIncompleted function 
    stringstream ss;
    TestList.DisplayIncompleted(ss);
    EXPECT_EQ("Completion | Name                | Priority | Time\n----------------------------------------------------\n    [ ]    | Name                |     0    | Time\n", ss.str());
}

TEST(ToDoList, DisplayIncompleted2){
    ToDoList TestList = ToDoList();
    TestList.Add(new Item(true));

    // Test DisplayIncompleted function 
    stringstream ss;
    TestList.DisplayIncompleted(ss);
    EXPECT_EQ("Completion | Name                | Priority | Time\n----------------------------------------------------\n", ss.str());
}

// int main(int argc, char** argv) {
//   ::testing::InitGoogleTest(&argc, argv);
//   return RUN_ALL_TESTS();
// }