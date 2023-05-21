#include "../header/display.h"
#include "../header/course.h"
#include <iostream>
#include <string>
#include <list>

using namespace std;

void displayCourse::displayCourses(Course& classes) {
    cout << "\t\tCourse Info: " << classes.getName() << endl;
    cout << "----------------------------------------" << endl;
    cout << "Meeting Times: " << classes.getTime() << endl;
    cout << "Location: " << classes.getLocation() << endl;
    cout << "Description of Class: \n" << endl;
    cout << endl;
    cout << "Priority: " << classes.getPriority() << endl;
    cout << "Completion Status: " << classes.getStatus() << endl;
    cout << "---------------------------------------" << endl;
    cout << "\t\tList of Assignments:" << endl;
    
}

