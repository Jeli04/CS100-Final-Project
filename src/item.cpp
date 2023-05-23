#include "../header/item.h"

Item::Item()
{
    Name = "default";
    Time = "default";
    Location = "default";
    Description = "default";
    Priority = 0;
    Type = "default";
    Completed = false;
}

Item::Item(string name, string time, string location, string description, int priority, string type)
{
    Name = name;
    Time = time;
    Location = location;
    Description = description;
    Priority = priority;
    Type = type;
    Completed = false;
}

int Item::getPriority()
{
    return Priority;
}

string Item::getName()
{
    return Name;
}