#pragma once
#include <cstdlib>
#include "BSTNode.h"
#include <iostream>

using namespace std;

class BSTree
{
    public:
        BSTree();
        virtual ~BSTree();
        bool insert(int newValue);
        void clear();
        void inOrder();
        bool remove(int newValue);
        unsigned int getSize() const;
        
    private:
        BSTNode* root;
        void inOrder(BSTNode* root);
        bool insert(int newValue, BSTNode*& root);
        unsigned int size;
        void clear(BSTNode*& root);
        bool remove(int newValue, BSTNode*& root);
        void removeMax(int& newValue, BSTNode*& root);
};


/*
private data members:

	root, BSTNode* that points to the root node of a binary search tree
	size, unsigned int the number of nodes in the tree

public function interface:

	default constructor, sets newValues root(NULL) and size(0)
	
	destructor, calls the clear function
	
	bool insert (int), calls private function insert(int, root)
	
	[NEW] bool remove (int), return newValue returned by private function remove(int, root)
	
	void clear (), call private function clear(root)
	
	unsigned int getSize () const
	
	void inOrder (), call private function inOrder(root)
	
private function interface:

	bool insert (int, BSTNode*&), create a new BSTNode and insert it into the tree, returns 
	               true; if integer is already in the true, does not insert, returns false
	
	[NEW] bool remove (int, BSTNode*&), traverse the tree and remove the node containing the target 
	               integer if present, return true; return false if target integer is not in tree
	
	[NEW] void removeMax (int&, BSTNode*&), helper function for private remove
	
	void clear (BSTNode*&), clear the entire contents of the tree, freeing all memory
	               associated with all nodes
	
	void inOrder (BSTNode*), print the data in all nodes in the tree, in ascending order, 
	               separate by spaces (there should be a space after the last output 
                  newValue)
*/