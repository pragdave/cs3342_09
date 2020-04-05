#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Word {
public:
    string getWord(){return word;}
    int getType(){return type;}
    void setWord(string w){word = w;}
    void setType(int t){type = t;}
    Word(string w, int t){word = w;
                          type = t; }

private:
    string word;
    int type;       //1 = the, 2 = adj, 3 = noun, 4 = verb, 5 = adverb, 6 = eoi

};

bool isSentence(vector<Word>* v){
    //start at 0
    if((*v)[0].getType() != 1){
        cout << "is not a sentence" << endl;
        return false;
    } else {
        //if the first word is the, check for adj or noun
        if((*v)[1].getType() != 2 && (*v)[1].getType() != 3){
            cout << "is not a sentence" << endl;
            return false;
        } else {
            int index = 2;
            if((*v)[1].getType() == 2){
                while((*v)[index].getType() == 2){
                    index++;
                }
                if((*v)[index].getType() != 3){
                    cout << "is not a sentence" << endl;
                    return false;
                } else if ((*v)[index].getType() == 3){
                    index++;
                    if((*v)[index].getType() != 4){
                        cout << "is not a sentence" << endl;
                        return false;
                    } else {
                        index++;
                        if((*v)[index].getType() != 5 && (*v)[index].getType() != 6){
                            cout << "is not a sentence" << endl;
                            return false;
                        } else if ((*v)[index].getType() == 6){
                            cout << "is a sentence" << endl;
                            return true;
                        }

                        index++;
                        if((*v)[index].getType() != 6){
                            cout << "is not a sentence" << endl;
                            return false;
                        }else {
                            cout << "is a sentence" << endl;
                            return true;
                        }
                    }
                }

            }
        }
    }
}

int main() {
    //normal sentence
    vector<Word> *v = new vector<Word>;
    Word the = Word("the", 1);              //create the word objects
    Word angry = Word("angry", 2);
    Word bug = Word("bug", 3);
    Word flew = Word("flew", 4);
    Word away = Word("away", 5);
    Word eoi = Word("eoi", 6);

    v->push_back(the);                       //build vector with them
    v->push_back(angry);
    v->push_back(bug);
    v->push_back(flew);
    v->push_back(away);
    v->push_back(eoi);

    cout << "normal sentence ";
   bool b = isSentence(v);

   //test 1 - multiple adjectives
   vector<Word> *c = new vector<Word>;
   Word t = Word("the", 1);              //create the word objects
   Word a = Word("angry", 2);
   Word a2 = Word("angry", 2);
   Word bu = Word("bug", 3);
   Word f = Word("flew", 4);
   Word aw = Word("away", 5);
   Word e = Word("eoi", 6);

   c->push_back(t);                       //build vector with them
   c->push_back(a);
   c->push_back(a2);
   c->push_back(bu);
   c->push_back(f);
   c->push_back(aw);
   c->push_back(e);

   cout << "test 1 ";
  b = isSentence(c);

  //test 2 - no adj, no adverb
  vector<Word> *d = new vector<Word>;
  Word t2 = Word("the", 1);
  Word b2 = Word("bug", 3);
  Word f2 = Word("flew", 4);
  Word e2 = Word("eoi", 6);

  d->push_back(t2);                       //build vector with them
  d->push_back(b2);
  d->push_back(f2);
  d->push_back(e2);

  cout << "test 2 ";
 b = isSentence(d);


    return 0;
}
