#pragma once

#include <cstdlib>
#include <string>
#include <fstream>
#include <sstream>
#include "BSTree.h"
#include "Word.h"
#include "BSTNode.h"

using namespace std;

struct Input{
    Input(string nextLine);
    
    char input;
    string Contents;
};

class Driver{
public:
    Driver(string download);
    ~Driver();
    
    void createTree();
    void deleteTree();
    
    void getSize();
    
    void run();
private:
    ifstream file;
    BSTree<Word>* tree;
};