#include "DLNode.h"
#include "Operator.h"
#include "DLList.h"
#include <cassert>
#include <fstream>
#include <cstdlib>
#include <iostream>
#include <sstream>
using namespace std;

int main(int  , char** )
{
    string temporary("file.txt");
    Operator runProgram(temporary);
    runProgram.run();
    
    return 0;
}