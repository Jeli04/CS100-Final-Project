#include <gtest/gtest.h>
#include "../header/item.h"
#include "../header/event.h"
#include <string>

using namespace std;

TEST(EventTests, testName){
    Event birthday;
    birthday.setName("Riyana's birthday");
    EXPECT_EQ(birthday.getName(), "Riyana's birthday");
}

TEST(EventTests, testLocation){
    Event birthday;
    birthday.setLocation("Event Center");
    EXPECT_EQ(birthday.getLocation(), "Event Center");
}

TEST(EventTests, testDate){
    Event birthday;
    birthday.setDate("11/12/2023");
    EXPECT_EQ(birthday.getDate(), "11/12/2023");
}

TEST(EventTests, testDescription){
    Event birthday;
    birthday.setDescription("Riyana's 18 Birthday Party");
    EXPECT_EQ(birthday.getDescription(), "Riyana's 18 Birthday Party");
}

TEST(EventTests, testPriority){
    Event birthday;
    birthday.setPriority(5);
    EXPECT_EQ(birthday.getPriority(), 5);
}
