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
#include <regex>

using namespace std;


MainMenu::MainMenu(){
    ToDoList* toDoList = new ToDoList();
    CourseList* courseList = nullptr;
    Calendar* calendar = nullptr;
    itemToAccess = "";
}

const char MainMenu::homePrompt(){
    int userChoice;
    cout << "           Welcome to Priority Flow!" << endl;
    cout << "--------------------------------------------------" << endl;
    cout << "1. Add a Task" << endl;
    cout << "2. Add an Event" << endl;
    cout << "3. Add a Course" << endl;
    cout << "4. View Calendar" << endl;
    cout << "5. View ToDoList" << endl;
    cout << "6. View CourseList" << endl;
    cout << "Please enter your option[1-6]: " << endl;

    cin >> userChoice;
    while (cin.fail() || (userChoice < 1) || (userChoice > 6)){
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(),'\n');
        cout << "----Invalid Input: Enter Number[1-6]----" << endl;
        cout << "Please enter your option[1-6]: ";
        cin >> userChoice;
        cout << endl << endl;
    }

    // switch(userChoice){
    //     case 1:
    //         taskPrompt();
    //     case 2:
    //         eventPrompt()
    //     case 3:
    //         coursePrompt();
    //     case 4: 
    //         calendar->displayAll();
    //     case 5: 
    //         toDoList->displayAll();
    //     case 6: 
    //         courseList->displayAll();
    // }
    return ' ';
}

// const char MainMenu::coursePrompt(ostream& ss){
//     // prompt the user to enter the name of the course 

//     // prompt the user for the course information to manage (add/delete/edit) and validate user input

//     // prompt the user to go home, quit, or back (return value)

//     return ' ';
// }

const char MainMenu::coursePrompt() {
    Course* newCourse = new Course();
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
    newCourse->setName(courseName);
    cout << endl;

    cout << "\tEnter Instructor Name: ";
    getline(cin, courseInstructor);
    newCourse->SetInstructorName(courseInstructor);
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

    newCourse->SetOccuringDays(days);
    cin.ignore();

    
    cout << "\tEnter Location Of Class: ";
    getline(cin, courseLoc);
    newCourse->setLocation(courseLoc);
    cout << endl;

    cout << "\tEnter Priority (Urgency): ";
    cin >> coursePriority;
    newCourse->setPriority(coursePriority);
    cout << endl;

    newCourse->setItemCompletion(0);

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
  return ' ';
}

    
const char MainMenu::taskPrompt() {
    int choice;
    Task* newTask = new Task();
    string taskName;
    string taskSubject;
    string taskDesc;
    string taskDate;
    int taskPriority;

    
    cout << endl;
    cout << "\t\tCreate a Task" << endl;
    cout << "--------------------------------------------------" << endl;
    cout << endl;

    cout << "\tEnter Task Name: ";
    getline(cin, taskName);
    newTask->setName(taskName);
    cout << endl;

    cout << "\tEnter Task School Subject (Enter if none): ";
    getline(cin, taskSubject);
    newTask->setSubject(taskSubject);
    cout << endl;

    cout << "\tEnter Task Description: \n";
    cout << "\t ";
    getline(cin, taskDesc);
    newTask->setDescription(taskDesc);
    cout << endl;

    cout << "\tEnter Due Date: ";
    getline(cin, taskDate);
    while (!isValidDateFormat(taskDate)){
        cout << endl;
        cout << "\tPlease re-enter valid date..." << endl;
        cout << "\t";
        getline(cin, taskDate);
        if (isValidDateFormat(taskDate)) {
            break;
        }
    }

    newTask->setDate(taskDate);
    cout << endl;

    cout << "\tEnter Task Priority: ";
    cin >> taskPriority;
    newTask->setPriority(taskPriority);
    cout << endl;

    newTask->setItemCompletion(false);

    toDoList->add(newTask); 

    cout << "--------------------------------------------------" << endl;
    cout << "\tNew Task has been created!" << endl;
    cout << "--------------------------------------------------" << endl;
    cout << endl;

    cout << "\tH) Home Q) Quit B) Back\t" << endl;
    cout << "\tEnter Your Choice: ";


    // while(true){
    //     cin >> userChoice;
    //     switch(userChoice) {
    //         case 'H':
    //             return 'H';
    //         case 'B':
    //             return 'B';
    //         case 'Q':
    //             return 'Q';
    //         default:
    //             cout << "Invalid option please enter a invalid choice" << endl;
    //             break;
    //     }
    // }
    return ' ';

}
    
