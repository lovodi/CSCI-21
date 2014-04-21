#pragma once
#include  <cstdlib>
#include<iostream>
using namespace std;

template <class T>

class Box 
{
    public:
        Box(T newContents)
        {
            contents = newContents;
        }
        void setContents(T newContents)
        {
            contents = newContents;
        }
        
        T getContents() const
        {
            return contents;
        }
        
        friend ostream& operator<< (ostream& out, const Box& src)
        {
            out << src.getContents();
            return out;
        }
    private:
        T contents;
};