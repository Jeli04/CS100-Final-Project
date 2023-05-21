#ifndef COURSE_H
#define COURSE_H

#include <string>
#include <list>
#include <vector>
#include "task.h"

using namespace std;


class Course : public Items {
    private:
        string InstructorName;
        vector<string> OccuringDays;
        //list<Task> ListOfAssignments;
    public:
        Course(vector<string> days, string instructorName);
        void Edit();
        void DisplayCourseInfo();
        void getOccuringDays();
        
};
#endif