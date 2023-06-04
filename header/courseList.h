#ifndef COURSELIST_H
#define COURSELIST_H

#include "toDoList.h"
#include "item.h"
#include "task.h"
#include "course.h"

#include <iostream>
#include <string>
#include <sstream>
#include <iterator>
#include <list>

using namespace std;


class CourseList : public Container {
    private:
        string schoolName;

    public: 
        CourseList(const string& _schoolName);
        string getSchoolName() const {return schoolName;}
        void printBody(ostream& ss, const list<Item*>& toDoListType) const override;
        void displayAll(ostream& ss) const override;
        void printTitle(ostream& ss) const override;
        // display all items when called on a course will only access the data saved to course

};

#endif