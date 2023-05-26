#include <gtest/gtest.h>
#include <iostream>
#include "../header/item.h"
using namespace std;

TEST (ItemTests, testDisplay) {
    Items newItem = Items(
        "Bake a Cake",
        "10/23/24",
        "Multidisciplinary Hall",
        "I can't wait to bake a new cake!",
        2,
        false
    );

    stringstream ss;
    newItem.displayItem(ss, newItem);
    EXPECT_EQ(
        "\t\tHere is your current Item: Bake a Cake\n--------------------------------------------------\n\t\tItem Type: Task\n\t\tDate of Item: 10/23/24\n\t\tItem Location: Multidisciplinary Hall\n\t\tItem's Priority: 2\n\t\tStatus of Completion: 0\n", ss.str());
}