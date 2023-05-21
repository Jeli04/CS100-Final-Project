#include "../header/task.h"


void Task::Edit(){
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
        this->itemName = newName;
    }
    else if (userInput == 2){
        string newTime;
        cout << "Enter new time: ";
        cin >> newTime;
        cout << endl;
        this->itemTime = newTime;
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
        cout << "Is this completed[y/n]? ";
        cin >> userInputCompleted;
        cout << endl;
        if (userInput == 'y'){
            this->itemCompletion = true;
        }
        else{
            this->itemCompletion = false;
        }
    }
}
