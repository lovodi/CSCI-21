#include <sstream>
#include <string>
#include  <cstdlib>
#include "DLList.h"

using namespace std;



class DLList
{
    public:
        //creates an empty double link list, NULL head and the size of 0
        DLList::DLList()
        : head(NULL), size(0)
        {
        }
        
        //removes head
        void clear()
        {
            while (head != NULL)
            {
                removeHead();
            }
        }
        
        //list destructor
        virtual ~DLList()
        {
            clear();
        }
        
        //inserts new nodes into the linked list and will be moved to the right position in list
        void insert(int newContents)
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
                SLNode* trailer = NULL;
                SLNode* spot = head;
                while (spot -> getNextNode() != NULL && newContents > spot -> getContents())
                {
                    trailer = spot;
                    spot = spot -> getNextNode();
                }
                if (spot -> getNextNode() == NULL && newContents > spot -> getContents())
                    insertTail(newContents);
                else
                {
                    SLNode* nodee = new SLNode(newContents);
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
        void insertHead(int value)
        {
            SLNode* nodie = new SLNode(value);
            nodie -> setNextNode(head);
            head = nodie;
            size++;
        }
                
        //inserts new node where the tail is
        void insertTail(int content)
        {
            if(head == NULL)
            {
                insertHead(content); //this will increment the count, no need for size++ etc.
            }
            else
            {
                SLNode* temp(new SLNode(content));
                SLNode* i = head;
                while (i -> getNextNode() != NULL)
                {
                    i = i -> getNextNode();
                }
                i -> setNextNode(temp);
                size++;
            }
        }
        
        //reads content from head
        int getHead() const;
        
        //reads content from tail
        int getTail() const;
        
        //removes nodes where the head is
        void removeHead()
        {
            if (head != NULL)
            {
                SLNode* temp = head;
                head = head -> getNextNode();
                delete temp;
                size--;
            }
        }
        
        //removes node where the tail is
        void removeTail();
        {
            if(head != NULL)
            {
                SLNode* i = head;
                SLNode* trailer = NULL;
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
        bool removeFirst(int target)
        {
            if (head == NULL)
                return false;
            else
            {
                SLNode* trailer = NULL;
                SLNode* spot = head;
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

        
        //mutates size
        unsigned int getSize() const
        {
            return size;
        }
        
        //returns the entire list as a string
        string toString () const
        {
            stringstream ss;
            
            for (SLNode* i = head; i != NULL; i = i -> getNextNode()) {
                ss << i ->getContents();
                if ((i -> getNextNode()) != NULL)
                    ss << ',';
            }
            return ss.str();
        }
    
    private:
        DLNode* head;
        unsigned int size;
};