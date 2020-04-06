state_machine(List) :- s0(List, 0).

s0(List, Index) :-
    nth0(Index, List, the),
    Index2 is Index + 1,
    s1(List, Index2),
    !.

s1(List, Index) :-
    s2(List, Index);
    (
        nth0(Index, List, I),
        (
            I = lazy;
            I = smelly
        ),
        Index2 is Index + 1,
        (
            s1(List, Index2);
            s2(List, Index2)
        ),
        !
    ).

s2(List, Index) :-
    nth0(Index, List, I),
    (
        I = dog;
        I = cat
    ),
    Index2 is Index + 1,
    s3(List, Index2),
    !.

s3(List, Index) :-
    nth0(Index, List, I),
    (
        I = ate;
        I = ran
    ),
    Index2 is Index + 1,
    s4(List, Index2),
    !.

s4(List, Index) :-
    s5(List, Index);
    (
        nth0(Index, List, I),
        (
            I = slowly;
            I = noisily
        ),
        Index2 is Index + 1,
        s5(List, Index2),
        !
    ).

s5(List, Index) :-
    nth0(Index, List, eoi).

:- begin_tests(all).

test(state_machine) :- state_machine([the, cat, ate, eoi]).
test(state_machine) :- state_machine([the, cat, ran, eoi]).
test(state_machine) :- state_machine([the, dog, ate, eoi]).
test(state_machine) :- state_machine([the, dog, ran, eoi]).

test(state_machine) :- state_machine([the, cat, ate, slowly, eoi]).
test(state_machine) :- state_machine([the, cat, ran, slowly, eoi]).
test(state_machine) :- state_machine([the, dog, ate, slowly, eoi]).
test(state_machine) :- state_machine([the, dog, ran, slowly, eoi]).
test(state_machine) :- state_machine([the, cat, ate, noisily, eoi]).
test(state_machine) :- state_machine([the, cat, ran, noisily, eoi]).
test(state_machine) :- state_machine([the, dog, ate, noisily, eoi]).
test(state_machine) :- state_machine([the, dog, ran, noisily, eoi]).

test(state_machine) :- state_machine([the, smelly, cat, ate, slowly, eoi]).
test(state_machine) :- state_machine([the, smelly, cat, ran, slowly, eoi]).
test(state_machine) :- state_machine([the, smelly, dog, ate, slowly, eoi]).
test(state_machine) :- state_machine([the, smelly, dog, ran, slowly, eoi]).
test(state_machine) :- state_machine([the, smelly, cat, ate, noisily, eoi]).
test(state_machine) :- state_machine([the, smelly, cat, ran, noisily, eoi]).
test(state_machine) :- state_machine([the, smelly, dog, ate, noisily, eoi]).
test(state_machine) :- state_machine([the, smelly, dog, ran, noisily, eoi]).
test(state_machine) :- state_machine([the, lazy, cat, ate, slowly, eoi]).
test(state_machine) :- state_machine([the, lazy, cat, ran, slowly, eoi]).
test(state_machine) :- state_machine([the, lazy, dog, ate, slowly, eoi]).
test(state_machine) :- state_machine([the, lazy, dog, ran, slowly, eoi]).
test(state_machine) :- state_machine([the, lazy, cat, ate, noisily, eoi]).
test(state_machine) :- state_machine([the, lazy, cat, ran, noisily, eoi]).
test(state_machine) :- state_machine([the, lazy, dog, ate, noisily, eoi]).
test(state_machine) :- state_machine([the, lazy, dog, ran, noisily, eoi]).

test(state_machine) :- state_machine([the, smelly, smelly, smelly, smelly, smelly, smelly, smelly, cat, ate, eoi]).

test(state_machine) :- not(state_machine([])).
test(state_machine) :- not(state_machine([the, cat, ate])).
test(state_machine) :- not(state_machine([cat, ate, eoi])).
test(state_machine) :- not(state_machine([the, eoi])).

:- end_tests(all).
