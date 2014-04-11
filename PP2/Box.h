#pragma once

#include <iostream>
#include "Prize.h"
#include <string>
using namespace std;

//
// Grader comments 2014.04.11
//
// Need more complete function documentation. See project requirements:
// "write correct file header and function (description, all parameters,
// and return value) documentation; use this sample as a guide" See also
// prize.h -- deducted 10 points
//
class Box
{
    public:
    
        /*
            Constructor for Box class.
            @param unsigned int boxNumber to 0
            @param string boxColor to "NO COLOR"
            @param unsigned int prizeCapacity to 5
            @param unsigned int prizeCount to 0
            @param prizes array with size equal to prizeCapacity
        */
        Box();
        
        /*
            Overloaded constructor of Box
            @param unsigned int boxNumber
            @param unsigned int prizeCapacity
            @param string boxColor
        */
        Box(unsigned int newNumber, string newColor, unsigned int newCapacity);
        
        /*
            deconstructor for Box class
            frees up memory
        */
        
        ~Box();
        
        /*
            mutator sets
            no return value on mutators, allows change of private values.
        */
        void setBoxNumber(unsigned int newNumber);
        void setBoxColor(string newColor);
        
        /*
            accessor sets
            allows you to retrieve values from mutator sets
        */
        unsigned int getBoxNumber() const;
        string getBoxColor() const;
        unsigned int getPrizeCapacity() const;
        unsigned int getPrizeCount() const;
        
        /*
            adds prizes into the prize array
        */
        bool addPrize(Prize prize);
        
        /*
            retrieves prizes from the prize array
        */
        Prize& getPrize(unsigned int index);
        
        /*
            removes a prize from the prize array
        */
        Prize removePrize(unsigned int index);
        
        
    private:
    
        unsigned int boxNumber;
        string boxColor;
        unsigned int prizeCapacity;
        unsigned int prizeCount;
        
        Prize scratch;
        Prize* prizes;

};
