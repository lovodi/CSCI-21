#pragma once
#include "Item.h"
#include <string>
#include <sstream>

using namespace std;

class FoodItem: public Item
{
    public:
        FoodItem(string newName = "fooditem", unsigned int newValue = 0, unsigned int newCal = 0, string newUnitOfMeasure = "nounits", float newUnits = 0);
        virtual ~FoodItem();
        
        void setCalories(unsigned int newCalories);
        void setUnitOfMeasure(string newUnitOfMeasure);
        void setUnits(float newUnits);
        
        unsigned int getCalories();
        string getUnitOfMeasure();
        float getUnits();
        string toString();
        
        
    private:
        unsigned int calories;
        string unitOfMeasure;
        float units;
    
};