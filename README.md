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

«replace this with your answer»
S -> 'r'
S -> 'b'
S -> 'g'
S -> 'r' S 'r'
S -> 'g' S 'g'
S -> 'b' S 'b'


## Q1.2  (1 point for the O() answer, 2 for the sentence)

Using big-O notation, what is the likely memory requirement for a parser that
can validate a particular path configuration, where `n` is the number of tiles?
In one sentence, explain why.

## A1.2

The memory requirement for a parser of this problem would be O(n), because the entire path must be put into memory so it can be searched through.  An algorithm, O(n), could possibly start at the head and tail and compare tiles heading towards the other end until they were on the same tile. 

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

«replace this with your answer»
<sentence> ::= <start> <adj> <noun> <verb_and_adverb> <period>
<start> ::= "The"
<adj> ::= "lazy" | "smelly"
<noun> ::= "dog" | "cat"
<verb_and_adverb> ::= "ate" adverb | "ran" adverb | "ate" | "ran"
<adveb> ::= "slowly" | "noisily" 
<period> ::= "."

## Q2.2 (5 points)

Write this grammar using EBNF with common extensions

## A2.2

«replace this with your answer»
<sentence> ::= "the" ["lazy" | "smelly"] {"dog" | "cat"} {"ate" | "ran"} ["slowly" | "noisily"] "."



## Q2.3 (6 points)

  Draw a diagram for an FSM which recognizes these sentences. Use EOI as the
  event that occurs at the end-of-input. Start with a state named S0. Receiving
  the word "the" in that state will transition to state S1. Name the final state
  END.

  You can hand draw it and snap a picture, or use a drawing tool. Either way,
  upload the image, and put the file name in the answer below.

  (Hint: my answer has seven states including the start and end states)
  You probably want to have six states, he was wrong :O


## A2.3

FSMDiagram.png


## Q2.4 (6 points)

Convert this diagram into a table of the form:

Current state | Next word | Next state
--------------|-----------|-----------
    S0        |    the    |     S1
    S1        |   . . .   |   . . .

(hint: my version has 13 entries. Yours _might_ be different)

## A2.4

Current state | Next word       | Next state
--------------|-----------------|-----------
    S0        |    the          |     S1
    S1        |    lazy         |     S2
    S1        |    smelly       |     S2
    S2        |    dog          |     S3
    S2        |    cat          |     S3
    S3        |    ate          |     S4
    S3        |    ran          |     S4
    S4        |    slowly       |     S5
    S4        |    noisily      |     S5
    S4        |    .            |     S5
    S5        |    .            |     S6
    S5        |    EOI          |     END
    S6        |    EOI          |     END


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

For the input file, each line must be one sentence. The sentence can be valid or not, and the program will return its validity. Please input the number of lines you wish to test.

## Q2.6 (3 points)

How many valid sentences are there in this language?

## A2.6

Because zero or more adjectives are accepted in this language, there are an infinite possible of combinations. Although the adjectives would be repeated and would not make grammatical sense to an English speaker, within this grammar it is correct. The infinite amount of possible adjectives makes for infinite combinations.

## Q2.7 (1 point for the level, 2 for the sentence)

Which is the simplest Chomsky grammar level for this language? In one sentence,
explain why.

## A2.7

The simplest grammar level would be level three. That is because it requires a FSM and does not require any backtracking.