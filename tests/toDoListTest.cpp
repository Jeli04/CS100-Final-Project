#include "gtest/gtest.h"
#include "../header/toDoList.h"

TEST(ToDoList, ToDoListTests){
    ToDoList TestList = ToDoList();
    EXPECT_EQ(TestList.GetItemCount(), 0);
}