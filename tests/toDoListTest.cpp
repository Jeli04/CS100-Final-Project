#include "gtest/gtest.h"
#include "../header/toDoList.h"

TEST(ToDoList, itemCount){
    ToDoList testList = ToDoList();
    testList.add(new Item(true));

    // Test getitemCount
    EXPECT_EQ(testList.getitemCount(), 1);
}

TEST(ToDoList, displayAll1){
    ToDoList testList = ToDoList();
    testList.add(new Item(false));

    // Test displayAll function 
    stringstream ss;
    testList.displayAll(ss);
    EXPECT_EQ("Completion | Name                | Priority | Time\n----------------------------------------------------\n    [ ]    | Name                |     0    | Time\n", ss.str());
}

TEST(ToDoList, displayAll2){
    ToDoList testList = ToDoList();
    testList.add(new Item(false));
    testList.add(new Item(false));
    testList.add(new Item(true));

    // Test displayAll function 
    stringstream ss;
    testList.displayAll(ss);
    EXPECT_EQ("Completion | Name                | Priority | Time\n----------------------------------------------------\n    [ ]    | Name                |     0    | Time\n    [ ]    | Name                |     0    | Time\n    [X]    | Name                |     0    | Time\n", ss.str());
}

TEST(ToDoList, displayCompleted1){
    ToDoList testList = ToDoList();
    testList.add(new Item(true));

    // Test displayCompleted function 
    stringstream ss;
    testList.displayCompleted(ss);
    EXPECT_EQ("Completion | Name                | Priority | Time\n----------------------------------------------------\n    [X]    | Name                |     0    | Time\n", ss.str());
}

TEST(ToDoList, displayCompleted2){
    ToDoList testList = ToDoList();
    testList.add(new Item(false));

    // Test displayCompleted function 
    stringstream ss;
    testList.displayCompleted(ss);
    EXPECT_EQ("Completion | Name                | Priority | Time\n----------------------------------------------------\n", ss.str());
}

TEST(ToDoList, displayIncompleted1){
    ToDoList testList = ToDoList();
    testList.add(new Item(false));

    // Test displayIncompleted function 
    stringstream ss;
    testList.displayIncompleted(ss);
    EXPECT_EQ("Completion | Name                | Priority | Time\n----------------------------------------------------\n    [ ]    | Name                |     0    | Time\n", ss.str());
}

TEST(ToDoList, displayIncompleted2){
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