#include "../header/task.h"
using namespace std;

Task::Task() : Items() {
    this->itemType = "Task";
    this->taskType = Other;
    this->subject = "";
}

Task::Task(string subjectName, Tasks type) : Items() {
    this->itemType = "Task";
    this->subject = subjectName;
    this->taskType = type;
}

void Task::displayItemInfo(ostream& ss, Items& newItem){
    cout << "hi" << endl;
}


void Task::editCompletion(){
    char userInputCompleted = '\0';
    cout << "Is this completed[y/n]? ";
    cin >> userInputCompleted;
    cout << endl;
    while (cin.fail() || (userInputCompleted != 'y' && userInputCompleted != 'n')){
        if (cin.fail()){
            cin.clear();
            cin.ignore();
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

void Task::editPriority(){
    int newPriority;
    cout << "Enter new priority: ";
    cin >> newPriority;
    cout << endl;
    while (cin.fail()){
        cin.clear();
        cin.ignore();
        cout << "----Invalid Input: Enter Number----" << endl;
        cout << "Enter new priority: ";
        cin >> newPriority;
        cout << endl;
    }
    this->itemPriority = newPriority;
}

void Task::printMenu() const{
   cout << "1. Name" << endl;
   cout << "2. Date" << endl;
   cout << "3. Location" << endl;
   cout << "4. Description" << endl;
   cout << "5. Priority" << endl;
   cout << "6. Completion" << endl;
   cout << "7. Subject" << endl;
   cout << "8. Type of task" << endl;
}

void Task::edit(){
    cout << "----Editing Task: " << this->itemName << "----" << endl;
    int userInput = 0;
    char continueEditInput = '\0';
    bool continueEdit = true;
    while (continueEdit == true){
        
        printMenu();
        cout << "Enter number of what you would like to edit ";

        cin >> userInput;
        cout << endl;

        //validating user input
        while(cin.fail() || userInput < 1 || userInput > 8){
            cin.clear();
            cin.ignore();
            cout << "----Invalid Input: Enter a number[1-8]----" << endl;
            cout << "Enter number of what you would like to edit[1-8]: ";
            cin >> userInput;
            cout << endl;
        }

        if (userInput == 1){
            string newName = "";
            cout << "Enter new name: ";
            cin >> newName;
            cout << endl;
            this->itemName = newName;
        }
        else if (userInput == 2){
            string newDate = "";
            cout << "Enter new date: ";
            cin >> newDate;
            cout << endl;
            this->itemDate = newDate;
        }
        else if (userInput == 3){
            string newLocation = "";
            cout << "Enter new location: ";
            cin >> newLocation;
            cout << endl;
            this->itemLocation = newLocation;
        }
        else if (userInput == 4){
            string newDescription = "";
            cout << "Enter new description: ";
            cin >> newDescription;
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
            string newSubject = "";
            cout << "Enter new subject: ";
            cin >> newSubject;
            cout << endl;
            this->subject = newSubject;
        }
        
        //checks if user would like to continue editing
        cout << "Would you like to edit anything else?[y/n]: ";
        cin >> continueEditInput;
        cout << endl;
        while (cin.fail() || (continueEditInput != 'y' && continueEditInput != 'n')){
            if (cin.fail()){
                cin.clear();
                cin.ignore();
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

void Task::displayItemInfo(ostream& ss) {
    ss << "\t  Task: " << getName() << endl;
    ss << "--------------------------------------------------" << endl;
    ss << "\t  Task Description: " << endl;
    ss << "\t " << getDescription() << endl;
    ss << "\t  Finish By: " << getDate() << endl;
    ss << "\t  Task Priority: " << getPriority() << endl;
    ss << "\t  Status of Completion: " << getStatus() << endl;
}
