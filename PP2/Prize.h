#pragma once

#include <string>
using namespace std;

class Prize
{
    public:
        
        /*
            Constructor for Prize class
            @param prizeName set to "NO NAME"
            @param prizeValue set to 0
        */
        Prize();
        
        /*
            Overload constructor
            @param string prize name
            @param unsigned int prizeValue
        */
        Prize(string newName,unsigned int newValue);
        
        /*
            deconstructor for Prize
        */
        virtual ~Prize();
        
        /*
            mutator
            sets name for prizes
        */
        void setPrizeName (string newName);
        
        /*
            mutator, sets value for prizes
        */
        void setPrizeValue(unsigned int newValue);
        
        
        /*
            accessor, retrieves name from mutator
        */
        string getPrizeName() const;
        
        /*
            accessor, retrieves value from mutator
        */
        unsigned int getPrizeValue() const;
        
        /*
            overloads comparison between prizes
        */
        friend bool operator ==(Prize prize1, Prize prize2);
        
    private:
        string prizeName;
        unsigned int prizeValue;
};
