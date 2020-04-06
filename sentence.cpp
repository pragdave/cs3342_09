#include <iostream>
#include <map>
#include <vector>
#include <string>

using namespace std;

bool checkSentence(vector<string> sentence) {
    const int END = 6;
    map<pair<int, string>, int> table = {
        {make_pair(0, "the"), 1},
        {make_pair(1, "lazy"), 2},
        {make_pair(1, "smelly"), 2},
        {make_pair(1, "dog"), 3},
        {make_pair(1, "cat"), 3},
        {make_pair(2, "lazy"), 2},
        {make_pair(2, "smelly"), 2},
        {make_pair(2, "dog"), 3},
        {make_pair(2, "cat"), 3},
        {make_pair(3, "ran"), 4},
        {make_pair(3, "ate"), 4},
        {make_pair(4, "slowly"), 5},
        {make_pair(4, "noisily"), 5},
        {make_pair(4, "EOI"), END},
        {make_pair(5, "EOI"), END}
    };

    int currState = 0;
    for (int i = 0; i < sentence.size(); i++) {
        if (table.count(make_pair(currState, sentence[i])) == 1) {
            currState = table.at(make_pair(currState, sentence[i]));
            if (currState == END) {
                return true;
            }
        }
        else {
            return false;
        }
    }
}

int main() {
    vector<string> s1 = { "the", "cat", "ate", "EOI" };
    vector<string> s2 = {"the", "dog", "ran", "slowly", "EOI"};
    vector<string> s3 = {"the", "lazy", "cat", "ran", "slowly", "EOI"};
    vector<string> s4 = {"the", "smelly", "dog", "ran", "EOI"};
    vector<string> s5 = {"smelly", "dog", "ran", "EOI"};
    vector<string> s6 = {"the", "cat", "ate"};
    vector<string> s7 = {"the", "cat", "EOI"};
    vector<string> s8 = {"the", "smelly", "lazy", "cat", "ate", "EOI"};

    vector<vector<string> > sentences;

    sentences.push_back(s1);
    sentences.push_back(s2);
    sentences.push_back(s3);
    sentences.push_back(s4);
    sentences.push_back(s5);
    sentences.push_back(s6);
    sentences.push_back(s7);
    sentences.push_back(s8);
    
    cout << endl;
    for (int i = 0; i < sentences.size(); i++) {
        vector<string> temp = sentences[i];
        cout << "The sentence '";
        for (int j = 0; j < temp.size(); j++) {
            cout << temp[j] << " ";
        }
        if (checkSentence(temp)) {
            cout << "' is a valid sentence." << endl; 
        }
        else {
            cout << "' is not a valid sentence." << endl; 
        }
    }
    cout << endl;

return 0;
}

