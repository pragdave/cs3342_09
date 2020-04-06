#include <iostream>
#include <string>
#include <vector>
using namespace std;

void print(vector<string> & sent){
    for(int i = 0; i < sent.size() - 1 ; i++)
    {
        cout << sent[i] << " ";
    }
    cout << sent[sent.size()-1];
}

bool check(vector<string>& wordChecks){
    int index = 0;
    if(wordChecks[index] != "the" && wordChecks[index] != "The"){
        cout << "ERROR 1! The sentence '";
        print(wordChecks);
        cout << "' does not meet requirements" << endl;
        return false;
    }

    index++;
    if(wordChecks[index] != "lazy" && wordChecks[index] != "smelly")
    {
        if(wordChecks[index] != "dog" && wordChecks[index] != "cat")
        {
            cout << "ERROR 2! The sentence '";
            print(wordChecks);
            cout << "' does not meet requirements" << endl;
            return false;
        }
    } else {
        index++;
        while(wordChecks[index] == "lazy" || wordChecks[index] == "smelly"){
            index++;
        }
    }

    if(wordChecks[index] != "dog" && wordChecks[index] != "cat")
    {
        cout << "ERROR 4! The sentence '";
        print(wordChecks);
        cout << "' does not meet requirements" << endl;
        return false;
    }

    index++;
    if(wordChecks[index] != "ran" && wordChecks[index] != "ate")
    {
        cout << "ERROR 5! The sentence '";
        print(wordChecks);
        cout << "' does not meet requirements" << endl;
        return false;
    }

    index++;
    if(index >= wordChecks.size()) {
        cout << "ERROR 6! The sentence '";
        print(wordChecks);
        cout << "' does not meet requirements" << endl;
        return false;
    }

    if(wordChecks[index] != "slowly" && wordChecks[index] != "noisily")
    {
        if(wordChecks[index] != "EOI"){
            cout << "ERROR 7! The sentence '";
            print(wordChecks);
            cout << "' does not meet requirements" << endl;
            return false;
        }
    } else {
        index++;
        if(wordChecks[index] != "EOI"){
            cout << "ERROR 8! The sentence '";
            print(wordChecks);
            cout << "' does not meet requirements" << endl;
            return false;
        }
    }

    cout << "CHECK COMPLETE! The sentence '";
    print(wordChecks);
    cout << "' fulfills sentence requirements" << endl;

    return true;
}

int main() {
    vector<string> v1 = {"The", "lazy", "dog", "ate", "slowly", "EOI"};
    check(v1);
    vector<string> v2 = {"lazy", "dog", "ate", "slowly", "EOI"};
    check(v2);
    vector<string> v3 = {"The", "dog", "ate", "slowly", "EOI"};
    check(v3);
    vector<string> v4 = {"The", "lazy", "lazy", "lazy", "lazy", "lazy", "dog", "ate", "slowly", "EOI"};
    check(v4);
    vector<string> v5 = {"The", "cat", "ate", "slowly", "EOI"};
    check(v5);
    vector<string> v6 = {"The", "cat", "ran", "noisily", "EOI"};
    check(v6);
    vector<string> v7 = {"The", "cat", "ran", "EOI"};
    check(v7);
    vector<string> v8 = {"The", "cat", "ate", "EOI"};
    check(v8);
    vector<string> v9 = {"The", "cat", "ate"};
    check(v9);
    vector<string> v10 = {"The", "lazy", "lazy", "lazy", "lazy", "lazy", "smelly", "smelly", "smelly", "dog", "ate", "slowly", "EOI"};
    check(v10);
    vector<string> v11 = {"The", "smelly", "cat", "ate", "EOI"};
    check(v11);
    vector<string> v12 = {"The", "smelly", "cat", "EOI"};
    check(v12);

    return 0;
}