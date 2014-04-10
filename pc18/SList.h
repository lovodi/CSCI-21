#pragma once

#include <sstream>
#include <string>
#include "SLNode.h"
#include  <cstdlib>


using namespace std;


class SList
{
    public:
        SList();
        virtual ~SList();
        
        void insertHead(int value);
        void removeHead();
        void clear();
        
        unsigned int getSize() const;
        
        string toString () const;
    
    private:
        SLNode* head;
        unsigned int size;
};