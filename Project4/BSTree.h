#pragma once
#include <string>
#include <sstream>
#include <iostream>
#include "BSTNode.h"
using namespace std;

template <typename T>

class BSTree
{
    public:
        BSTree()
        {
            count = 0;
            root = NULL;
        }
        
        virtual ~BSTree()
        {
            clear();
        }
        
        unsigned int getSize() const
        {
            return count;
        }
        
        void clear()
        {
            clear(root);
        }
        
        bool insert(T newContents)
        {
            return insert(newContents, root);
        }
        
        bool find(T targetData)
        {
            return find(targetData, root);
        }
        
        bool remove(T targetData)
        {
            return remove(targetData, root);
        }
        
        T* get(T targetData)
        {
            return get(targetData, root);
        }
        
        void inOrder()
        {
            inOrder(root);
        }
        
        void reverseOrder ()
        {
            reverseOrder (root);
        }
        
    private:
        BSTNode<T>* root;
        unsigned int count;
        
        void inOrder(BSTNode<T>* tempRoot)
        {
            if (root != NULL)
            {
                inOrder(root->getLeftChild());
                cout << root->getContents() << " ";
                inOrder(root->getRightChild());
            }
        }
        
        bool insert(T newContents, BSTNode<T>*& tempRoot)
        {
            if (root == NULL) 
            {
                root = new BSTNode<T>(newContents);
                count++;
                return true;
            }
            else if (newContents < root->getContents())
                return insert(newContents, root->getLeftChild());
            else if (newContents > root->getContents())
                return insert(newContents, root->getRightChild());
            else
                return false;
        }
        
        bool find (T targetData, BSTNode<T>* tempRoot)  // *** may be wrong ***
        {
            if (root == NULL)
                return false;
            else if (root->getContents() > targetData)
                return find(targetData, root->getLeftChild());
            else if (root->getContents() < targetData)
                return find(targetData, root->getRightChild());
            else 
            {
                if(root->getLeftChild() == NULL) 
                {
                    BSTNode<T>* oldRoot = root;
                    root = root->getRightChild();
                    delete oldRoot;
                } 
                else
                    find(root->getContents(), root->getLeftChild());
                count--;
                return true;
            }
        }
        
        void clear(BSTNode<T>*& tempRoot)
        {
            if (tempRoot == NULL)
                return;
            clear(tempRoot->getLeftChild());
            clear(tempRoot->getRightChild());
            delete tempRoot;
        }
        
        bool remove(T targetData, BSTNode<T>*& tempRoot)
        {
            if (root == NULL)
                return false;
            else if (root->getContents() > targetData)
                return remove(targetData, root->getLeftChild());
            else if (root->getContents() < targetData)
                return remove(targetData, root->getRightChild());
            else 
            {
                if(root->getLeftChild() == NULL) 
                {
                    BSTNode<T>* oldRoot = root;
                    root = root->getRightChild();
                    delete oldRoot;
                } 
                else
                    removeMax(root->getContents(), root->getLeftChild());
                count--;
                return true;
            }
        }
        
        void removeMax(T& targetData, BSTNode<T>*& tempRoot)
        {
            if (root->getRightChild() == NULL) 
            {
                BSTNode<T>* oldNode = root;
                targetData = root->getContents();
                root = root->getLeftChild();
                delete oldNode;
                oldNode = NULL;
            }
            else
                removeMax(targetData, root->getRightChild());
        }
        
        T* get (T targetData, BSTNode<T>* tempRoot)
        {
            
        }
        
        void reverseOrder (BSTNode<T>* tempRoot)  //***may be wrong***
        {
            if (root != NULL)
            {
                reverseOrder(root->getRightChild());
                cout << root->getContents() << " ";
                reverseOrder(root->getLeftChild());
            }
        }
};

//needs to be formatted like a template

//data members: size of tree (number of nodes), pointer to root
//BSTree () : initialize count to zero, root to NULL
//~BSTree () : call clear function
//unsigned int getSize () const : return count
//(public) void clear () : calls private clear
//(private) void clear (BSTNode<T>*& tempRoot) -- helper for public clear
//(public) bool insert (T newContents) : calls private insert
//(private) bool insert (T newContents, BSTNode<T>*& tempRoot) -- creates node to contain newContents and inserts it in the tree,
// returns true; if newContents is already in the tree, does not insert, returns false
//(public) bool find (T targetData) : calls private find
//(private) bool find (T targetData, BSTNode<T>* tempRoot) -- returns true if targetData can be found in tree, else returns false  
//(public) bool remove (T targetData) : calls private remove
//(private) bool remove (T targetData, BSTNode<T>*& tempRoot) -- returns true if targetData is removed from tree, else returns false
//(private) void removeMax (T& removed, BSTNode<T>*& tempRoot) -- for use with the recursive remove algorithm
//(public) T* get (T targetData) : calls private get
    //(private) T* get (T targetData, BSTNode<T>* tempRoot) -- returns a pointer to targetData on success, NULL on failure
//(public) void inOrder () : calls private inOrder
//(private) void inOrder (BSTNode<T>* tempRoot) -- displays contents of nodes in tree in ascending order (requires use of operator<< on node data)
//to STDOUT
//(public) void reverseOrder () : calls private reverseOrder
//(private) void reverseOrder (BSTNode<T>* tempRoot) -- displays contents of nodes in tree in descending order (requires use of operator<< on node data)
//to STDOUT
















