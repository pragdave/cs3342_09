//
// Created by Sam Walsh on 4/5/20.
//

#include "Word.h"

Word::Word(const string &word, const int &type) : word(word), type(type) {}

const string &Word::getWord() const {
    return word;
}

void Word::setWord(const string &word) {
    Word::word = word;
}

const int &Word::getType() const {
    return type;
}

void Word::setType(const int &type) {
    Word::type = type;
}
