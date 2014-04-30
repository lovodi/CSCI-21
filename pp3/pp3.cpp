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

int main(int , char**  )
{
    string program("file.txt");
    Operator runProgram(program);
    runProgram.run();
}