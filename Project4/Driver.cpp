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
    if (tree != NULL)
    tree -> clear();
}


void Driver::createTree()
{
    if(tree == NULL)
    {
        tree = new BSTree<int>;
    }
    else
    {
        delete tree;
        tree = new BSTree<int>;
    }
}

void Driver::run()
{
    string input;
    
    if(file.bad())
    {
        cout << "FILE NOT LOADED" << endl;
        exit(1);
    }
    else
    {
        while(getline(file, input))
        {
            Input command(input);
            switch(command.input)
            {
                case 'C':
                    createTree();
                    break;
                case 'X':
                    if(tree!=NULL)
                    {
                        tree->clear();
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
                        tree->insert(command.Contents);
                         cout << "VALUE "<< command.Contents << " INSERTED"<< endl << endl;
                    }
                    break;
                case 'F':
                    if(tree==NULL)
                        cout << "MUST CREATE TREE INSTANCE" << endl << endl;
                    else
                    {
                        tree->find(command.Contents);
                        cout << "VALUE "<< tree->find() << " ADDED TO FRONT" << endl << endl;
                    }
                    break;
                case 'R':
                    if(tree==NULL)
                        cout << "MUST CREATE TREE INSTANCE" << endl << endl;
                    else if(tree->remove(command.Contents))
                        cout << "VALUE " << command.Contents << " REMOVED" << endl << endl;
                    else
                        cout << "VALUE "<< command.Contents <<" NOT FOUND" << endl << endl;
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
                    else if(tree->inOrder(command.Contents))
                        cout << "VALUE " << command.Contents << " FOUND" << endl << endl;
                    else
                        cout << "VALUE "<< command.Contents <<" NOT FOUND" << endl << endl;
                    break;
                case 'E':
                    if(tree==NULL)
                        cout << "MUST CREATE TREE INSTANCE" << endl << endl;
                    else if(tree->reverseOrder(command.Contents))
                        cout << "VALUE " << command.Contents << " FOUND" << endl << endl;
                    else
                        cout << "VALUE "<< command.Contents <<" NOT FOUND" << endl << endl;
                    break;
                case '#':
                    break;
            }
        }
        fout.close();
    }
}