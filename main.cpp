#include <iostream>
#include <string>
#include <vector>
using namespace std;

void printSentence(vector<string> & vec){
    for(int i = 0; i < vec.size() - 1 ; i++)
    {
        cout << vec[i] << " ";
    }
    cout << vec[vec.size()-1];
}

bool progSentChecker(vector<string>& wordsToBeChecked){
    int index = 0;
    if(wordsToBeChecked[index] != "the" && wordsToBeChecked[index] != "The"){
        cout << "ERROR 1! The sentence '";
        printSentence(wordsToBeChecked);
        cout << "' doesn't fulfill sentence requirements" << endl;
        return false;
    }

    index++;
    if(wordsToBeChecked[index] != "lazy" && wordsToBeChecked[index] != "smelly")
    {
        if(wordsToBeChecked[index] != "dog" && wordsToBeChecked[index] != "cat")
        {
            cout << "ERROR 2! The sentence '";
            printSentence(wordsToBeChecked);
            cout << "' doesn't fulfill sentence requirements" << endl;
            return false;
        }
    } else {
        index++;
        while(wordsToBeChecked[index] == "lazy" || wordsToBeChecked[index] == "smelly"){
            index++;
        }
    }

    if(wordsToBeChecked[index] != "dog" && wordsToBeChecked[index] != "cat")
    {
        cout << "ERROR 4! The sentence '";
        printSentence(wordsToBeChecked);
        cout << "' doesn't fulfill sentence requirements" << endl;
        return false;
    }

    index++;
    if(wordsToBeChecked[index] != "ran" && wordsToBeChecked[index] != "ate")
    {
        cout << "ERROR 5! The sentence '";
        printSentence(wordsToBeChecked);
        cout << "' doesn't fulfill sentence requirements" << endl;
        return false;
    }

    index++;
    if(index >= wordsToBeChecked.size()) {
        cout << "ERROR 6! The sentence '";
        printSentence(wordsToBeChecked);
        cout << "' doesn't fulfill sentence requirements" << endl;
        return false;
    }

    if(wordsToBeChecked[index] != "slowly" && wordsToBeChecked[index] != "noisily")
    {
        if(wordsToBeChecked[index] != "EOI"){
            cout << "ERROR 7! The sentence '";
            printSentence(wordsToBeChecked);
            cout << "' doesn't fulfill sentence requirements" << endl;
            return false;
        }
    } else {
        index++;
        if(wordsToBeChecked[index] != "EOI"){
            cout << "ERROR 8! The sentence '";
            printSentence(wordsToBeChecked);
            cout << "' doesn't fulfill sentence requirements" << endl;
            return false;
        }
    }

    cout << "CHECK COMPLETE! The sentence '";
    printSentence(wordsToBeChecked);
    cout << "' fulfills sentence requirements" << endl;

    return true;
}

int main() {
    vector<string> v1 = {"The", "lazy", "dog", "ate", "slowly", "EOI"};
    progSentChecker(v1);
    vector<string> v2 = {"lazy", "dog", "ate", "slowly", "EOI"};
    progSentChecker(v2);
    vector<string> v3 = {"The", "dog", "ate", "slowly", "EOI"};
    progSentChecker(v3);
    vector<string> v4 = {"The", "lazy", "lazy", "lazy", "lazy", "lazy", "dog", "ate", "slowly", "EOI"};
    progSentChecker(v4);
    vector<string> v5 = {"The", "cat", "ate", "slowly", "EOI"};
    progSentChecker(v5);
    vector<string> v6 = {"The", "cat", "ran", "noisily", "EOI"};
    progSentChecker(v6);
    vector<string> v7 = {"The", "cat", "ran", "EOI"};
    progSentChecker(v7);
    vector<string> v8 = {"The", "cat", "ate", "EOI"};
    progSentChecker(v8);
    vector<string> v9 = {"The", "cat", "ate"};
    progSentChecker(v9);
    vector<string> v10 = {"The", "lazy", "lazy", "lazy", "lazy", "lazy", "smelly", "smelly", "smelly", "dog", "ate", "slowly", "EOI"};
    progSentChecker(v10);
    vector<string> v11 = {"The", "smelly", "cat", "ate", "EOI"};
    progSentChecker(v11);
    vector<string> v12 = {"The", "smelly", "cat", "EOI"};
    progSentChecker(v12);



    return 0;
}
