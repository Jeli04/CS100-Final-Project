#include "../header/course.h"


#ifndef COURSES_H
#define COURSES_H


Course::Course(vector<string> days, string instructor) {
   
   occuringDays = days;
   instructorName = instructor;
}


Course::Course() {
   this->instructorName = "";
}


string Course::GetInstructorName() const{
   return this->instructorName;
}


vector<string> Course::GetOccuringDays() const{
   return this->occuringDays;
}


void Course::SetInstructorName(const string& name){
   this->instructorName = name;
}


void Course::SetOccuringDays(vector<string> days){
   this->occuringDays = days;
}




void Course::Edit() {
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
   //type?
   else if (userInput == 7){
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
   else if (userInput == 8){
       string newInstructorName;
       cout << "Enter new instructor name: ";
       cin >> newInstructorName;
       cout << endl;
       this->instructorName = newInstructorName;
   }
   else if (userInput == 9){
       vector<string> newOccuringDays;
       int inputEditDays = 0;
       string inputAgain = "";


       while (inputAgain != "n"){
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
          
           cout << "Would you like to enter another day?[y/n]" << endl;
           cin >> inputAgain;
       }
       // set new days
   }
}


void Course::displayItemInfo(ostream& ss) {
    vector<string> days = GetOccuringDays();
    list<Task>::iterator it;
    ss << "\t  Course Name: " << getName() << endl;
    ss << "--------------------------------------------------" << endl;
    ss << "\t  Instructor: " << GetInstructorName() << endl;
    ss << "\t  Meeting Times: ";
    /*for (int i = 0; i < days.size() - 1; i++) {
        cout << days.at(i) << ", ";
    }
    ss << days.back() << endl; */
    PrintOccuringDays(ss, days);
    ss << "\t  Class Location: " << getLocation() << endl;
    ss << "\t  Class Priority: " << getPriority() << endl;
    ss << "\t  Status of Completion: " << getStatus() << endl;
    ss << "--------------------------------------------------" << endl;
    ss << endl;
    ss << "\t  List of Assignments" << endl;
    ss << "--------------------------------------------------" << endl;
    for (it = ListOfAssignments.begin(); it != ListOfAssignments.end(); ++it) {
        if (ListOfAssignments.empty()) {
            cout << "\t You currently have no given assignments...." << endl;
        } else {
            it->displayItemInfo(ss);
            ss << "--------------------------------------------------" << endl;
        }
    }
    
} 
//enum

void Course::createAssignment(Task& newTask) {
    ListOfAssignments.push_back(newTask);
}

void Course::PrintOccuringDays(ostream& ss, vector<string>& days) {
    for (int i = 0; i < days.size() - 1; ++i) {
        ss << days.at(i) << ", ";
    }
    ss << days.back() << endl;
}






#endif
