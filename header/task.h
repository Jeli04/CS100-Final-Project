#ifndef TASK_H
#define TASK_H
using namespace std;

#include "item.h"
#include <string>

enum Tasks {Homework, Tests, Shopping, Gym, Other}
class Task : public Items {
    private: 
        string subject;
        Tasks taskType;
    public: 
        Tasks();
        Tasks(string subjectName, Tasks type);
        void edit() override;
        void displayItemInfo() override;
};
#endif