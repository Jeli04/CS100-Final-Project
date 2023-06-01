#ifndef COURSE_H
#define COURSE_H


#include <string>
#include <list>
#include <vector>
#include "task.h"
#include "item.h"

using namespace std;

class Course : public Items {
   private:
       string instructorName;
       vector<string> occuringDays;
       //list<Task> ListOfAssignments;
   public:
       Course(vector<string> days, string instructor);
       Course();
       void edit() override;
       void displayItemInfo(ostream&, Items&) override;
       vector<string> GetOccuringDays() const;
       string GetInstructorName() const;
       void SetInstructorName(const string&);
       void SetOccuringDays(vector<string>);
       void editOccuringDays();
       void editPriority();
       void editCompletion();
       void printMenu() const;
};
#endif
