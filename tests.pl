:- use_module(library(plunit)).

% these should all return true.
:- begin_tests(test_for_valid_sentence).
test(is_valid_sentence):- is_valid_sentence("the dog ran eoi").
test(is_valid_sentence):- is_valid_sentence("the cat ate noisily eoi").
test(is_valid_sentence):- is_valid_sentence("the lazy lazy dog ate slowly eoi").
test(is_valid_sentence):- is_valid_sentence("the lazy cat ate noisily eoi").
test(is_valid_sentence):- is_valid_sentence("the lazy smelly dog ran slowly eoi").
test(is_valid_sentence):- is_valid_sentence("the smelly lazy cat ate noisily eoi").
test(is_valid_sentence):- is_valid_sentence("the cat ran eoi").
test(is_valid_sentence):- is_valid_sentence("the dog ran noisily eoi").
test(is_valid_sentence):- is_valid_sentence("the lazy smelly lazy dog ran eoi").
test(is_valid_sentence):- is_valid_sentence("the cat ate eoi").
:- end_tests(test_for_valid_sentence).


% These are false, but return true since they are indeed false
:- begin_tests(test_for_invalid_sentence).
test(is_valid_sentence):- \+is_valid_sentence("the dog eoi").
test(is_valid_sentence):- \+is_valid_sentence("the cat ate too damn noisily eoi").
test(is_valid_sentence):- \+is_valid_sentence("the fat ugly cat died eoi").
test(is_valid_sentence):- \+is_valid_sentence("the dog ate some smelly dinner eoi").
test(is_valid_sentence):- \+is_valid_sentence("the lazy smelly dog ran quickly eoi").
test(is_valid_sentence):- \+is_valid_sentence("the smelly fat lazy cat ate eoi").
test(is_valid_sentence):- \+is_valid_sentence("the fast cat ran eoi").
test(is_valid_sentence):- \+is_valid_sentence("the big cat was owned by joe exotic").
test(is_valid_sentence):- \+is_valid_sentence("the lazy smelly lazy dog ran noisily slowly eoi").
test(is_valid_sentence):- \+is_valid_sentence("the cat ate some toxic waste eoi").
:- end_tests(test_for_invalid_sentence).
