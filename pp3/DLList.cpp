#include "DLList.h"
#include "DLNode.h"
#include <iostream>
using namespace std;

//creates an empty double link list, NULL head and the size of 0
DLList::DLList()
: head(NULL), size(0)
{
}

//removes head
void DLList::clearList()
{
    while (head != NULL)
    {
        removeHead();
    }
    head = NULL;
    tail = NULL;
}

//list destructor
DLList::~DLList()
{
    clearList();
}

//inserts new nodes into the linked list and will be moved to the right position in list
void DLList::insert(int newContents)
{
    if (head == NULL)
        insertHead(newContents);
    else if (head -> getNext() == NULL)
    {
        if (newContents < head -> getContents())
            insertHead(newContents);
        else
            insertTail(newContents);
    }
    else
    {
        DLNode* trailer = NULL;
        DLNode* spot = head;
        while (spot -> getNext() != NULL && newContents > spot -> getContents())
        {
            trailer = spot;
            spot = spot -> getNext();
        }
        if (spot -> getNext() == NULL && newContents > spot -> getContents())
            insertTail(newContents);
        else
        {
            DLNode* nodee = new DLNode(newContents);
            nodee -> setNext(spot);
            if (trailer != NULL)
                trailer -> setNext(nodee);
            else
                head = nodee;
            size++;
        }
    }
}

//inserts new nodes where the head is
void DLList::insertHead(int value)
{
    DLNode* nodie = new DLNode(value);
    nodie -> setNext(head);
    head = nodie;
    size++;
}
        
//inserts new node where the tail is
void DLList::insertTail(int content)
{
    if(head == NULL)
    {
        insertHead(content); //this will increment the count, no need for size++ etc.
    }
    else
    {
        DLNode* temp(new DLNode(content));
        DLNode* i = head;
        while (i -> getNext() != NULL)
        {
            i = i -> getNext();
        }
        i -> setNext(temp);
        size++;
    }
}

//reads content from head
int DLList::getHead()
{
    if(head != NULL)
    {
        return head->getContents();
    }
    else
        return 0;
}

//reads content from tail
int DLList::getTail()
{
    if(tail != NULL)
    {
        return tail->getContents();
    }
    else
        return 0;
}

DLNode* DLList::getFirst()
{
    return head;
}


DLNode* DLList::getLast()
{
    return tail;
}


//removes nodes where the head is
void DLList::removeHead()
{
    if (head != NULL)
    {
        DLNode* temp = head;
        head = head -> getNext();
        delete temp;
        size--;
    }
}

//removes node where the tail is
void DLList::removeTail()
{
    if(head != NULL)
    {
        DLNode* i = head;
        DLNode* trailer = NULL;
        while(i->getNext() != NULL)
        {
            trailer = i;
            i = i -> getNext();
        }
        delete i;
        size--;
        if(trailer == NULL)
        {
            head = NULL;
        }
        else
        {
            trailer -> setNext(NULL);
        }
    }
}

//removes node from head
bool DLList::removeTarget(int target)
{
    if (head == NULL)
        return false;
    else
    {
        DLNode* trailer = NULL;
        DLNode* spot = head;
        while(spot != NULL &&spot -> getContents() != target)
        {
            trailer = spot;
            spot = spot -> getNext();
        }
        if(spot == NULL)
            return false;
        else if(spot == head)
        {
            removeHead();
            return true;
        }
        else
        {
            trailer -> setNext(spot->getNext());
            delete spot;
            size--;
            return true;
        }
    }
}

bool DLList::getContents(int targetContents)
{
    return(getSpecificContents(targetContents, head));
}

bool DLList::getSpecificContents(int contentRetrieved, DLNode* assignedNode)
{
    if(assignedNode == NULL)
        return false;
    else if(assignedNode -> getContents() == contentRetrieved)
        return true;
    else
        return getSpecificContents(contentRetrieved, assignedNode -> getNext());
}




//mutates size
unsigned int DLList::getSize() 
{
    return size;
}

//returns the entire list as a string
string DLList::toString () 
{
    stringstream ss;
    
    for (DLNode* i = head; i != NULL; i = i -> getNext()) {
        ss << i ->getContents();
        if ((i -> getNext()) != NULL)
            ss << ',';
    }
    return ss.str();
}