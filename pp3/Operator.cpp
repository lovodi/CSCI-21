#include "Operator.h"

Input::Input(string newline)
{
    input=(char)newline[0];
    if(newline.length()==2)
    {
        Contents=0;
        return;
    }
}
Operator::Operator(string newfile)
{
    file = newfile;
    testRun = NULL;
}


Operator::~Operator()
{
    delete testRun;
}


void Operator::createList()
{
    if(testRun == NULL)
        testRun=new DLList;
    else
    {
        delete testRun;
        testRun=new DLList;
    }
}

void Operator::run()
{
    fstream fout(file.c_str());
    if(!(fout.is_open()))
    {
        cout << "file load error." << endl;
        return;
    }
    
    string temp;
    while(getline(fout, temp))
    {
        Input newInput(temp);

        switch (newInput.input)
        {
            case 'C':
                createList();
                cout << "LIST CREATED"<<endl;
                break;
            case 'X':
                if(testRun!=NULL)
                {
                    testRun->clearList();
                    cout << "LIST CLEARED" << endl;
                }
                else
                {
                    cout << "MUST CREATE LIST INSTANCE" << endl;
                }
                break;
            case 'D':
                if(testRun==NULL)
                    cout << "MUST CREATE LIST INSTANCE" << endl;
                else
                {
                    delete testRun;
                    testRun=NULL;
                    cout << "LIST DELETED" << endl;
                }
                break;
            case 'I':
                if(testRun==NULL)
                    cout << "MUST CREATE LIST INSTANCE" << endl;
                else
                {
                    testRun->insert(newInput.Contents);
                     cout << "VALUE "<< newInput.Contents << " INSERTED"<< endl;
                }
                break;
            case 'F':
                if(testRun==NULL)
                    cout << "MUST CREATE LIST INSTANCE" << endl;
                else
                {
                    testRun->insertHead(newInput.Contents);
                    cout << "VALUE "<< testRun->getHead() << " ADDED TO HEAD" << endl;
                }
                break;
            case 'B':
                if(testRun==NULL)
                    cout << "MUST CREATE LIST INSTANCE" << endl;
                else
                {
                    testRun->insertTail(newInput.Contents);
                    cout << "VALUE "<< testRun->getTail() <<" ADDED TO TAIL"<< endl;
                }
                break;
            case 'A':
                if(testRun==NULL)
                    cout << "MUST CREATE LIST INSTANCE" << endl;
                else if(testRun->getFirst()==NULL)
                {
                    cout << "LIST EMPTY" << endl;
                }
                else
                {
                    cout << "VALUE " << testRun->getHead() << " AT HEAD" << endl;
                }
                break;
            case 'Z':
                if(testRun==NULL)
                    cout << "MUST CREATE LIST INSTANCE" << endl;
                else if(testRun->getLast()==NULL)
                {
                    cout << "LIST EMPTY" << endl;
                }
                else
                {
                     cout << "VALUE "<< testRun->getTail() <<" AT TAIL" << endl;
                }
                break;
            case 'T':
                if(testRun==NULL)
                    cout << "MUST CREATE LIST INSTANCE" << endl;
                else if(testRun->getFirst()==NULL)
                {
                    cout << "LIST EMPTY" << endl;
                }
                else
                {
                    testRun->removeHead();
                    cout << "REMOVED HEAD" <<endl;
                }
                break;
            case 'K':
                if(testRun==NULL)
                    cout << "MUST CREATE LIST INSTANCE" << endl;
                else if(testRun->getLast()==NULL)
                {
                    cout << "LIST EMPTY" << endl;
                }
                else
                {
                    testRun->removeTail();
                    cout << "REMOVED TAIL" << endl;
                }
                break;
            case 'E':
                if(testRun==NULL)
                    cout << "MUST CREATE LIST INSTANCE" << endl;
                else if(testRun->removeTarget(newInput.Contents))
                        cout << "VALUE "<< newInput.Contents <<" ELIMINATED" << endl;
                else
                        cout << "VALUE "<< newInput.Contents << " NOT FOUND" << endl;
                break;
            case 'R':
                if(testRun==NULL)
                    cout << "MUST CREATE LIST INSTANCE" << endl;
                else if(testRun->removeTarget(newInput.Contents))
                    cout << "VALUE " << newInput.Contents << " REMOVED" << endl;
                else
                    cout << "VALUE "<< newInput.Contents <<" NOT FOUND" << endl;
                break;
            case 'N':
                if(testRun==NULL)
                    cout << "MUST CREATE LIST INSTANCE" << endl;
                else
                {
                    testRun->getSize();
                }
                break;
            case 'G':
                if(testRun==NULL)
                    cout << "MUST CREATE LIST INSTANCE" << endl;
                else if(testRun->getContents(newInput.Contents))
                    cout << "VALUE " << newInput.Contents << " FOUND" << endl;
                else
                    cout << "VALUE "<< newInput.Contents <<" NOT FOUND" << endl;
                break;
            case 'P':
                if(testRun==NULL)
                    cout << "MUST CREATE LIST INSTANCE" << endl;
                else
                {
                    testRun->toString();
                }
                break;
            case '#':
                break;
        }
    }
    
    fout.close();
}