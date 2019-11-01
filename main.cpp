//
//  main.cpp
//  GrammarsAndSyntaxHW
//
//  Created by Kirby Cravens on 10/31/19.
//  Copyright © 2019 Kirby Cravens. All rights reserved.
//

#include <iostream>
#include <ctime>
#include <cstdlib>
#include <vector>

using namespace std;

string table[10][3] = {
    {"S0","the","S1"},
    {"S1","lazy","S1"},
    {"S1","smelly","S2"},
    {"S2","dog","S2"},
    {"S2","cat","S3"},
    {"S3","ate","S3"},
    {"S3","ran","S4"},
    {"S4","slowly","S4"},
    {"S4","noisily","S5"},
    {"S5","EOI","END"}
};

string sentence = "";

bool stateMachine(){
    string currentState, nextState;
    bool choice = true, done = false,optional = true;
    for(int i = 0; i < 10; i++){
        currentState = table[i][0];
        if(!table[i][2].empty())
            nextState = table[i][2];
        else
            return false;
        if(currentState == "S0"){
            sentence += table[i][1];
        }
        else if(currentState == "S1"){
            int r = rand() % 2;
            if(r)
                sentence += " " + table[i][1];
        }
        else if(currentState == "S2" || currentState == "S3"){
            if(!done){
                if(choice){
                    int r = rand() % 2;
                    if(r){
                        sentence += " " + table[i][1];
                        done = true;
                    }
                    else
                        choice = false;
                }
                else{
                    sentence += " " + table[i][1];
                    choice = true;
                }
            }
            else
                done = false;
        }
        else if(currentState == "S4"){
            int r = rand() % 2;
            if(r && optional){
                sentence += " " + table[i][1];
                optional = false;
            }
        }
        else if(currentState == "S5"){
            if(table[i][1] != "EOI")
                return false;
            if(nextState != "END")
                return false;
        }
    }
    return true;
}

bool test(){
    cout << "Running 10 Tests" << endl << endl;
    for(int i = 0; i < 10; i++){
        if(!stateMachine()){
            cout << "State Machine Failed" << endl;
            return false;
        }
        string word;
        vector<string> words;
        for(auto x : sentence){
            if (x == ' ')
            {
                words.push_back(word);
                cout << word + " ";
                word = "";
            }
            else
            {
                word = word + x;
            }
        }
        words.push_back(word);
        cout << word << endl;
        
        if(words[0] != "the"){
            cout << "Failed: Sentence does not start with 'the'" << endl;
            return false;
        }
        
        if(words[1] != "dog" && words[1] != "cat"){
            if(words[1] != "lazy" && words[1] != "smelly"){
                cout << "Failed: 'the' is not followed by a noun or adjective" << endl;
                return false;
            }
        }
        
        if(sentence.find("dog") != string::npos && sentence.find("cat") != string::npos){
            cout << "Failed: Sentence has two nouns" << endl;
            return false;
        }
        
        if(!(sentence.find("dog") != string::npos) && !(sentence.find("cat") != string::npos)){
            cout << "Failed: Sentence has no nouns" << endl;
            return false;
        }
        
        if(sentence.find("ate") != string::npos && sentence.find("ran") != string::npos){
            cout << "Failed: Sentence has two verbs" << endl;
            return false;
        }
        
        if(!(sentence.find("ate") != string::npos) && !(sentence.find("ran") != string::npos)){
            cout << "Failed: Sentence has no verbs" << endl;
            return false;
        }
        
        if(sentence.find("noisily") != string::npos && sentence.find("slowly") != string::npos){
            cout << "Failed: Sentence has two adverbs" << endl;
            return false;
        }
        
        if(words[words.size()-1] != "noisily" && words[words.size()-1] != "slowly"){
            if(words[words.size()-1] != "ate" && words[words.size()-1] != "ran"){
                cout << "Failed: Sentence does not end in verb or adverb" << endl;
                return false;
            }
        }
        cout << "Passed" << endl << endl;
        sentence = "";
    }
    return true;
}

int main(int argc, const char * argv[]) {
    srand(time(0));
    
    if(test())
        cout << "Passed all Tests" << endl;
    else
        cout << "Test Failed" << endl;
    
    return 0;
}
