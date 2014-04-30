#pragma once

#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <cstdlib>

#include "DLList.h"
#include "DLNode.h"

using namespace std;

struct Input
{
    Input(string newline="");

    char input;
    int Contents;
};

class Operator
{
public:
    Operator(string newfile="");
    virtual ~Operator();

    void createList();

    unsigned int getSize();

    void run();

private:
    string file;
    DLList* testRun;
};