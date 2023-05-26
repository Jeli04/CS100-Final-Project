#ifndef ITEM_H
#define ITEM_H

#include <string>
#include <iostream>

using namespace std;

class Item {
    protected:

        string itemName;
        string itemDate;
        string itemLocation;
        string itemDescription;
        int itemPriority;
        bool itemCompletion;

    public:

        //Setters of Item  
        Item();  
        void setName(const string&);
        void setDate(const string&);
        void setLocation(const string&);
        void setDescription(const string&);
        void setPriority(int);
        void setItemCompletion(bool);

        //Getters of Item
        string getName() const;
        string getDate() const;
        string getLocation() const;
        string getDescription() const;
        int getPriority() const;
        bool getStatus() const;

        virtual void Edit() = 0;

        //Making class abstract
        //virtual void item() = 0;

};

#endif
