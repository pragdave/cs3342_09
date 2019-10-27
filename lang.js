const itParam = require('mocha-param').itParam;

var start = "the";
var adjectives = ["lazy", "smelly"];
var noun = ["dog", "cat"];
var verb = ["ate", "ran"];
var adverb = ["slowly", "noisily"];
var end = "EOI";

function stateMachine(state, restSentence) {
    switch(state) {
        case "S0":
            if (restSentence[0] === start) {
                stateMachine("S1", restSentence.slice(1, restSentence.length));
            } else {
                return false;
            }
            break;
        case "S1":
            if (restSentence[0] === adjectives[0] || restSentence[0] === adjectives[1]) {
                stateMachine("S2", restSentence.slice(1, restSentence.length));
            } else if (restSentence[0] === noun[0] || restSentence[0] === noun[1]) {
                stateMachine("S3", restSentence.slice(1, restSentence.length));
            } else {
                return false;
            }
            break;
        case "S2":
            if (restSentence[0] === adjectives[0] || restSentence[0] === adjectives[1]) {
                stateMachine("S2", restSentence.slice(1, restSentence.length));
            } else if (restSentence[0] === noun[0] || restSentence[0] === noun[1]) {
                stateMachine("S3", restSentence.slice(1, restSentence.length));
            } else {
                return false;
            }
            break;
        case "S3":
            if (restSentence[0] === verb[0] || restSentence[0] === verb[1]) {
                stateMachine("S4", restSentence.slice(1, restSentence.length));
            } else {
                return false;
            }
            break;
        case "S4":
            if (restSentence[0] === adverb[0] || restSentence[0] === adverb[0]) {
                stateMachine("S5", restSentence.slice(1, restSentence.length));
            } else if (restSentence[0] === end) {
                stateMachine("S6", restSentence);
            } else {
                return false;
            }
            break;
        case "S5":
            if (restSentence[0] === adverb[0] || restSentence[0] === adverb[0]) {
                stateMachine("S5", restSentence.slice(1, restSentence.length));
            } else if (restSentence[0] === end) {
                stateMachine("S6", restSentence);
            } else {
                return false;
            }
            break;
        case "S6":
            return true;
    }
}

function testSentence(sentence) {
    let result = stateMachine("S0", sentence.split(" "));
    if (result === true) {
        return true;
    } else {
        return false;
    }
}


describe('Sentence Builder', () => {
    let sentenceTests = [
        "the dog ate EOI",
        "the cat ran EOI",
        "the lazy dog ate EOI",
        "the smelly cat ran EOI",
        "the lazy smelly dog ran EOI",
        "the smelly lazy cat ate EOI",
        "the cat ate slowly EOI",
        "the dog ran noisily EOI",
        "the smelly cat ate noisily EOI",
        "the lazy dog ran noisily slowly EOI",
        "the smelly lazy dog ran slowly noisily EOI",
        "the cool dog ate slowly EOI",
        "what the cool dog did EOI",
        "this sentence is all kinds of wrong EOI"
    ];

    it('sentences that should be found', () => {
        let result = testSentence(sentence[0]);
        expect(result).to.be.true;
        result = testSentence(sentence[1]);
        expect(result).to.be.true;
        result = testSentence(sentence[2]);
        expect(result).to.be.true;
        result = testSentence(sentence[3]);
        expect(result).to.be.true;
        result = testSentence(sentence[4]);
        expect(result).to.be.true;
        result = testSentence(sentence[5]);
        expect(result).to.be.true;
        result = testSentence(sentence[6]);
        expect(result).to.be.true;
        result = testSentence(sentence[7]);
        expect(result).to.be.true;
        result = testSentence(sentence[8]);
        expect(result).to.be.true;
        result = testSentence(sentence[9]);
        expect(result).to.be.true;
        result = testSentence(sentence[10]);
        expect(result).to.be.true;
        result = testSentence(sentence[11]);
        expect(result).to.be.true;
    })
    it('sentences that should not be found', () => {
        let result = testSentence(sentence[12]);
        expect(result).to.be.false;
        let result = testSentence(sentence[13]);
        expect(result).to.be.false;
        let result = testSentence(sentence[14]);
        expect(result).to.be.false;
    })
});