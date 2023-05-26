#ifndef EVENT_H
#define EVENT_H

#include <string>
#include "item.h"
using namespace std;

enum Events { Birthday, Meeting, Appointment, Other};

class Event : public Item {
    private:
        Events eventType;
    public:
        void Edit() override;
        void DisplayEventInfo();
        virtual void displayItem(Event&) override;
};

#endif