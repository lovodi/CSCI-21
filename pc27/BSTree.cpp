 #include "BSTree.h"

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

void BSTree::inOrder() 
{
    inOrder(root);
}

bool BSTree::remove (int value, BSTNode*& root) 
{
    if (root == NULL)
        return false;
    else if (root->getContents() > value)
        return remove(value, root->getLeftChild());
    else if (root->getContents() < value)
        return remove(value, root->getRightChild());
    else {
        if(root->getLeftChild() == NULL) 
        {
            BSTNode* oldRoot = root;
            root = root->getRightChild();
            delete oldRoot;
    } else
        removeMax(root->getContents(), root->getLeftChild());
    size--;
    return true;
    }
}
    
void BSTree::removeMax (int& removed, BSTNode*& root) 
{
if (root->getRightChild() == NULL) 
{
BSTNode* oldNode = root;
removed = root->getContents();
root = root->getLeftChild();
delete oldNode;
oldNode = NULL;
} else
removeMax(removed, root->getRightChild());
}
    
bool BSTree::remove (int value) 
{
return remove(value, root);
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
        if (root != NULL) {
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