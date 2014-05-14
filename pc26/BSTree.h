#pragma once
#include "BSTNode.h"
#include <iostream>
#include <cstdlib>
using namespace std;

class BSTree {

    public:
        BSTree();
        
     virtual ~BSTree();
    
     bool insert(int newValue);
    
     void clear();
    
     unsigned int getSize () const;
    
     void inOrder ();

    private:
     BSTNode* root;
     unsigned int size;
     bool insert (int, BSTNode*& root);
     void clear (BSTNode*& root);
     void inOrder (BSTNode* root);

};