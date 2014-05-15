 #include "BSTree.h"
 #include<cstdlib>
 using namespace std;
    
    
    BSTree::BSTree() 
    {
        root = NULL;
        size = 0;
    }
    
    BSTree::~BSTree() 
    {
        clear(root);
    }
     
    unsigned int BSTree::getSize() const 
    {
        return size;
    }

    void BSTree::inOrder () 
    {
        inOrder(root);
    }
        
    void BSTree::clear() 
    {
        clear(root);
    }
        
bool BSTree::insert(int newValue) 
{
        return insert(newValue, root);
    }
    
    void BSTree::inOrder (BSTNode* root) 
    {
        if (root != NULL) 
        {
            inOrder(root->getLeftChild());
            cout << root->getContents() << " ";
            inOrder(root->getRightChild());
        }
    }
   
    void BSTree::clear(BSTNode*& root) 
    {
        if (root == NULL)
            return;
        clear(root->getLeftChild());
        clear(root->getRightChild());
        delete root;
        root=NULL;
        size--;
            
        
    }
    
    bool BSTree::insert(int newValue, BSTNode*& root) 
    {
        if (root == NULL) 
        {
            root = new BSTNode(newValue);
            size++;
            return true;
        }
        else if (newValue < root->getContents())
            return insert(newValue, root->getLeftChild());
        else if (newValue > root->getContents())
            return insert(newValue, root->getRightChild());
        else
            return false;
    }