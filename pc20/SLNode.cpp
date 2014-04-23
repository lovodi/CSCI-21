#include "SLNode.h"

SLNode::SLNode()
: nextNode(NULL), Contents(0)
{
}

SLNode::SLNode(int newContents)
: nextNode(NULL), Contents(newContents)
{
}

SLNode::~SLNode()
{
    nextNode = NULL;
}

int SLNode::getContents() const
{
    return Contents;
}

SLNode* SLNode::getNextNode() const
{
    return nextNode;
}

void SLNode::setNextNode(SLNode* newNextNode)
{
    nextNode = newNextNode;
}

void SLNode::setContents(int newContents)
{
    Contents = newContents;
}