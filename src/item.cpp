#include "../header/item.h"

using namespace std;

Item::Item() {
    this->itemName = "";
    this->itemDate = "";
    this->itemLocation = "";
    this->itemDescription = "";
    this->itemPriority = 0;
    this->itemCompletion = false;
}

Item::Item(string name, string time, string loc, string desc, int priority, bool status)  {
    this->itemName = name;
    this->itemDate = time;
    this->itemLocation = loc;
    this->itemDescription = desc;
    this->itemPriority = priority;
    this->itemCompletion = status;
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

string Item::getType() const{
    return itemType;
}
void Item::setName(const string& name) {
    this->itemName = name;
}

void Item::setDate(const string& date) {
    this->itemDate = date;
}

void Item::setLocation(const string& location) {
    this->itemLocation = location;
}

void Item::setDescription(const string& description) {
    this->itemDescription = description;
}

void Item::setPriority(int priority) {
    this->itemPriority = priority;
}

void Item::setItemCompletion(bool status) {
    this->itemCompletion = status;
}

