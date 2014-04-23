#pragma once
#include <string>
#include <iostream>
#include <sstream>
#include "SLNode-template.h"
#include <cstdlib>
using namespace std;

template<class T>
class SList
{
    public:
        SList()
        {
            head = NULL;
            size;
        }
        
        ~SList()
        {
            clear();
        }
        
        void insertHead(T value)
        {
            SLNode<T>* nodie = new SLNode<T>(value);
            nodie -> setNextNode(head);
            head = nodie;
            size++;
        }
        
        void insertTail(T content)
        {
            if(head == NULL)
            {
                insertHead(content); //this will increment the count, no need for size++ etc.
            }
            else
            {
                SLNode<T>* temp = new SLNode<T>(content);
                SLNode<T>* i = head;
                while (i -> getNextNode() != NULL)
                {
                    i = i -> getNextNode();
                }
                i -> setNextNode(temp);
                size++;
            }
        }
        
        void removeHead()
        {
            if (head != NULL)
            {
                SLNode<T>* temp = head;
                head = head -> getNextNode();
                delete temp;
                size--;
            }
        }
        
        void removeTail()
        {
            if(head != NULL)
            {
                SLNode<T>* i = head;
                SLNode<T>* trailer = NULL;
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
        
        void insert(T newContents)
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
                SLNode<T>* trailer = NULL;
                SLNode<T>* spot = head;
                while (spot -> getNextNode() != NULL && newContents > spot -> getContents())
                {
                    trailer = spot;
                    spot = spot -> getNextNode();
                }
                if (spot -> getNextNode() == NULL && newContents > spot -> getContents())
                    insertTail(newContents);
                else
                {
                    SLNode<T>* nodee = new SLNode<T>(newContents);
                    nodee -> setNextNode(spot);
                    if (trailer != NULL)
                        trailer -> setNextNode(nodee);
                    else
                        head == nodee;
                }
            }
        }
        bool removeFirst(T target)
        {
            if (head == NULL)
                return false;
            else
            {
                SLNode<T>* trailer = NULL;
                SLNode<T>* spot = head;
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
        
        void clear()
        {
            while (head != NULL)
                removeHead();
        }
        
        T getSize() const
        {
            return size;
        }
        
        string toString () const {
            stringstream ss;
            
            for (SLNode<T>* i = head; i != NULL; i = i -> getNextNode()) {
                ss << i ->getContents();
                if ((i -> getNextNode()) != NULL)
                    ss << ',';
            }
            return ss.str();
        }
        
        bool removeAll()
        {
            while (head != NULL)
            {
                SLNode<T>* temp = head;
                head = head -> getNextNode();
                delete temp;
                size--;
            }
            if (head == NULL)
                return true;
            else
                return false;
        }
        
        
  private:
    SLNode<T>* head;
    T size;
};