#ifndef TASK_H
#define TASK_H

#include "item.h"

class Task : public Item{
public:
    Task(bool _Completed) : Item(_Completed) {}
    Task(string _Name, string _Time, bool _Completed) : Item(_Name, _Time, _Completed) {}
    Task(string _Name, string _Time, string _Location, string _Desription, int _Priority, string _Type, bool _Completed) : Item(_Name, _Time, _Location, _Desription, _Priority, _Type, _Completed){}
    void displayItemInfo(ostream& ss) const;
};

#endif