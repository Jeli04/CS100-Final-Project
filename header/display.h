#include "item.h"
#include "course.h"
#include "event.h"

using namespace std;

/*class displayEvent: public Event {
    public:
        void displayEvent() const;
}; */

/*
class displayTask: public Task {
    public:
        void displayTask() const;
} 
*/

class displayCourse: public Course {
    public:
        void displayCourses(Course&);
};