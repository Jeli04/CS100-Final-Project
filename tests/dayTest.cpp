#include "gtest/gtest.h"
#include "../header/day.h"

TEST(Day, displayDayInfoTest1){
  ToDoList* testList = new ToDoList();
  testList->add(new Item(true));
  Day day = Day(testList, "05/24/2023");
  stringstream ss;

  day.displayDayInfo(ss);

  EXPECT_EQ("", ss.str());

}

// int main(int argc, char** argv) {
//   ::testing::InitGoogleTest(&argc, argv);
//   return RUN_ALL_TESTS();
// }