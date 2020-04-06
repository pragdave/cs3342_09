#include <iostream>
#include <string>
#include <vector>
#include <time.h>
#include <stdlib.h>


 using namespace std;

void generateSetOfNumbers(int arr[], int n)
{
    srand(time(NULL));
    int p[9] = {0,1,2,3,4,5,6,7,8};


    for (int i=8; i>0; --i)
    {

        int j = rand()%i;
        //swap p[i] with p[j]
        int temp = p[i];
        p[i] = p[j];
        p[j] = temp;
    }

    for (int i=0; i<n; ++i)
        arr[i] = p[i];
}

    int main(){
        srand(time(NULL));

        vector <string> realList;
        realList.push_back("the");
        realList.push_back("smelly");
        realList.push_back("lazy");
        realList.push_back("dog");
        realList.push_back("cat");
        realList.push_back("ran");
        realList.push_back("ate");
        realList.push_back("noisily");
        realList.push_back("slowly");
        int realListCount = realList.size();
       // cout << realList[0] << endl;

        int randomNumber =   rand()%(9) ;
        cout << randomNumber <<endl;

       vector <string> wordList;
       int totalNum[randomNumber];

       generateSetOfNumbers(totalNum, randomNumber);
       cout << "Create list" << endl;

       for(int i = 0; i < randomNumber; i++){
           string newString = realList[totalNum[i]];
            wordList.push_back( newString);
            cout << wordList[i] <<endl;
       }


        cout << "In state 0" << endl;
        int vectorNumber = wordList.size();
        int count = 0;


        if(wordList[0] != "the" && count == vectorNumber){
            cout << "false" << endl;
            exit(1);
        }
        else{
            count++;
           cout << "In state 1" << endl;
            if(count == vectorNumber){
                cout << "reach the end of the wordList, not the program" << endl;
                exit(1);

            }
            if(wordList[count]== "smelly" && wordList[count] == "lazy"){
                    count++;
            }
                cout << "In state 2" << endl;
            if(wordList[count] == "dog" && wordList[count] == "cat"){
                cout << "In state 3" << endl;
                if(count == vectorNumber){
                    cout << "reach the end of the wordList, not the program" << endl;
                    exit(1);

                }
                count ++;
                if(wordList[count] == "ran" && wordList[count] == "ate"){
                    cout << "In state 4" << endl;
                    if(count == vectorNumber){
                        cout << "reach the end of the wordList, not the program" << endl;
                        exit(1);

                    }
                    count++;
                    if(wordList[count]== "noisily" && wordList[count] == "slowly"){
                        count++;
                    }
                    cout << "In state 5" << endl;
                    if(wordList[count] == "EOI" || count == vectorNumber){
                        cout << "Finish the process"<< endl;
                        cout << "True" << endl;
                    }
                    else{
                        cout << "false" << endl;
                        cout << "End of program" << endl;
                    }

                }
                else{
                    cout << "false" << endl;
                    exit(1);
                }


            }
            else{
                cout << "false" << endl;
                exit(1);
            }

        }
    };
