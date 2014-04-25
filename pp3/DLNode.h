#pragma once

#include <cstdlib>
#include <iostream>

using namespace std;

class DLNode
{
public:
    DLNode(int newContents = 0);
    virtual ~DLNode();
    int getContents();
    void setContents(int newContents);
    
    DLNode*& getprev();
    void setprev(DLNode* newprev);
    
    DLNode*& getNext();
    void setNext(DLNode* newNext);
    
private:
    int Contents;
    DLNode* prevNode;
    DLNode* nextNode;
};