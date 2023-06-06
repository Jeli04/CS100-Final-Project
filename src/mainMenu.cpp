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

const char mainMenu::addTask() {
    char userChoice;
    int choice;
    Task newTask = Task();
    string taskName;
    string taskDesc;
    string taskDate;
    int taskPriority;

    cin.ignore();
    cout << endl;
    cout << "\t\tCreate a Task" << endl;
    cout << "--------------------------------------------------" << endl;
    cout << endl;

    cout << "\tEnter Task Name: ";
    getline(cin, taskName);
    newTask.setName(taskName);
    cout << endl;

    cout << "\tEnter Task Description: \n";
    cout << "\t ";
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
    cout << "\tNew Task has been created!" << endl;
    cout << "--------------------------------------------------" << endl;
    cout << endl;

    cout << "\tH) Home Q) Quit B) Back\t" << endl;
    cout << "\tEnter Your Choice: ";

    while(true){
        cin >> userChoice;
        switch(userChoice) {
            case 'H':
                return 'H';
            case 'B':
                return 'B';
            case 'Q':
                return 'Q';
            default:
                cout << "Invalid option please enter a invalid choice" << endl;
                break;
        }
    }
    return ' ';

}

const char mainMenu::addCourse() {
    char userChoice;
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

    cout << "\tH) Home Q) Quit B) Back\t" << endl;
    cout << "\tEnter Your Choice: ";

    while(true){
        cin >> userChoice;
        switch(userChoice) {
            case 'H':
                return 'H';
            case 'B':
                return 'B';
            case 'Q':
                return 'Q';
            default:
                cout << "Invalid option please enter a invalid choice" << endl;
                break;
        }
    }
    return ' ';
}

