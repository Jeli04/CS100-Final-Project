#include <gtest/gtest.h>
#include "../header/item.h"
#include "../header/course.h"
#include "../header/event.h"
#include "../header/task.h"
#include <string>

using namespace std;

TEST(ItemTests, testName){
    Task task1;
    task1.setName("Math homework");
    EXPECT_EQ(task1.getName(), "Math homework");
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}