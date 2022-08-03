
:- use_module(library(clpfd)).

farm(C,D) :-
    C + D #= 32,
    D * 2 + C * 4 #= 74.

score(C,D, Score) :- Score #= 10 * C - 11 * D. 
