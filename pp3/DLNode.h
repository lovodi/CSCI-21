#pragma once

#include <cstdlib>
#include <iostream>

using namespace std;

class DLNode
{
public:
    DLNode(int newData=0);
    virtual ~DLNode();
    
    int getData();
    void setData(int newData);
    
    DLNode*& getLast();
    void setLast(DLNode* newLast);
    
    DLNode*& getNext();
    void setNext(DLNode* newNext);
    
private:
    int data;
    DLNode* lastNode;
    DLNode* nextNode;
};