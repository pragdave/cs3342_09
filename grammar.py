# -*- coding: utf-8 -*-
"""
Created on Thu Oct 31 19:34:26 2019
@author: Nathan Srirama
This is my code for "parsing" a valid sentence as defined below using a 
finite state machine (I can't remember if this is a Moore or Mealy version)

Current state | Next word | Next state
--------------|-----------|-----------
    S0        |    the    |     S1
    S1        |    lazy   |     S2
    S1        |    smelly |     S2
    S1        |    dog    |     S3
    S1        |    cat    |     S3
    S2        |    lazy   |     S2
    S2        |    smelly |     S2
    S2        |    cat    |     S3
    S2        |    dog    |     S3
    S3        |    ran    |     S4
    S3        |    ate    |     S4
    S4        |    slowly |     S5
    S4        |    noisily|     S5
    S4        |    EOI    |     End
    S5        |    EOI    |     End
"""

states = [
          [0, "the", 1],
          [1, "lazy", 2],
          [1, "smelly", 2],
          [1, "dog", 3],
          [1, "cat", 3],
          [2, "lazy", 2],
          [2, "smelly", 2],
          [2, "cat", 3],
          [2, "dog", 3],
          [3, "ran", 4],
          [3, "ate", 4],
          [4, "slowly", 5],
          [4, "noisily", 5],
          [4, "", -1],
          [5, "", -1]
         ]

def main():
    testFile = open("tests.txt")
    sentences = [x.strip() for x in testFile]
    for string_to_parse in sentences:
        flag = isValidSentence(string_to_parse.lower())
        if flag:
            print("\"" + string_to_parse + "\" is a valid sentence!")
        else:
            print("\"" + string_to_parse + "\" is not a valid sentence -_-")


def isValidSentence(string_to_parse):
    #sets the current state to the starting state
    curr_state = 0
    data = string_to_parse.split()
    #I append an empty string so that the function will know what a valid 
    #sentence end is vs. a premature end. I like this better than putting EOI
    #at the end of the sentences, which looks weird
    data.append("")
    for word in data:
        found = False
        #I wanted to try a find function of some sort to make this not so 
        #brute-force-ish, but my python knowledge is meh and I didn't know how
        #find functions would work with my list of lists used for states
        for state in states:
            if state[0] == curr_state and state[1] == word:
                curr_state = state[2]
                found = True
                break
        if not found:
            return False
    if curr_state == -1:    
        return True
    else:
        return False


    
if __name__ == "__main__":
    main()