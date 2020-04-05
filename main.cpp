//
//  main.cpp
//  
//
//  Created by Mitchell Morrison on 4/3/20.
//

#include <stdio.h>
#include <string>
#include <cstring>
#include <vector>
#include <iostream>
#include <cstring>

using namespace std;

bool checkStates(char*);
void testCases(vector<char*>&);

int main() {

    vector<char*> allStrings;
    
    char case1[] = "the lazy dog ran slowly";
    char case2[] = "this sentence should not pass";
    char case3[] = "the smelly smelly smelly cat ate";
    char case4[] = "the dog ate noisily";
    char case5[] = "the lazy smelly smelly lazy dog ran slowly";
    char case6[] = "this is another sentence";
    char case7[] = "why am i doing homework on a friday afternoon?";
    char case8[] = "the dog ran";
    char case9[] = "the cat ate";
    char case10[] = "I am done";
    
	//all the char*'s that should and should not pass, 
	//1 = true, should pass and meets state requirements
    bool answers[] = {1, 0, 1, 1, 1, 0, 0, 1, 1, 0};
    
    //add each to vector
    allStrings.push_back(case1);
    allStrings.push_back(case2);
    allStrings.push_back(case3);
    allStrings.push_back(case4);
    allStrings.push_back(case5);
    allStrings.push_back(case6);
    allStrings.push_back(case7);
    allStrings.push_back(case8);
    allStrings.push_back(case9);
    allStrings.push_back(case10);
    
        
    //get all cases and assert against answers array
    for (int a = 0; a < allStrings.size(); a++) {
        bool ans = checkStates(allStrings[a]);
        assert(ans == answers[a]);
    }
    
    return 0;
}


bool checkStates(char* sentence) {
    //tokenize all words
    vector<char*> allWords;
    char* token;
    token = strtok(sentence, " ");
    while (token != NULL) {
        allWords.push_back(token);
        token = strtok(NULL, " ");
    }
    
    char blank[] = "";
    allWords.push_back(blank);
    
    char* words[] = {"the", "smelly", "lazy", "dog", "cat", "ate", "ran", "slowly", "noisily", "\0"};
    
    int state = 0;
    int count = 0;
    
    while (count < allWords.size()) {
        switch(state) {
            case 0:
                if (strcmp(allWords[count], "the") == 0)  {
                    state = 1;
                }
                break;
            case 1:
                if (strcmp(allWords[count], "smelly") == 0 || strcmp(allWords[count], "lazy") == 0) {
                    state = 1;
                }
                else if (strcmp(allWords[count], "dog") == 0 || strcmp(allWords[count], "cat") == 0) {
                    state = 2;
                }
                break;

            case 2:
                if (strcmp(allWords[count], "ate") == 0 || strcmp(allWords[count], "ran") == 0) {
                    state = 3;
                }
                break;

            case 3:
                 if (strcmp(allWords[count], "slowly") == 0 || strcmp(allWords[count], "noisily") == 0) {
                   state = 4;
                }
                else if (strcmp(allWords[count], "\0") == 0) {
                    return true; //only true if meets all conditions
                }
                break;

            case 4:
                if (strcmp(allWords[count], "\0") == 0) {
                    return true; //only true if meets all conditions
                }
                break;

        }
        count++;
    }

    return false; //defaults to false if not all conditions are met
}
