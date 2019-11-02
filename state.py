# Reid Russell
# CS3342
# Grammar Assignment
# 2.5


# Define the parameters
start =         ["the", "The"]
adjectives =    ["lazy", "smelly"]
nouns =         ["dog", "cat"]
verbs =         ["ate", "ran"]
adverbs =       ["slowly", "noisily"]


def S4(sentence, index):
    if sentence[index] == "EOI":
        return True
    else:
        return False

def S3(sentence, index):
    if sentence[index] == "EOI":
        return True
    elif sentence[index] in adverbs:
        index += 1
        return S4(sentence, index)
    else:
        return False

def S2(sentence, index):
    if sentence[index] in verbs:
        index +=1
        return S3(sentence, index)
    else:
        return False

def S1(sentence, index):
    if sentence[index] in adjectives:
        index += 1
        return S1(sentence, index)
    elif sentence[index] in nouns:
        index += 1
        return S2(sentence, index)
    else:
        return False


def S0(sentence, index):
    if sentence[index] == "the" or sentence[index] == "The":
        index += 1
        return S1(sentence, index)
    else:
        return False


def execute(sentence, index):
    return S0(sentence, index)


# Several test sentences, some of which should be true and some that should be false
def runTests():
    index = 0  # This is what word we are on
    sentence = ["The", "lazy", "dog", "ran", "slowly", "EOI"]   # Should be true
    print(execute(sentence, index))

    index = 0
    sentence = ["the", "smelly", "cat", "ate", "noisily", "EOI"]    # Should be true
    print(execute(sentence, index))

    index = 0
    sentence = ["the", "smelly", "cat", "ate", "EOI"]   # Should be true
    print(execute(sentence, index))

    index = 0
    sentence = ["the", "lazy", "smelly" , "dog", "ate", "noisily", "EOI"]   # Should be true
    print(execute(sentence, index))

    index = 0
    sentence = ["Hello", "lazy", "smelly", "dog", "ate", "noisily", "EOI"]  # Should be false
    print(execute(sentence, index))

    index = 0
    sentence = ["the", "smelly", "thing", "ate", "noisily", "EOI"]  # Should be false
    print(execute(sentence, index))

    index = 0
    sentence = ["the", "lazy", "smelly", "cat", "ran", "slowly", "EOI"]  # Should be true
    print(execute(sentence, index))

    index = 0
    sentence = ["the", "lazy", "smelly", "dog", "pooped", "noisily", "EOI"]  # Should be false
    print(execute(sentence, index))


runTests()