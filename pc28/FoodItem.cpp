#include "FoodItem.h"

FoodItem::FoodItem(string newName, unsigned int newValue, unsigned int newCalories , string newUnitOfMeasure, float newUnit)
{
    Item(newName, newValue);
    calories = newCalories;
    unitOfMeasure = newUnitOfMeasure;
    units = newUnit;
}

FoodItem::~FoodItem(){}

void FoodItem::setCalories(unsigned int newCalories)
{
    calories = newCalories;
}

void FoodItem::setUnitOfMeasure(string newUnitOfMeasure)
{
    unitOfMeasure = newUnitOfMeasure;
}

void FoodItem::setUnits(float newUnits)
{
    units = newUnits;
}

unsigned int FoodItem::getCalories()
{
    return calories;
}

string FoodItem::getUnitOfMeasure()
{
    return unitOfMeasure;
}

float FoodItem::getUnits()
{
    return units;
}

string FoodItem::toString()
{
    stringstream out;
    out << Item::toString() << ", " << units << " " << unitOfMeasure << ", " << calories << " calories" << endl;
    return out.str();
}