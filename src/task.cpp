#include "../header/task.h"
using namespace std;

Tasks::Tasks() : Items() {
    taskType = Other;
    this->subject = "";
}

Tasks::Tasks(string subjectName, Tasks type) : Items() {
    this->subject = subjectName
    this->taskType = type;
}

void Tasks::displayItemInfo(){
    cout << "hi" << endl;
}

void Tasks::edit(){
  int userInput = 0;

   cout << "1. Name" << endl;
   cout << "2. Date" << endl;
   cout << "3. Location" << endl;
   cout << "4. Description" << endl;
   cout << "5. Priority" << endl;
   cout << "6. Completion" << endl;
   cout << "7. Subject" << endl;
   cout << "8. Type of task" << endl;
   cout << "Enter number of what you would like to edit ";


   cin >> userInput;
   cout << endl;


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
       int newPriority = 0;
       cout << "Enter new priority: ";
       cin >> newPriority;
       cout << endl;
       this->itemPriority = newPriority;
   }
   //type?
   else if (userInput == 6){
        bool validInput = false;
        while (validInput != true){
            string userInputCompleted = "";
            cout << "Is this completed[y/n]? ";
            cin >> userInputCompleted;
            cout << endl;
            if (userInput != "y" && userInput != "n"){
                cout << "Invalid Input: Enter 'y' or 'n'" << endl;
            }
            else if (userInput == 'y'){
                validInput = true;
                this->itemCompletion = true;
            }
            else if (userInput == 'n'){
                validInput = true;
                this->itemCompletion = false;
            }
        }
   }
   else if (userInput == 7){
        string newSubject = "";
        cout << "Enter new subject: ";
        cin >> newSubject;
        cout << endl;
        this->subject = newSubject;
   }
   else if (userInput == 8){
       string newInstructorName = "";
       cout << "Enter new instructor name: ";
       cin >> newInstructorName;
       cout << endl;
       this->instructorName = newInstructorName;
   }
}