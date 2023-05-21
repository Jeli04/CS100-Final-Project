#ifndef EVENT_H
#define EVENT_H

#include <string>
using namespace std;

enum Events { Birthday, Meeting, Appointment, Other};

class Event : public Items {
    private:
        Events eventType;
    public:
        void Edit();
        void DisplayEventInfo();
};

#endif