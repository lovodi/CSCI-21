#include "DLNode.h"
#include "Operator.h"
#include "DLList.h"
#include <cassert>
#include <fstream>
#include <cstdlib>
#include <iostream>
#include <sstream>
using namespace std;

int main(int argv , char** argc)
{
    if(argv==2)
    {
        string temp(argc[1]);
        Operator runtime(temp);
        runtime.run();
    }
    else
    {
        cout << "Improper Input, one argument" << endl;
    }
    
    return 0;
}