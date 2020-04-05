#include <string>
#include <vector>
#include <utility>
#include <cassert>
#include <iostream>

using namespace std;

struct entry
{
    int currentState;
    string nextWord;
    int nextState;
    entry(int a, string b, int c) : currentState(a), nextWord(b), nextState(c) {}
};

static const vector<entry> table{
    entry(0, "The", 1),
    entry(1, "smelly", 1),
    entry(1, "lazy", 1),
    entry(1, "dog", 2),
    entry(1, "cat", 2),
    entry(2, "ate", 3),
    entry(2, "ran", 3),
    entry(3, "slowly", 4),
    entry(3, "noisily", 4),
    entry(3, "EOI", 5),
    entry(4, "EOI", 5)};

bool isSentence(vector<string> sentence)
{
    int index = 0;
    int state = 0;
    bool isSentence = true;
    int size = sentence.size();

    if (size == 0 || size < 4)
        return false;

    while (true)
    {
        for (entry e : table)
        {
            if (e.currentState == state && sentence[index] == e.nextWord)
            {
                ++index;
                state = e.nextState;
                break;
            }
            else if (e.currentState > state)
            {
                isSentence = false;
                break;
            }
        }
        if (index >= size && state != 5)
        {
            isSentence = false;
            break;
        }
        else if (!isSentence || state == 5)
            break;
    }
    return isSentence;
}

void test()
{
    vector<vector<string>> trueTestTable{
        vector<string>{"The", "smelly", "cat", "ran", "noisily", "EOI"},
        vector<string>{"The", "smelly", "smelly", "smelly", "smelly", "smelly", "dog", "ate", "slowly", "EOI"},
    };
    vector<vector<string>> falseTestTable{
        vector<string>{"The", "lazy", "cat"},
        vector<string>{"lazy", "dog", "ate", "EOI"},
        vector<string>{"The", "smelly", "dog", "ran", "noisily"},
    };
    for (vector<string> testCase : trueTestTable)
    {
        assert(isSentence(testCase));
    }
    for (vector<string> testCase : falseTestTable)
    {
        assert(!isSentence(testCase));
    }
}

int main()
{
    test();
    cout << "Test success!" << endl;
    return 0;
}
