#pragma once
#include<cstdlib>

template <typename T>
class SLNode{
public:
    SLNode(T newContents)
        {
            nextNode = NULL;
            contents = newContents;
        }
    ~SLNode(){
        nextNode=NULL;
    }
    
    void setContents(T newContents){
        contents=newContents;
    }
    T getContents(){
        return contents;
    }
    
    void setNextNode(SLNode* newNext){
        nextNode=newNext;
    }
    SLNode* getNextNode(){
        return nextNode;
    }
private:
    SLNode* nextNode;
    T contents;
};
