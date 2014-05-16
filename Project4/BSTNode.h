#pragma once
#include <cstdlib>

template <typename T>

class BSTNode
{
    public:
        BSTNode(T newData)
        {
            leftChild = NULL;
            rightChild = NULL;
            data = newData;
        }
        
        virtual ~BSTNode(){}
        
        void setdata(T newData)
        {
            data = newData;
        }
        
        T getdata() const
        {
            return data;
        }
        
        T& getdata()
        {
            return data;
        }
        
        void setLeftChild(BSTNode* newLeftChild)
        {
            leftChild = newLeftChild;
        }
        
        void setRightChild(BSTNode* newRightChild)
        {
            rightChild = newRightChild;
        }
        
        BSTNode* getLeftChild() const
        {
            return leftChild;
        }
        
        BSTNode*& getLeftChild()
        {
            return leftChild;
        }
        
        BSTNode* getRightChild() const
        {
            return rightChild;
        }
        
        BSTNode*& getRightChild()
        {
            return rightChild;
        }
        
    private:
        BSTNode<T>* leftChild;
        BSTNode<T>* rightChild;
        T data;
};

/*
    data members: leftChild (BSTNode*), rightChild (BSTNode*), data (templated)
    BSTNode (T newData) : initialize leftChild and rightChild to NULL, data to newData
    virtual ~BSTNode () : nothing to be done
    void setData (T newData)
    void setLeftChild (BSTNode* newLeftChild)
    void setRightChild (BSTNode* newRightChild)
    T getData () const
    BSTNode* getLeftChild () const
    BSTNode* getRightChild () const
    T& getData ()
    BSTNode*& getLeftChild ()
    BSTNode*& getRightChild ()
*/