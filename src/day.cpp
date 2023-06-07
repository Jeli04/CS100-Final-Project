#include "../header/day.h"

Day::Day(ToDoList* _toDoList, CourseList* _courseList, const string& date){
    toDoList = _toDoList;
    courseList = _courseList;
    dayNumber = stoi(date.substr(3, 2));  // gets the first two characters

    // gets the day of the week
    tm inputTime = {0, 0, 0, dayNumber, stoi(date.substr(0,2))-1, stoi(date.substr(6, 4))-1900};   // day, month - 1, year - 1900
    time_t tempTime = mktime(&inputTime);
    string timeOut = asctime(localtime(&tempTime));   // gets the day name
    
    dayName = timeOut.substr(0, 3);
    monthName = timeOut.substr(4, 3);

    updateItems(date);
}

void Day::displayDayInfo(ostream& ss) const{
    toDoList->printDashes(ss, 50);
    toDoList->printSpaces(ss, 18);
    ss << dayName <<  ", " << monthName << " " << dayNumber << endl;
    toDoList->printDashes(ss, 50);

    for(Item* item : listOfItems){
        item->displayItemInfo(ss);   
    }
}

void Day::updateItems(const string& date){
    for(Item* listItem : courseList->getAllItems()){
        if(Course* courseItem = dynamic_cast<Course*>(listItem)){
            for(string day : courseItem->GetOccuringDays()){
                if(dayName == day){
                    listOfItems.push_back(courseItem);
                    break;
                }
            }
        }

    }

    for(Item* listItem : toDoList->getAllItems()){
        if(listItem->getDate() == date){
            listOfItems.push_back(listItem);
        }
    }
}



