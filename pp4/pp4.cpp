
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

int main(int argv, char** )
{
    if(argv!=2)
        cout << "MUST INPUT FILE" << endl;
    else
    { 
        Driver program("testFile.txt");
        program.run();
    }
    
}