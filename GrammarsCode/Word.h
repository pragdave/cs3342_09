//
// Created by Sam Walsh on 4/5/20.
//
#include <iostream>
#include <string>

using namespace std;

#ifndef GRAMMARSCODE_WORD_H
#define GRAMMARSCODE_WORD_H

class Word{
private:
    string word;
    int type;

public:
    Word(const string &word, const int &type);

    const string &getWord() const;

    void setWord(const string &word);

    const int &getType() const;

    void setType(const int &type);

};

#endif //GRAMMARSCODE_WORD_H
