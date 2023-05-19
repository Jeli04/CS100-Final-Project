#include "../header/item.h"

string Items::getName() const {
    return this->itemName_;
}

string Items::getTime() const {
    return this->itemTime_;
}

string Items::getLocation() const {
    return this->itemLocation_;
}

string Items::getDescription() const {
    return this->itemDescrip_;
}

int Items::getPriority() const {
    return this->itemPriority_;
}

bool Items::getStatus() const {
    return this->itemCompletion_;
}

void Items::setName(const string& name) {
    this->itemName_ = name;
}

void Items::setTime(const string& time) {
    this->itemTime_ = time;
}

void Items::setLocation(const string& location) {
    this->itemLocation_ = location;
}

void Items::setDescripion(const string& description) {
    this->itemDescrip_ = description;
}

void Items::setPriority(int priority) {
    this->itemPriority_ = itemPriority_;
}

void Items::setItemCompletion(bool status) {
    this->itemCompletion_ = status;
}



