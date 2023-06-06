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
#include <cctype>
#include <limits>

using namespace std;


MainMenu::MainMenu(){
    ToDoList* toDoList = new ToDoList();
    CourseList* courseList = nullptr;
    Calendar* calendar = nullptr;
    itemToAccess = "";
}

const char MainMenu::homePrompt(ostream& ss){
    // ss << "Welcome to Priority Flow" << endl;
    // ss << "Please enter 'T' to view your To-Do-List" << endl;
    // ss << "Please enter 'S' to view your Course List" << endl;
    // ss << "Please enter 'C' to view your Calendar" << endl;

    manageToDoList(cout);
}

const char MainMenu::coursePrompt(ostream& ss){
    // prompt the user to enter the name of the course 

    // prompt the user for the course information to manage (add/delete/edit) and validate user input

    // prompt the user to go home, quit, or back (return value)
}
    
const char mainMenu::taskPrompt() {
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
    
const char MainMenu::eventPrompt(ostream& ss){
    // prompt the user to enter the event name
    char userChoice = '\0';
    Event newEvent = Event();
    string eventName = "";
    string eventDesc = "";
    string eventDate = "";
    int eventType = 0;
    int eventPriority = 0;
    int eventLength = 0;

    // prompt the user for the event information to manage (add/delete/edit) and validate user input 
    cin.ignore();
    cout << endl;
    cout << "                 Add an Event" << endl;
    cout << "--------------------------------------------------" << endl;
    cout << endl;

    cout << "Enter Event Name: ";
    getline(cin, eventName);
    newEvent.setName(eventName);
    cout << endl << endl;

    cout << "Enter Event Description: \n";
    getline(cin, eventDesc);
    newEvent.setDescription(eventDesc);
    cout << endl << endl;

    cout << "Enter Event Date: ";
    getline(cin, eventDate);
    newEvent.setDate(eventDate);
    cout << endl << endl;

    cout << "Enter Event Priority: ";
    cin >> eventPriority;
    newEvent.setPriority(eventPriority);
    cout << endl << endl;

    cout << "1. Birthday" << endl;
    cout << "2. Meeting" << endl;
    cout << "3. Appointment" << endl;
    cout << "4. Other" << endl;
    cout << "Enter the type of Event[1-4]: ";
    cin >> eventType;

    //input validation
    while(cin.fail() || eventType < 1 || eventType > 4){
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(),'\n');
        cout << "----Invalid Input: Enter a number[1-4]----" << endl;
        cout << "Enter the type of Event[1-4]: ";
        cin >> eventType;
        cout << endl << endl;
    }
    newEvent.setEventType(eventType);

    cout << "Enter Event Length: ";
    cin >> eventLength;

    //input validation
    while (cin.fail()){
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(),'\n');
        cout << "----Invalid Input: Enter Number----" << endl;
        cout << "Enter Event Length: ";
        cin >> eventLength;
        cout << endl << endl;
    }
    newEvent.setLength(eventLength);

    newEvent.setItemCompletion(false);

    cout << "--------------------------------------------------" << endl;
    cout << "         New Event has been created!" << endl;
    cout << "--------------------------------------------------" << endl;
    cout << endl;

    // prompt the user to go home, quit, or back (return value)
    cout << "H) Home Q) Quit B) Back\t" << endl;
    cout << "Enter Your Choice[H,Q,B]: ";
    cin >> userChoice;
    cout << endl;

    while (cin.fail() || (tolower(userChoice) != 'h' && tolower(userChoice) != 'q' && tolower(userChoice) != 'b')){
        if (cin.fail()){
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(),'\n');
        }
        cin.ignore(numeric_limits<streamsize>::max(),'\n');
        cout << "----Invalid Input: Enter H, Q, or B----" << endl;
        cout << "H) Home Q) Quit B) Back" << endl;
        cout << "Enter Your Choice[H,Q,B]: ";
        cin >> userChoice;
        cout << endl << endl;
    }
    

}

const char MainMenu::manageCalendar(ostream& ss){
    // call the calendar display function here
    ss << "Please enter 'D' to view a specific day" << endl;
    ss << "Please enter 'B' to go back" << endl;

    // ask the user to select a day, go home, or quit

    // if the user selects day return 'D' (implement the day function as well)

    // prompt the user to go home, quit, or back (return value)


}

const char MainMenu::dayPrompt(ostream& ss){
    // Ask the user to enter a date in 00/00/2000 format
    // call the display day function

    // prompt the user if they want to add, edit, delete an item from the day, or return home/quit

    // prompt the user to go home, quit, or back (return value)

}

const char mainMenu::manageCourse() {
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
        }
    }
  return " ";
}


const char MainMenu::manageToDoList(ostream& ss){
    if(toDoList == nullptr){toDoList = new ToDoList();}
    // TEST CODE

    // Task* task1 = new Task();
    // task1->setName("Item 1");
    // Task* task2 = new Task();    
    // task2->setName("Item 2"); 
    // Task* task3 = new Task();
    // task3->setName("Item 3");
    // Task* task4 = new Task();
    // task4->setName("Item 4");

    // toDoList->add(task1);
    // toDoList->add(task2);
    // toDoList->add(task3);
    // toDoList->add(task4);


    toDoList->displayAll(ss);
    ss << endl;

    // ss << "Please enter 'V' to view an item on your To-Do-List" << endl;
    // ss << "Please enter 'A' to add an item onto your To-Do-List" << endl;
    // ss << "Please enter 'D' to delete an item on your To-Do-List" << endl;
    // ss << "Please enter 'E' to edit an item on your To-Do-List" << endl;
    // ss << "Please enter 'H' to go back Home" << endl;
    // ss << "Please enter 'Q' to quit the program" << endl;

    cout << "V) View A) Add E) Edit H) Home Q) Quit B) Back\t" << endl;
    cout << "Enter Your Choice: ";

    while(true){
        cin >> userChoice;
        switch(userChoice){
            case 'V':
                // ss << "Enter the name of the item to view" << endl;
                // cin >> itemToAccess;
                // item = toDoList->getItem(itemToAccess);
                // if(item == nullptr){
                //     ss << "This item does not exist" << endl;
                // }
                // else{
                //     item->displayItemInfo(ss);
                // }
                return 'V';
            case 'A':
                return 'A';
            case 'D':
                return 'D';
            case 'H':
                return 'H';
            case 'Q':
                return 'Q';
            default:
                ss << "Invalid option please enter a invalid choice" << endl;
                break;
        }
    }
    return ' ';
}

    


int main(){
    MainMenu mainMenu = MainMenu();
    mainMenu.manageToDoList(cout);

    return 0;
}

// prompt the user to enter a choice
// that function will return the choice as a char 
// a while loop that keeps on running until a char of q is returned
// this ends the program 
