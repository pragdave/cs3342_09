#!/bin/sh

base=function.pl
PL=swipl

exec $PL -c function.pl tests.pl
:- initialization go.

go :-
        current_prolog_flag(argv, Arguments),
        go(Arguments).

go(Args) :-
	[Args].
