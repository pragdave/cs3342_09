#include <vector>
#include <string>
#include "parser.h"
#include <iostream>
using namespace std;

int main() {
    vector<string> t1 {"the", "cat", "ran", "EOI"};
    vector<string> t2 {"the", "dog", "ran", "EOI"};
    vector<string> t3 {"the", "cat", "ran", "slowly", "EOI"};
    vector<string> t4 {"the", "cat", "EOI"};
    vector<string> t5 {"the", "smelly", "cat", "ran", "EOI"};
    vector<string> t6 {"the", "lazy", "lazy", "lazy", "dog", "ran", "noisily", "EOI"};
    vector<string> t7 {"the", "rabbit", "ran", "really fast", "EOI"};

    parser tester;
    cout << "A 1 means it is valid, a 0 means it is not" << endl;
    cout << "Test Sentence 1: " <<  tester.check(t1) << endl;
    cout << "Test Sentence 2: " <<  tester.check(t2) << endl;
    cout << "Test Sentence 3: " <<  tester.check(t3) << endl;
    cout << "Test Sentence 4: " <<  tester.check(t4) << endl;
    cout << "Test Sentence 5: " <<  tester.check(t5) << endl;
    cout << "Test Sentence 6: " <<  tester.check(t6) << endl;
    cout << "Test Sentence 7: " <<  tester.check(t7) << endl;



    return 0;
}
