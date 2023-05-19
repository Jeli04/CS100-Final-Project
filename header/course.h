#ifndef COURSE_H
#define COURSE_H

#include <string>
#include <list>
#include "task.h"

class Course : public Item {
    private:
        String InstructorName;
        vector<String> OccuringDays;
        list<Task> ListOfAssignments;
    public:
        Course(vector<String> days, String instructorName);
        void Edit();
        void DisplayCourseInfo();
        
}
#endif