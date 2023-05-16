#ifndef ITEM_H
#define ITEM_H

#include <string>
using namespace std;

class Item{
private:

protected:
    string Name;
    string Time;
    string Location;
    string Description;
    int Priority;
    string Type;
    bool Completed;

public:
    Item();
    void Delete();
    //void Add();
    void Edit();
};


#endif