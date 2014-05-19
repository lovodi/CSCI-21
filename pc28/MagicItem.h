#pragma once
#include "Item.h"
#include <string>
#include <sstream>

class MagicItem: public Item
{
    public:
        MagicItem(string newName = "magicitem", unsigned int newValue = 0, string newDescription = "no description", unsigned int newRequiredMana = 0);
        virtual ~MagicItem();
        
        void setDescription(string newDescription);
        void setManaRequired(unsigned int newManaRequired);
        
        string getDescription();
        unsigned int getManaRequired();
        
        string toString();
  
    private:
        string description;
        unsigned int manaRequired;
};