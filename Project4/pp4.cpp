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
    string program();
    Driver runProgram(program);
    runProgram.run();

int main(int argv, char** argc)
{
    if(argv==2)
    {
        string program(argc[1]);
        Driver runProgram(program);
        runProgram.run();
    }
    else
    {
        cout << "File not found, please have a file to input commands." << endl;
    }
    return 0;
}