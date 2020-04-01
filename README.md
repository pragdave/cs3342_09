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
S -> <<empty>>
S -> R S R
S -> G S G
S -> B S B
R -> "r"
G -> "g"
B -> "b"
S -> R
S -> G
S -> B

## Q1.2  (1 point for the O() answer, 2 for the sentence)

Using big-O notation, what is the likely memory requirement for a parser that
can validate a particular path configuration, where `n` is the number of tiles?
In one sentence, explain why.

## A1.2

O(n), since esentially it is determining a "palindrome" persay, so the maximum is n/2 because it may be false before then, and since n/2 is still greater than a linear search, it is still O(n). 

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

<sentence> ::= "The"<subject><predicate>"."
<subject>::=<noun>|<adjective><noun>
<noun>::="dog"|"cat"
<adjective>::="smelly"|"lazy"
<predicate>::=<verb>|<verb><adverb>
<verb>::="ate"|"ran"
<adverb>::="slowly"|"noisily"


## Q2.2 (5 points)

Write this grammar using EBNF with common extensions

## A2.2

<sentence>::="The"[<adjective>]<noun><verb>[<adverb>]
<verb>::="ate"|"ran"
<adverb>::="slowly"|"noisily"
<noun>::="dog"|"cat"
<adjective>::="smelly"|"lazy"

## Q2.3 (6 points)

  Draw a diagram for an FSM which recognizes these sentences. Use EOI as the
  event that occurs at the end-of-input. Start with a state named S0. Receiving
  the word "the" in that state will transition to state S1. Name the final state
  END.

  You can hand draw it and snap a picture, or use a drawing tool. Either way,
  upload the image, and put the file name in the answer below.

  (Hint: my answer has seven states including the start and end states)


## A2.3

![If the image will not appear, view cycles.jpg included in this file](/cycles.jpg)

## Q2.4 (6 points)

Convert this diagram into a table of the form:

Current state | Next word | Next state
--------------|-----------|-----------
    S0        |    the    |     S1
    S1        |   . . .   |   . . .

(hint: my version has 13 entries. Yours _might_ be different)

## A2.4

Line # |  Current state |    Next word   | Next state
-------|----------------|----------------|-----------
  1    |      S0        |    The         |    S1
  2    |      S1        |    dog         |    S3
  3    |      S1        |    cat         |    S3
  4    |      S1        |    smelly      |    S2
  5    |      S1        |    lazy        |    S2
  6    |      S2        |    dog         |    S3
  7    |      S2        |    cat         |    S3   
  8    |      S3        |    ate         |    S4
  9    |      S3        |    ran         |    S4
  10   |      S4        |    slowly      |    S5
  11   |      S4        |    noisily     |    S5
  12   |      S4        |      .         |    END
  13   |      S5        |      .         |    END

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

run main.cpp with sentences.txt as a command line argument:
g++ -o main main.cpp
./main sentences.txt

## Q2.6 (3 points)

How many valid sentences are there in this language?

## A2.6
36 total 

visual explanation: 
The dog ate.
The dog ran.
The smelly dog ate.
The lazy dog ate.
The smelly dog ran.
The lazy dog ran.
The dog ate slowly.
The dog ate noisily. 
The dog ran slowly. 
The dog ran noisily. 
The smelly dog ran noisily.
The lazy dog ran noisily.
The smelly dog ran slowly.
The lazy dog ran slowly.
The smelly dog ate noisily.
The lazy dog ate noisily.
The smelly dog ate slowly.
The lazy dog ate slowly.
The cat ate.
The cat ran.
The smelly cat ate.
The lazy cat ate.
The smelly cat ran.
The lazy cat ran.
The cat ate slowly.
The cat ate noisily. 
The cat ran slowly. 
The cat ran noisily. 
The smelly cat ran noisily.
The lazy cat ran noisily.
The smelly cat ran slowly.
The lazy cat ran slowly.
The smelly cat ate noisily.
The lazy cat ate noisily.
The smelly cat ate slowly.
The lazy cat ate slowly.

mathematical explanation:
1 * 3 * 2 * 2 * 3 * 1=36

1  *       3         *   2   *   2   *     3              *1
The smelly/lazy/blank dog/cat ate/ran slowly/noisily/blank .

## Q2.7 (1 point for the level, 2 for the sentence)

Which is the simplest Chomsky grammar level for this language? In one sentence,
explain why.

## A2.7

The simplest Chomsky grammar level for this language is type 2, as it needs to at least accomodate strings which Type 3 cannot do, but it is not context sensitive either and did not need to clarify function and variable. 
