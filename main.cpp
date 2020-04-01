#include <iostream>
#include <fstream>
#include <vector>

class Sentence{
public:
    std::ifstream inFile;

    void get_file(std:: string fileName){
        inFile.open(fileName);
        if(inFile.is_open()){
            while(!inFile.eof()) {
                bool valid = 0;
                std::string word;
               std::vector <std::string> sent;

                inFile >> word;
                //seeing if first word is "The"
                if (s0(word)) {
                    sent.push_back(word);
                    inFile >> word;

                    //seeing if the next word is either "dog" or "cat"
                    if(s1(word)){
                        sent.push_back(word);
                        inFile >> word;

                        //seeing if the next word is "ate" or "ran"
                        if(s3(word)){
                            sent.push_back(word);
                            inFile >> word;

                            //seeing if the next word is "."
                            if(s4(word)){
                                sent.push_back(word);
                                valid=1;
                            }
                                //seeing if the next word is "noisily" or "slowly"
                            else if(s5(word)){
                                sent.push_back(word);
                                inFile >> word;

                                //seeing if the next word is "."
                                if(s4(word)){
                                    sent.push_back(word);
                                    valid=1;
                                }
                            }
                        }
                    }

                    //if not "dog" or "cat", see if it is either "smelly" or "lazy"
                    else if(s2(word)){
                        sent.push_back(word);
                        inFile >> word;
                        //seeing if the next word is either "dog" or "cat"
                        if(s1(word)){
                            sent.push_back(word);
                            inFile >> word;
                            //seeing if the next word is "ate" or "ran"
                            if(s3(word)){
                                sent.push_back(word);
                                inFile >> word;
                                //seeing if the next word is "."
                                if(s4(word)){
                                    sent.push_back(word);
                                    valid=1;
                                }
                                //seeing if the next word is "noisily" or "slowly"
                                else if(s5(word)){
                                    sent.push_back(word);
                                    inFile >> word;
                                    //seeing if the next word is "."
                                    if(s4(word)){
                                        sent.push_back(word);
                                        valid=1;
                                    }
                                }
                            }
                        }
                    }
                }
            if(valid==1){
                std::cout<< "This is a valid sentence: ";
                for(int i=0;i <sent.size();i++){
                    std::cout<<sent.at(i)<<" ";
                }
                std::cout<<std::endl;
            }
            else{
                std::string garbage;
                std::cout<<"False"<<std::endl;
                std::getline(inFile,garbage);
            }
            }
        }
        else{
            std::cout<< "File could not be opened";
        }
    }

    bool s0(std::string word){
        if(word.compare("The")==0){
            return 1;

        }
        else{
            return 0;
        }
    }

    bool s1(std::string word){
        if(word.compare("dog")==0||word.compare("cat")==0){
            return 1;
        }
        else{
            return 0;
        }
    }

    bool s2(std::string word){
        if(word.compare("smelly")==0||word.compare("lazy")==0){
            return 1;
        }
        else{
            return 0;
        }
    }
    bool s3(std::string word){
        if(word.compare("ate")==0||word.compare("ran")==0){
            return 1;
        }
        else{
            return 0;
        }
    }
    bool s4(std::string word){
        if(word.compare(".")==0){
            return 1;
        }
        else{
            return 0;
        }
    }

    bool s5(std::string word){
        if(word.compare("slowly")==0||word.compare("noisily")==0){
            return 1;
        }
        else{
            return 0;
        }
    }


};

int main(int argc, char *argv[]) {
    std::cout << "Hello, World!" << std::endl;
    std::string filename;
    Sentence s;
    filename=argv[1];
    std::cout<<filename<<std::endl; 
    s.get_file(filename);

    return 0;
}