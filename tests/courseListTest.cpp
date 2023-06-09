#include "gtest/gtest.h"
#include <gmock/gmock.h>
#include <gmock/gmock-matchers.h>
#include "../header/toDoList.h"
#include "../header/item.h"
#include "../header/task.h"
#include "../header/container.h"
#include "../header/courseList.h"


TEST(CourseListTest, addToList)
{
    CourseList testList = CourseList("UCR");
    list<Item*> expectedList;
    Task *newItem = new Task();
    newItem->setItemCompletion(false);

    Task *anotherItem= new Task();
    anotherItem->setName("homework");
    anotherItem->setDate("06/04/2023");
    anotherItem->setLocation("here");
    anotherItem->setDescription("finish on canvas");
    anotherItem->setPriority(3);
    anotherItem->setItemCompletion(false);    

    Task *newItemExpect = new Task();
    newItemExpect->setItemCompletion(false);

    Task *anotherItemExpect = new Task();
    anotherItemExpect->setName("homework");
    anotherItemExpect->setDate("06/04/2023");
    anotherItemExpect->setLocation("here");
    anotherItemExpect->setDescription("finish on canvas");
    anotherItemExpect->setPriority(3);
    anotherItemExpect->setItemCompletion(false);
    
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
    CourseList testList = CourseList("UCR");
    list<Item*> expectedList;

   Item *testItem1 = new Task();
    testItem1->setName("homework");
    testItem1->setDate("06/04/2023");
    testItem1->setLocation("here");
    testItem1->setDescription("finish on canvas");
    testItem1->setPriority(3);
    testItem1->setItemCompletion(false);
    
    Item *testItem2 = new Task();
    testItem2->setName("project");
    testItem2->setDate("06/04/2023");
    testItem2->setLocation("there");
    testItem2->setDescription("finish on gradescope");
    testItem2->setPriority(1);
    testItem2->setItemCompletion(true);  
    
    Item *testItem3 = new Task();
    testItem3->setItemCompletion(false);  

    Item *expected1 = new Task();
    expected1->setItemCompletion(false);

    Item *expected2 = new Task();
    expected2->setName("project");
    expected2->setDate("06/04/2023");
    expected2->setLocation("there");
    expected2->setDescription("finish on gradescope");
    expected2->setPriority(1);
    expected2->setItemCompletion(true);  

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
    CourseList testList = CourseList("UCR");
    testList.add(new Task());
    testList.getAllItems().front()->setItemCompletion(true);
    // Test GetItemCount
    EXPECT_EQ(testList.getItemCount(), 1);
}

TEST(CourseListTest, DisplayAll1){
    CourseList testList = CourseList("UCR");
    testList.add(new Task());
    testList.getAllItems().front()->setItemCompletion(false);
    
    // Test displayAll function 
    stringstream ss;
    testList.displayAll(ss);
    EXPECT_EQ("                    UCR\n    Course Name         | Priority | Time\n----------------------------------------------------\n                        |     0    | \n", ss.str());
}

TEST(CourseListTest, DisplayAll2){
    CourseList testList = CourseList("UCR");
    testList.add(new Task());
    testList.getAllItems().front()->setName("Item1");
    testList.getAllItems().front()->setItemCompletion(false);

    testList.add(new Task());
    testList.getAllItems().front()->setName("Item2");
    testList.getAllItems().front()->setItemCompletion(false);

    testList.add(new Task());
    testList.getAllItems().front()->setName("Item3");
    testList.getAllItems().front()->setItemCompletion(true);

    // Test displayAll function 
    stringstream ss;
    testList.displayAll(ss);
    EXPECT_EQ("                    UCR\n    Course Name         | Priority | Time\n----------------------------------------------------\n    Item3               |     0    | \n    Item2               |     0    | \n    Item1               |     0    | \n", ss.str());
}
