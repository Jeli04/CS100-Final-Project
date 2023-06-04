#ifndef TASK_H
#define TASK_H

#include <string>
#include "item.h"

using namespace std;

#include "item.h"
#include <string>

class Task : public Items {
    public: 
        void Edit();
        void displayItemInfo(ostream&);
};
#endif