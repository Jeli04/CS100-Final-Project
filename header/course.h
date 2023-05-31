#ifndef COURSE_H
#define COURSE_H

#include "item.h"

using namespace std;

class Course : public Item{
public: 
    Course(bool _Completed) : Item(_Completed) {}
    Course(string _Name, string _Time, bool _Completed) : Item(_Name, _Time, _Completed) {}
    Course(string _Name, string _Time, string _Location, string _Desription, int _Priority, string _Type, bool _Completed) : Item(_Name, _Time, _Location, _Desription, _Priority, _Type, _Completed){}
    // void displayItemInfo(ostream& ss) const;
};

#endif