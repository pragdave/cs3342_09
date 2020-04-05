#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

void determineValidity(std::string input[]) {

    std::string nounArray[] = {"dog", "cat"};
    std::vector<std::string> nouns(nounArray,nounArray+2);

    std::string verbsArray[] = {"ran", "ate"};
    std::vector<std::string> verbs(verbsArray,verbsArray+2);

    std::string adjectivesArray[] = {"smelly", "lazy"};
    std::vector<std::string> adjectives(adjectivesArray,adjectivesArray+2);

    std::string adverbsArray[] = {"noisily", "slowly"};
    std::vector<std::string> adverbs(adverbsArray,adverbsArray+2);

    int state = 0; //represents the different states from FSM
    bool result = false; //end result to determine if input is valid or not

    if (input[0].compare("The") == 0) { //first word should be The
        state = 1; //update state
        int i = 1; //counter to keep track of place in sentence
        while (std::find(adjectives.begin(), adjectives.end(), input[i]) != adjectives.end()) {
            i++;
            continue; //continue in loop for however many adjectives there are
        }
        if (std::find(nouns.begin(), nouns.end(), input[i]) != nouns.end()) { //find noun
            i++, state++; //update state and place in sentence
            if (std::find(verbs.begin(), verbs.end(), input[i]) != verbs.end()){ //find verb
                i++, state++; //state = 3
                if (input[i] == "EOI") { //check if end of sentence
                    result = true;
                }
                else { //check for adverb
                    if (std::find(adverbs.begin(), adverbs.end(), input[i]) != adverbs.end()) {
                        i++, state++; //state = 4;
                        if (input[i] == "EOI") {
                            result = true;
                        }
                        else{
                            result = false;
                        }
                    }
                }
            }
        }
    }
    if(result){
        std::cout << "The sentence is valid" << std::endl;
    }
    else{
        std::cout << "The sentence is invalid" << std::endl;
    }
}

int main(int argc, char *argv[]) {

    //test cases
    std::string s1[] = {"The", "dog", "ran", "EOI"}; //valid
    std::string s2[] = {"cat", "ate"}; //invalid, needs to start with "The"
    std::string s3[] = {"The", "slow", "dog", "ate", "EOI"}; //invalid, no adj 'slow'
    std::string s4[] = {"The", "lazy", "smelly", "cat", "EOI"}; //invalid, need need verb
    std::string s5[] = {"The", "cat", "ran", "slowly", "EOI"}; //valid
    std::string s6[] = {"The", "cat", "ran", "slowly"}; //invalid, needs EOI
    std::string s7[] = {"The", "dog", "ran", "noisily", "EOI"}; //valid
    std::string s8[] = {"The", "smelly", "lazy", "dog", "ate", "EOI"}; //valid
    std::string s9[] = {"The", "smelly", "lazy", "cat", "ate", "noisily", "EOI"}; //valid
    std::string s10[] = {"The", "smelly", "lazy", "dog", "ate", "noisily", "slowly", "EOI"}; //invalid, too many adverbs

    determineValidity(s1);
    determineValidity(s2);
    determineValidity(s3);
    determineValidity(s4);
    determineValidity(s5);
    determineValidity(s6);
    determineValidity(s7);
    determineValidity(s8);
    determineValidity(s9);
    determineValidity(s10);

    return 0;
}