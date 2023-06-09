#include "../header/mainMenu.h"
#include "../header/toDoList.h"
#include "../header/courseList.h"
#include "../header/item.h"
#include "../header/task.h"
#include "../header/course.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <string>
#include <cctype>
#include <limits>
#include <regex>
#include <../nlohmann/json.hpp>
#include <ctime>
#include <chrono>

using json = nlohmann::json;
using namespace std;


MainMenu::MainMenu(){
    toDoList = new ToDoList();
    courseList = nullptr;
    Calendar* calendar = nullptr;
    itemToAccess = "";

    // checks if there exists a previous history
    if(!isJSONEmpty("UserHistory/history.json")){
        json jsonData;
        ifstream inputFile("UserHistory/history.json");
        inputFile >> jsonData;

        courseList = new CourseList("");

        for(const auto& data : jsonData){
            if(data["type"] == "Task") {
                Task* newTask = new Task();
                newTask->setName(data["name"]);
                newTask->setDate(data["date"]);
                newTask->setLocation(data["location"]);
                newTask->setDescription(data["description"]);
                newTask->setPriority(data["priority"]);
                newTask->setItemCompletion(data["completion"]);
                newTask->setSubject(data["subject"]);
                toDoList->add(newTask);
            }
            else if(data["type"] == "Course"){
                Course* newCourse = new Course();
                newCourse->setName(data["name"]);
                newCourse->setDate(data["date"]);
                newCourse->setLocation(data["location"]);
                newCourse->setDescription(data["description"]);
                newCourse->setPriority(data["priority"]);
                newCourse->setItemCompletion(data["completion"]);
                newCourse->setInstructorName(data["instructor"]);

                vector<string> occuringDays;
                for(auto days : data["occuringDays"]){
                    occuringDays.push_back(days);
                }
                newCourse->setOccuringDays(occuringDays);

                for(auto assignment : data["assignments"]){
                    Item* item = toDoList->getItem(assignment);
                    if(Task* newAssignment = dynamic_cast<Task*>(item)){
                        newCourse->createAssignment(newAssignment);
                    }
                }

                courseList->add(newCourse);
            } 
            else if(data["type"] == "Event"){
                Event* newEvent = new Event();
                newEvent->setName(data["name"]);
                newEvent->setDate(data["date"]);
                newEvent->setLocation(data["location"]);
                newEvent->setDescription(data["description"]);
                newEvent->setPriority(data["priority"]);
                newEvent->setItemCompletion(data["completion"]);
                newEvent->setEventType(data["eventType"]);
                newEvent->setLength(data["length"]);
                toDoList->add(newEvent);
            }
        }
    }
}

MainMenu::~MainMenu(){
    json jsonData;
    ofstream outputFile("UserHistory/history.json");
    outputFile << ""; // erases the previous data

    if(toDoList!=nullptr){
        for(Item* item : toDoList->getAllItems()){
            json itemData;
            itemData["name"] = item->getName();
            itemData["type"] = item->getType();
            itemData["date"] = item->getDate();
            itemData["location"] = item->getLocation();
            itemData["description"] = item->getDescription();
            itemData["priority"] = item->getPriority();
            itemData["completion"] = item->getStatus();
            if(Task* taskItem = dynamic_cast<Task*>(item)){
                itemData["subject"] = taskItem->getSubject();
            }
            if(Event* eventItem = dynamic_cast<Event*>(item)){
                itemData["eventType"] = eventItem->getEventType();
                itemData["length"] = eventItem->getLength();
            }
            jsonData.push_back(itemData);
        }
    }
    if(courseList!=nullptr){
        for(Item* course : courseList->getAllItems()){
            json courseData;
            json occuringDays;
            json assignments;

            courseData["name"] = course->getName();
            courseData["type"] = course->getType();
            courseData["date"] = course->getDate();
            courseData["location"] = course->getLocation();
            courseData["description"] = course->getDescription();
            courseData["priority"] = course->getPriority();
            courseData["completion"] = course->getStatus();

            if(Course* courseItem = dynamic_cast<Course*>(course)){
                courseData["instructor"] = courseItem->getInstructorName();

                for(string day : courseItem->getOccuringDays()){
                    occuringDays.push_back(day);
                }
                courseData["occuringDays"] = occuringDays;

                for(Item* task : courseItem->getListOfAssignments()){
                    assignments.push_back(task->getName());
                }
                courseData["assignments"] = assignments;
            }

            jsonData.push_back(courseData);
        }

        delete courseList;
    }
    if(calendar!=nullptr){
        for(Item* day : calendar->getAllItems()){
            delete day;
        }
        delete calendar;
    }
    delete toDoList;    // delete toDoList at the end because courselist has assignments that are in it 

    if(outputFile.is_open()){
        outputFile << jsonData.dump(4); // dump loads the data into the json file, 4 reprsents the spacing used 
        outputFile.close();
    }

}

