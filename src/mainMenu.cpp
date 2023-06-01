#include "../header/mainMenu.h"

void MainMenu::homePrompt(ostream& ss){
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