#pragma once

#include  <cstdlib>
using namespace std;

class SLNode
{
    public:
        SLNode();
        SLNode(int newContents);
        virtual ~SLNode();
        
        int getContents() const;
        SLNode* getNextNode() const;
        
        void setNextNode(SLNode* newNextNode);
        void setContents(int newContents);
        
    private:
        SLNode* nextNode;   //points to another/next node
        int Contents;
};