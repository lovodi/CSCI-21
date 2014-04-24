#pragma once
#include "SLNode.h"
#include <cstdlib>
#include <string>
#include <sstream>
#include <iostream>

using namespace std;

template <typename T>
class SList{
public:
    SList(){
        head=NULL;
        size=0;
    }
    
    ~SList() {
        clear();
    }
    
    	void insertHead (T value) 
    	{
            SLNode<T>* nodie = new SLNode<T>(value);
            nodie -> setNextNode(head);
            head = nodie;
            size++;
        }
    
    void removeHead () 
    {
        if (head != NULL) 
        {
            SLNode<T>* temp = head;
            head = head -> getNextNode();
            delete temp;
            size--;
        }
    }
    void insertTail (T value)
    {
        if (head == NULL) 
        {
            insertHead(value);
        } 
        else
        {
            SLNode<T>* temp = new SLNode<T>(value);
            SLNode<T>* i = head;
            while (i -> getNextNode() != NULL) {
                i = i -> getNextNode();
            }
            i -> setNextNode(temp);
            size++;
        }
    }
    
    void removeTail () 
    {
        if (head != NULL) 
        {
            SLNode<T>* i = head;
            SLNode<T>* trailer = NULL;
            while (i -> getNextNode() != NULL) 
            {
                trailer = i;
                i = i -> getNextNode();
            }
            delete i;
            size--;
        if (trailer == NULL)
            head = NULL;
        else
            trailer -> setNextNode(NULL);
        }
    }
    
    void clear () 
    {
        while (head != NULL)
            removeHead();
    }
    
    unsigned int getSize() const{
        return size;
    }
    
    string toString () const 
    {
        stringstream ss;
        
        for (SLNode<T>* i = head; i != NULL; i = i -> getNextNode()) 
        {
            ss << i ->getContents();
            if ((i -> getNextNode()) != NULL)
                ss << ',';
        }
            return ss.str();
    }
    
    
    bool removeFirst(T target) 
    {
        if (head == NULL)
            return false;
        else 
        {
            SLNode<T>* trailer = NULL;
            SLNode<T>* spot = head;
            while (spot != NULL && spot -> getContents() != target) 
            {
                trailer = spot;
                spot = spot -> getNextNode();
            }
        if (spot == NULL)
            return false;
        else if (spot == head) 
        {
            removeHead();
            return true;
        }
        else 
        {
            trailer -> setNextNode(spot -> getNextNode());
            delete spot;
            size--;
            return true;
            }
        }
    }
    
    bool removeAll (T target) 
    {
        bool holder (removeFirst(target));
            while (removeFirst(target));
                return holder;
    }
    
    void insert(T newValue) 
    {
        if ( head == NULL)
            insertHead(newValue);
        else if (head -> getNextNode() == NULL) 
        {
            if (newValue < head -> getContents())
                insertHead(newValue);
            else
                insertTail(newValue);
            }
            else 
            {
                SLNode<T>* trailer = NULL;
                SLNode<T>* spot = head;
    
                while ( spot -> getNextNode() != NULL && newValue > spot -> getContents()) 
                {
                    trailer = spot;
                    spot = spot -> getNextNode();
                }
                if (spot -> getNextNode() == NULL && newValue > spot -> getContents())
                    insertTail(newValue);
                else 
                {
                    SLNode<T>* nodee = new SLNode<T>(newValue);
                    nodee -> setNextNode(spot);
                if (trailer != NULL)
                    trailer -> setNextNode(nodee);
                else
                    head = nodee;
                    size++;
                }
            }
        }
    
private:
    SLNode<T>* head;
    unsigned int size;
};