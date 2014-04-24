#pragma once

#include <sstream>
#include <string>
#include "DLNode.h"
#include  <cstdlib>

using namespace std;

class DLList
{
    public:
        //creates an empty double link list, NULL head and the size of 0
        DLList();
        
        //removes head
        void clear();
        
        //list destructor
        virtual ~DLList();
        
        //inserts new nodes into the linked list and will be moved to the right position in list
        void insert(int newContents);
        
        //inserts new nodes where the head is
        void insertHead(int value);
        
        //inserts new node where the tail is
        void insertTail(int content);
        
        //reads content from head
        int getHead() const;
        
        //reads content from tail
        int getTail() const;
        
        //removes nodes where the head is
        void removeHead();
        
        //removes node where the tail is
        void removeTail();
        
        //removes node from head
        bool removeFirst(int target);
        
        //mutates size
        unsigned int getSize() const;
        
        //returns the entire list as a string
        string toString () const;
    
    private:
        DLNode* head;
        unsigned int size;
};