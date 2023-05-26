#ifndef ITEM_H
#define ITEM_H

#include <string>
#include <iostream>

using namespace std;

class Items {
    protected:

        string itemName;
        string itemType;
        string itemDate;
        string itemLocation;
        string itemDescription;
        int itemPriority;
        bool itemCompletion;

    
    public:
    
        Items(string, string, string, string, int, bool);
        Items();

        //Setters of Item    
        void setName(const string);
        void setDate(const string);
        void setLocation(const string);
        void setDescription(const string);
        void setPriority(int);
        void setItemCompletion(bool);


        //Getters of Item
        string getName() const;
        string getDate() const;
        string getLocation() const;
        string getDescription() const;
        int getPriority() const;
        bool getStatus() const;
        string getItemType() const; 

        //Making class abstract
        //virtual void displayItem() = 0;
        //virtual void Edit() = 0;

};

#endif