bool MainMenu::isJSONEmpty(const string& filename) const{
    ifstream file(filename);
    if(!file.is_open()){
        return true;    // if file is unable to be opened it should be empty
    }
    nlohmann::json data;
    file >> data;

    if(data.empty()){
        return true;
    }
    
    return false;
}

const char MainMenu::homePrompt(){
    char userChoice;

    if(previousPrompt == 'H' && currentPrompt == 'H'){cout << "           Welcome to Priority Flow!" << endl;}
    cout << "--------------------------------------------------" << endl;
    cout << "M. View Monthly Calendar" << endl;
    cout << "L. View your To-Do-List" << endl;
    cout << "S. View your Couse List" << endl;
    cout << "Q. Quit the program" << endl;
    cout << "Please enter your option[M/L/S/Q]: ";

    cin >> userChoice;
    while (cin.fail() || (userChoice != 'M' && userChoice != 'L' && userChoice != 'S' && userChoice != 'Q')){
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(),'\n');
        cout << "----Invalid Input: Enter Choices[M/L/S/Q]----" << endl;
        cout << "Please enter your option[M/L/S/Q]: ";
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

    return userChoice;
}

// const char MainMenu::coursePrompt(ostream& ss){
//     // prompt the user to enter the name of the course 

//     // prompt the user for the course information to manage (add/delete/edit) and validate user input

//     // prompt the user to go home, quit, or back (return value)

//     return ' ';
// }

