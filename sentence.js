const states_tab = {
    0: {
        "The": 1,
    },
    1: {
        "lazy": 1,
        "smelly": 1,
        "": 2
    },
    2: {
        "dog": 3,
        "cat": 3
    },
    3: {
        "ate": 4,
        "ran": 4
    },
    4: {
        "slowly": 5,
        "noisily": 5,
        "": 5
    },
    5: {
        "EOI": 6
    }
}


let validate_words = (words) => {
    curr_state = 0
    for (let word of words) {
        if (word in states_tab[curr_state]) {
            curr_state = states_tab[curr_state][word]
        }
        else if (word in states_tab[curr_state+1]) {
            curr_state = states_tab[curr_state+1][word]
        }
        else {
            return false
        }

        // END state
        if (curr_state == 6) {
            return true
        }
    }
    return false
}

// Testing
console.log("Begin testing")

const assert = require('assert').strict

assert(validate_words("The dog ran EOI".split(" ")))
assert(validate_words("The smelly lazy dog ran slowly EOI".split(" ")))
assert(validate_words("The lazy dog ran EOI".split(" ")))
assert(validate_words("The smelly cat ran EOI".split(" ")))
assert(validate_words("The smelly dog ate slowly EOI".split(" ")))
assert(validate_words("The lazy dog ate EOI".split(" ")))
assert(validate_words("The dog ran slowly EOI".split(" ")))
assert(validate_words("The dog ran".split(" ")) == false)
assert(validate_words("The ant ran EOI".split(" ")) == false)
assert(validate_words("The slowly ant ran EOI".split(" ")) == false)
assert(validate_words("The EOI".split(" ")) == false)
assert(validate_words("The lazy cat ate slowly".split(" ")) == false)

console.log("Done")