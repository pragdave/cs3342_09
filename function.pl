%         This is the table
%-------------------------------------
%      state    word       next_state
table(  s0,    "the",          s1).
table(  s0,    "the",          s2).
table(  s1,    "lazy",         s2).
table(  s1,    "smelly",       s2).
table(  s1,    "lazy",         s1).
table(  s1,    "smelly",       s1).
table(  s2,    "cat",          s3).
table(  s2,    "dog",          s3).
table(  s3,    "ran",          s4).
table(  s3,    "ate",          s4).
table(  s4,    "noisily",      s5).
table(  s4,    "slowly",       s5).
table(  s4,    "eoi",         end).
table(  s5,    "eoi",         end).
%---------------------------------------

% Definitely not the prolog way of solving this
% But I wanted to give it a shot... 
% And it works for the most part..however
% You will probably find a way to break it

% arg is a list
is_valid_sentence(List):-
    is_list(List),
    atomic_list_concat(List,' ', Atom),
    atom_string(Atom, Str),
    is_valid_sentence(s0,Str,_).

% arg is a string
is_valid_sentence(Str):- is_valid_sentence(s0,Str,_).

% base case
is_valid_sentence(S, "eoi", end):- table(S, "eoi", end), !.

% main method of finding valid sentence
is_valid_sentence(State, Str, Next_State):-
    split_string(Str," ", "", L),
    nth0(0,L, Elem),
    table(State, Elem, Next_State),
    string_length(Elem,NLength),    
    Length is NLength + 1,                
    string_length(Str,OLength),     
    NewLength is OLength - Length,  
    sub_string(Str,Length,NewLength,_, NewStr),
    is_valid_sentence(Next_State,NewStr,_),!.
