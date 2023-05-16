#ifndef ITEM_H
#define ITEM_H

class Items {
    protected:
        string itemName_;
        string itemTime_;
        string itemLocation_;
        string itemDescrip_;
        int itemPriority_;
        string itemType_;
        bool itemCompletion;
        
    public:

        string getName();
        string getTime();
        string getLocation();
        string getDescription();
        int getPriority();
        string getItemType();
        bool getStatus();
        Items();
        Items(string, string, string, string, int, string, bool);
        virtual void printItem() = 0;

}

#endif