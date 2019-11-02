/*
Please include a text file that has one sentence per line.
Input the number of lines you want to test and this program will return whether or not those lines are valid within the grammar
*/
#include <iostream>

#include <string>

#include <fstream>

#include <istream>

#include <map>

using namespace std;

bool article(string theArticle) {
  map < string, bool > article;
  article.insert(std::pair < string, bool > ("The", true));
  if (article[theArticle]) {
    return true;
  } else {
    return false;
  }
}

 string nextWord(string temp) {      
      string word = "";
      int i = 0;
      while (i < temp.length() && (temp[i] != ' ')) {
        word += temp[i];
        i++;
      }
      return word;
    }

string checker(string temp) {
    map < string, bool > article;
    article.insert(std::pair < string, bool > ("The", true));
    map < string, bool > adjs;
    adjs.insert(std::pair < string, bool > ("lazy", true));
    adjs.insert(std::pair < string, bool > ("smelly", true));
    map < string, bool > nouns;
    nouns.insert(std::pair < string, bool > ("dog", true));
    nouns.insert(std::pair < string, bool > ("cat", true));
    map < string, bool > verbs;
    verbs.insert(std::pair < string, bool > ("ate", true));
    verbs.insert(std::pair < string, bool > ("ran", true));
    map < string, bool > adverbs;
    adverbs.insert(std::pair < string, bool > ("slowly", true));
    adverbs.insert(std::pair < string, bool > ("noisily", true));
    map < string, bool > period;
    period.insert(std::pair < string, bool > (".", true));
    map < string, bool > eoi;
    eoi.insert(std::pair < string, bool > ("EOI", true));
    bool keepGoing = true;
    string word = "";
    
    word = nextWord(temp);
    temp = temp.substr(word.length());
    if(temp[0] == ' ')
      {
        temp = temp.substr(1);
      } 
    if(!(article[word]))
    {
      return "Article Invalid Sentence";
    }
    word = nextWord(temp);
    temp = temp.substr(word.length());
    if(temp[0] == ' ')
      {
        temp = temp.substr(1);
      } 
    while(adjs[word])
    {

    word = nextWord(temp);
    temp = temp.substr(word.length());
    if(temp[0] == ' ')
      {
        temp = temp.substr(1);
      } 
    }

    

    if(!(nouns[word]))
    {
      return "Noun Invalid Sentence";
    }
    word = nextWord(temp);
    temp = temp.substr(word.length());
    if(temp[0] == ' ')
      {
        temp = temp.substr(1);
      } 
    if(!(verbs[word]))
    {
      return "Verbs Invalid Sentence";
    }
    word = nextWord(temp);
    temp = temp.substr(word.length());
    if(temp[0] == ' ')
      {
        temp = temp.substr(1);
      } 
    if((adverbs[word]))
    {
      word = nextWord(temp);
      temp = temp.substr(word.length());
    }

    
    if(temp[0] == ' ')
      {
        temp = temp.substr(1);
      } 
    if(!(period[word]))
    {
      return "Period Invalid Sentence";
    }
    word = nextWord(temp);
    temp = temp.substr(word.length());
  
    if(!(eoi[word]))
    {
      return "EOI Invalid Sentence";
    }

      
    return "Valid Sentence";
    
}

    int main() {

      ifstream inFile("examples.txt");
      string sentence = "";
      string temp = "1";

    cout << "Please enter how many lines you are testing: ";
    int testing;
    cin >> testing;
      for(int i = 0; i < testing; i++)
      {
      getline(inFile, temp);
      cout << checker(temp) << endl;  
      }
    }