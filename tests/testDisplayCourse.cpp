#include <gtest/gtest.h>
#include "../header/item.h"
#include "../header/course.h"
#include "../header/task.h"
#include <string>
#include <vector>
#include <sstream>

using namespace std;


TEST(DisplayTests, testDisplay) {
    vector<string> days;
    stringstream ss;
    days.push_back("Monday");
    days.push_back("Friday");
    Course* newCourse = new Course();
    
    newCourse->setName("Applied Linear Algebra");
    newCourse->SetInstructorName("Mr. Kalley");
    newCourse->SetOccuringDays(days);
    newCourse->setDate("10/23/2003");
    newCourse->setLocation("Winston Chung");
    newCourse->setPriority(1);
    newCourse->setItemCompletion(true);

    newCourse->displayItemInfo(ss);

    EXPECT_EQ(
        "\t Course Name: Applied Linear Algebra\n--------------------------------------------------\n\t Instructor: Mr. Kalley\n\t Meeting Times: Monday, Friday\n\t Class Location: Winston Chung\n\t Class Priority: 1\n\t Status of Completion: 1\n--------------------------------------------------\n\n\t List of Assignments\n--------------------------------------------------\n", ss.str()
    );
}

TEST(DisplayTests, testDisplayOneAssignment) {
    vector<string> days;
    stringstream ss;
    days.push_back("Tuesday");
    days.push_back("Thursday");
    Course* newCourse = new Course();
    Task* newTask = new Task();

    newCourse->setName("English 10C");
    newCourse->SetInstructorName("Mrs. Melley");
    newCourse->SetOccuringDays(days);
    newCourse->setDate("10/23/2003");
    newCourse->setLocation("Sproul Hall");
    newCourse->setPriority(1);

    newTask->setName("Chapter 5: Shakespeare");
    newTask->setDescription("Understanding Literary Works");
    newTask->setDate("10/23/23");
    newTask->setPriority(3);
    newTask->setItemCompletion(false);

    newCourse->createAssignment(newTask);
    newCourse->displayItemInfo(ss);    
    EXPECT_EQ(
        "\t Course Name: English 10C\n--------------------------------------------------\n\t Instructor: Mrs. Melley\n\t Meeting Times: Tuesday, Thursday\n\t Class Location: Sproul Hall\n\t Class Priority: 1\n\t Status of Completion: 0\n--------------------------------------------------\n\n\t List of Assignments\n--------------------------------------------------\n\t Task: Chapter 5: Shakespeare\n--------------------------------------------------\n\t Task Description: \n\t Understanding Literary Works\n\t Finish By: 10/23/23\n\t Task Priority: 3\n\t Status of Completion: 0\n--------------------------------------------------\n\n--------------------------------------------------\n", ss.str()
    );
}

TEST(DisplayTests, testDisplayTwoAssignments) {
    vector<string> days;
    stringstream ss;
    days.push_back("Tuesday");
    days.push_back("Thursday");
    Course* newCourse = new Course();
    Task* newTask = new Task();
    Task* newTask2 = new Task();

    newCourse->setName("Differential Equations");
    newCourse->SetInstructorName("FNU Ishan");
    newCourse->SetOccuringDays(days);
    newCourse->setDate("10/23/2003");
    newCourse->setLocation("Sproul Hall");
    newCourse->setPriority(2);
    newCourse->setItemCompletion(true);

    newTask->setName("Chapter 5: Linear Equations");
    newTask->setDescription("This homework emphasises gaussian elimination and elementary row operations");
    newTask->setDate("10/23/23");
    newTask->setPriority(1);
    newTask->setItemCompletion(false);

    newTask2->setName("Gradient Descent");
    newTask2->setDescription("How to utilize weights for adjunct functions");
    newTask2->setDate("11/01/23");
    newTask2->setPriority(2);
    newTask2->setItemCompletion(true);

    newCourse->createAssignment(newTask);
    newCourse->createAssignment(newTask2);

    newCourse->displayItemInfo(ss);

    EXPECT_EQ(
        "\t Course Name: Differential Equations\n--------------------------------------------------\n\t Instructor: FNU Ishan\n\t Meeting Times: Tuesday, Thursday\n\t Class Location: Sproul Hall\n\t Class Priority: 2\n\t Status of Completion: 1\n--------------------------------------------------\n\n\t List of Assignments\n--------------------------------------------------\n\t Task: Chapter 5: Linear Equations\n--------------------------------------------------\n\t Task Description: \n\t This homework emphasises gaussian elimination and elementary row operations\n\t Finish By: 10/23/23\n\t Task Priority: 1\n\t Status of Completion: 0\n--------------------------------------------------\n\n--------------------------------------------------\n\t Task: Gradient Descent\n--------------------------------------------------\n\t Task Description: \n\t How to utilize weights for adjunct functions\n\t Finish By: 11/01/23\n\t Task Priority: 2\n\t Status of Completion: 1\n--------------------------------------------------\n\n--------------------------------------------------\n", ss.str()
    );

}