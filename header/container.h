#ifndef CONTAINER_H
#define CONTAINER_H

#include "item.h"
#include <iostream>
#include <string>
#include <sstream>
#include <iterator>
#include <list>
#include <algorithm>

using namespace std;

class Container{
private:
    bool comapreByPriority(const Item* item1, const Item* item2){return item1->getPriority() < item2->getPriority();}

protected:
    list<Item*> allItems;
    int itemCount = 0; 
  
    // helper functions
    virtual void printTitle(ostream& ss) const = 0;
    virtual void printBody(ostream& ss, const list<Item*>& toDoListType) const = 0;
    void printSpaces(ostream& ss, int spaceCount) const;
    void printDashes(ostream& ss, int numDashes) const;
    void printPadding(ostream& ss, const string& itemName) const;
public:
    // destructor
    ~Container();

    void add(Item* NewItem);
    void deleteItem(const string& itemName);
    virtual void displayAll(ostream& ss) const = 0;
    int getItemCount() const {return itemCount;}
    list<Item*> getAllItems() const;
    Item* getItem(const string& itemName);
    void updateAllItems();
};

#endif