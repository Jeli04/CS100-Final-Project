#include "../header/mainMenu.h"
#include "../header/toDoList.h"
#include "../header/courseList.h"
#include "../header/item.h"
#include "../header/task.h"
#include "../header/course.h"
#include <iostream>
#include <vector>
#include <sstream>
#include <string>

using namespace std;

void mainMenu::addTask(ostream&) {
    int choice;
    Task newTask = Task();
    string taskName;
    string taskDesc;
    string taskDate;
    int taskPriority;

    cout << "\t\tCreate a Task" << endl;
    cout << "--------------------------------------------------" << endl;
    cout << endl;

    cout << "\tEnter Task Name: ";
    getline(cin, taskName);
    newTask.setName(taskName);
    cout << endl;

    cout << "\tEnter Task Description: \n";
    cout << endl;
    getline(cin, taskDesc);
    newTask.setDescription(taskDesc);
    cout << endl;

    cout << "\tEnter Due Date: ";
    getline(cin, taskDate);
    newTask.setDate(taskDate);
    cout << endl;

    cout << "\tEnter Task Priority: ";
    cin >> taskPriority;
    newTask.setPriority(taskPriority);
    cout << endl;

    newTask.setItemCompletion(false);


    cout << "--------------------------------------------------" << endl;
    cout << "\tNew Class has been created!" << endl;
    cout << "--------------------------------------------------" << endl;
    cout << endl;

    cout << "1) Home 2) Calendar 3) Course List 4) Todo List\t" << endl;
    cout << "\tEnter Your Choice: ";
    cin >> choice;
    cout << endl;

}

void mainMenu::addCourse(ostream&) {
    int choice;
    Course newCourse = Course();
    string courseName;
    string courseInstructor;
    string courseLoc;
    int coursePriority;
    string status;

    int count;
    int x = 0;
    vector<string> days;
    string day;
    cout << endl;
    cout << "\t\tCreate a Course" << endl;
    cout << "--------------------------------------------------" << endl;
    cout << endl;
    cout << "\tEnter Name of Course: ";
    getline(cin, courseName);
    newCourse.setName(courseName);
    cout << endl;
    cout << "\tEnter Instructor Name: ";
    getline(cin, courseInstructor);
    newCourse.SetInstructorName(courseInstructor);
    cout << endl;
    cout << "\tEnter number of days a week: ";
    cin >> count;
    cout << endl;

    while (x < count) {
        cout << "\tEnter Day " << x + 1 << ": ";
        cin >> day;

        cout << endl;
        days.push_back(day);
        x++;
    }

    newCourse.SetOccuringDays(days);
    cin.ignore();

    
    cout << "\tEnter Location Of Class: ";
    getline(cin, courseLoc);
    newCourse.setLocation(courseLoc);
    cout << endl;

    cout << "\tEnter Priority (Urgency): ";
    cin >> coursePriority;
    newCourse.setPriority(coursePriority);
    cout << endl;

    newCourse.setItemCompletion(0);

    cout << "--------------------------------------------------" << endl;
    cout << "\tNew Class has been created!" << endl;
    cout << "--------------------------------------------------" << endl;
    cout << endl;

    cout << "1) Home 2) Calendar 3) Course List 4) Todo List\t" << endl;
    cout << "\tEnter Your Choice: ";
    cin >> choice;
    cout << endl;
    /*if (choice == 1) {
        MainMenu();
    } else if (choice == 2) {
        viewCalendar();
    } else if (choice == 3) {
        viewCourseList();
    } else if (choice == 4) {
        viewToDoList();
    } else {
        throw runtime_error("Invalid choice");
    }  */
}

