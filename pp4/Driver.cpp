#include "Driver.h"


Input::Input(string nextLine)
{
    input=nextLine[0];
    
    if(nextLine.length()==1)
        Contents="";
    else{
        stringstream temp(nextLine.substr(2));
        temp >> Contents;
        for(unsigned int i(0); i<Contents.length(); ++i)
        {
            Contents[i]=tolower(Contents[i]);
        }
    }
}

Driver::Driver(string download)
    :tree(NULL)
{
    file.open(download.c_str());
    if(file.bad())
    {
        cerr<< "File Not Loaded";
        exit(1);
    }
}

Driver::~Driver()
{
    if (tree!=NULL)
        tree->clear();
}

void Driver::createTree()
    {
    if(tree!=NULL)
        delete tree;
        
    tree = new BSTree<Word>;
}

void Driver::getSize()
{
    if(tree!=NULL)
        cout << tree->Size() << endl;
    else
        cout << "MUST CREATE TREE INSTANCE" << endl;
}

void Driver::deleteTree()
{
    if(tree!=NULL)
    {
        delete tree;
        tree=NULL;
    }
    else
        cout << "MUST CREATE TREE INSTANCE" << endl;
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
            Input com(input);
            switch(com.input)
            {
            case 'C':
                //create
                createTree();
                cout << "TREE CREATED" << endl;
            break;
            case'X':
                //clear
                if(tree==NULL)
                    cout << "MUST CREATE TREE INSTANCE" << endl;
                else
                {
                    tree->clear();
                    cout << "TREE CLEARED" << endl;
                }
            break;
            case 'D':
                //delete
                if(tree==NULL)
                    cout << "MUST CREATE TREE INSTANCE" << endl;
                else{
                    deleteTree();
                    cout << "TREE DELETED" << endl;
                }
            break;
            case 'I':
                //insert
                if(tree==NULL)
                    cout << "MUST CREATE TREE INSTANCE" << endl;
                else if(tree->insert(com.Contents))
                {
                    cout << "WORD ";
                    cout << com.Contents;
                    cout << " INSERTED" << endl;
                }
                else
                {
                    cout << "WORD " << com.Contents << " INCREMENTED" << endl;
                    tree->get(com.Contents)->incrementCount();
                }
            break;
            case 'F':
                //find
                if(tree==NULL)
                    cout << "MUST CREATE TREE INSTANCE" << endl;
                else if(tree->Size()==0)
                    cout << "TREE EMPTY" << endl;
                else if(tree->get(com.Contents) !=NULL)
                    cout << *tree->get(com.Contents)<< " FOUND" << endl;
                else
                    cout << com.Contents <<" NOT FOUND" << endl;
            break;
            case 'R':
                //remove
                if(tree==NULL)
                    cout << "MUST CREATE TREE INSTANCE" << endl;
                else if(tree->Size()==0)
                    cout << "TREE EMPTY" << endl;
                else if(tree->remove(com.Contents))
                    cout << "REMOVED " << com.Contents << endl;
                else
                    cout << com.Contents <<" NOT FOUND" << endl;
            break;
            case 'G':
                //get
                if(tree==NULL)
                    cout << "MUST CREATE TREE INSTANCE" << endl;
                else if(tree->Size()==0)
                    cout << "TREE EMPTY" << endl;
                else if(tree->get(com.Contents) !=NULL)
                    cout << tree->get(com.Contents);
                else
                    cout << com.input <<" NOT FOUND" << endl;
            break;
            case 'N':
                //number
                if(tree==NULL)
                    cout << "MUST CREATE TREE INSTANCE" << endl;
                else
                    cout << "TREE SIZE IS " << tree->Size() << endl;
            break;
            case 'O':
                //in order print
                if(tree==NULL)
                    cout << "MUST CREATE TREE INSTANCE" << endl;
                else
                {
                    tree->inOrder();
                    cout << endl;
                }
            break;
            case 'E':
                // in reverse print
                if(tree==NULL)
                    cout << "MUST CREATE TREE INSTANCE" << endl;
                else
                {
                    tree->reverseOrder();
                    cout << endl;
                }
            break;
            }
        }
    }
}