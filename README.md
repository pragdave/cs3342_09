# Grammars Assignment (50 points)

This file contains two questions. The first has 2 parts, the second has 7.

For all but questions 2.3 and 2.5 you'll answer questions by editing this file.
Your answers will appear in the Ax.y section after each question, replacing the
placeholders.

For question 2.3, you'll need to add an image file to the repository (.png or
.pdf) and put its file name as the answer.

For question 2.5, you'll write one or more source code files and add them to the
repository. You will then show the command used to run the files in the answer.
Do _not_ upload any binary files for this section.

Please do not edit anything outside the answers sections.


# Q1: Mr Fussy Builds a Path

# Q1

Mr Fussy wants to build a path using a row of large square pavers. His path is
one paver wide and an odd number of pavers long. Pavers come in three colors:
red, green, blue.

Mr Fussy has a rule: the sequence of colors must be symmetrical across the
length of the path: the last paver must be the same color as the first, the
second to last the same color as the second, and so on.

This is a valid path:  rgbgr
So is this: rrr

This is not: rgb
This is not: rggr    (it must be an odd length)

## Q1.1  (5 points)

Write a Chomsky type 2 grammar that describes any valid path containing at
least one paver. Use `S` as the start state, and `r`, `g`, `b` as terminals that
represent the tiles.

## A1.1

S -> r S r
S -> g S g
S -> b S b
S -> r | g | b

## Q1.2  (1 point for the O() answer, 2 for the sentence)

Using big-O notation, what is the likely memory requirement for a parser that
can validate a particular path configuration, where `n` is the number of tiles?
In one sentence, explain why.

## A1.2

O(n) because to validate a particular path, it checks each of the tiles to see if they match each of the rules to completely validate the entire configuration.


# Q2

A simple sentence structure might be

    "the" (zero or more adjectives) noun verb (optional adverb)

Adjectives are "lazy" or "smelly"

Nouns are "dog" or "cat"

Verbs are "ate" and "ran"

Adverbs are "slowly" and "noisily"

The following are examples of valid sentences:

* The smelly dog ran.
* The smelly dog ran slowly.
* The cat ate noisily.

## Q2.1 (7 points)

Write the BNF (not EBNF) description for this language.


## A2.1

<the> ::= 'The'|'the'
<adjective> ::= 'lazy'|'smelly'| <adjective>' '<adjective> 
<noun> ::= 'dog'|'cat'| <adjective>' '<noun>
<adverb> ::= 'slowly'|'noisily'
<verb> ::= 'ate'|'ran'| <verb>' '<adverb>

<sentence> ::= <the>' '<noun>' '<verb>


## Q2.2 (5 points)

Write this grammar using EBNF with common extensions

## A2.2

<the> ::= 'The'|'the'
<adjective> ::= 'lazy'|'smelly' 
<noun> ::= 'dog'|'cat'
<adverb> ::= 'slowly'|'noisily'
<verb> ::= 'ate'|'ran'

<sentence> ::= <the>' '{<adjective>' '}<noun>' '<verb>' '[<adverb>]


## Q2.3 (6 points)

  Draw a diagram for an FSM which recognizes these sentences. Use EOI as the
  event that occurs at the end-of-input. Start with a state named S0. Receiving
  the word "the" in that state will transition to state S1. Name the final state
  END.

  You can hand draw it and snap a picture, or use a drawing tool. Either way,
  upload the image, and put the file name in the answer below.

  (Hint: my answer has seven states including the start and end states)


## A2.3

A2-3.pdf

## Q2.4 (6 points)

Convert this diagram into a table of the form:

Current state | Next word | Next state
--------------|-----------|-----------
    S0        |    the    |     S1
    S1        |   . . .   |   . . .

(hint: my version has 13 entries. Yours _might_ be different)

## A2.4

| Current State | Next Word | Next State |
|---------------|-----------|------------|
| S0            | The       | S1         |
| S1            | lazy      | S1         |
| S1            | smelly    | S1         |
| S1            | dog       | S2         |
| S1            | cat       | S2         |
| S2            | ate       | S3         |
| S2            | ran       | S3         |
| S3            | slowly    | S4         |
| S3            | noisily   | S4         |
| S3            | EOI       | END        |
| S4            | EOI       | END        |


## Q2.5 (12 points)

Translate this table into a programming language of your choice. Then write a
function that takes a list of words (ending "EOI") and runs the list through the
state machine. If the state machine cannot find a transition for a word when in
a given state, return false. If the state machine runs out of words and the
state is not "END" then return false. Otherwise return true.

Then write some unit tests that exercise your function, making sure that it
recognizes valid sentences and rejects invalid ones.

The answer should appear in one or more source files in the same directory as
this file. If I need to do anything more that type a single command to run your
code, include a script or makefile that will do the job.

## A2.5

This is done in the files: FSM.h and main.cpp (run main.cpp with c++ compiler) (I wrote using visual c++ but I think gcc should work)

## Q2.6 (3 points)

How many valid sentences are there in this language?


## A2.6

//---------------------THIS IS WORK---------------------
The dog ate //only nouns and verb: 4 sentences
The cat ate
The dog ran
The cat ran

The dog ate slowly  //no adjectives, one adverb: 8 sentences
The cat ate slowly
The dog ate noisily
The cat ate noisily
The dog ran slowly
The cat ran slowly
The dog ran noisily
The cat ran noisily

The lazy dog ate //one adjective, no adverb: 8 sentences
The lazy cat ate
The smelly dog ate
The smelly cat ate
The lazy dog ran
The lazy cat ran
The smelly dog ran
The smelly cat ran

//two adjective, no adverb: 16 sentences
//two adjective, one adverb: 32 sentences
//---------------------THIS IS WORK--------------------- (answer below)

There are 68 sentences in this language (if we assume that there is a max of 2 adjectives)

Otherwise, there is an infinite amount of sentences because you can keep using the same adjectives over and over:
ex. "The lazy smelly lazy smelly smelly lazy dog ran." will technically pass since the only rules for adjectives are one or more


## Q2.7 (1 point for the level, 2 for the sentence)

Which is the simplest Chomsky grammar level for this language? In one sentence,
explain why.

## A2.7

The simplest Chomsky grammar level for this language would be level 3. 

This is because type 3 grammar is the most easily understandable and parsable grammar level; in addition, 
when dealing with type 3 grammar, there is less ambiguity and for every production rule, there is only one non-terminal: if we define simplest as easiest to understand for humans


^ Also that's technically one sentence because I used ; and :