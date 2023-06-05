#include "../header/mainMenu.h"

void MainMenu::homePrompt(ostream& ss){
    ss << "Welcome to Priority Flow" << endl;
    ss << "Please enter 'T' to view your To-Do-List" << endl;
    ss << "Please enter 'S' to view your Course List" << endl;
    ss << "Please enter 'C' to view your Calendar" << endl;
}

void addCoursePrompt(ostream& ss){

}
    
void addTaskPrompt(ostream& ss){

}
    
void addEventPrompt(ostream& ss){
    
}

void MainMenu::manageCalendar(ostream& ss){
    // call the calendar print function here
    ss << "Please enter 'D' to view a specific day" << endl;
    ss << "Please enter 'B' to go back" << endl;
}

// void MainMenu::dayPrompt(ostream& ss){
//     ss << "Please enter 'E' to edit a specific item" << endl;
//     // get input here to take the items name and call the edit function 
//     ss << "Please enter 'B' to go back" << endl;
// }

void MainMenu::manageCourseList(ostream& ss){
    ss << "Welcome to Priority Flow" << endl;
    ss << "Please enter 'T' to view your To-Do-List" << endl;
    ss << "Please enter 'S' to view your Course List" << endl;
    ss << "Please enter 'C' to view your Calendar" << endl;
}

void MainMenu::manageToDoList(ostream& ss){
    ss << "Welcome to Priority Flow" << endl;
    ss << "Please enter 'T' to view your To-Do-List" << endl;
    ss << "Please enter 'S' to view your Course List" << endl;
    ss << "Please enter 'C' to view your Calendar" << endl;
}

int main(){
    MainMenu mainMenu;
    mainMenu.homePrompt(cout);

    return 0;
}
