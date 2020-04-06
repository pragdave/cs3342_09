#include <string>
#include <iostream>
#include <vector>

using namespace std;

bool isValid(string, int&);

int main(){

    vector<vector<string>> sentences;

    //Test Sentences
    vector<string> s1 = {"the", "lazy", "dog", "ate", "slowly", "EOI"};
    vector<string> s2 = {"the", "lazy", "smelly", "dog", "ate", "slowly", "EOI"};
    vector<string> s3 = {"the", "smelly", "dog", "ran", "EOI"};
    vector<string> s4 = {"the", "dog", "ate", "EOI"};
    vector<string> s5 = {"the",  "cat", "noisily", "EOI"};
    vector<string> s6 = {"the", "lazy", "lazy", "ran", "slowly", "EOI"};
    vector<string> s7 = {"the",  "dog", "noisily", "slowly", "EOI"};
    vector<string> s8 = {"the", "smelly", "cat", "ran", "slowly", "EOI"};

    sentences.push_back(s1);
    sentences.push_back(s2);
    sentences.push_back(s3);
    sentences.push_back(s4);
    sentences.push_back(s5);
    sentences.push_back(s6);
    sentences.push_back(s7);
    sentences.push_back(s8);



    bool answers[8] = {false, true, true, true, false, false, false, true};
    bool results[8] = {true, true, true, true, true, true, true, true};

    for(int i = 0; i < sentences.size(); i++){
        bool valid = true;
        int state = 0;
        for(int j = 0; j < sentences[i].size(); j++){
           valid = isValid(sentences[i][j], state);

           if(valid == false){
               results[i] = false;
               break;
           }
        }
    }

    for(int i = 0; i <8; i++){
        if(!results[i]){
            cout << "Sentence " << i << " is not valid." << endl;
        }
        else{
            cout << "Sentence " << i << " is valid." << endl;
        }
    }

    return 0;

}

bool isValid(string word, int& state){
    bool valid = true;

    if(word == "the" && state == 0){
        state ++;
        return true;
    }

    else if((word == "lazy" ||  word == "smelly") && (state == 1)){
        return true;
    }

   else if((word == "dog" || word == "cat") && (state == 1)){
        state ++;
        return true;

    }

    else if((word == "ate" || word == "ran") && (state == 2)){
        state ++;
        return true;

    }

    else if((word == "noisily" || word == "slowly") && (state == 3)){
        return true;
    }
    else if(word == "EOI" && (state == 3)){
        return true;
    }
    else{
        cout << word << state << endl;
        return false;
    }




}