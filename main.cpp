

#include <iostream>
#include <vector>

using namespace std;

bool stateMachine(vector<string> sentence) {
    int index = 0;
    string currentWord = sentence[index];

    //State 0
    if(currentWord == "the") {
        //State 1
        index++;
        currentWord = sentence[index];
        while(true) {
            if(currentWord == "lazy" || currentWord == "smelly") {
                index++;
                currentWord = sentence[index];
            }
            else {
                break;
            }
        }
        if(currentWord == "dog" || currentWord == "cat") {
            //State 2
            index++;
            currentWord = sentence[index];
            if(currentWord == "ate" || currentWord == "ran") {
                //State 3
                index++;
                currentWord = sentence[index];
                if(currentWord == "EOI") {
                    //State END
                    return true;
                }
                if(currentWord == "slowly" || currentWord == "noisily") {
                    //State 4
                    index++;
                    currentWord = sentence[index];
                    if(currentWord == "EOI") {
                        //State END
                        return true;
                    }
                }
            }
        }
        
    }
    return false;
}

int main() {
    bool isValid;
    
    //TEST 1
    vector<string> sentence1 = {"the","smelly","cat","ate","noisily","EOI"};
    isValid = stateMachine(sentence1);
    if(isValid)
        cout << "TEST PASSED" << endl;
    else
        cout << "TEST FAILURE" << endl;
    
    //TEST 2
    vector<string> sentence2 = {"the","dog","ate","EOI"};
    isValid = stateMachine(sentence2);
    if(isValid)
        cout << "TEST PASSED" << endl;
    else
        cout << "TEST FAILURE" << endl;
    
    //TEST 3
    vector<string> sentence3 = {"the","smelly", "lazy", "lazy","cat","ate","slowly","EOI"};
    isValid = stateMachine(sentence3);
    if(isValid)
        cout << "TEST PASSED" << endl;
    else
        cout << "TEST FAILURE" << endl;
    
    //TEST 4
    vector<string> sentence4 = {"smelly","cat","ate","noisily","EOI"};
    isValid = stateMachine(sentence4);
    if(!isValid)
        cout << "TEST PASSED" << endl;
    else
        cout << "TEST FAILURE" << endl;
    
    //TEST 5
    vector<string> sentence5 = {"the","ate","noisily","EOI"};
    isValid = stateMachine(sentence5);
    if(!isValid)
        cout << "TEST PASSED" << endl;
    else
        cout << "TEST FAILURE" << endl;
    
    //TEST 6
    vector<string> sentence6 = {"the","cat","slowly","EOI"};
    isValid = stateMachine(sentence6);
    if(!isValid)
        cout << "TEST PASSED" << endl;
    else
        cout << "TEST FAILURE" << endl;
    
    //TEST 7
    vector<string> sentence7 = {"the","smelly","cat","ate","noisily","slowly","EOI"};
    isValid = stateMachine(sentence7);
    if(!isValid)
        cout << "TEST PASSED" << endl;
    else
        cout << "TEST FAILURE" << endl;
    
    return 0;
}
