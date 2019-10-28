# -*- coding: utf-8 -*-
"""
@author: Patrick DeVries
"""

def checkSentence(wordsArr):
    if len(wordsArr) < 3:
        return False
    
    words = []
    for w in wordsArr:
        words.append(w.lower())
        
    state = 'S0'
    nextW = 0;
    
    #S0, check for 'the'
    if words[nextW] == 'the':
        state = 'S1'
    else:
        return False
    
    #S1/S2, check for adjectives until there is a noun
    while (state == 'S1' or state == 'S2'):
        nextW = nextW + 1
        if (nextW == len(words)):
            return False
        if words[nextW] == 'lazy' or words[nextW] == 'smelly':
            continue
        elif words[nextW] == 'cat' or words[nextW] == 'dog':
            state = 'S3'
        else:
            return False
    
    #S3, check for a verb
    nextW = nextW+1
    if (nextW == len(words)):
        return False
    if words[nextW] == 'ate' or words[nextW] == 'ran':
        state = 'S4'
    else:
        return False
    
    #S4/S5 check for an adverb or a end of input
    nextW = nextW+1
    if (nextW == len(words)):
        return False
    if words[nextW] == 'slowly' or words[nextW] == 'noisily':
        state = 'S5'
    elif words[nextW] == 'eoi':
        state = 'END'
        return True
    else:
        return False
        
    #s5 check for end of input
    nextW = nextW+1
    if (nextW == len(words)):
        return False
    if words[nextW] == 'eoi':
        state = 'END'
        return True
    else:
        return False
    
    



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

    
        
    
    
    
