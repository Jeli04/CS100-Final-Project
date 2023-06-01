#include "../header/item.h"

using namespace std;

Items::Items() {
    this->itemName = "";
    this->itemDate = "";
    this->itemLocation = "";
    this->itemDescription = "";
    this->itemPriority = 0;
    this->itemCompletion = false;
}

Items::Items(string name, string time, string loc, string desc, int priority, bool status)  {
    this->itemName = name;
    this->itemDate = time;
    this->itemLocation = loc;
    this->itemDescription = desc;
    this->itemPriority = priority;
    this->itemCompletion = status;
}

string Items::getName() const {
    return this->itemName;
}

string Items::getDate() const {
    return this->itemDate;
}

string Items::getLocation() const {
    return this->itemLocation;
}

string Items::getDescription() const {
    return this->itemDescription;
}

int Items::getPriority() const {
    return this->itemPriority;
}

bool Items::getStatus() const {
    return this->itemCompletion;
}

string Items::getType() const{
    return itemType;
}
void Items::setName(const string& name) {
    this->itemName = name;
}

void Items::setDate(const string& date) {
    this->itemDate = date;
}

void Items::setLocation(const string& location) {
    this->itemLocation = location;
}

void Items::setDescription(const string& description) {
    this->itemDescription = description;
}

void Items::setPriority(int priority) {
    this->itemPriority = priority;
}

void Items::setItemCompletion(bool status) {
    this->itemCompletion = status;
}

void Items::displayItemInfo(ostream& ss, Items& newItem) {
    ss << "\t\tHere is your current Item: " << newItem.getName() << endl;
    ss << "--------------------------------------------------" << endl;
    ss << "\t\tItem Type: Task" << endl;
    ss << "\t\tDate of Item: " << newItem.getDate() << endl;
    ss << "\t\tItem Location: " << newItem.getLocation() << endl;
    ss << "\t\tItem's Priority: " << newItem.getPriority() << endl;
    ss << "\t\tStatus of Completion: " << newItem.getStatus() << endl;
}
