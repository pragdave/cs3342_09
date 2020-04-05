#include <iostream>
#include <fstream>
#include <string.h>

using namespace std;

// Translate this table into a programming language of your choice. Then write a
// function that takes a list of words (ending "EOI") and runs the list through the
// state machine. If the state machine cannot find a transition for a word when in
// a given state, return false. If the state machine runs out of words and the
// state is not "END" then return false. Otherwise return true.

// Then write some unit tests that exercise your function, making sure that it
// recognizes valid sentences and rejects invalid ones.

// The answer should appear in one or more source files in the same directory as
// this file. If I need to do anything more that type a single command to run your
// code, include a script or makefile that will do the job.

int main(int argc, char* argv[]){
    bool valid = false;
    string word;
    string state = "S0";
    for(int i = 1; i < argc; i++){
        word = argv[i];
        if(state == "S0"){
            if(word == "the"){
                state = "S1";
            }
            else{
                break;
            }
        }
        else if(state == "S1"){
            if(word == "smelly" || word == "lazy"){
                state = "S2";
            }
            else if(word == "dog" || word == "cat"){
                state = "S3";
            }
            else{
                break;
            }
        }
        else if(state == "S2"){
            if(word == "dog" || word == "cat"){
                state = "S3";
            }
            else if(word != "smelly" && word != "lazy"){
                break;
            }
        }
        else if(state == "S3"){
            if(word == "ran" || word == "ate"){
                state = "S4";
            }
            else{
                break;
            }
        }
        else if(state == "S4"){
            if(word == "slowly" || word == "noisily"){
                state = "S6";
            }
            else if(word == "EOI"){
                state = "END";
            }
            else{
                break;
            }
        }
        else if(state == "S6"){
            if(word == "EOI"){
                state = "END";
            }
            else{
                break;
            }
        }
        else{
            break;
        }
    }
    if(state == "END"){
        valid = true;
    }

    ofstream output;
    output.open("output.txt");
    if(!output.is_open()){
        cout << "failed to open output file" << endl;
        return -1;
    }
    output << valid;
    output.close();
    return 0;
}