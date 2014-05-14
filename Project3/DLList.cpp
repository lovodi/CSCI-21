//
// Grader comments 2014.05.13
// -66 points total
//
#include "DLList.h"

//creates an empty double link list, NULL head and the size of 0
DLList::DLList()
: size(count), head(NULL), count(0)
{
}

//removes head
void DLList::clearList()
{
    while (head != NULL)
    {
        popFront();
    }
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
        pushFront(newContents);
    else if (head -> getNext() == NULL)
    {
        if (newContents < head -> getContents())
            pushFront(newContents);
        else
            pushBack(newContents);
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
            pushBack(newContents);
        else
        {
            DLNode* nodee = new DLNode(newContents);
            nodee -> setNext(spot);
            if (trailer != NULL)
                trailer -> setNext(nodee);
            else
                head = nodee;
            count++;
        }
    }
}

//inserts new nodes where the head is
//
// Grader comments 2014.05.13
// Doesn't manage tail when necessary.
// -12 points
//
void DLList::pushFront(int value)
{
    DLNode* nodie = new DLNode(value);
    nodie -> setNext(head);
    if(head != NULL)
        head -> setPrevious(nodie);
    head = nodie;
    count++;
	
	// Rob
	if(count == 1) {
		tail = head;
	}
}

//inserts new node where the tail is
//
// Grader comments 2014.05.13
// Doesn't manage head and tail when necessary.
// -15 points
//
void DLList::pushBack(int Contents)
{
    if(head == NULL)
    {
        pushFront(Contents); //this will increment the count, no need for count++ etc.
    }
    else
    {
        DLNode* temp(new DLNode(Contents));
        DLNode* i = head;
        while (i -> getNext() != NULL)
        {
            i = i -> getNext();
        }
        i -> setNext(temp);
        count++;
		
		// Rob
		tail = temp;
		if(count == 1) {
			head = tail;
		}
    }
}

//reads content from head
int DLList::getFront() const
{
    if(head != NULL)
    {
        return head->getContents();
    }
    else
    {
        throw string("LIST EMPTY");
        return 0;   
    }
}

//reads content from tail
int DLList::getBack() const
{
    if(tail != NULL)
    {
        return tail->getContents();
    }
    else
    {
        return 0;
    }
}



//removes nodes where the head is
//
// Grader comments 2014.05.13
// Doesn't manage tail when necessary.
// -12 points
//
void DLList::popFront()
{
    if (head != NULL)
    {
        DLNode* temp = head;
        head = head -> getNext();
        delete temp;
        count--;
		
		// Rob
		if(count == 0) {
			tail = 0;
		}
    }
}



//removes node where the tail is
//
// Grader comments 2014.05.13
// Doesn't manage tail when necessary.
// -12 points
//
void DLList::popBack()
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
        count--;
        if(trailer == NULL)
        {
            head = NULL;
			tail = NULL;	// Rob
        }
        else
        {
			tail = trailer;	// Rob
            trailer -> setNext(NULL);
        }
    }
}

//removes node from head
bool DLList::removeFirst(int target)
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
            popFront();
            return true;
        }
        else
        {
//
// Grader comments 2014.05.13
// Doesn't manage tail when necessary.
// Doesn't insert new node properly.
// -15 points.
//
            trailer -> setNext(spot->getNext());
			
			// Rob
			DLNode* newNext = spot->getNext();
			if(newNext == 0) {
				tail = trailer;
			} else {
				newNext->setPrevious(trailer);
			}

            delete spot;
            count--;
            return true;
        }
    }
}

bool DLList::getContents(int targetContents) const
{
    return(getSpecificContents(targetContents, head));
}

bool DLList::getSpecificContents(int contentRetrieved, DLNode* assignedNode) const
{
    if(assignedNode == NULL)
        return false;
    else if(assignedNode -> getContents() == contentRetrieved)
        return true;
    else
        return getSpecificContents(contentRetrieved, assignedNode -> getNext());
}




//mutates size
unsigned int DLList::getSize() const
{
    return count;
}
string DLList::toString() const
{
    stringstream ss;
    for (DLNode* i = head; i != NULL; i = i -> getNext())
    {
        ss << i ->getContents();
        if ((i -> getNext()) != NULL)
        {
            ss << ',';
        }
    }
    return ss.str();
}


//returns the entire list as a string
ostream& operator << (ostream& out, const DLList& src)
{
    out << src.toString();
    return out;
}
