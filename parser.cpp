#include "parser.h"

using namespace std;

parser::parser(){};

bool parser::nounCheck(string x){
    if(x == "dog"){
        return true;
    }
    else if( x == "cat"){
        return true;
    }
    else{
        return false;
    }
};

bool parser::verbCheck(string x){
    if(x == "ate"){
        return true;
    }
    else if( x == "ran"){
        return true;
    }
    else{
        return false;
    }
};

bool parser::adjCheck(string x){
    if(x == "lazy"){
        return true;
    }
    else if( x == "smelly"){
        return true;
    }
    else{
        return false;
    }
};

bool parser::advCheck(string x){
    if(x == "slowly"){
        return true;
    }
    else if( x == "noisily"){
        return true;
    }
    else{
        return false;
    }
};

bool parser::FSManalyze(vector<string> vec){
    int state = 0;

    for(int i = 0; i < vec.size(); i++){
        switch(state){
            case 0:
                if(vec.at(i) == "the"){
                    state++;
                    break;
                }
                else{
                    return false;
                }

            case 1:
                //can assume that if adj state will remain the same
                if(adjCheck(vec.at(i))){
                    break;
                }
                else if(nounCheck(vec.at(i))){
                    state++;
                    break;
                }
                else{
                    return false;
                }

            case 2:
                if(verbCheck(vec.at(i))){
                    state++;
                    break;
                }
                        else{
                    return false;
                }

            case 3:
                if(advCheck(vec.at(i))){
                    state++;
                    break;
                }
                        else if(vec.at(i) == "EOI"){
                    return true;
                }
                else{
                    return false;
                }

            case 4:
                if(vec.at(i) == "EOI"){
                    return true;
                }
                else{
                    return false;
                }

        }
    }
    return false;
};
