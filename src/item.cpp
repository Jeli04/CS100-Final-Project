#include "../header/item.h"
using namespace std;

string Item::getName() const {
    return this->itemName_;
}

string Item::getTime() const {
    return this->itemTime_;
}

string Item::getLocation() const {
    return this->itemLocation_;
}

string Item::getDescription() const {
    return this->itemDescrip_;
}

int Item::getPriority() const {
    return this->itemPriority_;
}

bool Item::getStatus() const {
    return this->itemCompletion_;
}

void Item::setName(const string& name) {
    this->itemName_ = name;
}

void Item::setTime(const string& time) {
    this->itemTime_ = time;
}

void Item::setLocation(const string& location) {
    this->itemLocation_ = location;
}

void Item::setDescripion(const string& description) {
    this->itemDescrip_ = description;
}

void Item::setPriority(int priority) {
    this->itemPriority_ = itemPriority_;
}

void Items::setItemCompletion(bool status) {
    this->itemCompletion_ = status;
}