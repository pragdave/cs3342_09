#include <iostream>
#include <fstream>
int main(int argc, char *argv[]) {
    std::ifstream inFile;
    std::string filename=argv[1];
    inFile.open(filename);
    int currentState=0;
    bool correct=0;
        if(inFile.is_open()){
            std::string word;
            inFile>>word;
            while(inFile.good()) {
                switch(currentState){
                    case 0:
                        if(word.compare("The")==0){
                            currentState=1;
                            inFile>>word;
                        }
                    case 1:
                        if(word.compare("dog")==0||word.compare("cat")==0){
                            currentState=2;
                            inFile>>word;
                        }
                        else if(word.compare("smelly")==0||word.compare("lazy")==0){
                            currentState=1;
                            inFile>>word;
                            continue;
                        }
                    case 2:
                        if(word.compare("ate")==0||word.compare("ran")==0){
                            currentState=3;
                            inFile>>word;
                        }
                    case 3:
                        if(word.compare("slowly")==0||word.compare("noisily")==0){
                            currentState=4;
                            inFile>>word;
                        }
                        else if(word.compare(".")==0){
                            correct=1;
                            currentState=0;
                            break;
                        }
                    case 4:
                        if(word.compare(".")==0){
                            currentState=0;
                            correct=1;
                            break;
                        }
                }//end of switch statement
                if(correct){std::cout<<"Valid sentence"<<std::endl;
                correct=0;
                    inFile>>word;
                }
                else{std::cout<<"Invalid sentence"<<std::endl;
                currentState=0;
                getline(inFile,word);
                getline(inFile,word,' ');
                }//end of else statement
                }//end of file
            if(correct){std::cout<<"Valid sentence"<<std::endl;}
            else{std::cout<<"Invalid sentence"<<std::endl;}
            }//end of is_open
    return 0;
}//end of main