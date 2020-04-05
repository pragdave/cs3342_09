#include <iostream>
#include "parser.h"

using namespace std;
int main(){
    vector<string> T1 = {"the", "lazy", "cat", "ate", "slowly", "EOI"};
    vector<string> T2 = {"the", "lazy", "dog", "ate", "slowly", "EOI"};
    vector<string> T3 = {"the", "smelly", "cat", "ran", "slowly", "EOI"};
    vector<string> T4 = {"the", "smelly", "dog", "ran", "noisily", "EOI"};
    vector<string> T5 = {"the", "smelly", "cat", "ate", "noisily", "EOI"};

    vector<string> F1 = {"lazy", "cat", "ate", "slowly", "EOI"};
    vector<string> F2 = {"dog", "ate", "slowly", "EOI"};
    vector<string> F3 = {"the", "smelly", "ran", "slowly", "EOI"};
    vector<string> F4 = {"the", "smelly", "dog", "ran", "noisily"};
    vector<string> F5 = {"EOI"};

    parser parse;

    //true
    if(parse.FSManalyze(T1)){
        cout << "true" << endl;
    }
    else{
        cout << "false" << endl;
    }

    if(parse.FSManalyze(T2)){
        cout << "true" << endl;
    }
    else{
        cout << "false" << endl;
    }

    if(parse.FSManalyze(T3)){
        cout << "true" << endl;
    }
    else{
        cout << "false" << endl;
    }

    if(parse.FSManalyze(T4)){
        cout << "true" << endl;
    }
    else{
        cout << "false" << endl;
    }

    if(parse.FSManalyze(T5)){
        cout << "true" << endl;
    }
    else{
        cout << "false" << endl;
    }

    //false
    if(parse.FSManalyze(F1)){
        cout << "true" << endl;
    }
    else{
        cout << "false" << endl;
    }

    if(parse.FSManalyze(F2)){
        cout << "true" << endl;
    }
    else{
        cout << "false" << endl;
    }

    if(parse.FSManalyze(F3)){
        cout << "true" << endl;
    }
    else{
        cout << "false" << endl;
    }

    if(parse.FSManalyze(F4)){
        cout << "true" << endl;
    }
    else{
        cout << "false" << endl;
    }

    if(parse.FSManalyze(F5)){
        cout << "true" << endl;
    }
    else{
        cout << "false" << endl;
    }
}