#ifndef TASK_H
#define TASK_H

#include <string>
#include "item.h"

using namespace std;

#include "item.h"
#include <string>

class Task : public Items {
    private: 
        string subject;

    public: 
        Task();
        Task(string subjectName);
        void edit();
        void displayItemInfo(ostream&);
        void editCompletion();
        void editPriority();
        void printMenu() const;
};

#endif