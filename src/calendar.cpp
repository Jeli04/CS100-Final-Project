#include "../header/calendar.h"

Calendar::Calendar(const string& _year, const string& _month, const int _dayCount){
    year = _year;
    month = _month;
    dayCount = _dayCount;

    // gets the day of the week
    tmCalendar = {0, 0, 0, 1, monthMap[month]-1, stoi(year)-1900};   // day, month - 1, year - 1900
    mktime(&tmCalendar);    // normalizes the tm object 
}

Calendar::~Calendar(){
    for(auto item : dayList){
        delete item;
    }
}

void Calendar::addDay(Day* day){
    // error message should not occur since the days should correctly be handeled in main menu
    if(dayCount == dayListSize()){
        cout << "\tMonth is full" << endl;
        return;
    }

    dayList.push_back(day);
}

void Calendar::displayAll(ostream& ss) const  {
    // gets the first weekday in the month
    int weekday = (tmCalendar.tm_wday) % 7;

    // displays the month name and year
    ss << setw(14) << month << " " << year << endl;

    ss << string(28, '-') << endl;

    // displays the week day names
    ss << "Sun Mon Tue Wed Thu Fri Sat" << endl;

    // displays the first week 
    for(unsigned i = 0; i < weekday; i++){
        ss <<  "    ";
    }

    for(int i = 1; i <= dayCount; i++){
        ss << setw(3) << i << " ";
        // if the end of the week is reached print a new line
        if((weekday+i) % 7 == 0){
            ss << endl;
        }
    }
    ss << endl;
    ss << endl;
}

void Calendar::printTitle(ostream& ss) const{
    // prints the title 
    ss << "Completion | Name";
    printSpaces(ss, 16);
    ss << "| Priority | Time" << endl;
    printDashes(ss, 52);
}


void Calendar::printBody(ostream& ss, const list<Item*>& toDoListType) const{
    // prints the body
    for(Item* listItem : toDoListType){
        printSpaces(ss, 4);
        ss << "[";
        if(listItem->getStatus()){ss << "X";}
        else {ss << " ";}
        ss << "] ";
        printSpaces(ss, 3);

        ss << "| ";

        ss << listItem->getName();
        
        printPadding(ss, listItem->getName());

        //printSpaces(ss, 16);

        ss << "| ";

        printSpaces(ss, 4);

        ss << listItem->getPriority();

        printSpaces(ss, 4);

        ss << "| ";

        ss << listItem->getDate() << endl;
    }
}

int Calendar::dayListSize() const{return dayList.size();}
