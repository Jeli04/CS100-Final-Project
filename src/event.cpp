#include "event.h"
#include <iostream>
using namespace std;

void Event::Edit(){
    int userInput = 0;

    cout << "1. Name" << endl;
    cout << "2. Time" << endl;
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
        string newTime;
        cout << "Enter new time: ";
        cin >> newTime;
        cout << endl;
        this->itemDate = newTime;
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

