#ifndef EVENT_H
#define EVENT_H

#include <string>

enum Events { Birthday, Meeting, Appointment, Other}

class Event : public Item {
    private:
        Events eventType;
    public:
        void Edit();
        void DisplayEventInfo();
}

#endif