#include <iostream>
#include <string>
#include <vector>
using namespace std;

bool stateOneCheck(string g)
{
  //will check if word is an adjective
  
  bool returnValue = false;
  if (g == "smelly" | g == "lazy")
    returnValue = true;
  
  return returnValue;
}

bool changeToStateTwo(string g)
{
  //will check if transitional word is right and changes to state 2
  
  bool returnValue = false;
  if(g == "dog" | g == "cat")
    returnValue = true;
    
  return returnValue;
}

bool changeToStateThree(string g)
{
  //checks if transitional word is right and changes to state 3
  
  bool returnValue = false;
  if(g == "ran" | g == "ate")
    returnValue = true;
    
  return returnValue;
}

bool changeToStateFour(string g)
{
  //checks if transitional word is right and changes to the end
  
  bool returnValue = false;
  if(g == "slowly" | g == "noisily" | g == "EOI")
    returnValue = true;
    
  return returnValue;
}

bool changeToEnd(string g)
{
  //checks if transitional word is right and changes to the end
  
  bool returnValue = false;
  if(g == "EOI")
    returnValue = true;
    
  return returnValue;
}


bool stateMachine(vector<string> g)
{
  //checks if list of words makes it through state machine and returns true when hits end
  
  int curr = 0;
  bool returnValue = true;
  
  for(int i = 0; i < g.size();i++)
  {
    switch(curr)
    {
      case 0:
        if(g.at(i) == "the")
          curr++;
        else
          returnValue = false;
        break;
      case 1:
        if(stateOneCheck(g.at(i)))
          break;
        else if(changeToStateTwo(g.at(i)))
          curr++;
        else
          returnValue = false;
        break;
       case 2:
        if(changeToStateThree(g.at(i)))
          curr++;
        else
          returnValue = false;
        break;
       case 3:
        if(changeToStateFour(g.at(i)))
          curr++;
        else
          returnValue = false;
        break;
      case 4:
        if(changeToEnd(g.at(i)))
          curr++;
        else
          returnValue = false;
        break;
      default:
        cout << "no words that match";
    }
  }
  return returnValue;
}

int main()
{
  vector<string> check1 = {"the", "smelly", "dog", "ate", "noisily", "EOI"};
  vector<string> check2 = {"the", "lazy", "cat", "ran", "slowly", "EOI"};
  vector<string> check3 = {"the", "dog", "smelly"};
  vector<string> check4 = {"cat", "the", "EOI"};
  vector<string> check5 = {"EOI", "the", "smelly", "dog", "ate", "noisily"};
  
  if(stateMachine(check1) == 1)
    cout << "Check 1 is correct/true!" <<endl;
  else
    cout << "Check 1 is incorrect/false!" << endl;
    
  if(stateMachine(check2) == 1)
    cout << "Check 2 is correct/true!" <<endl;
  else
    cout << "Check 2 is incorrect/false!" << endl;
    
  if(stateMachine(check3) == 1)
    cout << "Check 3 is correct/true!" <<endl;
  else
    cout << "Check 3 is incorrect/false!" << endl;
    
  if(stateMachine(check4) == 1)
    cout << "Check 4 is correct/true!" <<endl;
  else
    cout << "Check 4 is incorrect/false!" << endl;
    
  if(stateMachine(check5) == 1)
    cout << "Check 5 is correct/true!" <<endl;
  else
    cout << "Check 5 is incorrect/false!" << endl;
    
  return 0;
}
  

