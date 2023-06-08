#ifndef TASK_H
#define TASK_H

#include <string>
#include "item.h"

using namespace std;

#include "item.h"
#include <string>

class Task : public Item {
    private: 
        string subject;
        vector<string> occuringDays;

    public: 
        Task();
        Task(string subjectName);
        void edit();
        void displayItemInfo(ostream&);
        void editCompletion();
        void editPriority();
        void printMenu() const;
        void setSubject(string& subjectName){subject = subjectName;}
        string getSubject() const{return subject;}
        vector<string> getOccuringDays() const override;
};

#endif