#include <iostream>
#include <vector>

using namespace std;

static bool isNoun(string s)
{
    if(s == "dog" || s == "cat")
        return true;
    else
        return false;
}

static bool isVerb(string s)
{
    if(s == "ate" || s == "ran")
        return true;
    else
        return false;
}

static bool isAdjective(string s)
{
    if(s == "lazy" || s == "smelly")
        return true;
    else
        return false;
}

static bool isAdverb(string s)
{
    if(s == "slowly" || s == "noisily")
        return true;
    else
        return false;
}

bool FSM(vector<string> v) {
    int state = 0;
    for(int i = 0; i < v.size(); i++)
    {
        if(state == 0)
        {
            if(v[i] == "the")
                state = 1;
            else
                return false;
        }
        else if(state == 1)
        {
            if(isAdjective(v[i]))
                state = 1;
            else if(isNoun(v[i]))
                state = 2;
            else
                return false;
        }
        else if(state == 2)
        {
            if(isVerb(v[i]))
                state = 3;
            else
                return false;
        }
        else if(state == 3)
        {
            if(isAdverb(v[i]))
                state = 4;
            else if(v[i] == "EOI")
                return true;
            else
                return false;
        }
        else if(state == 4)
        {
            if(v[i] == "EOI")
                return true;
            else
                return false;
        }
        else
            return false;
    }
    return false;
}

int main() {
    //valid
    vector<string> v1 = {"the","smelly","dog","ran","EOI"};
    vector<string> v2 = {"the","smelly","dog","ran","slowly","EOI"};
    vector<string> v3 = {"the","cat","ate","noisily","EOI"};
    //invalid
    vector<string> f0A = {"smelly","dog","ran","EOI"};
    vector<string> f1A = {"the","ran","EOI"};
    vector<string> f1B = {"the","smelly","ran","EOI"};
    vector<string> f1C = {"the","stupid","dog","ran","EOI"};
    vector<string> f2A = {"the","smelly","dog","EOI"};
    vector<string> f5A = {"the","smelly","dog","ran"};

    cout << (FSM(v1) == true) << endl;
    cout << (FSM(v2) == true) << endl;
    cout << (FSM(v3) == true) << endl;

    cout << (FSM(f0A) == false) << endl;
    cout << (FSM(f1A) == false) << endl;
    cout << (FSM(f1B) == false) << endl;
    cout << (FSM(f1C) == false) << endl;
    cout << (FSM(f2A) == false) << endl;
    cout << (FSM(f5A) == false) << endl;

    return 0;
}