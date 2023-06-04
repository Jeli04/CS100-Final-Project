#ifndef EVENT_H
#define EVENT_H

#include <string>
#include <list>
#include "item.h"
using namespace std;

enum Events { Birthday, Meeting, Appointment, Other};

class Event : public Items {


    private:
        Events eventType;
    public:
        Event();
        void Edit();
        void displayItem(ostream&);

        void setEventsType(Events);
        
        Events getEventsType();

        string to_string(Events);

        //code stubs
        void createEvent(Event&);
        ostream& PrintType(ostream&, Events value);

    //friend ostream& operator<<(ostream& , const Events);
};

#endif