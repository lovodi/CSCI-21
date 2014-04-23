#pragma once

#include <sstream>
#include <string>
#include "SLNode.h"
#include  <cstdlib>


using namespace std;


class SList
{
    public:
        //creates empty list, NULL head and the size of 0
        SList();
        //list destructor
        virtual ~SList();
        
        //inserts new nodes where the head is
        void insertHead(int value);
        //removes nodes where the head is
        void removeHead();
        
        //inserts new node where the tail is
        void insertTail(int content);
        //removes node where the tail is
        void removeTail();
        //inserts new nodes into the linked list and will be moved to the right position in list
        void insert(int newContents);
        
        bool removeFirst(int target);
        
        //removes head
        void clear();
        
        //mutates size
        unsigned int getSize() const;
        
        //returns the entire list as a string
        string toString () const;
    
    private:
        SLNode* head;
        unsigned int size;
};