const char MainMenu::coursePrompt() {
    currentPrompt = 'C';
    Course* newCourse = new Course();
    string courseName;
    string courseInstructor;
    string courseLoc;
    int coursePriority;
    string status;

    if(courseList == nullptr){
        string schoolName;
        cout << "--------------------------------------------------" << endl;
        cout << "\tEnter your school name: ";
        getline(cin, schoolName);
        courseList = new CourseList(schoolName);
        cin.ignore();
    }

    int count;
    int x = 0;
    vector<string> days;
    string day;
    cout << endl;
    cout << "\t\tCreate a Course" << endl;
    cout << "--------------------------------------------------" << endl;
    cout << endl;

    cout << "\tEnter Name of Course: ";
    cin.ignore();
    getline(cin, courseName);
    newCourse->setName(courseName);
    cout << endl;

    cout << "\tEnter Instructor Name: ";
    getline(cin, courseInstructor);
    newCourse->setInstructorName(courseInstructor);
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

    newCourse->setOccuringDays(days);
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

    courseList->add(newCourse);

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
    currentPrompt = 'T';
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
    cin.ignore();
    getline(cin, taskName);
    // checks if the item already exists
    Item* item = toDoList->getItem(taskName);
    if(item != nullptr){
        cout << "\tThis item already exists!" << endl;
        return 'L';
    }

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
    cout << "\tEnter Your Choice[H,Q,B]: ";


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
    
const char MainMenu::eventPrompt(){
    currentPrompt = 'E';
    // prompt the user to enter the event name
    char userChoice = '\0';
    Event* newEvent = new Event();
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
    newEvent->setName(eventName);
    cout << endl << endl;

    cout << "Enter Event Description: \n";
    getline(cin, eventDesc);
    newEvent->setDescription(eventDesc);
    cout << endl << endl;

    cout << "Enter Event Date: ";
    getline(cin, eventDate);
    newEvent->setDate(eventDate);
    while (!isValidDateFormat(eventDate)){
        cout << endl;
        cout << "\tPlease re-enter valid date..." << endl;
        cout << "\t";
        getline(cin, eventDate);
        if (isValidDateFormat(eventDate)) {
            break;
        }
    }
    cout << endl << endl;

    cout << "Enter Event Priority: ";
    cin >> eventPriority;
    newEvent->setPriority(eventPriority);
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
            newEvent->setEventType(Birthday);
        case 2:
            newEvent->setEventType(Meeting);
        case 3:
            newEvent->setEventType(Appointment);
        case 4:
            newEvent->setEventType(Other);
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
    newEvent->setLength(eventLength);

    newEvent->setItemCompletion(false);

    // add the event to the todolist 
    toDoList->add(newEvent);

    cout << "--------------------------------------------------" << endl;
    cout << "         New Event has been created!" << endl;
    cout << "--------------------------------------------------" << endl;
    cout << endl;

    // prompt the user to go home, quit, or back (return value)
    cout << "H) Home Q) Quit B) Back\t" << endl;
    cout << "Enter Your Choice[H,Q,B]: ";
    cout << endl;

    while(true){
        cin >> userChoice;
        cout << endl;
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

const char MainMenu::manageCalendar(ostream& ss){
    currentPrompt = 'M';
    // call the calendar display function here
    auto now = chrono::system_clock::now();
    time_t currentTime = chrono::system_clock::to_time_t(now);
    tm* currentTM = localtime(&currentTime);
    int currentYear = currentTM->tm_year + 1900; // Years since 1900
    string currYearString = to_string(currentYear);
    int currentMonth = currentTM->tm_mon + 1; // Months since January (0-11)
    string currMonthString = currentMonth >= 1 && currentMonth <= 12 ? 
                                  std::array<std::string, 12>{"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"}[currentMonth - 1] : 
                                  "Invalid month";
    int dayCount = (currentMonth == 2) ? 28 : (currentMonth == 4 || currentMonth == 6 || currentMonth == 9 || currentMonth == 11) ? 30 : 31;

    if(calendar == nullptr){
        calendar = new Calendar(currYearString, currMonthString, dayCount);
        for(int i = 1; i <= dayCount; i++){
            string date = "";
            if(currentMonth < 10){date += "0" + to_string(currentMonth) + "/";}
            else{date += currentMonth + "/";}
            if(i < 10){date+= "0" + to_string(i) + "/";}
            else{date += to_string(i) + "/";}
            date += to_string(currentYear);
            // cout << date << endl;
            calendar->addDay(new Day(toDoList, courseList, date));
        }
    }


    calendar->displayAll(ss);

    cout << "D) DayView Q) Quit B) Back\t" << endl;

    // ask the user to select a day, go home, or quit
    while(true){
        cin >> userChoice;
        switch(userChoice){
            // Item* course;
            case 'D':
                previousPrompt = 'M';
                return 'D';
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


    // if the user selects day return 'D' (implement the day function as well)


    // prompt the user to go home, quit, or back (return value)

    return 'H';

}

const char MainMenu::dayPrompt(ostream& ss){
    currentPrompt = 'D';

    cout << "Please enter a specific date (format MM/DD/YYYY): " << endl;

    cin >> itemToAccess;
    while (!isValidDateFormat(itemToAccess))
    {
        cout << "Incorrect date format, try again (format MM/DD/YYYY): " << endl;
        cin >> itemToAccess;
    }
    ss << endl;

    bool dayFound = false;
    for(Day* day : calendar->getDayList()){
        if(day->getDate() == itemToAccess){
            day->displayDayInfo(ss);
            dayFound = true;
        }
    }
    if(dayFound == false){cout << "This date is not in the calendar!" << endl;}

    // prompt the user if they want to add, edit, delete an item from the day, or return home/quit
    cout << "\tH) Home Q) Quit B) Back\t" << endl;
    cout << "\tEnter Your Choice[H,Q,B]: ";

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

    // prompt the user to go home, quit, or back (return value)

    return 'H';
}

const char MainMenu::manageCourseList(ostream& ss){
    currentPrompt = 'S';

    
    if(courseList == nullptr)
    {
        cout << "Please enter school name: " << endl;
        string schoolName;
        cin.ignore();
        getline(cin, schoolName);
        courseList = new CourseList(schoolName);
    }
 
    courseList->displayAll(ss);
    ss << endl;

    cout << "V) View A) Add D) Delete E) Edit H) Home Q) Quit B) Back\t" << endl;
    cout << "Enter Your Choice: ";

    string itemType; 
    while(true){
        cin >> userChoice;
        switch(userChoice){
            Item* course;
            case 'V':
                ss << "Enter the name of the item to view: ";
                cin >> itemToAccess;
                ss << endl;
                course = courseList->getItem(itemToAccess);
                if(course == nullptr){
                    ss << "This item does not exist" << endl;
                }
                else{
                    course->displayItemInfo(ss);
                }
                return 'L';
            case 'A':
                previousPrompt = 'S';   // updates the previous prompt 
                return 'C';
                break;
            case 'D':
                ss << "Enter the name of the item to delete: ";
                cin >> itemToAccess;
                ss << endl;
                course = courseList->getItem(itemToAccess);
                if(course == nullptr){
                    ss << "This item does not exist" << endl;
                }
                else{
                    courseList->deleteItem(itemToAccess);
                }
                return 'S';
            case 'E':
                previousPrompt = 'L';
                currentPrompt = 'E';

                ss << "Enter the name of the item to edit: ";
                cin >> itemToAccess;
                ss << endl;
                course = courseList->getItem(itemToAccess);
                if(course == nullptr){
                    ss << "This item does not exist" << endl;
                    return 'B';
                }
                else{
                    course->edit();
                    previousPrompt = 'H';   // resets previous prompt if edit is successful 
                    currentPrompt = 'L';
                }
                return 'S';
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


const char MainMenu::manageToDoList(ostream& ss){
    currentPrompt = 'L';
    if(toDoList == nullptr){toDoList = new ToDoList();}
 
    toDoList->displayAll(ss);
    ss << endl;

    cout << "V) View A) Add D) Delete E) Edit H) Home Q) Quit B) Back\t" << endl;
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
                return 'L';
            case 'A':
                previousPrompt = 'L';   // updates the previous prompt 

                ss << "What type of item do you want to add (Task/Course/Event): ";
                cin >> itemType;
                while(itemType != "Task" && itemType != "Course" && itemType != "Event"){
                    ss << "Invalid item type (Task/Course/Event): ";
                    cin >> itemType;
                }
                // checks the type of item that is being added 
                if(itemType == "Task"){return 'T';}
                if(itemType == "Course"){return 'C';}
                if(itemType == "Event"){return 'E';}
                break;
            case 'D':
                ss << "Enter the name of the item to delete: ";
                cin >> itemToAccess;
                ss << endl;
                item = toDoList->getItem(itemToAccess);
                if(item == nullptr){
                    ss << "This item does not exist" << endl;
                }
                else{
                    toDoList->deleteItem(itemToAccess);
                }
                return 'L';
            case 'E':
                previousPrompt = 'L';
                currentPrompt = 'E';

                ss << "Enter the name of the item to edit: ";
                cin >> itemToAccess;
                ss << endl;
                item = toDoList->getItem(itemToAccess);
                if(item == nullptr){
                    ss << "This item does not exist" << endl;
                    return 'B';
                }
                else{
                    item->edit();
                    previousPrompt = 'H';   // resets previous prompt if edit is successful 
                    currentPrompt = 'L';
                }
                return 'L';
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

const char MainMenu::back(){
    // calls the function linked with the character
    if (currentPrompt == 'M') {
        // Calendar
        previousPrompt = 'H';
        return 'H';
    } else if (currentPrompt == 'S') {
        // Course Lists
        previousPrompt = 'H';
        return 'H';
    } else if (currentPrompt == 'L') {
        // To Do List
        previousPrompt = 'H';
        return 'H';
    } else if (currentPrompt == 'C' || currentPrompt == 'E' || currentPrompt == 'D' || currentPrompt == 'T') {
        // Course
        return previousPrompt;
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
    char userInput = 'H';

    // mainMenu.homePrompt();
    mainMenu.setPrevPrompt('H');
    mainMenu.setCurrPrompt('H');

    while(userInput != 'Q'){
        if (userInput == 'M') {
            // Calendar 
            userInput = mainMenu.manageCalendar(cout);
        } else if (userInput == 'S') {
            // Course Lists
            userInput = mainMenu.manageCourseList(cout);
        } else if (userInput == 'L') {
            // To Do List
            userInput = mainMenu.manageToDoList(cout);
        } else if (userInput == 'B') {
            // Back 
            userInput = mainMenu.back();
        } else if(userInput == 'H'){
            // Home
            userInput = mainMenu.homePrompt();
        }
        else if (mainMenu.getCurrentPrompt() == 'S' || mainMenu.getCurrentPrompt() == 'L' || mainMenu.getCurrentPrompt() == 'M'){
            if (userInput == 'E') {
                // Event
                userInput = mainMenu.eventPrompt();
            } else if (userInput == 'T') {
                // Task
                userInput = mainMenu.taskPrompt();
            } else if (userInput == 'C') {
                // Course
                userInput = mainMenu.coursePrompt();
            } else if (userInput == 'D') {
                // Day
                userInput = mainMenu.dayPrompt(cout);
            } 
        } else{
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
