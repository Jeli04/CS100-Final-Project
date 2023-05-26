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
    Item(bool _Completed) : Name("Name"), Time("Time"), Location("Location"), Description("Description"), Priority(0), Type("Type"), Completed(_Completed) {}
    Item(string _Name, string _Time, bool _Completed) : Name(_Name), Completed(_Completed), Time(_Time) {}
    Item(string _Name, string _Time, string _Location, string _Desription, int _Priority, string _Type, bool _Completed) : Name(_Name), Time(_Time), Location(_Location), Description(_Desription), Priority(_Priority), Type(_Type), Completed(_Completed){}
    void Delete();
    void Edit();
    string getName() const {return Name;}
    string getTime() const {return Time;}
    string getLocation() const {return Location;}
    string getDescription() const {return Description;}
    int getPriority() const {return Priority;}
    string getType() const {return Type;}
    bool getCompletion() const {return Completed;}
    void setPriority(int p){Priority = p;}
    void setCompletion(bool c){Completed = c;}

    //helper
    int getPriority();
    string getName();
};
#endif