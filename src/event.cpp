#include "../header/event.h"
#include <iostream>
#include <list>
#include <sstream>
#include <stdexcept>
using namespace std;

Event::Event() {
    this->eventType = Other;
}

void Event::Edit() {
    int userInput = 0;

    cout << "1. Name" << endl;
    cout << "2. Date" << endl;
    cout << "3. Location" << endl;
    cout << "4. Description" << endl;
    cout << "5. Priority" << endl; 
    cout << "6. Completed" << endl;
    cout << "7. Event Type" << endl;
    cout << "Enter number of what you would like to edit ";

    cin >> userInput;
    cout << endl;

    if (userInput == 1){
        string newName;
        cout << "Enter new name: ";
        cin >> newName;
        cout << endl;
        this->itemName = newName;
    }
    else if (userInput == 2){
        string newDate;
        cout << "Enter new date: ";
        cin >> newDate;
        cout << endl;
        this->itemDate = newDate;
    }
    else if (userInput == 3){
        string newLocation;
        cout << "Enter new location: ";
        cin >> newLocation;
        cout << endl;
        this->itemLocation = newLocation;
    }
    else if (userInput == 4){
        string newDescription;
        cout << "Enter new description: ";
        cin >> newDescription;
        cout << endl;
        this->itemDescription = newDescription;
    }
    else if (userInput == 5){
        int newPriority;
        cout << "Enter new priority: ";
        cin >> newPriority;
        cout << endl;
        this->itemPriority = newPriority;
    }
    else if (userInput == 6){
        string userInputCompleted;
        cout << "Is this  completed[y/n]? ";
        cin >> userInputCompleted;
        cout << endl;
        if (userInput == 'y'){
            this->itemCompletion = true;
        }
        else{
            this->itemCompletion = false;
        }
    }
    else if (userInput == 7){
        int newEventType;
        cout << "1. Birthday" << endl;
        cout << "2. Meeting " << endl;
        cout << "3. Appointment " << endl;
        cout << "4. Other" << endl;
        cout << "What would like to change the event type too? Enter Number: " << endl;
        cin >> newEventType;
        if (newEventType == 1){
            eventType = Birthday;
        }
        else if (newEventType == 2){
            eventType = Meeting;
        }
        else if (newEventType == 3){
            eventType = Appointment;
        }
        else {
            eventType = Other;
        }
    }
}

void Event::displayItem(ostream& ss) {
    list<Event>::iterator it;
    ss << "\t Event Name: " << getName() << endl;
    ss << "--------------------------------------------------" << endl;
    try {
        ss << "\t Event Type: " << to_string(getEventsType()) << endl;
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


void Event::setEventsType(Events newEvent) {
    this->eventType = newEvent;
}

Events Event::getEventsType() {
    return this->eventType;
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

/*ostream& Event::PrintType(ostream& ss, Events value) {
    ss << "\t " << value << endl;
    return ss;
} */