const char MainMenu::eventPrompt(){
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

    //event type
    cout << "1. Birthday" << endl;
    cout << "2. Meeting" << endl;
    cout << "3. Appointment" << endl;
    cout << "4. Other" << endl;
    cout << "Enter the type of Event[1-4]: ";
    cin >> eventType;
    cout << endl << endl;

    //input validation
    while(cin.fail() || eventType < 1 || eventType > 4){
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(),'\n');
        cout << "----Invalid Input: Enter a number[1-4]----" << endl;
        cout << "Enter the type of Event[1-4]: ";
        cin >> eventType;
        cout << endl << endl;
    }
    
    switch(eventType){
        case 1:
            newEvent.setEventType(Birthday);
        case 2:
            newEvent.setEventType(Meeting);
        case 3:
            newEvent.setEventType(Appointment);
        case 4:
            newEvent.setEventType(Other);
    }

    //event length
    cout << "Enter Event Length: ";
    cin >> eventLength;
    cout << endl << endl;
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
        }
        cin.ignore(numeric_limits<streamsize>::max(),'\n');
        cout << "----Invalid Input: Enter H, Q, or B----" << endl;
        cout << "H) Home Q) Quit B) Back" << endl;
        cout << "Enter Your Choice[H,Q,B]: ";
        cin >> userChoice;
        cout << endl << endl;
    }

    return ' ';
}

const char MainMenu::manageCalendar(ostream& ss){
    // call the calendar display function here
    ss << "Please enter 'D' to view a specific day" << endl;
    ss << "Please enter 'B' to go back" << endl;

    // ask the user to select a day, go home, or quit

    // if the user selects day return 'D' (implement the day function as well)

    // prompt the user to go home, quit, or back (return value)

    return ' ';

}

const char MainMenu::dayPrompt(ostream& ss){
    // Ask the user to enter a date in 00/00/2000 format
    // call the display day function

    // prompt the user if they want to add, edit, delete an item from the day, or return home/quit

    // prompt the user to go home, quit, or back (return value)

    return ' ';
}



const char MainMenu::manageToDoList(ostream& ss){
    if(toDoList == nullptr){toDoList = new ToDoList();}
 
    toDoList->displayAll(ss);
    ss << endl;

    cout << "V) View A) Add E) Edit H) Home Q) Quit B) Back\t" << endl;
    cout << "Enter Your Choice: ";

    string itemType; 
    while(true){
        cin >> userChoice;
        switch(userChoice){
            Item* item;
            case 'V':
                ss << "Enter the name of the item to view: ";
                cin >> itemToAccess;
                ss << endl;
                item = toDoList->getItem(itemToAccess);
                if(item == nullptr){
                    ss << "This item does not exist" << endl;
                }
                else{
                    item->displayItemInfo(ss);
                }
                // return 'V';
                break;
            case 'A':
                ss << "What type of item do you want to add (Task/Course/Event): ";
                cin >> itemType;
                while(itemType != "Task" && itemType != "Course" && itemType != "Event"){
                    ss << "Invalid item type (Task/Course/Event): ";
                    cin >> itemType;
                }
                if(itemType == "Task"){return 'T';}
                if(itemType == "Course"){return 'C';}
                if(itemType == "Event"){return 'E';}
                break;
            case 'D':
                return 'D';
            case 'E':
                ss << "Enter the name of the item to edit: ";
                cin >> itemToAccess;
                ss << endl;
                item = toDoList->getItem(itemToAccess);
                if(item == nullptr){
                    ss << "This item does not exist" << endl;
                    return 'H';
                }
                else{
                    item->edit();
                }
                // return 'E';
                break;
            case 'H':
                return 'H';
            case 'B':
                return 'B';
            case 'Q':
                return 'Q';
            default:
                ss << "Invalid option please enter a invalid choice: ";
                break;
        }
    }
    return ' ';
}

bool MainMenu::isValidDateFormat(const string& date) {
    // Regular expression to match MM/DD/YYYY format
    regex pattern(R"(^(0[1-9]|1[0-2])/(0[1-9]|1\d|2\d|3[01])/\d{4}$)");

    // Check if the string matches the pattern
    return std::regex_match(date, pattern);
}


int main(){
    MainMenu mainMenu = MainMenu();
    char userInput = ' ';

    mainMenu.homePrompt();
    cin >> userInput;

    while(userInput != 'Q'){
        if (userInput == 'M') {
            // Calendar 
        } else if (userInput == 'S') {
            // Course Lists
        } else if (userInput == 'L') {
            // To Do List
            userInput = mainMenu.manageToDoList(cout);
        } else if (userInput == 'C') {
            // Course
        } else if (userInput == 'E') {
            // Event
        } else if (userInput == 'D') {
            // Day
            userInput = mainMenu.coursePrompt();
        } else if (userInput == 'T') {
            // Task
            userInput = mainMenu.taskPrompt();
        } else if (userInput == 'B') {
            // Back 
        } else if(userInput == 'H'){
            // Home

        }
        else{
            cout << "Invalid option please enter a invalid choice: ";
            cin >> userInput;
            cout << endl;
        }
    }

    return 0;
}

// prompt the user to enter a choice
// that function will return the choice as a char 
// a while loop that keeps on running until a char of q is returned
// this ends the program 
