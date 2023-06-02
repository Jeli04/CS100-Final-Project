#include "gtest/gtest.h"
#include "../header/calendar.h" 
#include "../header/toDoList.h" 

TEST(Calendar, addDayToCalendarTest1){
    ToDoList* toDoList = new ToDoList(); // empty ToDoList
    Calendar* calendar = new Calendar("2023", "May", 31);
    for(unsigned i = 0; i < 31; i++){
        calendar->addDay(new Day(toDoList, "05/"+to_string((i+1))+"/2023"));
    }

    EXPECT_EQ(calendar->dayListSize(), 31);
}

TEST(Calendar, addDayToCalendarTest2){
    ToDoList* toDoList = new ToDoList(); // empty ToDoList
    Calendar* calendar = new Calendar("2023", "May", 31);
    for(unsigned i = 0; i < 31; i++){
        calendar->addDay(new Day(toDoList, "05/"+to_string((i+1))+"/2023"));
    }

    EXPECT_EQ(calendar->dayListSize(), 31);
}

TEST(Calendar, addDayToCalendarTest3){
    ToDoList* toDoList = new ToDoList(); // empty ToDoList
    Calendar* calendar = new Calendar("2020", "June", 20);
    for(unsigned i = 0; i < 31; i++){
        calendar->addDay(new Day(toDoList, "06/"+to_string((i+1))+"/2020"));
    }

    EXPECT_EQ(calendar->dayListSize(), 20);
}

TEST(Calendar, displayCalendarTest1){
    ToDoList* toDoList = new ToDoList(); // empty ToDoList
    Calendar* calendar = new Calendar("2023", "March", 31);
    for(unsigned i = 0; i < 31; i++){
        calendar->addDay(new Day(toDoList, "03/"+to_string((i+1))+"/2023"));
    }

    stringstream ss;
    calendar->displayAll(ss);

    EXPECT_EQ(calendar->dayListSize(), 31);
    EXPECT_EQ("         March 2023\n----------------------------\nSun Mon Tue Wed Thu Fri Sat\n              1   2   3   4 \n  5   6   7   8   9  10  11 \n 12  13  14  15  16  17  18 \n 19  20  21  22  23  24  25 \n 26  27  28  29  30  31 \n", ss.str());
}

TEST(Calendar, displayCalendarTest2){
    ToDoList* toDoList = new ToDoList(); // empty ToDoList
    Calendar* calendar = new Calendar("2022", "August", 31);
    for(unsigned i = 0; i < 31; i++){
        calendar->addDay(new Day(toDoList, "08/"+to_string((i+1))+"/2022"));
    }

    stringstream ss;
    calendar->displayAll(ss);

    EXPECT_EQ(calendar->dayListSize(), 31);
    EXPECT_EQ("        August 2022\n----------------------------\nSun Mon Tue Wed Thu Fri Sat\n      1   2   3   4   5   6 \n  7   8   9  10  11  12  13 \n 14  15  16  17  18  19  20 \n 21  22  23  24  25  26  27 \n 28  29  30  31 \n", ss.str());
}

TEST(Calendar, displayCalendarTest3){
    ToDoList* toDoList = new ToDoList(); // empty ToDoList
    Calendar* calendar = new Calendar("2021", "November", 30);  // calendar with empty days
    
    stringstream ss;
    calendar->displayAll(ss);

    EXPECT_EQ(calendar->dayListSize(), 0);
    EXPECT_EQ("      November 2021\n----------------------------\nSun Mon Tue Wed Thu Fri Sat\n      1   2   3   4   5   6 \n  7   8   9  10  11  12  13 \n 14  15  16  17  18  19  20 \n 21  22  23  24  25  26  27 \n 28  29  30 \n", ss.str());
}
