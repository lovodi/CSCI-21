#pragma once
#include <cstdlib>
using namespace std;


template < class T >

class SLNode
{
    public:
        SLNode()
        {
            node = NULL;
        }
        
        SLNode(T newContents)
        {
            node = NULL;
            Contents = newContents;
        }
        
        ~SLNode()
        {
            node = NULL;
        }
        
        T getContents() const
        {
            return Contents;
        }
        
        SLNode* getNextNode(T nextNode) const
        {
            return nextNode;
        }
        
        void setNextNode(SLNode* nextNode)
        {
            node = nextNode;
        }
        
        void setContents(T newContents)
        {
            Contents = newContents;
        }
    private:
        T Contents;
        T node;
};