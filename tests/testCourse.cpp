#include <gtest/gtest.h>
#include "../header/item.h"
#include "../header/course.h"

TEST(CourseTests, testInstructor){
    String[] days = {Monday, Wednesday};
    Course math = new Course(days, "Mrs. Brown");
    EXPECT_EQ(math.getInstructorName, "Mrs.Brown");
}