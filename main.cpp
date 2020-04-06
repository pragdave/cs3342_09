#include <iostream>
#include <string>
#include <vector>
using namespace std;

//run this by running main, test results will print to terminal

//function to determine if the word is an adjective and in State 1
bool isStateOne(string x){

    bool returnVal = false;

    if(x == "smelly" | x == "lazy")
        returnVal = true;

    return returnVal;

}//end isAdj


//function to determine if the correct transitional word occurs, and we
//can move on to state two
bool moveStateTwo(string x){

    bool returnVal = false;

    if(x == "dog" | x == "cat")
        returnVal = true;

    return returnVal;

}//end isNoun


//function to determine if the correct transitional word occurs, and we
//can move on to state three
bool moveStateThree(string x){

    bool returnVal = false;

    if(x == "ate" | x == "ran")
        returnVal = true;

    return returnVal;

}//end isVerb


//function to determine if the correct transitional word occurs, and we
//can move on to state four
bool moveStateFour(string x){

    bool returnVal = false;

    if(x == "slowly" | x == "noisily" | x == "EOI")
        returnVal = true;

    return returnVal;

}//end isAdverb


//function to determine if the correct transitional word occurs, and we
//can move to END
bool moveEnd(string x){

    bool returnVal = false;

    if(x == "EOI")
        returnVal = true;

    return returnVal;

}//end moveEnd


//function to test if a list of words makes it through the state machine
//return true if it reaches "End", false if it does not
bool stateMachine(vector<string> myVec){

    //variables
    int currState = 0;
    bool returnVal = true;

    //Loop through each word in the list. If the correct transition word is there,
    //move on to the next state. Otherwise, return false
    for(int i = 0; i < myVec.size(); i++){

        switch(currState){
            case 0:
                if(myVec.at(i) == "the")
                    currState++;
                else
                    returnVal = false;
                break;

            case 1:
                if(isStateOne(myVec.at(i)))
                    break;
                if(moveStateTwo(myVec.at(i)))
                    currState++;
                else
                    returnVal = false;
                break;

            case 2:
                if(moveStateThree(myVec.at(i)))
                    currState++;
                else
                    returnVal = false;
                break;

            case 3:
                if(moveStateFour(myVec.at(i)))
                    currState++;
                else
                    returnVal = false;
                break;

            case 4:
                if(moveEnd(myVec.at(i)))
                    break;
                else
                    returnVal = false;
                break;

            default:
                 cout << "no match";

        }//end switch
    }//end for

    return returnVal;

}//end stateMachine


int main() {

    //create list of words to test
    vector<string> test1 = {"the", "lazy", "dog", "ate", "slowly", "EOI"};
    vector<string> test2 = {"the", "smelly", "cat", "ran", "noisily", "EOI"};
    vector<string> test3 = {"the", "cat", "smelly"};
    vector<string> test4 = {"lazy", "the", "EOI"};
    vector<string> test5 = {"EOI", "the", "smelly", "dog", "ran", "slowly"};

    //determine and output the results of testing
    if(stateMachine(test1) == 1)
        cout << "test 1 is true (correct)" << endl;
    else
        cout << "test 1 is false (incorrect)" << endl;

    if(stateMachine(test2) == 1)
        cout << "test 2 is true (correct)" << endl;
    else
        cout << "test 2 is false (incorrect)" << endl;

    if(stateMachine(test3) == 1)
        cout << "test 3 is true (incorrect)" << endl;
    else
        cout << "test 3 is false (correct)" << endl;

    if(stateMachine(test4) == 1)
        cout << "test 4 is true (incorrect)" << endl;
    else
        cout << "test 4 is false (correct)" << endl;

    if(stateMachine(test5) == 1)
        cout << "test 5 is true (incorrect)" << endl;
    else
        cout << "test 5 is false (correct)" << endl;

    return 0;

}//end main
