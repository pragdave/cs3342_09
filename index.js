
function isSentence(sentence) {
    var tokens = sentence.split(" ")
    let i = 0
    //Check S0
    if( (tokens[i] != 'the' ) && (tokens[i] != 'The') )
    {
        return false
    }


    i++ //next word in sentence
    if( (tokens[i] != 'smelly') && (tokens[i] != 'lazy') )
    {
        if(tokens[i] == 'dog' || tokens[i] == 'cat')
        {
            tokens.splice(i, 0, "")
        }
        else
            return false
    }
    else{
        i++
        if(tokens[i] != 'smelly' && tokens[i] != 'lazy')
        {
            if(tokens[i] == 'dog' || tokens[i] == 'cat')
            {
                tokens.splice(i, 0, "")
                         }   
            else{
                return false
            }
        }
    }
    i++

    //S2 fail condition
    if(tokens[i] != 'dog' &&  tokens[i] != 'cat')
        return false

    i++

    //S3 fail condition
    if(tokens[i] != 'ran' && tokens[i] != 'ate')
        return false

    i++

    //S4 fail condition
    if(tokens[i] == 'EOI')
        return true
    if(tokens[i] != 'noisily' && tokens[i] != 'slowly')
        return false

    i++
    //S5 fail condition
    if(tokens[i] != 'EOI')
        return false

    return true
}

//idea behind the code was to code my FSM diagram in with javascript because javascript will allow me to abstract state into a function of the sentence more easily than c++

//the other strategy is that I am starting from the assumption that the sentence will qualify and checking fail conditions for each state
console.log("Output true: ");
console.log(isSentence("the lazy cat ate EOI"))
console.log(isSentence("The lazy dog ate noisily EOI"))

console.log("Output false: ");
console.log(isSentence("the darting rat ate EOI"))
console.log(isSentence("the smelly lazy lazy smelly cat ate noisily"))

