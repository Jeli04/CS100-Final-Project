#ifndef ITEM_H
#define ITEM_H

#include <string>
#include <vector>
#include <list>
#include <iostream>
#include <sstream>

using namespace std;

class Item {
    protected:

        string itemName;
        string itemType;
        string itemDate;
        string itemLocation;
        string itemDescription;
        int itemPriority;
        bool itemCompletion;

        // helper function
        
    public:
    
        Item(string, string, string, string, int, bool);
        Item();
        ~Item();

        //Setters of Item    
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
        string getType() const; 

        //Making class abstract
        virtual void displayItemInfo(ostream&) = 0;
        virtual void edit() = 0;
        virtual vector<string> getOccuringDays() const = 0;
};

#endif
