#include "Operator.h"

Input::Input(string newline)
{
    input=(char)newline[0];
    Contents=0;
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
    {
        testRun = new DLList;
    }
    else
    {
        delete testRun;
        testRun = new DLList;
    }
}

void Operator::run()
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
                createList();
                break;
            case 'X':
                if(testRun!=NULL)
                {
                    testRun->clearList();
                    cout << "LIST CLEARED" << endl << endl;
                }
                else
                {
                    cout << "MUST CREATE LIST INSTANCE" << endl << endl;
                }
                break;
            case 'D':
                if(testRun==NULL)
                    cout << "MUST CREATE LIST INSTANCE" << endl << endl;
                else
                {
                    delete testRun;
                    testRun=NULL;
                    cout << "LIST DELETED" << endl << endl;
                }
                break;
            case 'I':
                if(testRun==NULL)
                    cout << "MUST CREATE LIST INSTANCE" << endl << endl;
                else
                {
                    testRun->insert(newInput.Contents);
                     cout << "VALUE "<< newInput.Contents << " INSERTED"<< endl << endl;
                }
                break;
            case 'F':
                if(testRun==NULL)
                    cout << "MUST CREATE LIST INSTANCE" << endl << endl;
                else
                {
                    testRun->pushFront(newInput.Contents);
                    cout << "VALUE "<< testRun->getFront() << " ADDED TO FRONT" << endl << endl;
                }
                break;
            case 'B':
                if(testRun==NULL)
                {
                    cout << "MUST CREATE LIST INSTANCE" << endl << endl;
                }
                else
                {
                    testRun->pushBack(newInput.Contents);
                    cout << "VALUE "<< testRun->getBack() <<" ADDED TO BACK"<< endl << endl;
                }
                break;
            case 'A':
                if(testRun==NULL)
                    cout << "MUST CREATE LIST INSTANCE" << endl << endl;
                else if(!testRun->getSize())
                {
                    cout << "LIST EMPTY" << endl << endl;
                }
                else
                {
                    cout << "VALUE " << testRun->getFront() << " AT FRONT" << endl << endl;
                }
                break;
            case 'Z':
                if(testRun==NULL)
                    cout << "MUST CREATE LIST INSTANCE" << endl << endl;
                else if(!testRun->getSize())
                {
                    cout << "LIST EMPTY" << endl << endl;
                }
                else
                {
                     cout << "VALUE "<< testRun->getBack() <<" AT BACK" << endl << endl;
                }
                break;
            case 'T':
                if(testRun==NULL)
                    cout << "MUST CREATE LIST INSTANCE" << endl << endl;
                else if(!testRun->getSize())
                {
                    cout << "LIST EMPTY" << endl << endl;
                }
                else
                {
                    testRun->popFront();
                }
                break;
            case 'K':
                if(testRun==NULL)
                    cout << "MUST CREATE LIST INSTANCE" << endl << endl;
                else if(!testRun->getSize())
                {
                    cout << "LIST EMPTY" << endl << endl;
                }
                else
                {
                    testRun->popBack();
                    cout << "REMOVED BACK" << endl << endl;
                }
                break;
            case 'E':
                if(testRun==NULL)
                    cout << "MUST CREATE LIST INSTANCE" << endl << endl;
                else if(testRun->removeAll(newInput.Contents))
                        cout << "VALUE "<< newInput.Contents <<" ELIMINATED" << endl << endl;
                else
                        cout << "VALUE "<< newInput.Contents << " NOT FOUND" << endl << endl;
                break;
            case 'R':
                if(testRun==NULL)
                    cout << "MUST CREATE LIST INSTANCE" << endl << endl;
                else if(testRun->removeAll(newInput.Contents))
                    cout << "VALUE " << newInput.Contents << " REMOVED" << endl << endl;
                else
                    cout << "VALUE "<< newInput.Contents <<" NOT FOUND" << endl << endl;
                break;
            case 'N':
                if(testRun==NULL)
                    cout << "MUST CREATE LIST INSTANCE" << endl << endl;
                else
                {
                    testRun->getSize();
                }
                break;
            case 'G':
                if(testRun==NULL)
                    cout << "MUST CREATE LIST INSTANCE" << endl << endl;
                else if(testRun->getContents(newInput.Contents))
                    cout << "VALUE " << newInput.Contents << " FOUND" << endl << endl;
                else
                    cout << "VALUE "<< newInput.Contents <<" NOT FOUND" << endl << endl;
                break;
            case 'P':
                if(testRun==NULL)
                    cout << "MUST CREATE LIST INSTANCE" << endl << endl;
                else
                {
                    testRun->getSize();
                }
                break;
            case '#':
                break;
        }
    }
    fout.close();
}
