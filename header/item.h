#ifndef ITEM_H
#define ITEM_H

class Items {
    protected:

        string itemName_;
        string itemTime_;
        string itemLocation_;
        string itemDescrip_;
        int itemPriority_;
        bool itemCompletion;

    public:

        //Setters of Item    
        void setName(const string&);
        void setTime(const string&);
        void setLocation(const string&);
        void setDescription(const string&);
        void setPriority(int);
        void setItemCompletion(bool);

        //Getters of Item
        string getName() const;
        string getTime() const;
        string getLocation() const;
        string getDescription() const;
        int getPriority() const;
        bool getStatus() const;

        //Making class abstract
        virtual void item() = 0;

}

#endif