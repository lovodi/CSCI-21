#include "DLNode.h"

DLNode::DLNode(int newContents)
    :Contents(newContents), prevNode(NULL), nextNode(NULL)
{}

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

DLNode*& DLNode::getPrevious()
{
    return prevNode;
}

void DLNode::setPrevious(DLNode* newPrev)
{
    prevNode=newPrev;
}

DLNode*& DLNode::getNext()
{
    return nextNode;
}

void DLNode::setNext(DLNode* newNext)
{
    nextNode=newNext;
}
