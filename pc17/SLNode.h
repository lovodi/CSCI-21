#pragma once

#include  <cstdlib>
using namespace std;

class SLNode
{
    public:
        //sets empty node, NULL node and 0 contents;
        SLNode();
        //sets nodes to contents
        SLNode(int newContents);
        //node destructor
        virtual ~SLNode();
        
        //retrieves contents from nodes
        int getContents() const;
        //retrieves contents from the next node over
        SLNode* getNextNode() const;
        
        //sets next node in the list
        void setNextNode(SLNode* newNextNode);
        //sets contents for the new contents
        void setContents(int newContents);
        
    private:
        SLNode* nextNode;   //points to another/next node
        int Contents;
};