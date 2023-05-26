#include "../header/toDoList.h"

ToDoList::ToDoList(){
    itemCount = 0;
}

// add stub function
void ToDoList::add(Item* newItem) {
    allItems.push_back(newItem);
    if(newItem->getCompletion()){completedItems.push_back(newItem);}
    else{incompletedItems.push_back(newItem);}
    itemCount++;
}

void ToDoList::displayAll(ostream& ss) const {
    printTitle(ss);
    printBody(ss, allItems);
}

void ToDoList::displayCompleted(ostream& ss) const {
    printTitle(ss);
    printBody(ss, completedItems);
}

void ToDoList::displayIncompleted(ostream& ss) const {
    printTitle(ss);
    printBody(ss, incompletedItems);
}

void ToDoList::printTitle(ostream& ss) const{
    // prints the title 
    ss << "Completion | Name";
    printSpaces(ss, 16);
    ss << "| Priority | Time" << endl;
    printDashes(ss, 52);
}

void ToDoList::printBody(ostream& ss, const list<Item*>& toDoListType) const{
    // prints the body
    for(Item* listItem : toDoListType){
        printSpaces(ss, 4);
        ss << "[";
        if(listItem->getCompletion()){ss << "X";}
        else {ss << " ";}
        ss << "] ";
        printSpaces(ss, 3);

        ss << "| ";

        ss << listItem->getName();
        
        printPadding(ss, listItem->getName());

        //printSpaces(ss, 16);

        ss << "| ";

        printSpaces(ss, 4);

        ss << listItem->getPrioirty();

        printSpaces(ss, 4);

        ss << "| ";

        ss << listItem->getTime() << endl;
    }
}

void ToDoList::printSpaces(ostream& ss, int spaceCount) const{
    for(unsigned i = 0; i < spaceCount; i++){
        ss << " ";
    }
}

void ToDoList::printDashes(ostream& ss, int numDashes) const{
    for(unsigned i = 0; i < numDashes; i++){
        ss << "-";
    }
    ss << endl;
}

void ToDoList::printPadding(ostream& ss, const string& itemName) const{
    for (unsigned i = 0; i < 20-itemName.size(); i++){ss<<" ";}
}
