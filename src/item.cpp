#include "../header/item.h"

using namespace std;

Item::Item(){
    itemName = "";
    itemDate = "";
    itemLocation = "";
    itemDescription = "";
    itemPriority = 0;
    itemCompletion = false;
}


string Item::getName() const {
    return this->itemName;
}

string Item::getDate() const {
    return this->itemDate;
}

string Item::getLocation() const {
    return this->itemLocation;
}

string Item::getDescription() const {
    return this->itemDescription;
}

int Item::getPriority() const {
    return this->itemPriority;
}

bool Item::getStatus() const {
    return this->itemCompletion;
}

void Item::setName(const string& name) {
    this->itemName = name;
}

void Item::setDate(const string& time) {
    
    this->itemDate = time;
}

void Item::setLocation(const string& location) {
    this->itemLocation = location;
}

void Item::setDescription(const string& description) {
    this->itemDescription = description;
}

void Item::setPriority(int priority) {
    this->itemPriority = itemPriority;
}

void Item::setItemCompletion(bool status) {
    this->itemCompletion = status;
}