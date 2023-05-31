#ifndef ITEM_H
#define ITEM_H

#include <string>
#include <iostream>
using namespace std;

class Item{
protected:
    string Name;
    string Date;
    string Location;
    string Description;
    int Priority;
    string Type;
    bool Completed;

public:
    Item(bool _Completed) : Name("Name"), Date("Time"), Location("Location"), Description("Description"), Priority(0), Type("Type"), Completed(_Completed) {}
    Item(string _Name, string _Time, bool _Completed) : Name(_Name), Completed(_Completed), Date(_Time) {}
    Item(string _Name, string _Time, string _Location, string _Desription, int _Priority, string _Type, bool _Completed) : Name(_Name), Date(_Time), Location(_Location), Description(_Desription), Priority(_Priority), Type(_Type), Completed(_Completed){}
    void Delete();
    void Edit();
    string getName() const {return Name;}
    string getDate() const {return Date;}
    string getLocation() const {return Location;}
    string getDescription() const {return Description;}
    int getPriority() const {return Priority;}
    string getType() const {return Type;}
    bool getCompletion() const {return Completed;}
    void setPriority(int p){Priority = p;}
    void setCompletion(bool c){Completed = c;}
    void setDate(string d){Date = d;}
    // virtual void displayItemInfo(ostream& ss) const = 0;

};
#endif