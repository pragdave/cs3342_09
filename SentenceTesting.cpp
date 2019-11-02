//Xiyuan Cui; Grammar HW code of laguage

//This code won't consider the conditian of repeati using adjectives, which could be reached in the table and diagram
//but not allowed in the senirios in questions

#include <iostream>
#include <string>
#include <vector>


using namespace std;


int main(){
    string sentence1[6] = {"The","smelly","dog","ran","slowly","EOI"};
    string sentence2[2] = {"dog","EOI"};
    string sentence3[4] = {"The","cat","ran","EOI"};
    string sentence4[6] = {"The", "lazy","cat","ate","noisily","EOI"};

        tester(sentence1,6);

        tester(sentence2,2);

        tester(sentence3,4);

        tester(sentence4,6);
 
    return 0;
}



void tester(string input[],int size){

    int condition = 0;
    int counter = 0;

    while(counter<size){
        eachWord(input[counter],condition);
        counter ++;
    }

    if(condition == -1)
        cout<<"It is not a valid sentence.";
    else if (condition == 5)
        cout<<"This sentence makes sense.";

}

int eachWord(string word,int condition){
    switch (condition)
    {
        case 0:{
            if(word == "The" || word == "the")
                return 1;
            else
                return -1;
        }//end case 0, for word whose current state is 0

        case 1:{
            if(word == "smelly" || word == "lazy")
                return 1;
            else if(word == "dog" || word == "cat")
                return 2;
            else
                return -1;        
        }//end case 1, for word whose current state is 1
    
        case 2:{
            if(word == "ate" || word == "ran")
                return 3;
            else
                return -1;        
        }//end case2, for word whose current state is 2

        case 3:{
            if(word == "slowly" || word == "noisily")
                return 4;
            else if(word == "EOI")
                return 5;
            else
                return -1;        
        }//end case3, for word whose current state is 3

        case 4:{
            if(word == "EOI")
                return 5;
            else 
                return -1;
        }
    }//end switch
}