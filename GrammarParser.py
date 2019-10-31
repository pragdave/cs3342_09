def parser(input):
    words = input.split();
    
    #Makes sure there were words passed in
    if(len(words) == 0):
        return False;
    
    #The first word should be the
    if(words[0] != "the"):
        return False;
    
    #Remove a word and make sure there are more
    words.pop(0);
    if(len(words) == 0):
        return False;
    
    #There should be any number of adjectives
    while(words[0] in ["lazy", "smelly"]):
        #Remove a word and make sure there are more
        words.pop(0);
        if(len(words) == 0):
            return False;
    
    #There should be exactly one noun
    if(words[0] not in ["dog", "cat"]):
        return False;
    
    #Remove a word and make sure there are more
    words.pop(0);
    if(len(words) == 0):
        return False;
    
    #There should be exactly one verb
    if(words[0] not in ["ate", "ran"]):
        return False;
    
    #Remove a word
    words.pop(0);
    
    #True if no adverb
    if(len(words) == 0):
        return True;
    
    #If anything besides an adverb return false
    if(words[0] not in ["slowly", "noisily"]):
        return False;
        
    #Removes the adverb
    words.pop(0);
    
    #Makes sure the list is now empty
    if(len(words) == 0):
        return True;
    
    #If the list is not empty, return false
    return False

print("Parser returned ", parser("the lazy dog ran slowly"));
print("Parser returned ", parser("the cat ate noisily"));
print("Parser returned ", parser("the lazy smelly lazy dog ran"));
print("Parser returned ", parser("the lazy dog"));
print("Parser returned ", parser(""));
print("Parser returned ", parser("Hello World"));
print("Parser returned ", parser("the lazy ran"));
print("Parser returned ", parser("the smelly cat"));