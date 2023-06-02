#ifndef EVENT_H
#define EVENT_H

#include <string>
#include "item.h"
using namespace std;

enum Events { Birthday, Meeting, Appointment, Other};

class Event : public Items {
    private:
        Events eventType;
    public:
        Event();
        Event(Events typeEvent);
        void edit() override;
        void displayItemInfo(ostream&, Items&) override;
};
#endif