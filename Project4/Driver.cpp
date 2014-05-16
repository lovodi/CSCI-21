#include "Driver.h"

Input::Input(string newline)
{
    input=(char)newline[0];
    Contents=0;
}
Driver::Driver(string newfile)
{
    file = newfile;
    tree = NULL;
}


Driver::~Driver()
{
    delete tree;
}


void Driver::createTree()
{
    if(tree == NULL)
    {
        tree = new BSTree;
    }
    else
    {
        delete tree;
        tree = new BSTree;
    }
}

void Driver::run()
{
    fstream fout(file.c_str());
    if(!(fout.is_open()))
    {
        return;
    }

    string temp;
    while(getline(fout, temp))
    {
        Input newInput(temp);

        switch (newInput.input)
        {
            case 'C':
                createTree();
                break;
            case 'X':
                if(tree!=NULL)
                {
                    tree->clearTree();
                    cout << "TREE CLEARED" << endl << endl;
                }
                else
                {
                    cout << "MUST CREATE TREE INSTANCE" << endl << endl;
                }
                break;
            case 'D':
                if(tree==NULL)
                    cout << "MUST CREATE TREE INSTANCE" << endl << endl;
                else
                {
                    delete tree;
                    tree=NULL;
                    cout << "TREE DELETED" << endl << endl;
                }
                break;
            case 'I':
                if(tree==NULL)
                    cout << "MUST CREATE TREE INSTANCE" << endl << endl;
                else
                {
                    tree->insert(newInput.Contents);
                     cout << "VALUE "<< newInput.Contents << " INSERTED"<< endl << endl;
                }
                break;
            case 'F':
                if(tree==NULL)
                    cout << "MUST CREATE TREE INSTANCE" << endl << endl;
                else
                {
                    tree->find(newInput.Contents);
                    cout << "VALUE "<< tree->find() << " ADDED TO FRONT" << endl << endl;
                }
                break;
            case 'R':
                if(tree==NULL)
                    cout << "MUST CREATE TREE INSTANCE" << endl << endl;
                else if(tree->remove(newInput.Contents))
                    cout << "VALUE " << newInput.Contents << " REMOVED" << endl << endl;
                else
                    cout << "VALUE "<< newInput.Contents <<" NOT FOUND" << endl << endl;
                break;
            case 'N':
                if(tree==NULL)
                    cout << "MUST CREATE TREE INSTANCE" << endl << endl;
                else
                {
                    tree->getSize();
                }
                break;
            case 'O':
                if(tree==NULL)
                    cout << "MUST CREATE TREE INSTANCE" << endl << endl;
                else if(tree->inOrder(newInput.Contents))
                    cout << "VALUE " << newInput.Contents << " FOUND" << endl << endl;
                else
                    cout << "VALUE "<< newInput.Contents <<" NOT FOUND" << endl << endl;
                break;
            case 'E':
                if(tree==NULL)
                    cout << "MUST CREATE TREE INSTANCE" << endl << endl;
                else if(tree->reverseOrder(newInput.Contents))
                    cout << "VALUE " << newInput.Contents << " FOUND" << endl << endl;
                else
                    cout << "VALUE "<< newInput.Contents <<" NOT FOUND" << endl << endl;
                break;
            case '#':
                break;
        }
    }
    fout.close();
}
