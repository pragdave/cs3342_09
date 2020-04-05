
function sentenceCheck(sentence) {
    var words = sentence.split(" ")
    let i = 0
    //state 0

    if(words[i] != 'the' && words[i] != 'The')
    {
        return false
    }
    

    i++

    //state 1
    if(words[i] != 'smelly' && words[i] != 'lazy')
    {
        if(words[i] == 'dog' || words[i] == 'cat')
        {
            words.splice(i, 0, "")
        }
        else
            return false
    }
    else{

        i++
        if(words[i] != 'smelly' && words[i] != 'lazy')
        {
            if(words[i] == 'dog' || words[i] == 'cat')
            {
                words.splice(i, 0, "")
            }   
            else{
                return false
            }
        }
    }
    i++

    //state 2
    if(words[i] != 'dog' &&  words[i] != 'cat')
        return false

    i++
    //state 3
    if(words[i] != 'ran' && words[i] != 'ate')
        return false
    
    i++
    //state 4
    if(words[i] == 'EOI')
        return true
    if(words[i] != 'noisily' && words[i] != 'slowly')
        return false

    i++
    //state 5
    if(words[i] != 'EOI')
        return false

    return true
}

console.log('Sentences that should work')

console.log('The dog ran EOI: ' + sentenceCheck('The dog ran EOI')) //No adjective/adverb
console.log('The lazy cat ran EOI: ' + sentenceCheck('The lazy cat ran EOI')) //adjective only
console.log('The cat ate noisily EOI: ' + sentenceCheck('The cat ate noisily EOI')) //adverb only
console.log('The smelly dog ate slowly EOI: ' + sentenceCheck('The smelly dog ate slowly EOI')) //adjective and adverb
console.log('The lazy smelly dog ran EOI: ' + sentenceCheck('The lazy smelly dog ran EOI')) //Two adjectives
console.log('The smelly lazy cat ate noisily EOI: ' + sentenceCheck('The smelly lazy cat ate noisily EOI')) //two adjectives and adverb

console.log('\nSentences that should not work')

console.log('the fat cat ate slowly EOI: ' + sentenceCheck('the fat cat ate slowly EOI')) //Non-present words
console.log('Cat ran EOI: ' + sentenceCheck('Cat ran EOI')) //no 'the'
console.log('the dog ate: ' + sentenceCheck('the dog ate')) //no 'EOI'
console.log('the lazy smelly lazy cat ate EOI: ' + sentenceCheck('the lazy smelly lazy cat ate EOI')) //too many adjectives
