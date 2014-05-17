#include "Word.h"

Word::Word()
    :count(1)
{/*why*/}
Word::Word(string newWord)
    :word(newWord), count(1)
{/*hello*/}
Word::~Word()
{/*there*/}

string Word::getWord() const{
    return word;
}
void Word::setWord(string newWord)
{
    word = newWord;
}

unsigned int Word::getCount() const
{
    return count;
}
void Word::incrementCount()
{
    ++count;
}

bool operator ==(Word word1, Word word2)
{
    for(unsigned int i(0); i<word1.word.length(); ++i)
        word1[i] = tolower(word1[i]);
    for(unsigned int i(0); i<word2.word.length(); ++i)
        word2[i] = tolower(word2[i]);
    return (word1.word == word2.word);
}
bool operator <(Word word1, Word word2)
{
    for(unsigned int i(0); i<word1.word.length(); ++i)
        word1[i] = tolower(word1[i]);
    for(unsigned int i(0); i<word2.word.length(); ++i)
        word2[i] = tolower(word2[i]);
    return (word1.word < word2.word);
}
bool operator >(Word word1, Word word2)
{
    for (unsigned int i(0); i<word1.word.length(); ++i)
        word1[i] = tolower(word1[i]);
    for(unsigned int i(0); i<word2.word.length(); ++i)
        word2[i] = tolower(word2[i]);
    return (word1.word > word2.word);
}
ostream& operator <<(ostream& out, Word word1)
{
    out << word1.word << " " << word1.count;
    return out;
}

char& Word::operator [](unsigned int i)
{
    return word[i];
}

