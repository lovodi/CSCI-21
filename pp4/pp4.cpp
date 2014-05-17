
#include "Word.h"
#include "BSTNode.h"
#include "BSTree.h"
#include <cassert>
#include <cstdlib>
#include <iostream>
#include <sstream>
#include <streambuf>
#include <iostream>
#include "Driver.h"
using namespace std;

int main(int argv, char** argc)
{
    if(argv!=2)
        cout << "INPUT FILE OR COMMANDS" << endl;
    else
    { 
        Driver program(argc[1]);
        program.run();
    }
    
}