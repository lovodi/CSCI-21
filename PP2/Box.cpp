#include "Box.h"
#include <iostream>
using namespace std;

Box::Box()
{
    boxNumber = 0;
    boxColor = "NO COLOR";
    prizeCapacity = 5;
    prizeCount = 0;
    prizes = new Prize[prizeCapacity];
}


Box::Box(unsigned int newNumber, string newColor, unsigned int newCapacity)
{
    boxNumber = newNumber;
    boxColor = newColor;
    prizeCapacity = newCapacity;
    prizeCount = 0;
    prizes = new Prize[prizeCapacity];
}

Box::~Box()
{
    delete[] prizes;
    prizes = NULL;
}

unsigned int Box::getBoxNumber() const
{
    return boxNumber;
}

string Box::getBoxColor() const
{
    return boxColor;
}

unsigned int Box::getPrizeCount() const
{
    return prizeCount;
}

void Box::setBoxNumber(unsigned int newNumber)
{
    boxNumber = newNumber;
}

void Box::setBoxColor(string newColor)
{
    boxColor = newColor;
}

unsigned int Box::getPrizeCapacity() const
{
    return prizeCapacity;
}
//if there is space in the prize array, adds a prize, else scratch.
bool Box::addPrize(Prize newPrize)
{
    if(prizeCount < prizeCapacity)
    {
        prizes[prizeCount++] = newPrize;
        return true;
    }
    else
        return false;
}


Prize& Box::getPrize(unsigned int index)
{
    if (index < prizeCount)
        return prizes [index];
    else
        return scratch;
}

//returns prize after removed if index is valid, else scratch.
Prize Box::removePrize (unsigned int index)
{
    if (index < prizeCount)
    {
        Prize prizeHolder = prizes [index];
        for (unsigned int holder = index; holder < prizeCount; holder++)
            if (index < prizeCount-1)
                prizes [holder] = prizes [holder + 1];
        prizeCount--;
        return prizeHolder;
    }
    else
        return scratch;
}




