#include "DLNode.h"

DLNode::DLNode(int newContents)
    :Contents(newContents), prevNode(NULL), nextNode(NULL)
{/*intntentionally left blank*/}

DLNode::~DLNode()
{
    prevNode=NULL;
    nextNode=NULL;
}

int DLNode::getContents()
{
    return Contents;
}

void DLNode::setContents(int newContents)
{
    Contents = newContents;
}

DLNode*& DLNode::getprev()
{
    return prevNode;
}

void DLNode::setprev(DLNode* newprev)
{
    prevNode=newprev;
}

DLNode*& DLNode::getNextNode()
{
    return nextNode;
}

void DLNode::setNextNode(DLNode* newNext)
{
    nextNode=newNext;
}

