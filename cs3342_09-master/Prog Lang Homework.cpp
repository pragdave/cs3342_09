#include <iostream>
#include <map>
using namespace std;

 
typedef int state;

typedef
  std::map <
  std::string,
  state >
  transitions;

typedef
  std::map <
  state,
  transitions >
  stateTable;

 
const int
  END = 99;

 
stateTable states =
{
  
  {
    0,
    {
      {
  "the", 1}}}, 
  {
    1,
    {
      {
      "lazy", 2},
      {
      "smelly", 2},
      {
      "dog", 3},
      {
  "cat", 3}}}, 
  {
    2,
    {
      {
      "lazy", 2},
      {
      "smelly", 2},
      {
      "dog", 3},
      {
  "cat", 3}}}, 
  {
    3,
    {
      {
      "ate", 4},
      {
  "ran", 4}}}, 
  {
    4,
    {
      {
      "slowly", 5},
      {
      "noisily", 5},
      {
  "EOI", END}}}, 
  {
    5,
    {
      {
"EOI", END}}} 
};


 
int
nextState (int curState, string nextword) 
{
  
transitions t = states[curState];
  
if (t.count (nextword))
    
return t[nextword];
  
  else
    
return -1;

}


int
main (int argc, char *argv[]) 
{
  
int
    curState = 0;
  
string sentence1[5] =
  {
  "the", "lazy", "dog", "ran", "EOI"};
  
while (curState != END)
    
    {
      
curState = nextState (curState, sentence1[curState]);
    
 
}
  
 
 
if (curState == 99)
    
cout << "(the lazy dog ran)passed" << endl;
  
  else
    
cout << "(the lazy dog ran)failed" << endl;
  
curState = 0;
  
 
 
 
string sentence2[6] =
  {
  "the", "smelly", "dog", "ran", "slowly", "EOI"};
  
while (curState != END)
    
    {
      
curState = nextState (curState, sentence2[curState]);
    
}
  
 
 
if (curState == 99)
    
cout << "(the smelly dog ran slowly)passed" << endl;
  
  else
    
cout << "(the lazy dog ran)failed" << endl;
  
curState = 0;
  
 
 
string sentence3[6] =
  {
  "the", "stupid", "dog", "ran", "slowly", "EOI"};
  
while (curState != END)
    
    {
      
curState = nextState (curState, sentence3[curState]);
      
if (curState == -1)
	
break;
    
}
  
 
 
if (curState == 99)
    
cout << "(the stupid dog ran slowly)passed" << endl;
  
  else
    
cout << "(the stupid dog ran slowly)failed" << endl;
  
curState = 0;
  
 
string sentence4[6] =
  {
  "the", "dog", "ran", "noisily", "slowly", "EOI"};
  
while (curState != END)
    
    {
      
curState = nextState (curState, sentence4[curState]);
      
if (curState == -1)
	
break;
    
}
  
 
 
if (curState == 99)
    
cout << "(the dog ran noisily slowly)passed" << endl;
  
  else
    
cout << "(the dog ran noisily slowly)failed" << endl;
  
curState = 0;
  
int
    counter = 0;
  
string sentence5[6] =
  {
  "the", "lazy", "smelly", "dog", "ran", "EOI"};
  
while (curState != END)
    
    {
      
curState = nextState (curState, sentence5[curState]);
      
counter++;
      
if (curState == -1 || counter >= 150)
	
break;
    
}
  
 
 
if (curState == 99)
    
cout << "(the lazy smelly dog ran)passed" << endl;
  
  else
    
cout << "(the lazy smelly dog ran)failed" << endl;
  
if (counter >= 150)
    
cout << "(the lazy smelly dog ran)failed[runs forever]" << endl;
  
curState = 0;

 
}
