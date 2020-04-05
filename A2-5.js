// Run: node A2-5.js

print = console.log

// Current State, Next Word, Next State (6 = END)
var fsmTable = [
    [0, "the", [1, 2]],
    [1, "lazy", [1, 2]],
    [1, "smelly", [1, 2]],
    [2, "dog", [3]],
    [2, "cat", [3]],
    [3, "ate", [4]],
    [3, "ran", [4]],
    [4, "slowly", [5]],
    [4, "noisily", [5]],
    [4, "EOI", [6]],
    [5, "EOI", [6]]
]

function isSentence(words) {
    words = words.split(" ")
    if (words.length < 4
        || words.length > 7)
        return false
    var index = 0
    var currentState = 0;
    for (var word of words)
    {
        for (var i = 0; i < fsmTable.length; i++)
        {
            if (fsmTable[i][1] == word)
            {
                if (fsmTable[i][0] != currentState
                    && word != "EOI")                    
                    return false
                nextState = fsmTable[i][2]
                if (nextState.length == 2
                    && 
                    (words[index+1] == "dog"
                    || words[index+1] == "cat"))
                    currentState = nextState[1]
                else
                    currentState = nextState[0]
                break
            }
            else if (i == fsmTable.length - 1)
                return false   
        }
        index++
    }
    currentState = nextState
    return currentState != 6 ? false : true
}

const assert = require('assert').strict
Error.stackTraceLimit = 2

assert.equal(isSentence("the dog ate EOI"), true)
assert.equal(isSentence("the cat ate EOI"), true)
assert.equal(isSentence("the dog ate slowly EOI"), true)
assert.equal(isSentence("the dog ran noisily EOI"), true)
assert.equal(isSentence("the cat ran slowly EOI"), true)
assert.equal(isSentence("the lazy cat ate slowly EOI"), true)
assert.equal(isSentence("the smelly cat ran EOI"), true)
assert.equal(isSentence("the lazy smelly dog ran noisily EOI"), true)
assert.equal(isSentence("the smelly lazy dog ate noisily EOI"), true)

assert.equal(isSentence("the lazy cat ate slowly"), false)
assert.equal(isSentence("the lazy smelly cat dog ate slowly EOI"), false)
assert.equal(isSentence("the lazy animal ran EOI"), false)
assert.equal(isSentence("dog ate slowly EOI"), false)
assert.equal(isSentence("the lazy cat ran slowly noisily EOI"), false)
assert.equal(isSentence("the EOI"), false)
assert.equal(isSentence("EOI"), false)
assert.equal(isSentence(""), false)