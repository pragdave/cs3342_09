#include <iostream>
#include <string>
#include <vector>
#include "Word.h"

using namespace std;

/*
 * Current state | Next word | Next state
--------------|-----------|-----------
    S0        |    the    |     S1
    S1        |    Adj    |     S2
    S2        |    Adj    |     S2
    S2        |   Noun    |     S3
    S1        |   Noun    |     S3
    S3        |   Verb    |     S4
    S4        |    EOI    |     END
    S4        |   Adverb  |     S5
    S5        |    EOI    |     END
 *
 * Translate this table into a programming language of your choice. Then write a
function that takes a list of words (ending "EOI") and runs the list through the
state machine. If the state machine cannot find a transition for a word when in
a given state, return false. If the state machine runs out of words and the
state is not "END" then return false. Otherwise return true.

Then write some unit tests that exercise your function, making sure that it
recognizes valid sentences and rejects invalid ones.

The answer should appear in one or more source files in the same directory as
this file. If I need to do anything more that type a single command to run your
code, include a script or makefile that will do the job.

 The = 1
 Adj = 2
 Noun = 3
 Verb = 4
 Adverb = 5
 EOI = 6
 */
bool isThisASentence(vector<Word>* vec);
int main() {
    vector<Word> statement;
    Word one("the", 1);
    Word two("smart", 2);
    Word three("dog", 3);
    Word four("ran", 4);
    Word five("gently", 5);
    Word six("eoi", 6);

    //The smart smart smart smart dog ran
    statement.push_back(one);
    statement.push_back(two);
    statement.push_back(two);
    statement.push_back(two);
    statement.push_back(two);
    statement.push_back(three);
    statement.push_back(four);
    statement.push_back(six);

    bool status = isThisASentence(&statement);

    if(status)
        cout << "This is a sentence!" << endl << endl;
    if(!status)
        cout << "This is not a sentence!" << endl << endl;

    statement.clear();

    //the smart dog ran gently
    statement.push_back(one);
    statement.push_back(two);
    statement.push_back(three);
    statement.push_back(four);
    statement.push_back(five);
    statement.push_back(six);

    status = isThisASentence(&statement);
    if(status)
        cout << "This is a sentence!" << endl << endl;
    if(!status)
        cout << "This is not a sentence!" << endl << endl;

    statement.clear();

    //the smart ran gently
    statement.push_back(one);
    statement.push_back(two);
    statement.push_back(four);
    statement.push_back(five);
    statement.push_back(six);

    status = isThisASentence(&statement);
    if(status)
        cout << "This is a sentence!" << endl << endl;
    if(!status)
        cout << "This is not a sentence!" << endl << endl;

    return 0;
}
bool isThisASentence(vector<Word>* vec){
    //State is zero. If the transition is not "the" it is not a sentence
    if((*vec)[0].getType() != 1) {
        cout << (*vec)[0].getWord() << " ";
        cout << endl;
        return false;
    }
    else
        cout << (*vec)[0].getWord() << " ";

    //If reached here, state is now one. If transition is not an Adj or a Noun, return false;
    if((*vec)[1].getType() != 2 && (*vec)[1].getType() != 3) {
        cout << (*vec)[1].getWord() << " ";
        cout << endl;
        return false;
    }
    else
        cout << (*vec)[1].getWord() << " ";

    int index = 2;

    //If we go on to state 2, go on as long as we still have adjectives. Then check if the next transition leads to S3
    if((*vec)[1].getType() ==  2){
        while((*vec)[index].getType() == 2){
            cout << (*vec)[index].getWord() << " ";
            index++;
        }
        if((*vec)[index].getType() != 3) {
            cout << (*vec)[index].getWord() << " ";
            cout << endl;
            return false;
        }
        else
            cout << (*vec)[index].getWord() << " ";
    }

    index++;
    //Now that we are at state 3 with both scenarios covered, check for transition to state four
    if((*vec)[index].getType() != 4) {
        cout << (*vec)[index].getWord() << " ";
        cout << endl;
        return false;
    }
    else
        cout << (*vec)[index].getWord() << " ";

    index++;
    //Now that we are at state 4, check for both possible transitions
    //if the transition is the end of the input, exit with a true status
    if((*vec)[index].getType() != 5 && (*vec)[index].getType() != 6) {
        cout << endl;
        return false;
    }
    else if((*vec)[index].getType() == 6){
        cout << endl;
        return true;
    }

    index++;
    //if we reach here we are at state 5, so check transition
    if((*vec)[index].getType() != 6) {
        cout << (*vec)[index - 1].getWord() << " " << endl;
        cout << endl;
        return false;
    }
    else{
        cout << (*vec)[index - 1].getWord() << " " << endl;
        return true;
    }
}
