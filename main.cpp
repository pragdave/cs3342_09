#include <iostream>
#include <string>
#include <vector>
using namespace std;

//returns true if a valid sentence
bool simpleSentence(vector<string> line){
    int size = line.size(); // used to prevent out of bounds error
    int i = 1;
    //checks first word is the
    if(line[0] != "the"){
        return false;
    }
    //determines if adjecives are in the sentence
    if((size > i) && (line[i] == "lazy" || line[i] == "smelly")){
        i++; // if one adjective then move the word iterator to the next word
        while(i < size) {
            if (line[i] == "lazy" || line[i] == "smelly") {
                i++; // if a more adjective move the word iterator
            }
            else{
                break;
            }
        }
    }

    //checks if following word is noun
    if((size > i) && (line[i] == "dog" || line[i] == "cat")){
        i++; // moves iterator
    }
    else{
        return false;
    }

    //checks if following word is verb
    if((size > i) && (line[i] == "ran" || line[i] == "ate")){
        i++; // moves iterator
    }
    else{
        return false;
    }

    //determines if there is an adverb
    if((size > i) && (line[i] == "nosily" || line[i] == "slowly")){
        i++;
    }

    //if end of sentence reached with no error return true
    return (size > i) && (line[i] == "EOI");
}
int main() {
    //Testing Strings
    vector<string> test1 = {"the", "dog", "ran", "EOI"};
    vector<string> test2 = {"the", "car", "ran", "EOI"};
    vector<string> test3 = {"the", "lazy", "smelly", "cat", "ate", "nosily", "EOI"};
    vector<string> test4 = {"the", "cat", "nosily", "EOI"};
    vector<string> test5 = {"the", "lazy", "dog", "ate", "EOI"};
    vector<string> test6 = {"the", "dog", "ran", "slowly", "EOI"};
    vector<string> test7 = {"the", "smelly", "dog", "ran", "lazy", "EOI"};
    vector<string> test8 = {"cat", "nosily", "ate", "EOI"};
    vector<string> test9 = {"the", "lazy", "lazy", "smelly", "cat", "ate", "nosily", "EOI"};

    cout << simpleSentence(test1) << endl;
    cout << simpleSentence(test2) << endl;
    cout << simpleSentence(test3) << endl;
    cout << simpleSentence(test4) << endl;
    cout << simpleSentence(test5) << endl;
    cout << simpleSentence(test6) << endl;
    cout << simpleSentence(test7) << endl;
    cout << simpleSentence(test8) << endl;
    cout << simpleSentence(test9) << endl;

    return 0;
}
