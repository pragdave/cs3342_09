# -*- coding: utf-8 -*-
"""
@author: Patrick DeVries
"""

def checkSentence(wordsArr):
    #Each state is a tuple of (currentState, nextWord, nextState)
    states = [('S0', 'the', 'S1'),
              ('S1', 'lazy', 'S1'),
              ('S1', 'smelly', 'S1'),
              ('S1', 'dog', 'S2'),
              ('S1', 'cat', 'S2'),
              ('S2', 'ate', 'S3'),
              ('S2', 'ran', 'S3'),
              ('S3', 'slowly', 'S4'),
              ('S3', 'noisily', 'S4'),
              ('S3', 'EOI', 'END'),
              ('S4', 'EOI', 'END')]
    
    #auto-fail if the sentence doesnt have minimum of three words ('the', <noun>, <verb>)
    if len(wordsArr) < 3:
        return False
    
    state = 'S0'
    nextW = 0
    
    while(state != 'END'):
        
        #If out of words, return false
        if nextW >= len(wordsArr):
            return False
        
        found = False
        #For all possible states, if the current state of a tuple is this state,
        #Compare the next word to the tuple's next word, and change states if matching
        for i in states:
            if i[0] == state:
                if (wordsArr[nextW].lower() == i[1].lower()):
                    state = i[2]
                    found = True
                    
        #If a state matching the current state and next word was not found, return false
        #Otherwise continue to next word
        if not found:            
            return False
        else:
            nextW = nextW + 1
            continue
        
    #If the function reaches the END state and breaks out of the loop, sentence has passed
    return True


#main function
if __name__=='__main__':  
    #should all be true to pass
    s = [['the', 'lazy', 'dog', 'ate', 'noisily', 'EOI'],
         ['the', 'smelly', 'cat', 'ran', 'slowly', 'EOI'],
         ['the', 'smelly', 'lazy', 'cat', 'ran', 'EOI'],
         ['the', 'smelly', 'lazy', 'smelly', 'dog', 'ate', 'EOI'],
         ['the', 'dog', 'ate', 'EOI'],
         ['the', 'cat', 'ran', 'slowly', 'EOI']]
    
    for i, sentence in enumerate(s):
        # if it is valid, pass
        if (checkSentence(sentence)):
            print('Validation test ' + str(i+1) + ' passed')
        else:
            print('Validation test ' + str(i+1) + ' failed')
            
        print("sentence: ", end = " ")
        for word in sentence:
            print(word, end = " ")
        print('\n')
            
    #should all be false to pass
    s = [['the', 'dog', 'ate'],
         ['dog', 'ate', 'EOI'],
         ['the', 'lazy' , 'ran', 'EOI'],
         ['the'],
         ['EOI'],
         ['the', 'cat', 'ran', 'noisily'],
         ['the', 'dog', 'ate', 'noisily', 'slowly', 'EOI'],
         ['the', 'slowly', 'dog', 'ate', 'noisily', 'EOI'],
         ['the', 'lazy', 'dog', 'ate', 'smelly', 'EOI']]
    
    for i, sentence in enumerate(s):
        #if it is valid, fail
        if (checkSentence(sentence)):
            print('Invalidation test ' + str(i+1) + ' failed')
        else:
            print('Invalidation test ' + str(i+1) + ' passed')
            
        print("sentence: ", end = " ")
        for word in sentence:
            print(word, end = " ")
        print('\n')

    
        
    
    
    
