
#include <string>
#include <iostream>
#include <iterator>
#include <map>
#include <utility>
#include<vector>

using namespace std;
bool validateSentence(vector<string> ,std::map<pair<int,string>,int> & );
void unitTests(std::map<pair<int,string>,int> & okPaths);

/* make a map where the key is a pair of the current state and event, and the value is the next state.
map contains all valid key value pairs for the grammar provided */
void generateMap(std::map<pair<int,string>,int> & mp){

    mp.insert(make_pair(make_pair(0,"the"), 1));
    mp.insert(make_pair(make_pair(1,"smelly"), 1));
    mp.insert(make_pair(make_pair(1,"lazy"), 1));
    mp.insert(make_pair(make_pair(1,"dog"), 2));
    mp.insert(make_pair(make_pair(1,"cat"), 2));
    mp.insert(make_pair(make_pair(2,"ate"), 3));
    mp.insert(make_pair(make_pair(2,"ran"), 3));
    mp.insert(make_pair(make_pair(3,"slowly"), 4));
    mp.insert(make_pair(make_pair(3,"noisily"), 4));
    mp.insert(make_pair(make_pair(3,"EOI"), 50));
    mp.insert(make_pair(make_pair(4,"EOI"), 50));

}

int main () {
    //make map
    map<pair<int,string>, int> okPaths;
    generateMap(okPaths);

    unitTests(okPaths);//test validateSentence function
}

//tests the validateSentence function
void unitTests(std::map<pair<int,string>,int> & okPaths) {
    vector<string> sentence1{ "the", "smelly", "dog", "ran", "slowly", "EOI"};
    vector<string> sentence2 {"the", "lazy", "smelly", "cat", "ate", "EOI"};
    vector<string> sentence3 {"the", "cat", "ran", "wild", "EOI"};
    vector<string> sentence4 {"cat"};
    vector<string> sentence5{"the", "lazy" , "cat", "ate", "slowly"};
    vector<string> sentence6{"the" , "smelly", "lazy" ,"dog" , "ate", "EOI"};
    vector<string> sentence7{"piggy", "went", "home", "EOI"};
    vector<string> sentence8{"the", "smelly" , "lazy", "smelly", "cat", "ate","EOI"};

    bool isValid1 = validateSentence(sentence1,okPaths);
    cout <<"Test 1 "<<"Should be 1." << "It is: " << isValid1 <<endl;
    bool isValid2 = validateSentence(sentence2,okPaths);
    cout <<"Test 2 " << "Should be 1." << "It is: " << isValid2 <<endl;
    bool isValid3 = validateSentence(sentence3,okPaths);
    cout <<"Test 3 " << "Should be 0." << "It is: " << isValid3 <<endl;
    bool isValid4 = validateSentence(sentence4,okPaths);
    cout <<"Test 4 " <<"Should be 0." << "It is: " << isValid4 <<endl;
    bool isValid5 = validateSentence(sentence5,okPaths);
    cout <<"Test 5 " <<"Should be 0." << "It is: " << isValid5 <<endl;
    bool isValid6 = validateSentence(sentence6,okPaths);
    cout <<"Test 6 " <<"Should be 1." << "It is: " << isValid6 <<endl;
    bool isValid7 = validateSentence(sentence7,okPaths);
    cout <<"Test 7 " <<"Should be 0." << "It is: " << isValid7 <<endl;
    bool isValid8 = validateSentence(sentence8,okPaths);
    cout <<"Test 8 " <<"Should be 1." << "It is: " << isValid8 <<endl;
}

/*function that receives a vector of strings representing a possible sentence
 and a reference to a map containing the grammar rules.Checks if sentence complies to rules,
 and returns true if it does. Otherwise, returns false.*/
bool validateSentence(vector<string> theSent,std::map<pair<int,string>,int> & theMap){

    if(theSent.at(0)!="the"){
        return false;
    }
    int state = 0;
    int vecLength = theSent.size();
    for(int i= 0; i < vecLength;i++){
        string word = theSent.at(i);
        pair <int, string> stateEvent ;
        stateEvent.first = state;
        stateEvent.second = word ;

        if ( theMap.find(stateEvent) == theMap.end() ) {
            return false;       // pair not found in map, so sentence invalid
        }

        else {
            state = theMap.at(stateEvent); //pair found
            if ( (word == "EOI") && (state ==50)){  //50 is the final "next state"
                return true;    //sentence is valid
            }
        }
    }//end for loop
    return false;
}
