/*
* PROGRAM PROJECT 3
*
*
* Lovodi
* Date created: 4/19/14
* Last date modified: 4/25/14
*
* SOURCES USED
*
*/

#include "DLNode.h"
#include "Operator.h"
#include "DLList.h"
#include <cassert>
#include <fstream>
#include <cstdlib>
#include <iostream>
#include <sstream>
using namespace std;
    string program();
    Operator runProgram(program);
    runProgram.run();

int main(int argv, char** argc)
{
    if(argv==2)
    {
        string program(argc[1]);
        Operator runProgram(program);
        runProgram.run();
    }
    else
    {
        cout << "File not found, please have a file to input commands." << endl;
    }
    return 0;
}