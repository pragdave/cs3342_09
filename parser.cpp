#include "parser.h"

parser::parser() {
    machine.insert(make_pair(make_pair(0, "the"), 1));
    machine.insert(make_pair(make_pair(1, "lazy"), 1));
    machine.insert(make_pair(make_pair(1, "smelly"), 1));
    machine.insert(make_pair(make_pair(1, "dog"), 2));
    machine.insert(make_pair(make_pair(1, "cat"), 2));
    machine.insert(make_pair(make_pair(2, "ran"), 3));
    machine.insert(make_pair(make_pair(2, "ate"), 3));
    machine.insert(make_pair(make_pair(3, "noisily"), 4));
    machine.insert(make_pair(make_pair(3, "slowly"), 4));
    machine.insert(make_pair(make_pair(3, "EOI"), 5));
    machine.insert(make_pair(make_pair(4, "EOI"), 5));
}

bool parser::check(vector<string> sentence) {
    int state = 0;
    for (int x = 0; x < sentence.size(); x++) {
        pair<int, string> current = make_pair(state, sentence[x]);
        //call find function from map, if it is not found, the sentence isnt valid
        if (machine.find(current) == machine.end()) {
            return false;
        } else {
            state = machine[current];
        }
    }
    //if it reached the end state, it is a valid sentence
    if (state == 5) {
        return true;
    }
    return false;
}
