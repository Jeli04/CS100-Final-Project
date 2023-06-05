#include "gtest/gtest.h"
#include "../header/day.h" 
#include "../header/course.h" 
#include "../header/task.h" 
#include "../header/event.h" 


TEST(Day, displayDayInfoTest1){
  ToDoList* testList = new ToDoList();
  testList->add(new Course({"Monday"}, "Instructor"));
  testList->getAllItems().back()->setName("Course");
  testList->getAllItems().back()->setDate("05/24/2023");
  testList->getAllItems().back()->setLocation("UCR");
  testList->getAllItems().back()->setPriority(3);
  testList->getAllItems().back()->setItemCompletion(true);

  testList->add(new Task());
  testList->getAllItems().front()->setName("Task");
  testList->getAllItems().front()->setDate("05/24/2023");
  testList->getAllItems().front()->setItemCompletion(true);


  testList->add(new Event());
  testList->getAllItems().front()->setName("Event");
  testList->getAllItems().front()->setDate("05/24/2023");
  testList->getAllItems().front()->setItemCompletion(true);

  // cout << testList->getAllItems().front()->getType() << endl;

  Day day = Day(testList, "05/24/2023");
  stringstream ss;

  day.displayDayInfo(ss);

  EXPECT_EQ("--------------------------------------------------\n                  Wed, May 24\n--------------------------------------------------\n\t Event: Event\n--------------------------------------------------\n\t Event Type: Other\n\t Event Description: \n\t \n\t Event Location: \n\t Event Date: 05/24/2023\n\t Event Completed: 1\n--------------------------------------------------\n\n\t Task: Task\n--------------------------------------------------\n\t Task Description: \n\t \n\t Finish By: 05/24/2023\n\t Task Priority: 0\n\t Status of Completion: 1\n--------------------------------------------------\n\n\t Course Name: Course\n--------------------------------------------------\n\t Instructor: Instructor\n\t Meeting Times: Monday\n\t Class Location: UCR\n\t Class Priority: 3\n\t Status of Completion: 1\n--------------------------------------------------\n\n\t List of Assignments\n--------------------------------------------------\n", ss.str());

}

TEST(Day, displayDayInfoTest2){
  ToDoList* testList = new ToDoList();
  testList->add(new Course({"Monday"}, "Instructor"));
  testList->getAllItems().back()->setName("Course");
  testList->getAllItems().back()->setDate("05/24/2023");
  testList->getAllItems().back()->setLocation("UCR");
  testList->getAllItems().back()->setPriority(3);
  testList->getAllItems().back()->setItemCompletion(true);

  Day day = Day(testList, "05/24/2023");
  stringstream ss;

  day.displayDayInfo(ss);

  EXPECT_EQ("--------------------------------------------------\n                  Wed, May 24\n--------------------------------------------------\n\t Course Name: Course\n--------------------------------------------------\n\t Instructor: Instructor\n\t Meeting Times: Monday\n\t Class Location: UCR\n\t Class Priority: 3\n\t Status of Completion: 1\n--------------------------------------------------\n\n\t List of Assignments\n--------------------------------------------------\n", ss.str());

}

TEST(Day, displayDayInfoTest3){
  ToDoList* testList = new ToDoList();

  Day day = Day(testList, "05/24/2023");
  stringstream ss;

  day.displayDayInfo(ss);

  EXPECT_EQ("--------------------------------------------------\n                  Wed, May 24\n--------------------------------------------------\n", ss.str());

}