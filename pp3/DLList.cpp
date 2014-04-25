#include "DLList.h"

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
    else if (head -> getNextNode() == NULL)
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
        while (spot -> getNextNode() != NULL && newContents > spot -> getContents())
        {
            trailer = spot;
            spot = spot -> getNextNode();
        }
        if (spot -> getNextNode() == NULL && newContents > spot -> getContents())
            insertTail(newContents);
        else
        {
            DLNode* nodee = new DLNode(newContents);
            nodee -> setNextNode(spot);
            if (trailer != NULL)
                trailer -> setNextNode(nodee);
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
    nodie -> setNextNode(head);
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
        while (i -> getNextNode() != NULL)
        {
            i = i -> getNextNode();
        }
        i -> setNextNode(temp);
        size++;
    }
}

//reads content from head
int DLList::getHead()
{
    if(head != NULL)
        return head->getContents();
    else
        return 0;
}

//reads content from tail
int DLList::getTail()
{
    if(tail != NULL)
        return tail->getContents();
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
        head = head -> getNextNode();
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
        while(i->getNextNode() != NULL)
        {
            trailer = i;
            i = i -> getNextNode();
        }
        delete i;
        size--;
        if(trailer == NULL)
        {
            head = NULL;
        }
        else
        {
            trailer -> setNextNode(NULL);
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
            spot = spot -> getNextNode();
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
            trailer -> setNextNode(spot->getNextNode());
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
        return getSpecificContents(contentRetrieved, assignedNode -> getNextNode());
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
    
    for (DLNode* i = head; i != NULL; i = i -> getNextNode()) {
        ss << i ->getContents();
        if ((i -> getNextNode()) != NULL)
            ss << ',';
    }
    return ss.str();
}