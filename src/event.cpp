#include "../header/event.h"
#include <iostream>
#include <limits>
using namespace std;

Event::Event(){
    this->itemType = "Event";
    this->eventType = Other;
    this->length = 0;
}

Event::Event(Events typeEvent) {
    this->eventType = typeEvent;
}

void Event::setLength(int eventLength){
    this->length = eventLength;
}

int Event::getLength() const{
    return this->length;
}

Events Event::getEventType() const{
    return this->eventType;
}

void Event::editCompletion(){
    char userInputCompleted = '\0';
    cout << "Is this completed[y/n]? ";
    cin >> userInputCompleted;
    cout << endl;
    while (cin.fail() || (userInputCompleted != 'y' && userInputCompleted != 'n')){
        if (cin.fail()){
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        cout << "----Invalid Input: Enter 'y' or 'n'----" << endl;
        cout << "Is this completed[y/n]? ";
        cin >> userInputCompleted;
        cout << endl;
    }
    if (userInputCompleted == 'y'){
        this->itemCompletion = true;
    }
    else{
        this->itemCompletion = false;
    }
}

void Event::editPriority(){
    int newPriority;
    cout << "Enter new priority: ";
    cin >> newPriority;
    cout << endl;
    while (cin.fail()){
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "----Invalid Input: Enter Number----" << endl;
        cout << "Enter new priority: ";
        cin >> newPriority;
        cout << endl;
    }
    this->itemPriority = newPriority;
    cout << "New Priority: " << itemPriority << endl;
}

void Event::editEventType(){
    int newEventType;
    cout << "1. Birthday" << endl;
    cout << "2. Meeting " << endl;
    cout << "3. Appointment " << endl;
    cout << "4. Other" << endl;
    cout << "What would you like to change the event type too? Enter Number[1-4]: " << endl;
    cin >> newEventType;
    //validating user input
    while(cin.fail() || newEventType < 1 || newEventType > 4){
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "----Invalid Input: Enter a number[1-4]----" << endl;
        cout << "What would you like to change the event type too? Enter Number[1-4]: ";
        cin >> newEventType;
        cout << endl;
    }

    switch (newEventType){
        case 1:
            eventType = Birthday;
            break;
        case 2:
            eventType = Meeting;
            break;
        case 3:
            eventType = Appointment;
            break;
        default:
            eventType = Other;
            break;
    }
}

void Event::printMenu() const{
    cout << "1. Name" << endl;
    cout << "2. Date" << endl;
    cout << "3. Location" << endl;
    cout << "4. Description" << endl;
    cout << "5. Priority" << endl; 
    cout << "6. Completion" << endl;
    cout << "7. Event Type" << endl;
}

void Event::edit(){
    cout << "----Editing Event: " << this->itemName << "----" << endl;
    cout << endl;

    int userInput = 0;
    char continueEditInput = '\0';
    bool continueEdit = true;

    while (continueEdit == true){

        printMenu();
        cout << "Enter number of what you would like to edit[1-7]: ";
        cin >> userInput;
        cout << endl;

        //validating user input
        while(cin.fail() || userInput < 1 || userInput > 7){
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "----Invalid Input: Enter a number[1-7]----" << endl;
            cout << "Enter number of what you would like to edit[1-7]: ";
            cin >> userInput;
            cout << endl;
        }

        if (userInput == 1){
            string newName;
            cout << "Enter new name: ";
            getline(cin, newName);
            cout << endl;
            this->itemName = newName;
        }
        else if (userInput == 2){
            string newDate;
            cout << "Enter new date: ";
            getline(cin, newDate);
            cout << endl;
            this->itemDate = newDate;
        }
        else if (userInput == 3){
            string newLocation;
            cout << "Enter new location: ";
            getline(cin, newLocation);
            cout << endl;
            this->itemLocation = newLocation;
        }
        else if (userInput == 4){
            string newDescription;
            cout << "Enter new description: ";
            getline(cin, newDescription);
            cout << endl;
            this->itemDescription = newDescription;
        }
        else if (userInput == 5){
            this->editPriority();
        }
        else if (userInput == 6){
            this->editCompletion();
        }
        else if (userInput == 7){
            this->editEventType();
        }

        //checks if user would like to continue editing
        cout << "Would you like to edit anything else?[y/n]: ";
        cin >> continueEditInput;
        cout << endl;
        while (cin.fail() || (continueEditInput != 'y' && continueEditInput != 'n')){
            if (cin.fail()){
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }
            cout << "----Invalid Input: Enter 'y' or 'n'----" << endl;
            cout << "Would you like to edit anything else?[y/n]: ";
            cin >> continueEditInput;
            cout << endl;
        }
        if (continueEditInput == 'n'){
            continueEdit = false;
        }
    }
}

void Event::displayItemInfo(ostream& ss) {
    list<Event>::iterator it;
    ss << "\t Event: " << getName() << endl;
    ss << "--------------------------------------------------" << endl;
    try {
        ss << "\t Event Type: " << to_string(getEventType()) << endl;
    }
    catch (const runtime_error& e) {
        ss << "Error: " << e.what() << endl;
    }
    ss << "\t Event Description: " << endl;
    ss << "\t " << getDescription() << endl;
    ss << "\t Event Location: " << getLocation() << endl;
    ss << "\t Event Date: " << getDate() << endl;
    ss << "\t Event Completed: " << getStatus() << endl;
    ss << "--------------------------------------------------" << endl;
    ss << endl;
}


void Event::setEventType(Events newEvent) {
    this->eventType = newEvent;
}

string Event::to_string(Events newEvent) {
        switch(newEvent) {
            case Birthday:
                return "Birthday";
            case Meeting:
                return "Meeting";
            case Appointment:
                return "Appointment";
            case Other:
                return "Other";
            default:
                throw runtime_error("Invalid Event Type...");
        }

}



vector<string> Event::getOccuringDays() const{
   return this->occuringDays;
}