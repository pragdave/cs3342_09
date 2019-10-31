#include <iostream>
#include <vector>

using namespace std;

class Example {
public:
    bool isAdj(string strToCheck);
    bool isAdv(string strToCheck);
    bool isNoun(string strToCheck);
    bool isVerb(string strToCheck);
    bool isValidSentence(vector<string> listOfWords);
};

int main()
{
    Example ex;
    vector<bool> testResults;

    vector<string> vec1{"the","cat","ate","slowly","EOI"}; //valid
    vector<string> vec2{"cat","ate","slowly","EOI"}; //not valid, missing "the" at begin
    vector<string> vec3{"the","lazy","smelly","dog","ran","slowly","EOI"}; //valid
    vector<string> vec4{"the","cat","ate","slowly"}; //not valid, missing EOI
    vector<string> vec5{"the","ate","slowly", "EOI"}; //not valid, missing noun
    vector<string> vec6{"the","lazy","smelly","dog","slowly","EOI"}; //not valid, missing verb

    testResults.push_back(ex.isValidSentence(vec1));
    testResults.push_back(ex.isValidSentence(vec2));
    testResults.push_back(ex.isValidSentence(vec3));
    testResults.push_back(ex.isValidSentence(vec4));
    testResults.push_back(ex.isValidSentence(vec5));
    testResults.push_back(ex.isValidSentence(vec6));

    string properoutput = "101000";
    string testoutput;


    cout << "remember, true = 1 and false = 0" << endl;
    cout << "The proper string should be 1010000" << endl;
    for (unsigned int i = 0; i < testResults.size(); i++) {
        cout << "Result of Test " << i+1 << endl;
        cout << (bool)testResults[i] << endl << endl;
        testoutput = testoutput + to_string(testResults[i]);
    }

    if (properoutput.compare(testoutput) == 0) cout << "All Tests Passed!" << endl;
}

bool Example::isValidSentence(vector<string> listOfWords) {
    string state;
    string s2loop = "S2";
    string s5loop = "S5";
    string end = "EOI";
    if (listOfWords[0] != "the") {return false;} //otherwise we're in S1 successfully
    //state = "S1";
    unsigned int pos = 1;

    //check here to see if we got to the end prematurely
    if (pos == listOfWords.size()) return false;

    string nextword = listOfWords[pos];
    //need to check if the next word is an adjective, or if its a noun --> S2 or S3
    if (this->isAdj(nextword)) state = "S2";
    else if (this->isNoun(nextword)) state = "S3";
    pos++;

    //check here to see if we got to the end prematurely
    if (pos == listOfWords.size()) return false;

    nextword = listOfWords[pos];
    //need to continually check for this condition
    while (state.compare(s2loop) == 0) {
        if (this->isAdj(nextword)) pos++; // S2 --> adj --> S2
        else if (this->isNoun(nextword))  {
            state = "S3"; // S2 --> noun --> S3
            pos++;
        }
        else return false; //found an illogical end state
        nextword = listOfWords[pos];
    }
    //check if the next word is verb (if not, return false)
    if (!(this->isVerb(nextword))) return false; //S3 --> S4
    state = "S4";
    pos++;

    //check here to see if we got to the end prematurely
    if (pos == listOfWords.size()) return false;

    nextword = listOfWords[pos];
    //check if the next word is either EOI (return true) or an adverb
    if (nextword.compare(end) == 0) return true;
    else if (this->isAdv(nextword)) state = "S5";
    pos++;
    //check here to see if we got to the end prematurely
    if (pos == listOfWords.size()) return false;
    nextword = listOfWords[pos];
    if (nextword.compare(end) != 0) return false;
}

bool Example::isAdj(string strToCheck) {
    string adj1 = "smelly";
    string adj2 = "lazy";

    if ((adj1.compare(strToCheck) == 0) || (adj2.compare(strToCheck) == 0)) {
        return true;
    }
    else return false;
}

bool Example::isNoun(string strToCheck) {
    string noun1 = "cat";
    string noun2 = "dog";

    if ((noun1.compare(strToCheck) == 0) || (noun2.compare(strToCheck) == 0)) {
        return true;
    }
    else return false;

}
bool Example::isVerb(string strToCheck) {
    string verb1 = "ran";
    string verb2 = "ate";

    if ((verb1.compare(strToCheck) == 0) || (verb2.compare(strToCheck) == 0)) {
        return true;
    }
    else return false;
}

bool Example::isAdv(string strToCheck) {
    string adv1 = "slowly";
    string adv2 = "noisily";

    if ((adv1.compare(strToCheck) == 0) || (adv2.compare(strToCheck) == 0)) {
        return true;
    }
    else return false;
}
