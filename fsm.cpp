#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

// a "table" with the key being (current state, next word) and
//the value as the next state to go to
map<pair<int, string>, int> table;

void initialization(){
    //create a table with all the valid states and next states
    table.insert(make_pair(make_pair(0, "the"), 1));
    table.insert(make_pair(make_pair(1, "lazy"), 1));
    table.insert(make_pair(make_pair(1, "smelly"), 1));
    table.insert(make_pair(make_pair(1, "dog"), 2));
    table.insert(make_pair(make_pair(1, "cat"), 2));
    table.insert(make_pair(make_pair(2, "ate"), 3));
    table.insert(make_pair(make_pair(2, "ran"), 3));
    table.insert(make_pair(make_pair(3, "slowly"), 4));
    table.insert(make_pair(make_pair(3, "noisily"), 4));
    table.insert(make_pair(make_pair(3, "EOI"), 5));
    table.insert(make_pair(make_pair(4, "EOI"), 5));
}

bool valid(vector<string> sentence){
    //initial state is 0
    int state = 0;
    for(int i = 0; i < sentence.size(); i++){
        //create a pair called key that contains the state and the next word
        pair<int, string> key = make_pair(state, sentence[i]);
        //if key is not found, the sentence is not valid, otherwise continue 
        //iterating over the sentence, getting the next state
        if(table.find(key) == table.end())
            return false;
        else
            state = table[key];
    }
    //if the final state is 5, my end state, and the word in the sentence is EOI, its valid
    if(state == 5 && sentence[sentence.size() - 1] == "EOI")
        return true;
    return false;
}

void tests(){
    //a variable to store each test sentence in
    vector<vector<string> > testSentences {
        {"the", "dog", "ate", "EOI"},
        {"the", "cat", "ate", "EOI"},
        {"the", "smelly", "dog", "ate", "EOI"},
        {"the", "lazy", "cat", "ran", "EOI"},
        {"the", "smelly", "cat", "ate", "noisily", "EOI"},
        {"the", "lazy", "dog", "ate", "slowly", "EOI"},
        {"the", "lazy", "smelly", "smelly", "smelly", "dog", "ate", "EOI"},
        {"the", "lazy", "dog", "barked", "noisily", "EOI"},
        {"the", "dog", "ate"},
        {"the", "EOI"}
    };
    //loop over every test sentence and test if its valid
    for(int i = 0; i < testSentences.size(); i++){
        if(valid(testSentences[i]))
            cout << "Sentence " << i << " is valid" << endl;
        else
            cout << "Sentence " << i << " is invalid" << endl;
    }
}

int main() {
    initialization();
    tests();
    return 0;
}
