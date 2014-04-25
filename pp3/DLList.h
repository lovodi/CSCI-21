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
        void clearList();
        
        //list destructor
        virtual ~DLList();
        
        //inserts new nodes into the linked list and will be moved to the right position in list
        void insert(int newContents);
        
        //inserts new nodes where the head is
        void insertHead(int value);
        
        //inserts new node where the tail is
        void insertTail(int content);
        
        //reads content from head
        int getHead();
        
        //reads content from tail
        int getTail();
        
        //reads first node
        DLNode* getFirst();
        
        //reads last node
        DLNode* getLast();
        
        //removes nodes where the head is
        void removeHead();
        
        bool getContents(int targetContents);
        
        bool getSpecificContents(int contentRetrieved, DLNode* assignedNode);
        
        //removes node where the tail is
        void removeTail();
        
        //removes node from head
        bool removeTarget(int target);
        
        //mutates size
        unsigned int getSize();
        
        //returns the entire list as a string
        string toString ();
    
    private:
        DLNode* head;
        unsigned int size;
        DLNode* tail;
};