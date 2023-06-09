#include "../header/task.h"
using namespace std;
#include <limits>

Task::Task() {
    this->itemType = "Task";
    this->subject = "";
}

Task::Task(string subjectName) {
    this->itemType = "Task";
    this->subject = subjectName;
}

void Task::editCompletion(){
    string userInputCompleted = "";
    cout << "Is this completed[y/n]? ";
    cin >> userInputCompleted;
    cout << endl;
    while (cin.fail() || (userInputCompleted != "y" && userInputCompleted != "n")){
        if (cin.fail()){
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        cout << "----Invalid Input: Enter 'y' or 'n'----" << endl;
        cout << endl;
        cout << "\tIs this completed[y/n]? ";
        cin >> userInputCompleted;
        cout << endl;
    }
    if (userInputCompleted == "y"){
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
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "----Invalid Input: Enter Number----" << endl;
        cout << endl;
        cout << "Enter new priority: ";
        cin >> newPriority;
        cout << endl;
    }
    this->itemPriority = newPriority;
}

void Task::printMenu() const{
   cout << "\t1. Name" << endl;
   cout << endl;
   cout << "\t2. Date" << endl;
   cout << endl;
   cout << "\t3. Location" << endl;
   cout << endl;
   cout << "\t4. Description" << endl;
   cout << endl;
   cout << "\t5. Priority" << endl;
   cout << endl;
   cout << "\t6. Completion" << endl;
   cout << endl;
   cout << "\t7. Subject" << endl;
   cout << endl;
}

void Task::edit(){
    cout << "\t`----Editing Task: " << this->itemName << "----" << endl << endl;

    int userInput = 0;
    string continueEditInput = "";
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
            string newName = "";
            cout << "Enter new name: ";
            cin.ignore();
            getline(cin, newName);
            cout << endl;
            this->itemName = newName;
        }
        else if (userInput == 2){
            string newDate = "";
            cout << "Enter new date: ";
            cin.ignore();
            getline(cin, newDate);
            cout << endl;
            this->itemDate = newDate;
        }
        else if (userInput == 3){
            string newLocation = "";
            cout << "Enter new location: ";
            cin.ignore();
            getline(cin, newLocation);
            cout << endl;
            this->itemLocation = newLocation;
        }
        else if (userInput == 4){
            string newDescription = "";
            cout << "Enter new description: ";
            cin.ignore();
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
        while (cin.fail() || (continueEditInput != "y" && continueEditInput != "n")){
            if (cin.fail()){
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }
            cout << "----Invalid Input: Enter 'y' or 'n'----" << endl;
            cout << "Would you like to edit anything else?[y/n]: ";
            cin >> continueEditInput;
            cout << endl;
        }
        if (continueEditInput == "n"){
            cout << "----Exiting Edit----" << endl;
            continueEdit = false;
        }
    }
}

void Task::displayItemInfo(ostream& ss) {
    ss << "\t Task: " << getName() << endl;
    ss << "--------------------------------------------------" << endl;
    ss << "\t Task Description: " << endl;
    ss << "\t " << getDescription() << endl;
    ss << "\t Finish By: " << getDate() << endl;
    ss << "\t Task Priority: " << getPriority() << endl;
    ss << "\t Status of Completion: " << getStatus() << endl;
    ss << "--------------------------------------------------" << endl;
    ss << endl;
}



vector<string> Task::getOccuringDays() const{
   return this->occuringDays;
}