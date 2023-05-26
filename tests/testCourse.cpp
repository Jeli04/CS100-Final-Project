#include <gtest/gtest.h>
#include "../header/item.h"
#include "../header/course.h"
#include <string>


using namespace std;




TEST(CourseTests, testInstructor){
   vector<string> days = {"Monday", "Wednesday"};
   Course math(days, "Mrs. Brown");
   EXPECT_EQ(math.GetInstructorName(), "Mrs. Brown");
}


TEST(CourseTests, testName){
   vector<string> days = {"Monday", "Wednesday"};
   Course math(days, "Mrs. Brown");
   math.setName("Math");
   EXPECT_EQ(math.getName(), "Math");
}


TEST(CourseTests, testLocation){
   Course math;
   math.setLocation("Pierce Hall");
   EXPECT_EQ(math.getLocation(),"Pierce Hall");
}


TEST(CourseTests, testDescription){
   Course math;
   math.setDescription("Math 10a Multivariable Calc Section 004");
   EXPECT_EQ(math.getDescription(),"Math 10a Multivariable Calc Section 004");
}


TEST(CourseTests, testOccuringDays){
   Course math;
   vector<string> days = {"Monday", "Wednesday"};
   math.SetOccuringDays(days);
   EXPECT_TRUE(math.GetOccuringDays() == days);
}




int main(int argc, char **argv) {
 ::testing::InitGoogleTest(&argc, argv);
 return RUN_ALL_TESTS();
}
