#pragma once

#include <sstream>
#include <string>
#include "DLNode.h"
#include <cstdlib>

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
        void pushFront(int value);

        //inserts new node where the tail is
        void pushBack(int Contents);

        //reads content from head
        int getFront();

        //reads content from tail
        int getBack();


        //removes nodes where the head is
        void popFront();

        bool getContents(int targetContents);

        bool getSpecificContents(int contentRetrieved, DLNode* assignedNode);

        //removes node where the tail is
        void popBack();

        //removes node from head
        bool removeAll(int target);

        //mutates size
        unsigned int getSize();

        string toString() const;

        //returns the entire list as a string
        friend ostream& operator << (ostream& out, const DLList& src);

    private:
        DLNode* head;
        unsigned int count;
        DLNode* tail;
};
