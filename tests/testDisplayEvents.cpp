#include <string>
#include <list>
#include <sstream>
#include <iostream>
#include <gtest/gtest.h>
#include "../header/item.h"
#include "../header/course.h"
#include "../header/task.h"
#include "../header/event.h"

using namespace std;

TEST(DisplayTests, testEventDisplay) {
    stringstream ss;

    Event* newEvent = new Event();

    newEvent->setName("Cousins Birthday Bash!");
    newEvent->setEventsType(Birthday);
    newEvent->setDescription("I can't wait to celebrate my cousins 5th birthday!");
    newEvent->setLocation("3445 Winbrow St");
    newEvent->setDate("10/20/23");
    newEvent->setItemCompletion(false);

    newEvent->displayItemInfo(ss);

    EXPECT_EQ(
        "\t Event Name: Cousins Birthday Bash!\n--------------------------------------------------\n\t Event Type: Birthday\n\t Event Description: \n\t I can't wait to celebrate my cousins 5th birthday!\n\t Event Location: 3445 Winbrow St\n\t Event Date: 10/20/23\n\t Event Completed: 0\n--------------------------------------------------\n\n", ss.str()
    );
}

TEST(DisplayTests, testValidType1) {
    stringstream ss;


    Event* newEvent = new Event();

    newEvent->setEventsType(Birthday);

    EXPECT_EQ(newEvent->to_string(newEvent->getEventsType()), "Birthday");
}

TEST(DisplayTests, testValidType2) {
    stringstream ss;


    Event* newEvent = new Event();

    newEvent->setEventsType(Meeting);

    EXPECT_EQ(newEvent->to_string(newEvent->getEventsType()),"Meeting");
}

TEST(DisplayTests, testValidType3) {
    stringstream ss;


    Event* newEvent = new Event();

    newEvent->setEventsType(Appointment);

    EXPECT_EQ(newEvent->to_string(newEvent->getEventsType()),"Appointment");
}

TEST(DisplayTests, testValidType4) {
    stringstream ss;


    Event* newEvent = new Event();

    newEvent->setEventsType(Other);

    EXPECT_EQ(newEvent->to_string(newEvent->getEventsType()), "Other");
}