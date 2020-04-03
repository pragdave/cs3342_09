#include <cassert>
#include <vector>
#include <string>
#include <unordered_map>
using namespace std;

class sentenceValidator {
private:
    // transition["the"][0] = 1, for S0 --the--> S1
    unordered_map<string, 
                  unordered_map<int, int>> transition;
    
    const int START = 0, END = 5;

    void addTransition(int stateSrc, int stateDest, string word) {
        transition[word][stateSrc] = stateDest;
    }

public:
    sentenceValidator() {
        addTransition(START, 1, "the");
        addTransition(1, 1, "lazy");
        addTransition(1, 1, "smelly");
        addTransition(1, 2, "dog");
        addTransition(1, 2, "cat");
        addTransition(2, 3, "ate");
        addTransition(2, 3, "ran");
        addTransition(3, 4, "noisily");
        addTransition(3, 4, "slowly");
        addTransition(3, END, "\0"); // EOI
        addTransition(4, END, "\0"); // EOI
    }

    bool isValid(vector<string> sentence) {
        sentence.push_back("\0"); // add EOI to the back

        int curState = START;

        for (string word: sentence) {
            // cannot find the word 
            if (!transition.count(word)) return false;
            
            // cannot find the source state
            if (!transition[word].count(curState)) {
                return false;
            }

            // move to next state
            curState = transition[word][curState];
        }
        return (curState == END);
    } 
};


void unitTest() {
    sentenceValidator sv;

    // false assertions
    assert(!sv.isValid({"no"}));
    assert(!sv.isValid({"the", "lazy", "cat", "run", "slowly"}));
    assert(!sv.isValid({"the"}));
    assert(!sv.isValid({"dog", "ate", "noisily"}));
    assert(!sv.isValid({"the", "smelly", "lazy", "cat"}));
    assert(!sv.isValid({"the", "ran", "cat", "slowly"}));
    assert(!sv.isValid({"the", "smelly", "lazy", "cats", "ate", "slowly"}));
    
    // true assertions
    assert(sv.isValid({"the", "smelly", "lazy", "cat", "ate", "slowly"}));
    assert(sv.isValid({"the", "smelly", "smelly", "cat", "ate", "slowly"}));
    assert(sv.isValid({"the", "dog", "ate"}));
    assert(sv.isValid({"the", "lazy", "dog", "ran"}));
    assert(sv.isValid({"the", "lazy", "smelly", "lazy", "dog", "ran"}));
    assert(sv.isValid({"the", "lazy", "smelly", "lazy", "dog", "ran", "noisily"}));
    assert(sv.isValid({"the", "lazy", "smelly", "lazy", "dog", "ran"}));
}

int main() {
    unitTest();

    return 0;
}