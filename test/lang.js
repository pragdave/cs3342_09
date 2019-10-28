var mocha = require('mocha');
var describe = mocha.describe;
var it = mocha.it;
var assert = require('assert');

var start = "the";
var adjectives = ["lazy", "smelly"];
var noun = ["dog", "cat"];
var verb = ["ate", "ran"];
var adverb = ["slowly", "noisily"];
var end = "EOI";

var returnVal = false;

function stateMachine(state, restSentence) {
    //let returnVal = false;
    switch(state) {
        case "S0":
            if (restSentence[0] === start) {
                stateMachine("S1", restSentence.slice(1, restSentence.length));
            }
            break;
        case "S1":
            if (restSentence[0] === adjectives[0] || restSentence[0] === adjectives[1]) {
                stateMachine("S2", restSentence.slice(1, restSentence.length));
            } else if (restSentence[0] === noun[0] || restSentence[0] === noun[1]) {
                stateMachine("S3", restSentence.slice(1, restSentence.length));
            }
            break;
        case "S2":
            if (restSentence[0] === adjectives[0] || restSentence[0] === adjectives[1]) {
                stateMachine("S2", restSentence.slice(1, restSentence.length));
            } else if (restSentence[0] === noun[0] || restSentence[0] === noun[1]) {
                stateMachine("S3", restSentence.slice(1, restSentence.length));
            }
            break;
        case "S3":
            if (restSentence[0] === verb[0] || restSentence[0] === verb[1]) {
                stateMachine("S4", restSentence.slice(1, restSentence.length));
            }
            break;
        case "S4":
            if (restSentence[0] === adverb[0] || restSentence[0] === adverb[1]) {
                stateMachine("S5", restSentence.slice(1, restSentence.length));
            } else if (restSentence[0] === end) {
                stateMachine("S6", restSentence);
            }
            break;
        case "S5":
            if (restSentence[0] === adverb[0] || restSentence[0] === adverb[1]) {
                stateMachine("S5", restSentence.slice(1, restSentence.length));
            } else if (restSentence[0] === end) {
                stateMachine("S6", restSentence);
            }
            break;
        case "S6":
            if (restSentence[0] === end) {
                returnVal = true;
            }
    }
    return returnVal;
}

function testSentence(sentence) {
    let ret = stateMachine("S0", sentence.split(" "));
    returnVal = false;
    return ret;
}


describe('Sentence Builder', () => {
    let sentenceTests = [
        "the dog ate EOI",                          //0
        "the cat ran EOI",                          //1
        "the lazy dog ate EOI",                     //2
        "the smelly cat ran EOI",                   //3
        "the lazy smelly dog ran EOI",              //4
        "the smelly lazy cat ate EOI",              //5
        "the cat ate slowly EOI",                   //6
        "the dog ran noisily EOI",                  //7
        "the smelly cat ate noisily EOI",           //8
        "the lazy dog ran noisily slowly EOI",      //9
        "the smelly lazy dog ran slowly EOI",       //10
        "the cool dog ate slowly EOI",              //11
        "what the cool dog did EOI",                //12
        "this sentence is all kinds of wrong EOI"   //13
    ];

    it('sentences that should be found', () => {
        let result = testSentence(sentenceTests[0]);
        assert.equal(result, true);
        result = testSentence(sentenceTests[1]);
        assert.equal(result, true);
        result = testSentence(sentenceTests[2]);
        assert.equal(result, true);
        result = testSentence(sentenceTests[3]);
        assert.equal(result, true);
        result = testSentence(sentenceTests[4]);
        assert.equal(result, true);
        result = testSentence(sentenceTests[5]);
        assert.equal(result, true);
        result = testSentence(sentenceTests[6]);
        assert.equal(result, true);
        result = testSentence(sentenceTests[7]);
        assert.equal(result, true);
        result = testSentence(sentenceTests[8]);
        assert.equal(result, true);
        result = testSentence(sentenceTests[9]);
        assert.equal(result, true);
        result = testSentence(sentenceTests[10]);
        assert.equal(result, true);
    })
    it('sentences that should not be found', () => {
        let result = testSentence(sentenceTests[11]);
        assert.equal(result, false);
        result = testSentence(sentenceTests[12]);
        assert.equal(result, false);
        result = testSentence(sentenceTests[13]);
        assert.equal(result, false);
    })
});