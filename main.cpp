#include <string>
#include <iostream>
#include <utility>
#include <map>
#include <vector>

using namespace std;

typedef int curr;
typedef int nextState;

typedef pair<string, int> word;
typedef word state [];
typedef map<int, state> grammer;

state zero = {{"the", 1}};
state one = {{"lazy", 2}, {"lazy", 1}, {"smelly", 2}, {"smelly", 2}, {"", 2}};
state two = {{"cat", 3}, {"dog", 3}};
state three = {{"ran", 4}, {"ate", 4}};
state four = {{"slowly", 5}, {"noisily", 5}, {"", 5}};

grammer g = {{0, zero}, {1, one}, {2, two}, {3, three}, {4, four}};

int main(){
    for(int i = 0; i < g.size(), i++){
        for(int j = 0; j < sizeof(g[i]); j++){
            if(g[i][j].second > g.size()){
                //if next state value does not exist return false
                return false;
            }
        }
        if(i == g.size()-1 && g[i][j].second != g.size){
            //if loop is at last state and next state is not "end" return false
            return false;
        }
    }
    return true;

}


