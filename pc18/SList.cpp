#include "SLNode.h"
#include "SList.h"

SList::SList()
: head(NULL), size(0)
{
}

SList::~SList()
{
    clear();
}

void SList::insertHead(int value)
{
    SLNode* nodie = new SLNode(value);
    nodie -> setNextNode(head);
    head = nodie;
    size++;
}

void SList::removeHead()
{
    if (head != NULL)
    {
        SLNode* temp = head;
        head = head -> getNextNode();
        delete temp;
        size--;
    }
}

void SList::clear()
{
    while (head != NULL)
        removeHead();
}

unsigned int SList::getSize() const
{
    return size;
}

string SList::toString () const {
    stringstream ss;
    
    for (SLNode* i = head; i != NULL; i = i -> getNextNode()) {
        ss << i ->getContents();
        if ((i -> getNextNode()) != NULL)
            ss << ',';
    }
    return ss.str();
}