#pragma once

#include <iostream>
using namespace std;

template <typename T>
class BSTNode
{
    public:
        //constructor
        BSTNode(T newData)
            :data(newData), leftChild(NULL), rightChild(NULL){}
        //destructor
        virtual ~BSTNode()
        {
            leftChild=rightChild=NULL;
        }
        
        //set and get for the Data of the tree
        void Data(T newData)
        {
            data=newData;
        }
        T& Data(){
            return data;
        }
        
        
        //set and get for left child;
        void LeftChild(BSTNode* newLeft)
        {
            leftChild=newLeft;
        }
        BSTNode* LeftChild() const{
            return leftChild;
        }
        
        //set and get for right child
        void RightChild(BSTNode* newRight)
        {
            rightChild=newRight;
        }\
        BSTNode* RightChild() const
        {
            return rightChild;
        }
        
        BSTNode*& RightChild()
        {
            return rightChild;
        }
        BSTNode*& LeftChild()
        {
            return leftChild;
        }
        
        //had to rewrite to pass unit test
        //calls Data above
        T getData(){
            return Data();
        }
        //returns left child
        BSTNode*& getLeftChild()
        {
            return LeftChild();
        }
        //returns right child
        BSTNode*& getRightChild()
        {
            return RightChild();
        }
        
        void setData(T newData){
            Data(newData);
        }
        void setRightChild(BSTNode* which)
        {
            RightChild(which);
        }
        void setLeftChild(BSTNode* which)
        {
            LeftChild(which);
        }
        
    private:
        T data;
        BSTNode* leftChild;
        BSTNode* rightChild;
};