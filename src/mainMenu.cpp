#include "../header/mainMenu.h"

MainMenu::MainMenu(){
    ToDoList* toDoList = new ToDoList();
    CourseList* courseList = nullptr;
    Calendar* calendar = nullptr;
    itemToAccess = "";
}

const char MainMenu::homePrompt(ostream& ss){
    // ss << "Welcome to Priority Flow" << endl;
    // ss << "Please enter 'T' to view your To-Do-List" << endl;
    // ss << "Please enter 'S' to view your Course List" << endl;
    // ss << "Please enter 'C' to view your Calendar" << endl;

    manageToDoList(cout);
}

const char MainMenu::coursePrompt(ostream& ss){
    // prompt the user to enter the name of the course 

    // prompt the user for the course information to manage (add/delete/edit) and validate user input

    // prompt the user to go home, quit, or back (return value)
}
    
const char MainMenu::taskPrompt(ostream& ss){
    // prompt the user to enter the name of the task

    // prompt the user for the task information to manage (add/delete/edit) and validate user input 

    // prompt the user to go home, quit, or back (return value)
}
    
const char MainMenu::eventPrompt(ostream& ss){
    // prompt the user to enter the event name

    // prompt the user for the event information to manage (add/delete/edit) and validate user input 

    // prompt the user to go home, quit, or back (return value)
}

const char MainMenu::manageCalendar(ostream& ss){
    // call the calendar display function here
    ss << "Please enter 'D' to view a specific day" << endl;
    ss << "Please enter 'B' to go back" << endl;

    // ask the user to select a day, go home, or quit

    // if the user selects day return 'D' (implement the day function as well)

    // prompt the user to go home, quit, or back (return value)


}

const char MainMenu::dayPrompt(ostream& ss){
    // Ask the user to enter a date in 00/00/2000 format
    // call the display day function

    // prompt the user if they want to add, edit, delete an item from the day, or return home/quit

    // prompt the user to go home, quit, or back (return value)

}

const char MainMenu::manageCourseList(ostream& ss){
    // call the courselist display function here 

    // ask the user to select a course 

    // prompt the user to go home, quit, or back (return value)
}

const char MainMenu::manageToDoList(ostream& ss){
    if(toDoList == nullptr){toDoList = new ToDoList();}
    // TEST CODE

    // Task* task1 = new Task();
    // task1->setName("Item 1");
    // Task* task2 = new Task();    
    // task2->setName("Item 2"); 
    // Task* task3 = new Task();
    // task3->setName("Item 3");
    // Task* task4 = new Task();
    // task4->setName("Item 4");

    // toDoList->add(task1);
    // toDoList->add(task2);
    // toDoList->add(task3);
    // toDoList->add(task4);


    toDoList->displayAll(ss);
    ss << endl;

    // ss << "Please enter 'V' to view an item on your To-Do-List" << endl;
    // ss << "Please enter 'A' to add an item onto your To-Do-List" << endl;
    // ss << "Please enter 'D' to delete an item on your To-Do-List" << endl;
    // ss << "Please enter 'E' to edit an item on your To-Do-List" << endl;
    // ss << "Please enter 'H' to go back Home" << endl;
    // ss << "Please enter 'Q' to quit the program" << endl;

    cout << "V) View A) Add E) Edit H) Home Q) Quit B) Back\t" << endl;
    cout << "Enter Your Choice: ";

    while(true){
        cin >> userChoice;
        switch(userChoice){
            case 'V':
                // ss << "Enter the name of the item to view" << endl;
                // cin >> itemToAccess;
                // item = toDoList->getItem(itemToAccess);
                // if(item == nullptr){
                //     ss << "This item does not exist" << endl;
                // }
                // else{
                //     item->displayItemInfo(ss);
                // }
                return 'V';
            case 'A':
                return 'A';
            case 'D':
                return 'D';
            case 'H':
                return 'H';
            case 'Q':
                return 'Q';
            default:
                ss << "Invalid option please enter a invalid choice" << endl;
                break;
        }
    }
    return ' ';
    
}

int main(){
    MainMenu mainMenu = MainMenu();
    mainMenu.manageToDoList(cout);

    return 0;
}

// prompt the user to enter a choice
// that function will return the choice as a char 
// a while loop that keeps on running until a char of q is returned
// this ends the program 