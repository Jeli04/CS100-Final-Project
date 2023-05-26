#include "../header/course.h"

#ifndef COURSES_H
#define COURSES_H

Course::Course(String[] days, String instructor) : Item() {
    occuringDays = days;
    instructorName = instructor;
}

String Course::getInstructorName(){
    return this->instructorName;
}

String[] Course::getOccuringDays(){
    return this->occuringDays;
}
void Course::Edit(){
    int userInput = 0;

    cout << "1. Name" << endl;
    cout << "2. Time" << endl;
    cout << "3. Location" << endl;
    cout << "4. Description" << endl;
    cout << "5. Priority" << endl; 
    cout << "6. Type" << endl;
    cout << "7. Completed" << endl;
    cout << "8. Instructor Name" << endl;
    cout << "9. Occuring Days" << endl;
    cout << "Enter number of what you would like to edit ";

    cin >> userInput;
    cout << endl;

    if (userInput == 1){
        string newName;
        cout << "Enter new name: ";
        cin >> newName;
        cout << endl;
        this.Name = newName;
    }
    else if (userInput == 2){
        string newTime;
        cout << "Enter new time: ";
        cin >> newTime;
        cout << endl;
        this.Time = newTime;
    }
    else if (userInput == 3){
        string newLocation;
        cout << "Enter new location: ";
        cin >> newLocation;
        cout << endl;
        this.Location = newLocation;
    }
    else if (userInput == 4){
        string newDescription;
        cout << "Enter new description: ";
        cin >> newDescription;
        cout << endl;
        this.Description = newDescription;
    }
    else if (userInput == 5){
        int newPriority;
        cout << "Enter new priority: ";
        cin >> newPriority;
        cout << endl;
        this.Priority = newPriority;
    }
    //type?
    else if (userInput == 7){
        string userInputCompleted;
        cout << "Is this completed[y/n]? ";
        cin >> userInputCompleted;
        cout << endl;
        if (userInput == 'y'){
            this.Completed = true;
        }
        else{
            this.Completed = false;
        }
    }
    else if (userInput == 8){
        string newInstructorName;
        cout << "Enter new instructor name: ";
        cin >> newInstructorName;
        cout << endl;
        this.InstructorName = newInstructorName;
    }
    else if (userInput == 9){
        vector<String> newOccuringDays;
        String inputEditDays;
        while (inputEditDays != 'q'){
            cout << "1. Sunday" << endl;
            cout << "2. Monday" << endl;
            cout << "3. Tuesday" << endl;
            cout << "4. Wednesday" << endl;
            cout << "5. Thursday" << endl;
            cout << "6. Friday" << endl;
            cout << "7. Saturday" << endl;
            cout << "Enter the number of the day this course is on: ";
            cin >> inputEditDays;
            cout << endl;

            if (inputEditDays == 1){
                newOccuringDays.push_back("Sunday");
            }
            

            String inputAgain;
            cout << "Would you like to enter another day?[y/n]" << endl;
            cin >> inputAgain;
        }
        // set new days
    }
}

//enum

#endif