#include <unordered_map>
#include <string>
#include <sstream>
#include <iostream>
using namespace std;

bool validateState(const string&);
void runTests();

int main()
{
    runTests();

    return 0;
}

void runTests()
{
    string tests[9];
    tests[0] = "the lazy dog ate slowly";
    tests[1] = "the smelly dog ran noisily";
    tests[2] = "the lazy smelly dog ate slowly";
    tests[3] = "the smelly lazy dog ran noisily";
    tests[4] = "the dog ran slowly";
    tests[5] = "the ate slowly";
    tests[6] = "the lazy dog ate slowly noisily";
    tests[7] = "the lazy dog ate";
    tests[8] = "the lazy smelly lazy smelly smelly lazy dog ate";

    bool expected[9];
    expected[0] = true;
    expected[1] = true;
    expected[2] = true;
    expected[3] = true;
    expected[4] = true;
    expected[5] = false;
    expected[6] = false;
    expected[7] = true;
    expected[8] = true;

    int success = 0;

    cout << "RUNNING TESTS" << endl;

    for (int i = 0; i < 9; i++)
    {
        bool state = validateState(tests[i]);

        if (state != expected[i])
        {
            cout << "FAILED TEST " << (i + 1) << ": SENTENCE '" << tests[i] << "' RESULTED IN '" << (state ? "valid" : "invalid") << "' ERRONEOUSLY" << endl;
            continue;
        }

        success++;
    }

    cout << "PASSED " << success << " TESTS" << endl;
}

bool validateState(const string& sentence)
{
    const int END_STATE = 5;
    const string EOI = "\0";

    unordered_map<int, unordered_map<string, int>> state_changers;
    state_changers[0]["the"] = 1;
    state_changers[1]["lazy"] = 1;
    state_changers[1]["smelly"] = 1;
    state_changers[1]["dog"] = 2;
    state_changers[1]["cat"] = 2;
    state_changers[2]["ate"] = 3;
    state_changers[2]["ran"] = 3;
    state_changers[3][EOI] = END_STATE;
    state_changers[3]["slowly"] = 4;
    state_changers[3]["noisily"] = 4;
    state_changers[4][EOI] = END_STATE;

    int state = 0;
    istringstream buffer(sentence);
    string word;

    while (buffer.good())
    {
        buffer >> word;
        
        if (state_changers[state].empty() || state_changers[state].count(word) == 0)
        {
            return false;
        }

        state = state_changers[state][word];
    }

    if (state_changers[state].empty() || state_changers[state].count(EOI) == 0)
    {
        return false;
    }

    state = state_changers[state][EOI];

    return state == END_STATE;
}