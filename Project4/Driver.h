#pragma once

#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <cstdlib>

#include "BSTree.h"
#include "Word.h"

using namespace std;

struct Input
{
    Input(string newline);

    char input;
    int Contents;
};

class Driver
{
public:
    Driver(string newfile);
    virtual ~Driver();

    void createList();

    unsigned int getSize();

    void run();

private:
    ifstream file;
    BSTree<int>* tree;
};