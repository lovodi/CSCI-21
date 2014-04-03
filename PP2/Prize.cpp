#include "Prize.h"
#include <iostream>
using namespace std;


Prize::Prize()
{
    prizeName = "NO NAME";
    prizeValue = 0;
}

Prize::Prize(string newName, unsigned int newValue)
{
    prizeName = newName;
    prizeValue = newValue;
}

void Prize::setPrizeName (string newName)
{
    prizeName = newName;
}

void Prize::setPrizeValue (unsigned int newValue)
{
    prizeValue = newValue;
}

string Prize::getPrizeName () const
{
    return prizeName;
}

unsigned int Prize::getPrizeValue () const
{
    return prizeValue;
}

bool operator ==(Prize prize1, Prize prize2)
{
    if (prize1.prizeName==prize2.prizeName && prize1.prizeValue == prize2.prizeValue)
        return true;
    else
        return false;
}

Prize::~Prize()
{
}