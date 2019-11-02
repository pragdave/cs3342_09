#include <iostream>
#include <sstream>




using namespace std;


int Analyze(string newString, int state){
    switch (state)
    {
    case 0:{
        if (newString == "the"){return 1;}
        else if (newString == "The"){return 1;}
        else{return -1;}
        break;
    }
    case 1:{
        if (newString == "lazy"){return 1;}
        else if (newString == "smelly"){return 1;}
        else if (newString == "dog"){return 2;}
        else if (newString == "cat"){return 2;}
        else{return -1;}
        break;
    }
    case 2:{
        if (newString == "ate"){return 3;}
        else if (newString == "ran"){return 3;}
        else{return -1;}
        break;
    }
    case 3:{
        if (newString == "slowly"){return 4;}
        else if (newString == "noisily"){return 4;}
        else if (newString == "EOI."){return 5;}
        else{return -1;}
        break;
    }
    case 4:{
        if (newString == "EOI."){return 5;}
        else{return -1;}
        break;
    }
    case -1:{
        return -1;
    }    
    default:
        return -1;
        break;
    }
}


int main(){
    string inputCommand = "";
    while(inputCommand != "q"){
        cout << "Enter a command or enter \"q\" to exit: ";
        getline(cin,inputCommand);

        int state = 0;
        string token;
        istringstream iss(inputCommand);

        while(getline(iss, token, ' ')){
            state = Analyze(token, state);
        }
        if (state == 5 && inputCommand != "q"){
            cout << "It is a valid input "<< endl;
        }
        else if (inputCommand != "q"){
            cout << "It is an invalid input "<< endl;
        }
    }


}


