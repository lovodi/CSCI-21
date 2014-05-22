#pragma once

#include <sstream>
#include <string>
#include "DLNode.h"
#include <cstdlib>

using namespace std;

#define clear clearList
#define get getContents
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
        int getFront() const;

        //reads content from tail
        int getBack() const;


        //removes nodes where the head is
        void popFront();

        bool getContents(int targetContents) const;

        bool getSpecificContents(int contentRetrieved, DLNode* assignedNode) const;

        //removes node where the tail is
        void popBack();

        //removes node from head
		//
		// Grader comments 2014.05.13
		// Looks like you got removeFirst() and removeAll() switched. I switched
		// them around to give you the most points possible.
		//
        bool removeFirst(int target);
		bool removeAll(int) { /* Rob added to get the unit test to work */ return false; }

        //mutates size
        unsigned int getSize() const;

        string toString() const;

        //returns the entire list as a string
        friend ostream& operator << (ostream& out, const DLList& src);

	private:
        DLNode* head;
        unsigned int count;
        DLNode* tail;
};
