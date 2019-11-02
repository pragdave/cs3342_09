
adjectives = ["lazy", "smelly"]
nouns = ["dog", "cat"]
verbs = ["ate", "ran"]
adverbs = ["slowly", "noisily"]

def parser( words ):
    adj = False
    noun = False
    verb = False

    for i, val in enumerate(words):
        if i == 0:
            if val == "the":
                continue
            else:
                return False
        elif i > 0 and i < 3 :
            if words[i] in adjectives:
                adj = True
                continue
            elif(adj):
                if words[i] in nouns:
                    noun = True
                    continue
                else:
                    return False
        elif i >= 3 and i < 5 :
            if(noun):
                if words[i] in verbs:
                    verb = True
                    continue
            else:
                if words[i] in nouns:
                    noun = True
                    continue
                else:
                    return False
        elif i > 4:
            if(verb):
                if words[i] in adverbs:
                    continue
                elif words[i] == "EOI":
                    return True
                else:
                    return False
            else:
                if words[i] in verbs:
                    verb = True
                    continue
                else:
                    return False
    return True

test1 = ["the", "smelly", "dog", "ran", "EOI"]
test2 = ["the", "lazy", "cat", "ate", "noisily", "EOI"]
test3 = ["the", "lazy", "smelly", "monkey"]
test4 = ["hello"]
test5 = ["the", "smelly", "lazy", "cat", "ran", "slowly", "EOI"]
test6 = ["the", "smelly", "lazy", "cat", "ran", "slowly", "loudly"]
print(test1, parser(test1))
print(test2, parser(test2))
print(test3, parser(test3))
print(test4, parser(test4))
print(test5, parser(test5))
print(test6, parser(test6))

            



