#ifndef EVENT_H
#define EVENT_H

#include <string>
#include "item.h"
using namespace std;

enum Events { Birthday, Meeting, Appointment, Other};

class Event : public Items {
    private:
        Events eventType;
        int length;
    public:
        Event();
        Event(Events);
        void setLength(int);
        int getLength() const;
        void setEventType(Events);
        Events getTypeOfEvent() const;
        void editCompletion();
        void editPriority();
        void editEventType();
        void printMenu() const;
        void edit() override;
        void displayItemInfo(ostream&, Items&) override;
};

#endif