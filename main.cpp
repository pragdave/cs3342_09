//DYLAN WEEKS, 47343235, CSE 3342, GRAMMAR AND SYNTAX
#include <iostream>
#include <vector>

using namespace std;

//FSM FUNCTION TESTS EACH STATE AKA COUNTER AND EITHER CONTINUES RETURNS TRUE(VALID) OR FALSE(INVALID)
bool fsm(vector<string> sentence)
{
    int counter = 0;
    
    for(int i = 0; i < sentence.size(); i++)
    {
        if(counter == 0)
        {
            if(sentence[i] == "the")
                counter = 1;
            else
            {
                return false;
            }
        }
        else if (counter == 1)
        {
            if(sentence[i] == "lazy" || sentence[i] == "smelly")
            {
                counter = 2;
            }
            else if(sentence[i] == "dog" || sentence[i] == "cat")
            {
                counter = 3;
            }
            else
            {
                return false;
            }
        }
        else if (counter == 2)
        {
            if(sentence[i] == "lazy" || sentence[i] == "smelly")
            {
                counter = 2;
            }
            else
            {
                counter = 3;
            }
        }
        else if (counter == 3)
        {
            if(sentence[i] == "ate" || sentence[i] == "ran")
            {
                counter = 4;
            }
            else
            {
                return false;
            }
        }
        else if (counter == 4)
        {
            if(sentence[i] == "slowly" || sentence[i] == "noisily")
            {
                counter = 5;
            }
            else if(sentence[i] == "EOI")
            {
                return true;
            }
            else
            {
                return false;
            }
        }
        else if (counter == 5)
        {
            if(sentence[i] == "EOI")
            {
                return true;
            }
            else
            {
                return false;
            }
        }
        else
        {
            return false;
        }
    }
    return true;
}


int main(int argc, const char * argv[])
{
    
    //VALID SENTENCES
    vector<vector<string>> s;
    vector<string> s1 = {"the", "lazy", "cat", "ate", "EOI"};
    s.push_back(s1);
    vector<string> s2 = {"the", "smelly", "cat", "ran", "EOI"};
    s.push_back(s2);
    vector<string> s3 = {"the", "dog", "ran", "noisily", "EOI"};
    s.push_back(s3);
    vector<string> s4 = {"the", "lazy", "smelly", "dog", "ran", "slowly", "EOI"};
    s.push_back(s4);
    
    
    //INVALID SENTENCES
    vector<string> s5 = {"smelly", "lazy", "cat", "ate", "EOI"};
    s.push_back(s5);
    vector<string> s6 = {"the", "lazy", "ate", "EOI"};
    s.push_back(s6);
    vector<string> s7 = {"the", "lazy", "cat", "EOI"};
    s.push_back(s7);
    vector<string> s8 = {"the", "lazy", "smelly", "dog", "ran", "smelly", "EOI"};
    s.push_back(s8);
    
    //LOOP THAT CHECKS AND PRINTS THE VALIDITY OF STATES AND DIFFERENT SENTENCES
    for(int i = 0; i<s.size(); i++)
    {
        int valid;
        valid = fsm(s[i]);
        if(valid == 1)
        {
            cout << "Valid Sentence" << endl;
        }
        else
        {
            cout << "Invalid Sentence" << endl;
        }
    }
    
    return 0;
    
}
