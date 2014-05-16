#pragma once
#include <string>
#include <sstream>
#include "BSTree.h"

using namespace std;

template <typename T>

class Word
{
    public:
        Word()
        {
            count = 1;
        }
        
        Word(string newWord)
        {
            word = newWord;
            count = 1;
        }
        
        virtual ~Word(){}
        
        string getWord() const
        {
            return word;
        }
        
        void setWord(string newWord)
        {
            word = newWord;
        }
        
        unsigned int getCount() const
        {
            return count;
        }
        
        void incrementCount()
        {
            count++;
        }
        
        
        friend bool operator ==(Word word1, Word word2)
        {
            for(unsigned int i(0); i<word1.word.length(); ++i)
                word1[i] = tolower(word1[i]);
            for(unsigned int i(0); i<word2.word.length(); ++i)
                word2[i] = tolower(word2[i]);
            return (word1.word == word2.word);
        }
        
        friend bool operator <(Word word1, Word word2)
        {
            for(unsigned int i(0); i<word1.word.length(); ++i)
                word1[i] = tolower(word1[i]);
            for(unsigned int i(0); i<word2.word.length(); ++i)
                word2[i] = tolower(word2[i]);
            return (word1.word < word2.word);
        }
        
        friend bool operator >(Word word1, Word word2)
        {
            for (unsigned int i(0); i<word1.word.length(); ++i)
                word1[i] = tolower(word1[i]);
            for(unsigned int i(0); i<word2.word.length(); ++i)
                word2[i] = tolower(word2[i]);
            return (word1.word > word2.word);
        }
        
        friend ostream& operator <<(ostream& out, Word word1)
        {
            out << word1.word << " " << word1.count;
            return out;
        }
        
        char& operator [](unsigned int i)
        {
            return word[i];
        }
    
    private:
        string word;
        unsigned int count;
    
};





/*
data members: word (string), count (unsigned int)
Word () : count to 1
Word (string newWord) : initialize word to newWord, count to 1
virtual ~Word () : nothing to be done
string getWord () const
void setWord (string newWord)
unsigned int getCount () const
void incrementCount () : add 1 to count
operator== (make sure this is case-insensitive)
operator< (make sure this is case-insensitive)
operator> (make sure this is case-insensitive)
operator<< : place contents of Word formatted as "WORD COUNT" on the stream
*/




