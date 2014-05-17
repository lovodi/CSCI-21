#pragma once

#include <string>
#include <cstdlib>
#include <iostream>

using namespace std;

class Word{
public:
    Word();
    Word(string newWord);
    virtual ~Word();
    
    string getWord() const;
    void setWord(string newWord);
    
    unsigned int getCount() const;
    void incrementCount();
    
    friend bool operator ==(Word word1, Word word2);
    friend bool operator <(Word word1, Word word2);
    friend bool operator >(Word word1, Word word2);
    friend ostream& operator <<(ostream& out, Word word1);
    char& operator [](unsigned int);
private:
    string word;
    unsigned int count;
};

