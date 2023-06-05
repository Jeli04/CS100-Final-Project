#include "gtest/gtest.h"
#include "../header/day.h" 
#include "../header/course.h" 
#include "../header/task.h" 
#include "../header/event.h" 


TEST(Day, displayDayInfoTest1){
  ToDoList* testList = new ToDoList();
  testList->add(new Course("Name", "05/24/2023", true));
  testList->add(new Task("Name", "05/24/2023", true));
  testList->add(new Event("Name", "05/24/2023", true));

  Day day = Day(testList, "05/24/2023");
  stringstream ss;

  day.displayDayInfo(ss);

  EXPECT_EQ("-------------------------\n      Wed, May 24\n-------------------------\nItem info\nItem info\nItem info\n", ss.str());

}

TEST(Day, displayDayInfoTest2){
  ToDoList* testList = new ToDoList();
  testList->add(new Course("Name", "05/24/2023", true));
  testList->add(new Task("Name", "05/23/2023", true));
  testList->add(new Event("Name", "05/23/2023", true));

  Day day = Day(testList, "05/24/2023");
  stringstream ss;

  day.displayDayInfo(ss);

  EXPECT_EQ("-------------------------\n      Wed, May 24\n-------------------------\nItem info\n", ss.str());

}

TEST(Day, displayDayInfoTest3){
  ToDoList* testList = new ToDoList();


  Day day = Day(testList, "05/24/2023");
  stringstream ss;

  day.displayDayInfo(ss);

  EXPECT_EQ("-------------------------\n      Wed, May 24\n-------------------------\n", ss.str());

}