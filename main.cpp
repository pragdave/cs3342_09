#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <unordered_map>
#include <sstream>
#include <algorithm>

using namespace std;

vector <pair<string, string>> tests;

void readTests(string);
void runTests();

int main(int argc, char* argv[])
{
    std::string testsFile(argv[1]);
    readTests(testsFile);
    runTests();
    return 0;
}
void readTests(string testsFile)
{
    ifstream in(testsFile);
    if ( !in ) cout << "Can't read tests file." << endl;
    else{
        int i = 0;
        while(!(in.eof())){
            char buffer[1000];
            string sentence;
            string req;
            
            in.getline( buffer, 1000,'\n');
            sentence = string(buffer);

            in.getline( buffer, 1000,'\n');
            req = string(buffer);
            
            tests.push_back(make_pair(sentence,req));
        }
    }
}
void runTests()
{
    // translating the state table from A2.4
    unordered_map<int, unordered_map<string, int>> stateTable;
    stateTable[0]["the"] = 1;
    stateTable[1]["lazy"] = 1;
    stateTable[1]["smelly"] = 1;
    stateTable[1]["dog"] = 2;
    stateTable[1]["cat"] = 2;
    stateTable[2]["ran"] = 3;
    stateTable[2]["ate"] = 3;
    stateTable[3]["slowly"] = 4;
    stateTable[3]["noisily"] = 4;
    stateTable[3]["\0"] = 5;
    stateTable[4]["\0"] = 5;
    
    int testNum = 0;
    for ( auto itr = tests.begin() ; itr != tests.end() ; itr++ ){
        istringstream sentence((*itr).first);
        int currState = 0;
        string valid = "1";
        while (sentence.good())
        {
            string word;
            sentence >> word; // breaking the senstence into words

            // if exists a state with a next word that matches (word) -> go on to the next state
            if ( stateTable[currState][word] ) currState = stateTable[currState][word]; 
            else{
                valid = "0";
                break;
            }

        }
        // if the loop exited before reaching EOI -> sentence is invalid
        if ( valid == "1" && (!stateTable[currState]["\0"]) ) valid = "0"; 
        
        // asserting tests
        if ( valid == (*itr).second ) cout << "Test #" << ++testNum << ": Passed" << endl;
        else cout << "Test #" << ++testNum << ": Failed" << endl;
    }
}