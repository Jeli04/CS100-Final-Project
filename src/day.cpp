#include "../header/day.h"

Day::Day(string date){
    dayNumber = stoi(date.substr(0, 2));  // gets the first two characters

    // gets the day of the week
    tm time_in = {0, 0, 0, 24, 10, 2023-2020};
    time_t time_temp = mktime(&time_in);
    dayName = localtime(&time_temp)->tm_wday;   // gets the day name
   
    for(Item* listItem : AllItems){
        if(listItem->)
        // if listItem->date == date
        // add to listOfItems
    }
}