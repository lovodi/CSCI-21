/*
* PROGRAM PROJECT 3
*
*
* Lovodi
* Date created: 5/1/14
* Last date modified: 5/16/14
*
* SOURCES USED
*
*/

#include "Driver.h"
#include "BSTree.h"
#include "BSTNode.h"
#include "Word.h"
#include <cassert>
#include <fstream>
#include <cstdlib>
#include <iostream>
#include <sstream>

using namespace std;

int main(int argv, char** argc)
{
    if(argv!=2)
    {
        cout << "File not found, please have a file to input commands." << endl;
    }
    else
    {
        Driver program(argc[1]);
        program.run();
    }
    return 0;
}