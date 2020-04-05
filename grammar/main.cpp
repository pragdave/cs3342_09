//Translate this table into a programming language of your choice. Then write a
//        function that takes a list of words (ending "EOI") and runs the list through the
//        state machine. If the state machine cannot find a transition for a word when in
//a given state, return false. If the state machine runs out of words and the
//        state is not "END" then return false. Otherwise return true.
//
//Then write some unit tests that exercise your function, making sure that it
//recognizes valid sentences and rejects invalid ones.
//
//The answer should appear in one or more source files in the same directory as
//this file. If I need to do anything more that type a single command to run your
//code, include a script or makefile that will do the job.

//    Current state | Next word | Next state
//    --------------|-----------|-----------
//        S0        |    the    |   S1
//        S1        | Adjective |   S2
//        S1        |    Noun   |   S3
//        S2        | Adjective |   S2
//        S2        |    Noun   |   S3
//        S3        |   Verb    |   S4
//        S4        |  Adverb   |   S5
//        S4        |    EOI    |   END
//        S5        |    EOI    |   END

#include <iostream>
#include <string>
#include <vector>
#include <sstream>

using namespace std;

bool parse(const string& str);
bool start(vector<string> vec, int pos);
bool s1(vector<string> vec, int pos);
bool s2(vector<string> vec, int pos);
bool s3(vector<string> vec, int pos);
bool s4(vector<string> vec, int pos);
bool s5(vector<string> vec, int pos);

int main() {
    cout << "1: valid sentence, 0: invalid sentence" << endl;
    string str1 = "the adjective noun verb adverb EOI";
    bool bool1 = parse(str1);
    cout << str1 << ": " << bool1 << endl;
    string str2 = "the noun verb EOI";
    bool bool2 = parse(str2);
    cout << str2 << ": " << bool2 << endl;
    string str3 = "noun EOI";
    bool bool3 = parse(str3);
    cout << str3 << ": " << bool3 << endl;
    string str4 = "the adjective adjective adjective noun verb EOI";
    bool bool4 = parse(str4);
    cout << str4 << ": " << bool4 << endl;
    string str5 = "the noun verb";
    bool bool5 = parse(str5);
    cout << str5 << ": " << bool5 << endl;
    return 0;
}

bool parse(const string& str){
    vector<string> tokens;
    stringstream check(str);
    string temp;
    while(getline(check, temp, ' ')){
        tokens.push_back(temp);
    }
    return start(tokens, 0);
}

//"the"
bool start(vector<string> vec, int pos){
    if(pos > vec.size() - 1)
        return false;
    string test = vec.at(pos);
    if(test != "the")
        return false;
    pos++;
    return s1(vec, pos);
}

//the -> adj or noun
bool s1(vector<string> vec, int pos){
    if(pos > vec.size() - 1)
        return false;
    string test = vec.at(pos);
    pos++;
    if(test == "adjective")
        return s2(vec, pos);
    else if(test == "noun")
        return s3(vec, pos);
    else
        return false;
}

//adj -> adj or noun
bool s2(vector<string> vec, int pos){
    if(pos > vec.size() - 1)
        return false;
    string test = vec.at(pos);
    pos++;
    if(test == "adjective")
        return s2(vec, pos);
    else if(test == "noun")
        return s3(vec, pos);
    else
        return false;
}

// noun -> verb
bool s3(vector<string> vec, int pos){
    if(pos > vec.size() - 1)
        return false;
    string test = vec.at(pos);
    pos++;
    if(test == "verb")
        return s4(vec, pos);
    else
        return false;
}

//verb -> adverb or eoi
bool s4(vector<string> vec, int pos){
    if(pos > vec.size() - 1)
        return false;
    string test = vec.at(pos);
    pos++;
    if(test == "EOI")
        return true;
    else if(test == "adverb")
        return s5(vec, pos);
    else
        return false;
}

//adverb -> eoi
bool s5(vector<string> vec, int pos){
    if(pos > vec.size())
        return false;
    string test = vec.at(pos);
    pos++;
    return test == "EOI";
}