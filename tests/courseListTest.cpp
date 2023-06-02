#include "gtest/gtest.h"
#include <gmock/gmock.h>
#include <gmock/gmock-matchers.h>
#include "../header/toDoList.h"
#include "../header/item.h"
#include "../header/task.h"
#include "../header/container.h"


TEST(CourseListTest, addToList)
{
    CourseList testList;
    list<Item*> expectedList;
    Task *newItem = new Task(false);
    Task *anotherItem = new Task("homework", "tomorrow", "here", "finish on canvas", 3, "task", false);
    Task *newItemExpect = new Task(false);
    Task *anotherItemExpect = new Task("homework", "tomorrow", "here", "finish on canvas", 3, "task", false);
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

TEST(CourseListTest, deleteFromList)
{
    CourseList testList;
    list<Item*> expectedList;

    Item *testItem1 = new Task("homework", "tomorrow", "here", "finish on canvas", 3, "task", false);
    Item *testItem2 = new Task("project", "today", "there", "finish on gradescope", 1, "task", true);
    Item *testItem3 = new Task(false);;

    Item *expected1 = new Task(false);;
    Item *expected2 = new Task("homework", "tomorrow", "here", "finish on canvas", 3, "task", false);

    expectedList.push_back(expected1);
    expectedList.push_back(expected2);

    testList.add(testItem1);
    testList.add(testItem2);
    testList.add(testItem3);

    testList.deleteItem("project");
    ASSERT_EQ(testList.getAllItems().size(), expectedList.size());
    list<Item*>::iterator it1 = testList.getAllItems().begin();
    list<Item*>::iterator it2 = expectedList.begin();
    ASSERT_EQ((*it1)->getName(), (*it2)->getName());
}


TEST(CourseListTest, ItemCount){
    CourseList testList = ToDoList();
    testList.add(new Task(true));

    // Test GetItemCount
    EXPECT_EQ(testList.getItemCount(), 1);
}

TEST(CourseListTest, DisplayAll1){
    CourseList testList = ToDoList();
    testList.add(new Task(false));

    // Test displayAll function 
    stringstream ss;
    testList.displayAll(ss);
    EXPECT_EQ("Completion | Name                | Priority | Time\n----------------------------------------------------\n    [ ]    | Name                |     0    | Time\n", ss.str());
}

TEST(CourseListTest, DisplayAll2){
    CourseList testList = ToDoList();
    testList.add(new Task(false));
    testList.add(new Task(false));
    testList.add(new Task(true));

    // Test displayAll function 
    stringstream ss;
    testList.displayAll(ss);
    EXPECT_EQ("Completion | Name                | Priority | Time\n----------------------------------------------------\n    [X]    | Name                |     0    | Time\n    [ ]    | Name                |     0    | Time\n    [ ]    | Name                |     0    | Time\n", ss.str());
}

TEST(CourseListTest, DisplayCompleted1){
    CourseList testList = ToDoList();
    testList.add(new Task(true));

    // Test displayCompleted function 
    stringstream ss;
    testList.displayCompleted(ss);
    EXPECT_EQ("Completion | Name                | Priority | Time\n----------------------------------------------------\n    [X]    | Name                |     0    | Time\n", ss.str());
}

TEST(CourseListTest, DisplayCompleted2){
    CourseList testList = ToDoList();
    testList.add(new Task(false));

    // Test displayCompleted function 
    stringstream ss;
    testList.displayCompleted(ss);
    EXPECT_EQ("Completion | Name                | Priority | Time\n----------------------------------------------------\n", ss.str());
}

TEST(CourseListTest, DisplayIncompleted1){
    CourseList testList = ToDoList();
    testList.add(new Task(false));

    // Test displayIncompleted function 
    stringstream ss;
    testList.displayIncompleted(ss);
    EXPECT_EQ("Completion | Name                | Priority | Time\n----------------------------------------------------\n    [ ]    | Name                |     0    | Time\n", ss.str());
}

TEST(CourseListTest, DisplayIncompleted2){
    CourseList testList = ToDoList();
    testList.add(new Task(true));

    // Test displayIncompleted function 
    stringstream ss;
    testList.displayIncompleted(ss);
    EXPECT_EQ("Completion | Name                | Priority | Time\n----------------------------------------------------\n", ss.str());
}

int main(int argc, char** argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}