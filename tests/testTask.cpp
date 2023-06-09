#include <gtest/gtest.h>
#include "../header/item.h"
#include "../header/task.h"
#include <string>

using namespace std;

TEST(TaskTests, testType) {
    Task newTask;
    EXPECT_EQ(newTask.getType(), "Task");
}

TEST(TaskTests, testNameSetter) {
    Task newTask;
    newTask.setName("Wash blankets");
    EXPECT_EQ(newTask.getName(), "Wash blankets");
}

TEST(TaskTests, testDateSetter) {
    Task newTask;
    newTask.setDate("11/09/2022");
    EXPECT_EQ(newTask.getDate(), "11/09/2022");
}

TEST(TaskTests, testDescriptionSetter) {
    Task newTask;
    newTask.setDescription("Wash red and white blanket");
    EXPECT_TRUE(newTask.getDescription() == "Wash red and white blanket");
}

TEST(TaskTests, testLocationSetter) {
    Task newTask;
    newTask.setLocation("Home");
    EXPECT_TRUE(newTask.getLocation() == "Home");
}

TEST(TaskTests, testPrioritySetter) {
    Task newTask;
    newTask.setPriority(9);
    EXPECT_TRUE(newTask.getPriority() == 9);
}

TEST(TaskTests, testCompletionSetter) {
    Task newTask;
    newTask.setItemCompletion(false);
    EXPECT_EQ(newTask.getStatus(), false);
}

// int main(int argc, char **argv) {
//  ::testing::InitGoogleTest(&argc, argv);
//  return RUN_ALL_TESTS();
// }
