#include <gtest/gtest.h>
#include "../header/item.h"
#include "../header/course.h"
#include "../header/task.h"
#include <string>
#include <vector>
#include <sstream>

TEST(DisplayTests, testTaskDisplay) {
    stringstream ss;
    Task newTask = Task();

    newTask.setName("Go grocery shopping");
    newTask.setDescription("I need milk and some bread for french toast!");
    newTask.setDate("Today");
    newTask.setPriority(3);
    newTask.setItemCompletion(true);

    newTask.displayItemInfo(ss);

    EXPECT_EQ(
        "\t  Task: Go grocery shopping\n--------------------------------------------------\n\t  Task Description: \n\t I need milk and some bread for french toast!\n\t  Finish By: Today\n\t  Task Priority: 3\n\t  Status of Completion: 1\n", ss.str()
    );
}