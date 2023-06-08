#ifndef COURSE_H
#define COURSE_H

#include "item.h"
#include "task.h"

using namespace std;

class Course : public Item {
   private:
       string instructorName;
       vector<string> occuringDays;
       list<Task*> ListOfAssignments;
   public:
       Course(vector<string> days, string instructor);
       Course();
       void edit();
       void displayItemInfo(ostream&);
       vector<string> GetOccuringDays() const;
       string GetInstructorName() const;
       list<Task*> getListOfAssignments() const {return this->ListOfAssignments;}
       void SetInstructorName(const string&);
       void SetOccuringDays(vector<string>);
       void editOccuringDays();
       void editPriority();
       void editCompletion();
       void printMenu() const;
       void PrintOccuringDays(ostream&, vector<string>&);
       void createAssignment(Task*);
};
#endif
